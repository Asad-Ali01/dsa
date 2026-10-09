#include<iostream>
using namespace std;
#define MAX 5
class Stack{
    private:
    int top;
    int arr[MAX];

    public:
    Stack(){
        top = -1;
    }

   void push(int x){
    if(top >= (MAX - 1)){
        cout<<"Stack overflow!"<<endl;
        return;
    }
    arr[++top] = x;
    cout<<x<<" pushed into stack \n";
    cout<<"Updated stack is: ";
    print();
   }

   void pop(){
     if(top < 0){
        cout<<"Stack is empty \n";
        return;
    }
    int x = arr[top--];
    cout<<x<<" is removed from stack \n";
     cout<<"Updated stack is: ";
    print();
   }
   void print(){
    if(top < 0){
        cout<<"Stack is empty \n";
        return;
    }
    for(int i = top; i >= 0; i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   }
    bool isEmpty(){
       return (top < 0);
    }
};

class DynamicStack{
    private:
    int capacity;
    int top;
    int *arr;

    void resize(){
        int  newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        for(int i = 0; i <= top; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;

        cout<<"\n Stack resized successfully. New capacity: "<<capacity<<"\n\n";
    }

    public:
    DynamicStack(int initialCapacity = 2){
        capacity = initialCapacity;
        arr = new int[capacity];
        top = -1;
    }
    ~DynamicStack(){
        delete[] arr;
    }

    void push(int value){
        if(top == capacity - 1){
            resize();
        }
        arr[++top] = value;
        cout<<value<< " pushed into stack.\n";
        print();
    }

    void print(){
        if(top < 0){
            cout<<"Stack underflow"<<endl;
            return;
        }
        for(int i = top; i >= 0;i--){
            cout<<arr[i]<<endl;
        }
        cout<<endl;
    }
    void pop(){
         if(top < 0){
            cout<<"Stack underflow"<<endl;
            return;
        }
        int removedElement = arr[top--];
        cout<<removedElement<<" popped from stack \n";
     
        print();

    }

    void peek(){
         if(top < 0){
            cout<<"Stack underflow"<<endl;
            return;
        }
        cout<<"Here is peek: "<<arr[top]<<endl;
    }
    void size(){
        cout<<"Here is size: "<<top + 1;
    }
    
};


int main(){
//    Stack *s = new Stack();
//    s->push(10);
//    s->push(20);
//    s->pop();
//    delete s;

   DynamicStack d;
   d.push(10);
   d.push(20);
   d.push(30);
   d.push(40);
   d.peek();
   d.size();
   return 0;
}