#include<iostream>
using namespace std;

class Queue{
    private:
    int queue[5];
    int front;
    int rear;
    int size = 5;
    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    void push(int value){
       if((rear + 1) % size == front){
        cout<<"Queue overflow"<<endl;
        return;
       }

       if(front == -1){
        front = 0;
        rear = 0;
       }else{
        rear = (rear + 1) % size;
       }

       queue[rear] = value;
       cout<< value << "pushed into queue"<<endl;

       
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
       }else{
        front = (front + 1) % size;
       }

    }

    void print(){
        cout<<"Print function"<<endl;
         if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
         }

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

    void peek(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Here is peek: "<<queue[front]<<endl;
    }
};


int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.pop();
    q.pop();
    // q.peek();
    q.print();
}


// 10 20 30 40 50   front = 0 rear = 4  queue full
// pop 2 time 10 20  30 40 50 front = 3 rear = 4
// 4 % 2  rear % front + 1