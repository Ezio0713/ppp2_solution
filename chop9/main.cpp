#include"std_lib_facilities.h"


struct DateS
{
		int year;
		int month;
		int day;
		//���캯��
		DateS(int y, int m, int d) {
			year = y;
			month = m;
			day = d;
		};
};
//��date
class Date
{
public:
	//���ڼ��Ƿ�����
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
	//������ںϷ����򷵻�true
	bool is_valid();
};
Date::Date(int yy, int mm, int dd) :y{yy}, m{mm}, d{dd} {
}



//9.5ö������
//������ö�٣�����ͨ��month::jan����jan��
enum class month
{
	//����ʼ���Ļ�������ÿ��ö��ֵ��ֵΪ��һ��ö��ֵ+1
	//�������ʼ����һ��ö�٣���ô��0��ʼ
	jan = 1, feb,mar,apr,may,june
};
//ƽ̹ö�٣����÷�Ҫ��::���ã����ҿ��Խ�ö��ֵ��int����
enum goal
{
	getJob=1,pracCamara=2,getCar=3
};
int main()//������
{
	//DateS today{2025,3,18};
	//���ȻҲ����
	//++today.day;
	//cout << today.year << endl;
	//cout << today.month << endl;
	// << today.day << endl;

	Date yestoday{2025,3,18};
	//cout << yestoday.year()<< endl;
	//cout << yestoday.month()<< endl;
	//cout<< yestoday.day()<< endl;
	month m = month::may;
	//goal a = 1;����
	goal a = (goal)2;
	//�������������������ö�����;ͻᱨ��
	int getjob = getJob;
	int pracCamara = a;
	cout << getjob<<endl;
	cout << a;
	return 0;//���ص�������
}
