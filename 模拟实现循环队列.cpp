#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>

using namespace std;
class MyCircularQueue {
public:
    vector<int> arr;
    int head;
    int tail;
    MyCircularQueue(int k) : arr(k), head(INT_MAX), tail(INT_MAX) {}

    bool enQueue(int value) {
        //1. if uninitilized
        int size = arr.size();
        if (isEmpty()) {
            head = 0;
            tail = 1 % size;    //head == tail under k = 1
            arr[head] = value;
            return true;
        }

        //2. check if full
        if (head == tail)
            return false;

        //3. some availability
        arr[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }

    bool deQueue() {
        //1. if uninitizlied
        if (isEmpty())
            return false;

        int size = arr.size();
        //2. 
        head = (head + 1) % size;

        // O  O O
        // |      h
        // h 
        if (head == tail) { // all of the spaces have been free up
            head = INT_MAX;
            tail = INT_MAX;
        }

        return true;
    }

    int Front() {
        //1. if uninitiaze empty
        if (isEmpty())
            return -1;

        return arr[head];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        int size = arr.size();
        return arr[(tail - 1 + size) % size];
    }

    bool isEmpty() {
        return head == INT_MAX;
    }

    bool isFull() {
        return head != INT_MAX && head == tail;
    }
};