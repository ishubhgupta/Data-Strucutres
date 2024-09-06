#include<iostream>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

// Enqueue function to insert an element into the circular queue
void enqueue(struct Queue *q, int x) {
    if ((q->rear + 1) % q->size == q->front) {
        cout << "Queue is full" << endl;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

// Dequeue function to remove and return an element from the circular queue
int dequeue(struct Queue *q) {
    int x = -1;
    if (q->front == q->rear) {
        cout << "Queue is empty" << endl;
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

// Display function to print the elements in the circular queue
void display(struct Queue *q) {
    if (q->front == q->rear) {
        cout << "Queue is empty" << endl;
    } else {
        int i = (q->front + 1) % q->size;
        do {
            cout << q->Q[i] << " ";
            i = (i + 1) % q->size;
        } while (i != (q->rear + 1) % q->size);
        cout << endl;
    }
}

int main() {
    Queue q;
    q.front = q.rear = 0; 
    q.size = 6;           
    q.Q = new int[q.size];
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    cout << "Dequeued: " << dequeue(&q) << endl;
    
    enqueue(&q, 60);
    display(&q);

    delete[] q.Q;

    return 0;
}
