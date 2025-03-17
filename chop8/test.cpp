#include"std_libx_facilities.h"
void fibnaha(int x, int y, vector<int> v, int n) {
	int z;
	if (--n >= 0)
	{
		v.push_back(x);
	}

	if (--n >= 0)
	{
		v.push_back(y);
	}

	while (n-- >= 0)
	{
		z = x + y;
		v.push_back(z);
		x = y;
		y = z;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
//8.5
vector<int> reverse_v1(const vector<int>& v1)
{
	vector<int>v2(v1.size());

	for (int i = v1.size() - 1, j = 0; i >= 0; i--, j++)
		v2[j] = v1[i];
	return v2;
}

void reverse_v2(vector<int>& v)
{
	for (int i = 0, j = v.size() - 1; i < j; i++, j--)
		swap(v[i], v[j]);
}
//8.7
void nameAge() {
	vector<string> name;
	vector<int> age;
	string nameStr;
	int ageNum;
	cout << "请输入姓名,输入q结束";
	while (true)
	{	
		cin >> nameStr;
		if (nameStr=="q")
		{
			break;
		}
		name.push_back(nameStr);
	}
	cout << "请输入姓名顺序的年龄";
	while (age.size()<name.size())
	{
		cin >> ageNum;
		age.push_back(ageNum);
	}
	vector<string> nameOrigin = name;
	sort(name.begin(), name.end());
	//储存排序后的年龄
	vector<int> newAge(age.size());
	auto j = 0;
	for (size_t i = 0; i < name.size(); i++)
	{
		j = 0;
		while (name[i]!=nameOrigin[j]) {
			j++;
		}
		newAge[i] = age[j];

	}
	for (size_t i = 0; i < name.size(); i++)
	{
		cout << name[i] << endl;
	}
	for (size_t i = 0; i < age.size(); i++)
	{
		cout << newAge[i] << endl;
	}	
}
//8.12
vector<int> getStringLength(vector<string>  stringVec) {
	int maxLength=0;
	string maxLengthString="";
	vector<int> lengthVec;
	for (size_t i = 0; i < stringVec.size(); i++)
	{
		lengthVec.push_back(stringVec[i].size());
		 if (stringVec[i].size()> maxLength) {
			maxLength = stringVec[i].size();
			maxLengthString = stringVec[i];
		}
	}
	sort(stringVec);
	cout << "最长字符串是" << maxLengthString << endl;
	cout << "最长字符串长度是：" << maxLength << endl;
	return lengthVec;
}
//8.13
void f(const int n)
{
	cout << "const int n = " << n << endl;
}