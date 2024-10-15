---
title: DSA - Assignment 1 - Stack
---
# Stack:

<SwmSnippet path="stack.cpp" line="4" collapsed>

---

Here a \*Stack Data Type\* is implemented using a Class.

template is used to make this class Generic so that the stack is able to store any Data Type.

```
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

```

---

</SwmSnippet>

<SwmSnippet path="stack.cpp" line="22" collapsed>

---

### Push:&nbsp;

This function takes a value of the given template, verifies if the stack is not full and then inserts the value at top of the stack.

```
    void push(T value) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow: Cannot push as the stack is full." << endl;
            return;
        }
        arr[++topIndex] = value;
    }

```

---

</SwmSnippet>

<SwmSnippet path="stack.cpp" line="30" collapsed>

---

### Pop:

This function verifies if the stack is not empty, and then removes the last/top most item of the Stack and returns that.

```
    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop as the stack is empty." << endl;
            return T();
        }
        return arr[topIndex--];
    }

```

---

</SwmSnippet>

<SwmSnippet path="stack.cpp" line="38" collapsed>

---

### Top:

This returns the top most item of the stack if its not empty

```
    T top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return T();
        }
        return arr[topIndex];
    }

```

---

</SwmSnippet>

<SwmSnippet path="/stack.cpp" line="46" collapsed>

---

### Is Empty:

It verifies if the stack is empty.

```c++
    bool isEmpty() {
        return topIndex == -1;
    }
};
```

---

</SwmSnippet>

<SwmMeta version="3.0.0" repo-id="Z2l0aHViJTNBJTNBc2VtMy1kc2EtYXNzMSUzQSUzQXlhczFuc2hhaA==" repo-name="sem3-dsa-ass1"><sup>Powered by [Swimm](https://app.swimm.io/)</sup></SwmMeta>
