#include <iostream>
using namespace std;

struct Stack {
    int size;
    int top;
    int *s;
};

bool isEmpty(struct Stack *st){
    if(st->top == -1) return true;
    return false;
}

bool isFull(struct Stack *st){
    if(st->top== st->size-1) return true;
    return false;
}

// Push an element onto the stack
void push(Stack *st, int x) {
    if (isFull(st)) {
        cout << "Stack is full" << endl;
    } else {
        st->s[++st->top] = x;
    }
}

// Pop an element from the stack
int pop(Stack *st) {
    if (isEmpty(st)) {
        cout << "Stack is empty" << endl;
        return -1; 
    } else {
        return st->s[st->top--]; 
    }
}

// Display elements of the stack
void display(const Stack &st) {
    if (st.top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = 0; i <= st.top; i++) {
            cout << st.s[i] << " ";
        }
        cout << endl;
    }
}

// Clean up stack resources
void cleanup(Stack *st) {
    delete[] st->s;
}

int main() {
    string t = "a+b*c/(d+e)";
    Stack st;
    st.size = t.size();
    st.top = -1;
    st.s = new int[st.size];

    for(int i = 0;i<t.size();i++){
        
    }


    return 0;
}
