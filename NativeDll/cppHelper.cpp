#include "pch.h"
#include "cppHelper.h"

using namespace Platform;

std::wstring s2ws(std::string s)
{
	std::wstring ws;
	ws.assign(s.begin(), s.end());
	return ws;
}

std::string ws2s(std::wstring ws)
{
	std::string s;
	s.assign(ws.begin(), ws.end());
	return s;
}



std::wstring s2ws_2(std::string s)
{
	setlocale(LC_ALL, "chs");

	const char* _Source = s.c_str();
	size_t _Dsize = s.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);

	std::wstring result = _Dest;

	delete[]_Dest;
	setlocale(LC_ALL, "C");

	return result;
}

std::string ws2s_2(std::wstring ws)
{
	std::string curLocale = setlocale(LC_ALL, NULL);

	setlocale(LC_ALL, "chs");
	const wchar_t* _Source = ws.c_str();
	size_t _Dsize = 2 * ws.size() + 1;
	char *_Dest = new char[_Dsize];
	memset(_Dest, 0, _Dsize);
	wcstombs(_Dest, _Source, _Dsize);
	
	std::string result = _Dest;

	delete[]_Dest;
	setlocale(LC_ALL, curLocale.c_str());

	return result;
}



std::wstring s2ws_3(std::string s)
{
	std::wstring wszStr;

	int nLength = MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, NULL, NULL);
	wszStr.resize(nLength);
	LPWSTR lpwszStr = new wchar_t[nLength];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, lpwszStr, nLength);
	wszStr = lpwszStr;
	delete[] lpwszStr;

	return wszStr;
}

std::string ws2s_3(std::wstring ws)
{
	int nBufSize = WideCharToMultiByte(CP_ACP, 0, ws.c_str(), -1, NULL, 0, 0, FALSE);
	char *szBuf = new char[nBufSize];
	WideCharToMultiByte(CP_ACP, 0, ws.c_str(), -1, szBuf, nBufSize, 0, FALSE);

	std::string strRet(szBuf);

	delete[]szBuf;
	szBuf = NULL;

	return strRet;
}



std::string int2string(int i)
{
	if (i == 0)
		return "0";

	std::string str = "";
	int i_ = i > 0 ? i : -1 * i;

	while (i_)
	{
		str = (char)(i_ % 10 + 48) + str;
		i_ /= 10;
	}

	if (i < 0)
		str = "-" + str;

	return str;
}

std::string float2string(float f)
{
	char c[32];
	sprintf(c, "%.2f", f);

	return std::string(c);
}