// Imported from doldecomp/ogws (CC0), src/nw4r/ut/ut_Font.cpp
#include <nw4r/ut.h>

namespace nw4r {
namespace ut {

void Font::InitReaderFunc(FontEncoding encode) {
    switch (encode) {
    case FONT_ENCODING_UTF8: {
        mReadFunc = &CharStrmReader::ReadNextCharUTF8;
        break;
    }

    case FONT_ENCODING_UTF16: {
        mReadFunc = &CharStrmReader::ReadNextCharUTF16;
        break;
    }

    case FONT_ENCODING_SJIS: {
        mReadFunc = &CharStrmReader::ReadNextCharSJIS;
        break;
    }

    case FONT_ENCODING_CP1252:
    default: {
        mReadFunc = &CharStrmReader::ReadNextCharCP1252;
        break;
    }
    }
}

} // namespace ut
} // namespace nw4r

#include "common.hpp"

extern "C" {

s32 __dl__FPv(void);

s32 fn_80363F2C(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}
