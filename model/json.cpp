#include "../common/rapidjson/filereadstream.h"
#include "../common/rapidjson/document.h"
#include <cstdio>
#include <iostream>
#include "windows.h"

using namespace rapidjson;
using namespace std;

string UTF8ToGBK(const char* strUTF8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
    wchar_t* wszGBK = new wchar_t[len+1];
    memset(wszGBK, 0, len*2+2);
    MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
    char* szGBK = new char[len+1];
    memset(szGBK, 0, len+1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
    string strTemp(szGBK);
    if(wszGBK) delete[] wszGBK;
    if(szGBK) delete[] szGBK;
    return strTemp;
}
int main()
{
	FILE* fp = fopen("����˹-ʩ��.json", "rb");
	char buffer[65536];
	FileReadStream is(fp, buffer, sizeof(buffer));
	Document d;
	d.ParseStream(is);
	for (auto& a : d.GetArray())
	{
		cout << a["season"][0].GetString() << endl;;
		cout << a["ast"][0].GetString() << endl;
		cout << a["w"][0].GetString() << endl;
	}
	//printf("hello = %s\n", document["hello"].GetString());
	return 0;
}
