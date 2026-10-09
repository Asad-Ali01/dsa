#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        this->head = nullptr;
    }
    ~CircularLinkedList()
    {
        if (head == nullptr)
        {
            return;
        }
        head -> prev -> next = nullptr;
        Node* current = head;
        while(current != nullptr){
            Node* temp = current;
            current = current -> next;
            delete temp;
        }
        head = nullptr;
    }

    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }
        Node *tail = head -> prev;

        newNode -> next = head;
        newNode -> prev = tail;

        tail -> next = newNode;
        head -> prev = newNode;

        head = newNode;
        
    }

    void insertAtEnd(int value){
        if(head == nullptr){
            insertAtHead(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* tail = head -> prev;
        head -> prev = newNode;
        tail -> next = newNode;

        newNode -> prev = tail; 
        newNode -> next = head;
    }

    void insertAtMiddle(int value){
        if(head == nullptr){
            insertAtHead(value);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        Node* tail = head -> prev;
        while(fast != tail && fast -> next != tail){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        Node* newNode = new Node(value);
        Node* nextNode = slow -> next;
        slow -> next = newNode;
        newNode -> prev = slow;  
        newNode -> next = nextNode;
        nextNode -> prev = newNode;  
    }

    void insertAtPosition(int pos,int value){
        if (pos < 1) return;
    if(pos == 1){
        insertAtHead(value);
        return;
    }
    
    Node* temp = head;
    int count = 1;
    while( temp -> next != head){
        temp = temp -> next;
        count++;
    }

    if(pos > count + 1){
        cout<<"Position not found"<<endl;
        return;
    }
    if(pos == count + 1){
        insertAtEnd(value);
        return;
    }
    temp = head;
    for(int i = 1; i < pos - 1; i++){
        temp = temp -> next;
    }
    Node* newNode = new Node(value);
    Node* nextNode = temp -> next;
    newNode -> prev = temp;
    newNode -> next = nextNode;
    temp -> next = newNode;
    nextNode -> prev = newNode;
    }

    void updateByPos(int pos,int value){
        if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        if(pos == 1){
            head -> data = value;
            return;
        }
        Node* temp = head;
        int i = 1;
        do
        {
            temp = temp -> next;

            i++;
        } while (temp != head && i < pos);
        
        if(temp == head){
            cout<<"Position not found"<<endl;
            return;
        }
        temp -> data = value;
    }

    void updateByValue(int oldVal,int newVal){
          if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        Node* temp = head;
        do
        {
            if(temp -> data == oldVal){
                temp -> data = newVal;
            }
            temp = temp -> next;
        } while (temp != head);
        
    }


    void deleteByPos(int pos){
          if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
    if(pos < 1){
        cout<<"Position not found"<<endl;
        return;
    }

        if(pos == 1){
            Node* temp = head;
            if(head -> next != head){
                Node* tail = head -> prev;
                head = head -> next;
                tail -> next = head;
                head -> prev = tail;
                delete temp;
                return;
            }
            delete temp;
            head = nullptr;
            return;
        }
        Node* temp = head;
       int i = 1;
       do
       {
        temp = temp -> next;
        i++;
       } while (temp != head && i < pos);
       if(temp == head){
        cout<<"Position not found"<<endl;
        return;
       }
       Node* deleteNode = temp;
       deleteNode -> prev -> next = deleteNode -> next;
       deleteNode -> next -> prev = deleteNode -> prev;
       delete deleteNode;
    }

    void printNode()
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        cout<<"------------- Linked list Print----------------"<<endl;
        Node* temp = head;
        do
        {
            cout<<temp -> data;
            if(temp->next != head) cout << " -> ";
            temp = temp -> next;
        } while (temp != head);
        cout<<endl;
    }

    void printReverseNode()
    {
         if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        cout<<"-------------Reverse Linked list Print----------------"<<endl;

      Node* tail = head -> prev;
      Node* temp = tail;
      do
      {
        cout<<temp -> data;
        if(temp != head) cout<<" -> ";
        temp = temp -> prev;
      } while (temp != tail);
      cout<<endl;
    }

    void printLastNode(){
         if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        cout<<"-------------Here is Last Node----------------"<<endl;
        cout<<head -> prev -> data<<endl;
    }

};
int main()
{
    CircularLinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtEnd(30);
    // list.insertAtMiddle(70);
    // list.insertAtPosition(2,100);
    list.updateByPos(7,200);
    list.printNode();
    // list.deleteByPos(41);
    // list.updateByValue(30,1);
    // list.deleteByPos(1);
    // list.updateByValue(30,2);
    list.printReverseNode();
    list.printLastNode();
    return 0;
}