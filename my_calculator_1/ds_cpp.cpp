//#include <iostream>
//#include <string>
//#include <cctype>
//#include <stdexcept>
//using namespace std;
//double parseTerm(const string&, size_t& index);
//double parsePrimary(const string&, size_t& index);
//double parseNumber(const string& res, size_t& index);
//
//
//double parseExpression(const string& res, size_t& index) {
//	double left = parseTerm(res, index);
//	char op;
//	while (index < res.length())
//	{
//		if (res[index] != '+' && res[index] != '-')
//		{
//			return left;
//		}
//		op = res[index];
//		index++;
//		double right = parseTerm(res, index);
//		if (op == '+')
//		{
//			left += right;
//		}
//		else {
//			left -= right;
//		}
//	}
//	return left;
//}
//double parseTerm(const string& res, size_t& index) {
//	double left = parsePrimary(res, index);
//	char op;
//	while (index < res.length())
//	{
//		op = res[index];
//		if (op != '*' && op != '/')
//		{
//			return left;
//		}
//		index++;
//		double right = parsePrimary(res, index);
//		if (op == '*')
//		{
//			left *= right;
//		}
//		else
//		{
//			if (right == 0)
//			{
//				throw invalid_argument("0不能作为被除数'");
//			}
//			else
//			{
//				left /= right;
//			}
//
//		}
//	}
//}
//double parsePrimary(const string& res, size_t& index) {
//	double result = 0;
//	if (res[index] == '(')
//	{
//		index++;
//		result = parseExpression(res, index);
//		if (res[index] != ')')
//		{
//			throw invalid_argument("Expected ')'");
//		}
//		index++;
//	}
//	else {
//		if (isdigit(res[index]) && index < res.length())
//		{
//			result = parseNumber(res, index);
//		}
//	}
//	return result;
//
//
//}
//double parseNumber(const string& res, size_t& index) {
//	double result = 0;
//	while (isdigit(res[index]) && index < res.length()) {
//		result = result * 10 + (res[index] - '0');
//		index++;
//	}
//	if (res[index] == '.')
//	{
//		double fraction = 1;
//		index++;
//		while (index < res.length() && isdigit(res[index]))
//		{
//			fraction /= 10;
//			result = result + (res[index] - '0') * fraction;
//			index++;
//		}
//
//	}
//	return result;
//}
////int main() {
////	size_t index = 0;
////	string res;
////	getline(cin, res);
////	try
////	{
////		double result = parseExpression(res, index);
////		cout << result;
////	}
////	catch (const std::exception& e)
////	{
////		cout << e.what();
////	}
////}