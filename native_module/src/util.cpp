#include "util.h"

#include <codecvt>
#include <locale>

std::wstring convert2WString(std::string str)
{
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
}

std::string convert2String(std::wstring str)
{
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(str);
}

