#include <iostream>
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

int main() {
    Stack<int> intStack(3);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.push(40);

    cout << "Top element (int): " << intStack.top() << endl;
    cout << "Popped element (int): " << intStack.pop() << endl;
    cout << "Top element after pop (int): " << intStack.top() << endl;

    Stack<string> stringStack(2);
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("Extra");
    
    cout << "Top element (string): " << stringStack.top() << endl;
    cout << "Popped element (string): " << stringStack.pop() << endl;
    cout << "Top element after pop (string): " << stringStack.top() << endl;

    return 0;
}
