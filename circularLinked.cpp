#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;
public:
    CircularList() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* node = new Node(val);
        if (head == NULL) {
            head = tail = node;
            node->next = head;
        } else {
            tail->next = node;
            tail = node;
            tail->next = head;
        }
    }

    void push_front(int val) {
        Node* node = new Node(val);
        if (head == NULL) {
            head = tail = node;
            node->next = head;
        } else {
            node->next = head;
            head = node;
            tail->next = head;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    CircularList cl;
    cl.push_back(10);
    cl.push_back(20);
    cl.push_back(30);
    cl.push_front(5);

    cout << "Circular List: ";
    cl.display();

    cl.pop_front();
    cout << "After pop_front: ";
    cl.display();

    cl.pop_back();
    cout << "After pop_back: ";
    cl.display();

    return 0;
}
