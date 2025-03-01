#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

// ��ȡ�����������ȼ�
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ִ�м򵥵���ѧ����
double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) throw invalid_argument("Division by zero.");
        return a / b;
    default: throw invalid_argument("Invalid operator.");
    }
}

// ������ʽ��ֵ
double evaluateExpression(const string& expression) {
    stack<double> values; // �洢��ֵ
    stack<char> ops;      // �洢������

    for (size_t i = 0; i < expression.length(); i++) {
        // �����ո�
        if (isspace(expression[i])) continue;

        // ��������֣������������ֲ�ѹ��ֵջ
        if (isdigit(expression[i]) || expression[i] == '.') {
            double val = 0;
            size_t j = i;
            while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) j++;
            val = stod(expression.substr(i, j - i));
            values.push(val);
            i = j - 1;
        }
        // ����������ţ�ѹ�������ջ
        else if (expression[i] == '(') {
            ops.push(expression[i]);
        }
        // ����������ţ���������������ڵ����в�����
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            if (!ops.empty() && ops.top() == '(') ops.pop();
        }
        // ����ǲ�����
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.push(expression[i]);
        }
    }

    // ����ʣ��Ĳ�����
    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

//int main() {
//    cout << "�������������" << endl;
//    cout << "������һ�����ʽ (����: 3 + 5 * (2 - 8)): \n";
//    string expression;
//    getline(cin, expression);
//
//    try {
//        double result = evaluateExpression(expression);
//        cout << "���: " << result << endl;
//    }
//    catch (const exception& e) {
//        cerr << "����: " << e.what() << endl;
//    }
//
//    return 0;
//}
