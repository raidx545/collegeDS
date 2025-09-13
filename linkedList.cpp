// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{

public :
    Node* next ;
    int data ;
    Node(int val){
        data = val ;
        next = NULL ;
    }
};
class List{
    Node* head ;
    Node* tail ;
public:
    List(){
        head = tail = NULL ;
    }
    
    void push_front(int val){
        Node* node = new Node(val);
        if(head == NULL){
            head = tail =  node ;
            return ;
        }
        else{
            node->next = head ;
            head = node ;
            return ;
        }
    }
    void push_back(int val){
        Node* node = new Node(val);
        if(tail == NULL){
            head = tail =  node ;
            return ;
        }
        else{
            tail->next = node ;
            tail = node ;
            return ;
        }
    }
    void pushAtIndex(int i , int val ){
        Node* temp = head ;
        Node* node = new Node(val);
        if(head == NULL && i > 0 ) {
            cout<<"Give a valid index"<<endl ;
            return;
        }
        else{
            while(--i){
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node ;
            return ;
        }
    }
    void print_list(){
        Node* node = head ;
        if(head == NULL){
            cout<<"List is empty " << endl ;
            return;
        }
        while(node != NULL){
            cout<<node->data<<"-->" ;
            node = node->next ;
        }
        return ;
    }
    void pop_front(){
        if(head == NULL){
            cout<<"List is already empty" << endl ;
            return ;
        }
        else{
            Node* temp= head ;
            temp = NULL ;
            head = head->next ;
            return ;
        }
    }
    void pop_back(){
        if(tail == NULL){
            cout<<"LIST IS ALREADY EMPTY " <<endl ;
            return ;
        }
        else{
            Node* temp = head ;
            while(temp->next != tail){
                temp = temp->next;
            }
            tail = temp ;
            tail->next = NULL ;
            return ;
        }
    }
    void popAtIndex(int i){
        if(head == NULL){
            cout<<"List is already empty" << endl ;
            return ;
        }
        else{
            Node* temp = head ;
            while(--i){
                temp = temp->next;
            }
            Node* todelete = temp->next ;
            temp->next = temp->next->next ;
            todelete = NULL ;
            return ;
        }
    }
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        tail = head;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool find(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    int front() {
        if (head == NULL) return -1;
        return head->data;
    }

    int back() {
        if (tail == NULL) return -1;
        return tail->data;
    }

    void clear() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = NULL;
    }
};

int main() {
    List ll;
    ll.push_front(5);
    ll.push_front(7);
    ll.push_front(9);
    ll.push_front(8);
    ll.push_back(10);
    ll.push_front(11);
    ll.push_back(45);
    ll.pushAtIndex(2, 45);
    cout << "Initial list: ";
    ll.print_list();
    cout << endl;
    cout << "Size of list: " << ll.size() << endl;
    cout << "Find 45: " << (ll.find(45) ? "Found" : "Not Found") << endl;
    cout << "Find 100: " << (ll.find(100) ? "Found" : "Not Found") << endl;
    cout << "Front element: " << ll.front() << endl;
    cout << "Back element: " << ll.back() << endl;
    ll.pop_front();
    cout << "After pop_front: ";
    ll.print_list();
    cout << endl;
    ll.pop_back();
    cout << "After pop_back: ";
    ll.print_list();
    cout << endl;
    ll.popAtIndex(2);
    cout << "After popAtIndex(2): ";
    ll.print_list();
    cout << endl;
    ll.reverse();
    cout << "After reverse: ";
    ll.print_list();
    cout << endl;
    ll.clear();
    cout << "After clear: ";
    ll.print_list();
    cout << endl;

    return 0;
}