#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

template <typename T>
class Stack {
private:
    int topIndex;
    int capacity;
    T* arr;

public:
    Stack(int size = 10) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow: Cannot push as the stack is full." << endl;
            return;
        }
        arr[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop as the stack is empty." << endl;
            return T();
        }
        return arr[topIndex--];
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return T();
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};


int evaluatePostfix(string postfix) {
    Stack<int> stack(postfix.length());

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            stack.push(ch - '0');

        } else {

            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (ch) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': stack.push(operand1 / operand2); break;
                case '^': stack.push(pow(operand1, operand2)); break;
                default: cout << "Invalid operator: " << ch << endl; return -1;
            }
        }
    }

    return stack.pop();
}

int main() {
    string postfix = "53+82-*";
    cout << "Postfix Expression: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
