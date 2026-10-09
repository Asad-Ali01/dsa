#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Stack{
    private:
    Node* top;
    public:
    Stack(){
        top = nullptr;
    }
    ~Stack(){
        while(top != nullptr){
            Node* temp = top;
            top = top -> next;
            delete temp;
        }
    }
    void push(int value){
       Node *newNode = new Node(value);
       newNode -> next = top;
       top = newNode;
       cout<<value<<" is inserted in stack"<<endl;

    }

    void pop(){
        if(top == nullptr){
            cout<<"Stack underflow"<<endl;
            return;
        }
       Node* temp = top;
       cout<<temp -> data << " popped from stack"<<endl;
       top = top -> next;
       delete temp;
    }

    void peek(){
           if(top == nullptr){
            cout<<"Stack underflow"<<endl;
            return;
        }

        cout<<top -> data << " is peek"<<endl;
    }

    void print(){
         if(top == nullptr){
            cout<<"Stack underflow"<<endl;
            return;
        }
        Node* temp = top;
        while(temp != nullptr){
            cout<<temp -> data;
            if(temp -> next != nullptr){
                cout<<" -> ";
            }
            temp = temp -> next;
        }
    }
};

int main(){
    Stack s;
    s.push(20);
    s.push(10);
    s.print();
    return 0;
}