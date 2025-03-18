#include"std_lib_facilities.h"


struct DateS
{
		int year;
		int month;
		int day;
		//构造函数
		DateS(int y, int m, int d) {
			year = y;
			month = m;
			day = d;
		};
};
//类date
class Date
{
public:
	//用于检查非法日期
	class Invalid {
	};
	Date(int yy, int mm, int dd);
	void add_day(int n);
	int month() {
		return m;
	}
	int day() {
		return d;
	}
	int year() {
		return y;
	}
private:
	int y, m, d;
	//如果日期合法，则返回true
	bool is_valid();
};
Date::Date(int yy, int mm, int dd) :y{yy}, m{mm}, d{dd} {
}



//9.5枚举类型
//作用域枚举（必须通过month::jan调用jan）
enum class month
{
	//不初始化的话，赋予每个枚举值的值为上一个枚举值+1
	//如果不初始化第一个枚举，那么从0开始
	jan = 1, feb,mar,apr,may,june
};
//平坦枚举：不用非要用::调用，而且可以将枚举值用int接收
enum goal
{
	getJob=1,pracCamara=2,getCar=3
};
int main()//主函数
{
	//DateS today{2025,3,18};
	//这居然也可以
	//++today.day;
	//cout << today.year << endl;
	//cout << today.month << endl;
	// << today.day << endl;

	Date yestoday{2025,3,18};
	//cout << yestoday.year()<< endl;
	//cout << yestoday.month()<< endl;
	//cout<< yestoday.day()<< endl;
	month m = month::may;
	//goal a = 1;错误
	goal a = (goal)2;
	//下面这种如果是作用域枚举类型就会报错
	int getjob = getJob;
	int pracCamara = a;
	cout << getjob<<endl;
	cout << a;
	return 0;//返回到主程序
}
