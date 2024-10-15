#include <iostream>
#include <string>
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
            cout << "Stack Overflow: Cannot push " << value << " as the stack is full." << endl;
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
            return T(); // Return a default-constructed value of T
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOpening(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

string infixToPostfix(string infix) {
    Stack<char> stack(infix.length());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];


        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (isOpening(ch)) {
            stack.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            while (!stack.isEmpty() && !isOpening(stack.top())) {
                postfix += stack.pop();
            }

            if (!stack.isEmpty()) {
                stack.pop();
            }
        }

        else {
            while (!stack.isEmpty() && precedence(stack.top()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

int main() {
    string infix = "[A+B+{(C^a)^b}]";
    cout << "Infix Expression: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
