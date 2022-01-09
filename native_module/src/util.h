#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <algorithm>
#include <string>
#include <olectl.h>

std::wstring convert2WString(std::string str);
std::string convert2String(std::wstring str);

#endif // UTIL_H