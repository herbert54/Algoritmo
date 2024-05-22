#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> deque;
    int maxSize;
public:
    MyCircularDeque(int k) {
        deque.reserve(k);
        maxSize = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        deque.insert(deque.begin(), value);
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        deque.push_back(value);
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        deque.erase(deque.begin());
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        deque.pop_back();
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deque.front();
    }

    int getRear() {
        if (isEmpty()) return -1;
        return deque.back();
    }

    bool isEmpty() {
        return deque.empty();
    }

    bool isFull() {
        return deque.size() == maxSize;
    }
};

#include <iostream>

int main() {
    MyCircularDeque* obj = new MyCircularDeque(3);
    cout << obj->insertLast(1) << endl; // return True
    cout << obj->insertLast(2) << endl; // return True
    cout << obj->insertFront(3) << endl; // return True
    cout << obj->insertFront(4) << endl; // return False, the queue is full.
    cout << obj->getRear() << endl; // return 2
    cout << obj->isFull() << endl; // return True
    cout << obj->deleteLast() << endl; // return True
    cout << obj->insertFront(4) << endl; // return True
    cout << obj->getFront() << endl; // return 4

    delete obj;

    return 0;
}