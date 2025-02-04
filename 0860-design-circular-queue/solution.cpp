class MyCircularQueue {
    int front, rear, size;
    int* arr;

public:
    MyCircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool enQueue(int val) {
        if (isFull()) {
            cout << "Overflow!" << endl;
            return false;
        }
        if (isEmpty()) {
            rear = front = 0;
        }
        else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        cout << "Enqueued " << val << " to the MyCircularQueue" << endl;
        return true;
    }

    bool deQueue() {  
        if (isEmpty()) {
            cout << "Underflow!" << endl;
            return false;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        cout << "Dequeued " << val << " from the MyCircularQueue" << endl;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear() {  
        if (isEmpty()) return -1;
        return arr[rear];
    }

    ~MyCircularQueue() {
        delete[] arr;
    }
};
