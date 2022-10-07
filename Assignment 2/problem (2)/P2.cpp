/* 
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/
#include <iostream>
using namespace std;

class Queue {
private:
    int SIZE = 0;
    int cnt = 0;
    int* items, front, rear;

public:
    Queue(int size) {
        front = -1;
        rear = -1;
        items = new int[size];
        SIZE = size;
    }
    // Check if the queue is full
    bool isFull() {
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        if (front == rear + 1) {
            return true;
        }
        return false;
    }
    // Check if the queue is empty
    bool isEmpty() {
        if (front == -1)
            return true;
        else
            return false;
    }
    // Adding an element
    void enQueue(int element) {
        if (isFull()) {
            cout << "Queue is full";
        }
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cnt++;
        }
    }
    // Removing an element
    int deQueue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return (-1);
        }
        else {
            element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            // Q has only one element,
            // so we reset the queue after deleting it.
            else {
                front = (front + 1) % SIZE;
            }
            cnt--;
            return (element);
        }
    }

    void display() {
        // Function to display status of Circular Queue
        int i;
        if (isEmpty()) {
            cout << endl
                << "Empty Queue" << endl;
        }
        else {
            cout << "Front -> " << front;
            cout << endl
                << "Items -> ";
            for (i = front; i != rear; i = (i + 1) % SIZE)
                cout << items[i];
            cout << items[i];
            cout << endl
                << "Rear -> " << rear;
        }
    }
    int back()
    {
        return items[rear];
    }
    int Front()
    {
        return items[front];
    }
    int size()
    {
        return cnt;
    }
};

int fun(Queue q, int k)
{
    int cnt = 0;
    int s = q.size();
    if (k == s - 1) cnt = 0;
    else
    {
        cnt = k + 1;
        for (int i = 0; i <= k; i++)
        {
            int x = q.Front();
            q.deQueue();
            x--;
            if (x > 0) q.enQueue(x);
            if (i == k && x == 0) return cnt;
        }
    }
    while (!q.isEmpty())
    {
        bool y = false;
        s = q.size();
        for (int i = 0; i < s; i++)
        {
            int x = q.Front();
            q.deQueue();
            x--;
            if (x > 0) q.enQueue(x);
            cnt++;
            if (i == s - 1 && x == 0) {
                y = true;
                break;
            }

        }
        if (y)
            break;
        if (q.size() == 1)
        {
            cnt += q.Front();
            break;
        }
    }
    return cnt;
}
int main() {

    Queue q(3);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(2);
    int k = 2;
    cout << 2 << " " << 3 << " " << 2 << endl;

    cout << "At Index 2: ";
    cout << fun(q, k) << endl;

    cout << endl;


    Queue q1(4);
    q1.enQueue(5);
    q1.enQueue(1);
    q1.enQueue(1);
    q1.enQueue(1);
    int k1 = 0;
    cout << 5 << " " << 1 << " " << 1 << " " << 1 << endl;

    cout << "At Index 0: ";
    cout << fun(q1, k1) << endl;

    cout << "At Index 3: ";
    cout << fun(q1, 3) << endl;

    cout << endl;

    Queue q2(7);
    q2.enQueue(1);
    q2.enQueue(1);
    q2.enQueue(1);
    q2.enQueue(5);
    q2.enQueue(1);
    q2.enQueue(1);
    q2.enQueue(1);
    cout << 1 << " " << 1 << " " << 1 << " " << 5 << " " << 1 << " " << 1 << " " << 1 << endl;
    cout << "At Index 0 : ";
    cout << fun(q2, 0) << endl;

    cout << "At Index 3: ";
    cout << fun(q2, 3) << endl;

    cout << endl;




    return 0;
}
