
#include"std_libx_facilities.h"
#include "test.cpp";
//可以重复声明，但不可以重复定义
//double sqrt(double);
//double sqrt(double);
////如果定义两个，那么下运行时报错
////double sqrt(double) {
////
////}
//double sqrt(double) {
//	return 0;
//	}

int main()
{
	//nameAge();
	//vector<string> s = { "fe","aa","gewgew","gewa","hteh","bve" };
	//for (string str :s) {
	//	cout << str<<endl;
	//}

	//vector<int> c = getStringLength(s);
	int i = 5;
	constexpr int j = 6;

	f(i);
	f(j);
	f(7);

	return 0;
}

