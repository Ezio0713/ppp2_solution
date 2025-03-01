#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

// 获取操作符的优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 执行简单的数学操作
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

// 计算表达式的值
double evaluateExpression(const string& expression) {
    stack<double> values; // 存储数值
    stack<char> ops;      // 存储操作符

    for (size_t i = 0; i < expression.length(); i++) {
        // 跳过空格
        if (isspace(expression[i])) continue;

        // 如果是数字，解析整个数字并压入值栈
        if (isdigit(expression[i]) || expression[i] == '.') {
            double val = 0;
            size_t j = i;
            while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) j++;
            val = stod(expression.substr(i, j - i));
            values.push(val);
            i = j - 1;
        }
        // 如果是左括号，压入操作符栈
        else if (expression[i] == '(') {
            ops.push(expression[i]);
        }
        // 如果是右括号，弹出并解决括号内的所有操作符
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            if (!ops.empty() && ops.top() == '(') ops.pop();
        }
        // 如果是操作符
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

    // 处理剩余的操作符
    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

//int main() {
//    cout << "复合运算计算器" << endl;
//    cout << "请输入一个表达式 (例如: 3 + 5 * (2 - 8)): \n";
//    string expression;
//    getline(cin, expression);
//
//    try {
//        double result = evaluateExpression(expression);
//        cout << "结果: " << result << endl;
//    }
//    catch (const exception& e) {
//        cerr << "错误: " << e.what() << endl;
//    }
//
//    return 0;
//}
