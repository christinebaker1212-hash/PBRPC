import json
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import automatch
from elf32 import ElfReloc, ElfSymbol


class RelocationAddendTests(unittest.TestCase):
    def reloc(self, addend):
        symbol = ElfSymbol('record', 0, 8, 1, 1, 0)
        return (0, 109, automatch.reloc_name(None, ElfReloc(0, 109, symbol, addend)))

    def test_rejects_different_fields_of_same_symbol(self):
        code = bytes.fromhex('80600000')
        self.assertFalse(automatch.same((code, [self.reloc(0)]),
                                       (code, [self.reloc(4)])))

    def test_accepts_equal_addends(self):
        code = bytes.fromhex('80600000')
        for addend in (-4, 0, 4):
            with self.subTest(addend=addend):
                self.assertTrue(automatch.same((code, [self.reloc(addend)]),
                                              (code, [self.reloc(addend)])))


class ApplyRegressionTests(unittest.TestCase):
    def run_candidate(self, candidate):
        good = (bytes.fromhex('4e800020'), [])
        wrong = (bytes.fromhex('60000000'), [])
        targets = {'old': good, 'new': good}
        target = SimpleNamespace(
            elf=SimpleNamespace(functions=lambda: targets), function=targets.get)
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / 'unit.cpp'
            source.write_text('original')
            (root / 'new.cpp').write_text('candidate')
            (root / 'objdiff.json').write_text(json.dumps({'units': [{
                'name': 'main/unit', 'base_path': 'unit.o',
                'metadata': {'source_path': 'unit.cpp'},
            }]}))

            def compiled(_):
                state = source.read_text()
                functions = {'old': wrong if state == 'regression' else good}
                if state != 'original':
                    functions['new'] = good
                return SimpleNamespace(function=functions.get)

            with patch.object(automatch, 'ROOT', root), \
                 patch.object(automatch, 'Obj', side_effect=compiled), \
                 patch.object(automatch, 'build_unit', return_value=True), \
                 patch.object(automatch, 'remove_definition', side_effect=lambda s, n: s), \
                 patch.object(automatch, 'merge_into', return_value=candidate):
                applied = automatch.apply('unit', 'RPBE01', root, ['new'], target)
            return applied, source.read_text()

    def test_rejects_candidate_that_breaks_existing_match(self):
        self.assertEqual(self.run_candidate('regression'), ([], 'original'))

    def test_accepts_candidate_preserving_existing_match(self):
        self.assertEqual(self.run_candidate('compatible'), (['new'], 'compatible'))


if __name__ == '__main__':
    unittest.main()
