#include <iostream>
using namespace std;

struct Queue {
    int data[100];
    int front;
    int rear;
    int maxSize = 100;
};

Queue createQueue() {
    Queue Q;
    Q.front = -1;
    Q.rear = -1;
    return Q;
}

bool isEmpty(Queue Q) {
    return (Q.front == -1 || Q.front > Q.rear);
}

void enqueue(Queue &Q, int value) {
    if (Q.rear == Q.maxSize - 1) {
        cout << "Queue penuh! Tidak bisa menambah data." << endl;
        return;
    }
    
    if (Q.front == -1) {
        Q.front = 0;
    }
    
    Q.rear++;
    Q.data[Q.rear] = value;
    cout << "Data " << value << " berhasil ditambahkan ke queue" << endl;
}

void dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak ada data yang bisa dikeluarkan." << endl;
        return;
    }
    
    cout << "Data " << Q.data[Q.front] << " dikeluarkan dari queue" << endl;
    
    if (Q.front == Q.rear) {
        Q.front = -1;
        Q.rear = -1;
    } else {
        Q.front++;
    }
}

void displayQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    
    cout << "Isi Queue: ";
    for (int i = Q.front; i <= Q.rear; i++) {
        cout << Q.data[i] << " ";
    }
    cout << endl;
}

int main() {
    Queue myQueue = createQueue();
    
    cout << "=== Testing Queue Operations ===" << endl;
    cout << "\n1. Cek queue kosong: ";
    if (isEmpty(myQueue)) {
        cout << "Queue kosong" << endl;
    }
    
    cout << "\n2. Enqueue beberapa data:" << endl;
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    
    cout << "\n3. Tampilkan isi queue:" << endl;
    displayQueue(myQueue);
    
    cout << "\n4. Dequeue beberapa data:" << endl;
    dequeue(myQueue);
    dequeue(myQueue);
    
    cout << "\n5. Tampilkan isi queue setelah dequeue:" << endl;
    displayQueue(myQueue);
    
    cout << "\n6. Enqueue data baru:" << endl;
    enqueue(myQueue, 50);
    
    cout << "\n7. Tampilkan isi queue final:" << endl;
    displayQueue(myQueue);
    
    cout << "\n8. Dequeue semua data:" << endl;
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    
    cout << "\n9. Coba dequeue dari queue kosong:" << endl;
    dequeue(myQueue);
    
    return 0;
}