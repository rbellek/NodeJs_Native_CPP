#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <algorithm>
#include <string>

std::wstring convert2WString(std::string str);
std::string convert2String(std::wstring str);

#endif // UTIL_H