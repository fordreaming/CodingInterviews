#include <iostream>
#include <vector>
#include <string>
#include "BruteReplace.hpp"
using namespace std;

int main()
{
	BruteReplace bruteReplace;
	/*string str("we are you");*/
	/*string str = "we are you";*/
	char cstr[100] = "we are you";
	/*bruteReplace.ReplaceBlank(str);*/
	/*bruteReplace.replaceSpace(cstr, strlen(cstr));*/
	bruteReplace.replaceSpaceByCal(cstr, strlen(cstr));
	return 0;
}