#include <iostream>
using namespace std;

struct Stack {
    int size;
    int top;
    char *s; 
};

bool isFull(const Stack &st) {
    return st.top == st.size - 1;
}

bool isEmpty(const Stack &st) {
    return st.top == -1;
}

void push(Stack *st, char c) {
    if (isFull(*st)) {
        cout << "Stack is Full" << endl;
    } else {
        st->s[++st->top] = c;
    }
}

char pop(Stack *st) {
    if (isEmpty(*st)) {
        cout << "Stack is Empty" << endl;
        return '\0';
    } else {
        return st->s[st->top--];
    }
}

void cleanup(Stack *st) {
    delete[] st->s;
}

int main() {
    Stack st;
    string t1 = "({a+b}*[c+d])";
    int n = t1.size();

    st.size = n;
    st.top = -1;
    st.s = new char[st.size];
    
    bool balanced = true;

    for (int i = 0; i < n; i++) {
        if (t1[i] == '(' || t1[i] == '{' || t1[i] == '[') {
            push(&st, t1[i]);
        }
        else if (t1[i] == ')') {
            if (isEmpty(st) || pop(&st) != '(') {
                balanced = false;
                break;
            }
        }
        else if (t1[i] == '}') {
            if (isEmpty(st) || pop(&st) != '{') {
                balanced = false;
                break;
            }
        }
        else if (t1[i] == ']') {
            if (isEmpty(st) || pop(&st) != '[') {
                balanced = false;
                break;
            }
        }
    }

    if (!isEmpty(st)) {
        balanced = false;
    }

    if (balanced) {
        cout << "Parentheses and brackets are matching" << endl;
    } else {
        cout << "Parentheses and brackets are not matching" << endl;
    }

    cleanup(&st);

    return 0;
}
