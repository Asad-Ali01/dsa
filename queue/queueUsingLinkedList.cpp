#include<iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};
class Queue{
    private:
    Node* front;
    Node* rear;
  public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    void push(int value){
        
        Node* newNode = new Node(value);
        if(front == nullptr){
            front = rear = newNode;
          return;
        }
        
            rear -> next = newNode;
            rear = rear -> next;
       
    }

    void pop(){
        if(front == nullptr){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* deleteNode = front;
        if(front == rear){
          front = rear = nullptr;
        }
        else{
            front = front -> next;
        }
        delete deleteNode;
    }
    void isEmpty(){
        if(front == nullptr){
            cout<<"Queue is empty"<<endl;
        }else{
            cout<<"Queue is not empty"<<endl;
        }
    }
    void size(){
        int count = 0;
        Node* temp = front;
        while(temp != nullptr){
            count++;
            temp = temp -> next;
        }
        cout<<"Size is: "<<count<<endl;
    }
    void peek(){
         if(front == nullptr){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<front -> data <<" is peek"<<endl;
    }
    void print(){
         if(front == nullptr){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        do
        {
           cout<<temp -> data<<" ";
           temp = temp -> next;
        } while (temp != nullptr);
        cout<<endl;
    }
};
int main(){
Queue q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.size();
q.print();
}