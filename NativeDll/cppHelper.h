#pragma once

#include <string>

// string 转 wstring，不支持中文
std::wstring s2ws(std::string s);

// wstring 转 string，不支持中文
std::string ws2s(std::wstring ws);



// string 转 wstring，支持中文
std::wstring s2ws_2(std::string s);

// wstring 转 string，支持中文
std::string ws2s_2(std::wstring ws);



// string 转 wstring，支持中文
std::wstring s2ws_3(std::string s);

// wstring 转 string，支持中文
std::string ws2s_3(std::wstring ws);



// int 转 string
std::string int2string(int i);

// float 转 string
std::string float2string(float f);