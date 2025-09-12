#include <iostream>
using namespace std ;

class Node{
    public:
        int data ;
        Node* next ;
        Node(int val){
        data = val;
        next = NULL;
    }
};
class LinkedList{
    public:
        Node* head ;
        Node* tail ;
        LinkedList(){
            head = NULL;
            tail = NULL;
        }
        void addAtStart(int val){
            Node* node = new Node(val);
            if(head == NULL){
                head = node;
                tail = node;
                return;
            }
            (*node).next = head ; 
            head = node;
            return ;
        }
        void printList(){
            Node* node = head ;
            if(head == NULL){
                cout<<"List is empty" ;
                return;
            }
            while(node != NULL){
                cout<<node->data<<"-->" ;
                node = node->next ;
            }
            
        }
};

int main(){
    LinkedList ll ;
    ll.addAtStart(5);
    ll.addAtStart(6);
    ll.addAtStart(7);
    ll.addAtStart(9);
    ll.printList();
    return 0 ;
}