#include<iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};
class Queue{
    private:
    Node* front;
    Node* rear;
    int count = 0;
    public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    ~Queue(){
        while(front != nullptr){
            Node* temp = front;
            front = front -> next;
            delete temp;
        }
    }
    void push(const int& value){
     
        Node* newNode = new Node(value);
        if(front == nullptr)
        {
            front = newNode;
            rear = newNode;
            count++;
        }
        else
        {
            rear -> next = newNode;
            rear = rear -> next;
            count++;
        }
    }

    void pop(){
        if(front == nullptr){
            cout<<"Queue is empty"<<endl;
            return;
        }
        if(front == rear){
            delete front;
            front = nullptr;
            rear = nullptr;
            count--;
            return;
        }
        Node* temp = front;
        front = front -> next;
        delete temp;
        count--;
    }

    void print(){
        if(front == nullptr){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        while(temp != nullptr){
            cout<<temp -> data;
            if(temp -> next != nullptr){
                cout<<" -> ";
            }
            temp = temp -> next;
        }
    }
    void size(){
        cout<<"Total size is : "<<count<<endl;
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
    q.print();
}