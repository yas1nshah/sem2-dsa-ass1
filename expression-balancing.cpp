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


bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string& expression) {
    Stack<char> stack(expression.length());

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);

        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false;
            }

            char topChar = stack.pop();
            if (!isMatchingPair(topChar, ch)) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main() {
    string expression ="(A+B)*(C-D)";

    if (isBalanced(expression)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }

    return 0;
}
