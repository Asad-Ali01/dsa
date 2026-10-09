#include<iostream>
using namespace std;
class Queue{
    private:
    int front;
    int rear;
    int size = 5;
    int queue[5];
    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    void push(int value){
        if((rear + 1) % size == front){
            cout<<"Queue is full"<<endl;
            return;
        }

        if(front == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % size;
        }
        queue[rear] = value;
        cout<<value<< " pushed into queue \n";
    }   

    void pop(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<queue[front]<<" popped from queue"<<endl;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
        
    }

    void peek(){
          if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<queue[front]<<" is peek"<<endl;
    }

    void print(){
          if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Print function"<<endl;
        int i = front;
        while(true){
            cout<<queue[i]<<" ";
            if(i == rear){
                break;
            }
            i = (i + 1) % size;
    
        }
        cout<<endl;
    }
    void isFull(){
        if((rear + 1) % size == front){
            cout<<"Queue is full"<<endl;
        }
    }
    void sizeOfNumberInQueue(){
        int totalElements = (rear - front + size) % size + 1;
        cout<<"Total numbers in queue :"<<totalElements<<endl;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
   q.pop();
   q.print();
   q.print();
   q.sizeOfNumberInQueue();


}