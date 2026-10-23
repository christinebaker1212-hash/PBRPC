import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from automatch import mask, same


class BranchRelocationTests(unittest.TestCase):
    def test_rel24_masks_only_displacement(self):
        for flags in range(4):
            instruction = (0x4BFFFFFC | flags).to_bytes(4, "big")
            expected = (0x48000000 | flags).to_bytes(4, "big")
            self.assertEqual(mask(instruction, [(0, 10, "callee")]), expected)

    def test_rel24_preserves_surrounding_instructions(self):
        code = bytes.fromhex("60000000 4bffffff 4e800020")
        self.assertEqual(
            mask(code, [(4, 10, "callee")]),
            bytes.fromhex("60000000 48000003 4e800020"),
        )

    def test_same_accepts_different_displacements(self):
        relocs = [(0, 10, "callee")]
        self.assertTrue(same((bytes.fromhex("48000001"), relocs),
                             (bytes.fromhex("4bfffffd"), relocs)))

    def test_same_rejects_different_branch_control_bits(self):
        relocs = [(0, 10, "callee")]
        for flags in (1, 2, 3):
            with self.subTest(flags=flags):
                self.assertFalse(same(
                    ((0x48000000).to_bytes(4, "big"), relocs),
                    ((0x48000000 | flags).to_bytes(4, "big"), relocs),
                ))


if __name__ == "__main__":
    unittest.main()
