#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        this->data = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList{
    private:
    Node* head;
    public:
    DoublyLinkedList(){
        this->head = nullptr;
    }
    ~DoublyLinkedList(){
        while(head){
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
    }

    void insertAtHead(int value){
            Node* newNode = new Node(value);
            newNode -> next = head;
            if(head != nullptr){
                head -> prev = newNode;
            }
            head = newNode;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        newNode -> prev = temp;
        temp -> next = newNode;
    }


    void insertAtMiddle(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        Node* newNode = new Node(value);
        Node* nextNode = slow -> next;
        newNode -> prev = slow;
        newNode -> next = nextNode;
        slow -> next = newNode;
        if(nextNode != nullptr){
            nextNode -> prev = newNode;
        }
    }

    void insertAtPosition(int pos,int value){
        if(pos == 0){
            insertAtHead(value);
            return;
        }
        Node* temp = head;
        for(int i = 1; i < pos  && temp != nullptr; i++){
            temp = temp -> next;
        }
        if(temp == nullptr) return;
        Node* newNode = new Node(value);
        Node* nextNode = temp -> next;
        newNode -> prev = temp;
        newNode -> next = nextNode;
        temp -> next = newNode;
        if(nextNode != nullptr){
            nextNode -> prev = newNode;
        }
    }

    void updateByPosition(int pos,int value){
        if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        Node* temp = head;
        for(int i = 1; i < pos && temp != nullptr; i++){
            temp = temp -> next;
        }
        if(temp == nullptr) return;
        temp -> data = value;
    }

    void updateByValue(int oldVal,int newVal){
        if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != nullptr){
            if(temp -> data == oldVal){
                temp -> data = newVal;
                return;
            }
            temp = temp -> next;
        }
    }


    void deleteByPosition(int pos){
         if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        if(pos == 1){
            Node* temp = head;
            head = head -> next;
            if(head != nullptr){
                head -> prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        for(int i = 1; i < pos && temp != nullptr; i++){
            temp = temp -> next;
        }
        if(temp == nullptr) return;
        temp -> prev -> next = temp  -> next;
        if(temp -> next != nullptr){

            temp -> next -> prev = temp -> prev;
        }
        delete temp;
    }

    void deleteByValue(int value){
        if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        if(head -> data == value){
            Node* temp = head;
            head = head -> next;
            if(head != nullptr){
                head -> prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp != nullptr){
            if(temp -> data == value){
                temp -> prev -> next = temp -> next;
              if(temp -> next != nullptr){
                temp -> next -> prev = temp -> prev;
              }
                delete temp;
                return;
            }
            temp = temp -> next;
        }
    }
    void printNode(){
        if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data;
            if(temp -> next != nullptr){
                cout<<"->";
            }
            temp = temp -> next;
        }
        cout<<endl;
    }

    void reversePrintNode(){
        if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        while(temp != nullptr){
            cout<<temp -> data;
            if(temp -> prev != nullptr){
                cout<<"-> ";
            }
            temp = temp -> prev;
        }
        cout<<endl;
    }
};
int main(){
    DoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtHead(30);
    list.insertAtMiddle(70);
    list.insertAtMiddle(80);
    list.insertAtPosition(2,100);
    // list.deleteByPosition(1);
    // list.updateByPosition(2,200);
    // list.deleteByPosition(2);
    // list.updateByValue(100,1);
    list.deleteByValue(30);
    list.printNode();
    list.reversePrintNode();
    
}