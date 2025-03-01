
//#include "std_lib_facilities.h"
//const char number = '8';
//const char quit = 'q';
//const char print = ';';
//const string prompt = ">>";
//const string result = "=";
//class Token {
//	char type;
//	double value;
//public:
//	Token(char ch) :type(ch), value(0){}
//	Token(char ch,double value) :type(ch), value(value) {}
//
//};
//class Token_stream {
//	bool isFull;
//	Token buffer;
//	Token get_Token();
//	void putBack(Token t);
//};
//Token_stream ts;
////用于获取token
//Token Token_stream::get_Token() {
//	if (isFull)
//	{
//		isFull = false;
//		return buffer;
//	}
//	else
//	{
//		char ch;
//		cin >> ch;
//		switch (ch)
//		{
//		case '0':
//		case '1':
//		case '2':
//		case '3':
//		case '4':
//		case '5':
//		case '6':
//		case '7':
//		case '8':
//		case '9':
//			double val;
//			cin.putback(ch);
//			cin >> val;
//			Token t('8',val);
//			return t;
//		case '+':
//		case '-':
//		case '*':
//		case '/':
//		case ';':
//		case '(':
//		case ')':
//			Token t(ch, 0);
//			return t;
//		default:
//			break;
//		}
//	}
//
//}
//void Token_stream::putBack(Token t) {
//	isFull = true;
//	buffer = t;
//}
//double express() {
//}
//double term() {
//
//}
//double primary() {
//
//}

//int main() {
////
//}