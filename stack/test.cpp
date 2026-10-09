#include<iostream>
using namespace std;
template<typename T>
class Stack{
    private:
    int top;
    int capacity;
    T *arr;

    public: Stack(int capacity){
        this-> capacity = capacity;
        arr = new T[capacity];
        top = -1;
    }
    ~Stack(){
        delete []arr;
    }
    void resize(){
        int newCapacity = capacity * 2;
        T *newArr = new T[newCapacity];
        for(int i = 0; i < size(); i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    
        capacity = newCapacity;
    }

    void push(const T& value){
        if( top == capacity - 1){
            resize();
        }
        value = 20;
        arr[++top] = value;
    }

    void pop(){
        if(top < 0){
            cout<<"Stack underflow"<<endl;
            return;
        }
        top--;
    }
    void peek(){
          if(top < 0){
            cout<<"Stack underflow"<<endl;
            return;
        }
        cout<<arr[top] << " is peek"<<endl;
    }
    int size(){
        return top + 1;
    }
    void print(){
          if(top < 0){
            cout<<"Stack underflow"<<endl;
            return;
        }
        for(int i = top; i >= 0; i-- ){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Stack<int> s(1);
    s.push(10);
    s.push(20);
    s.push(20);
    s.push(20);
    s.push(20);
    s.push(20);
    s.print();
    s.~Stack();
    
}