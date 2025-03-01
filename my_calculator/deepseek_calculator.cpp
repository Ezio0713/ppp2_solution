#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

// 解析表达式并计算结果的函数
double parseExpression(const string& expr, size_t& index);

// 解析数字
double parseNumber(const string& expr, size_t& index) {
    double number = 0;
    while (index < expr.length() && isdigit(expr[index])) {
        number = number * 10 + (expr[index] - '0');
        index++;
    }
    if (index < expr.length() && expr[index] == '.') {
        index++;
        double fraction = 1;
        while (index < expr.length() && isdigit(expr[index])) {
            fraction /= 10;
            number += (expr[index] - '0') * fraction;
            index++;
        }
    }
    return number;
}

// 解析括号或数字
double parsePrimary(const string& expr, size_t& index) {
    if (index >= expr.length()) {
        throw invalid_argument("Unexpected end of expression");
    }
    if (expr[index] == '(') {
        index++; // 跳过 '('
        double result = parseExpression(expr, index);
        if (index >= expr.length() || expr[index] != ')') {
            throw invalid_argument("Expected ')'");
        }
        index++; // 跳过 ')'
        return result;
    }
    if (isdigit(expr[index]) || expr[index] == '.') {
        return parseNumber(expr, index);
    }
    throw invalid_argument("Unexpected character");
}

// 解析乘法和除法
double parseTerm(const string& expr, size_t& index) {
    double left = parsePrimary(expr, index);
    while (index < expr.length()) {
        char op = expr[index];
        if (op != '*' && op != '/') {
            break;
        }
        index++;
        double right = parsePrimary(expr, index);
        if (op == '*') {
            left *= right;
        }
        else {
            if (right == 0) {
                throw invalid_argument("Division by zero");
            }
            left /= right;
        }
    }
    return left;
}

// 解析加法和减法
double parseExpression(const string& expr, size_t& index) {
    double left = parseTerm(expr, index);
    while (index < expr.length()) {
        char op = expr[index];
        if (op != '+' && op != '-') {
            break;
        }
        index++;
        double right = parseTerm(expr, index);
        if (op == '+') {
            left += right;
        }
        else {
            left -= right;
        }
    }
    return left;
}

 //主函数
int main() {
    string expr;
    cout << "请输入一个表达式（支持加减乘除和括号）：";
    getline(cin,expr);

    try {
        size_t index = 0;
        double result = parseExpression(expr, index);
        cout << "结果: " << result << endl;
    }
    catch (const invalid_argument& e) {
        cout << "错误: " << e.what() << endl;
    }

    return 0;
}