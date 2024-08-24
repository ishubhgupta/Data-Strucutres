#include<iostream>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q, int x) {
    if (q->rear == q->size - 1) {
        cout << "Queue is full" << endl;
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    if (q->front == q->rear) {
        cout << "Queue is empty" << endl;
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue *q) {
    if (q->front == q->rear) {
        cout << "Queue is empty" << endl;
    } else {
        for (int i = q->front + 1; i <= q->rear; i++) {
            cout << q->Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    q.front = q.rear = -1;
    q.size = 10;
    q.Q = new int[q.size];
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    cout << "Dequeued: " << dequeue(&q) << endl;
    display(&q);

    delete[] q.Q;

    return 0;
}
