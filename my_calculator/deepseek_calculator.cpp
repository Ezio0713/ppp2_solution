#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

// �������ʽ���������ĺ���
double parseExpression(const string& expr, size_t& index);

// ��������
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

// �������Ż�����
double parsePrimary(const string& expr, size_t& index) {
    if (index >= expr.length()) {
        throw invalid_argument("Unexpected end of expression");
    }
    if (expr[index] == '(') {
        index++; // ���� '('
        double result = parseExpression(expr, index);
        if (index >= expr.length() || expr[index] != ')') {
            throw invalid_argument("Expected ')'");
        }
        index++; // ���� ')'
        return result;
    }
    if (isdigit(expr[index]) || expr[index] == '.') {
        return parseNumber(expr, index);
    }
    throw invalid_argument("Unexpected character");
}

// �����˷��ͳ���
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

// �����ӷ��ͼ���
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

 //������
int main() {
    string expr;
    cout << "������һ�����ʽ��֧�ּӼ��˳������ţ���";
    getline(cin,expr);

    try {
        size_t index = 0;
        double result = parseExpression(expr, index);
        cout << "���: " << result << endl;
    }
    catch (const invalid_argument& e) {
        cout << "����: " << e.what() << endl;
    }

    return 0;
}