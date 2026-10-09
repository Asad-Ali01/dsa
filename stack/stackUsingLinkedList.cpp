#include<iostream>
struct Node{
    int data;

    Node* next;
    Node(int value){
    
        next = nullptr;
        data = value;
    }
};
class stackLinkedList{
    private:
    Node *top;
    int count = 0;
    public:
    stackLinkedList(){
        top = nullptr;
    }
    void push(int value){
        Node* newNode = new Node(value);
       newNode -> next = top;

       top = newNode;
    std::cout<<top -> data<<" pushed into stacked \n";
    count++;
    }

    void pop(){
        if(top == nullptr){
            std::cout<<"Stack is empty \n";
        }
        Node* temp = top;
        
        delete temp;
        count--;
    }
    void print(){
        std::cout<<"Printing function \n";
        Node* temp = top;
        while( temp != nullptr){
            std::cout<< temp -> data <<" ";
            temp = temp -> next;
        }
        std::cout<<std::endl;
    }
    void peek(){
    if (top == nullptr) {
        std::cout << "Stack is empty, nothing to peek." << std::endl;
        return;
    }
        std::cout<<"Here is peek: "<<top -> data<<std::endl;
    }
    void size(){
      
        std::cout<<"Here is size: "<<count<<std::endl;
    }
};

int main(){
    stackLinkedList s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.peek();
    s.size();
    s.pop();
    s.print();
}