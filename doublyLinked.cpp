#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;
public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* node = new Node(val);
        if (head == NULL) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void push_back(int val) {
        Node* node = new Node(val);
        if (tail == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void pushAtIndex(int i, int val) {
        if (i == 0) {
            push_front(val);
            return;
        }
        Node* temp = head;
        while (--i && temp != NULL) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid Index\n";
            return;
        }
        Node* node = new Node(val);
        node->next = temp->next;
        node->prev = temp;
        if (temp->next != NULL) temp->next->prev = node;
        else tail = node; 
        temp->next = node;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }

    void pop_back() {
        if (tail == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) tail->next = NULL;
        else head = NULL;
        delete temp;
    }

    void popAtIndex(int i) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (i == 0) {
            pop_front();
            return;
        }
        Node* temp = head;
        while (i-- && temp != NULL) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid Index\n";
            return;
        }
        if (temp->next != NULL) temp->next->prev = temp->prev;
        else tail = temp->prev;
        if (temp->prev != NULL) temp->prev->next = temp->next;
        delete temp;
    }

    void display_forward() {
        Node* temp = head;
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void display_backward() {
        Node* temp = tail;
        if (tail == NULL) {
            cout << "List is empty\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyList dl;
    dl.push_front(10);
    dl.push_front(20);
    dl.push_back(30);
    dl.pushAtIndex(1, 15);

    cout << "Forward: ";
    dl.display_forward();

    cout << "Backward: ";
    dl.display_backward();

    dl.pop_front();
    cout << "After pop_front: ";
    dl.display_forward();

    dl.pop_back();
    cout << "After pop_back: ";
    dl.display_forward();

    dl.popAtIndex(1);
    cout << "After popAtIndex(1): ";
    dl.display_forward();

    return 0;
}
