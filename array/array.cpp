#include<iostream>
using namespace std;
class MyVector{
    private:
    int* arr;
    int size;
    int capacity;
    public:
    MyVector(){
        cout<<"Created"<<endl;
        arr = new int[1];
        size = 0;
        capacity = 1;
    }
    MyVector(const MyVector& other){

        this->size = other.size;
        this->capacity = other.capacity;
        this->arr = new int[this->capacity];

        for(int i = 0; i < this->size;i++){
            this->arr[i] = other.arr[i];
        }
    }
    MyVector& operator=(const MyVector& other){
        cout<<"Other is: "<<&other<<endl;
        cout<<"This is: "<<this<<endl;
        if(this == &other) return *this;
        delete[] arr;
        
        this->size = other.size;
        this->capacity = other.capacity;
        this->arr = new int[capacity];

        for(int i = 0; i < size;i++){
            this->arr[i] = other.arr[i];
        }
        return *this;
    }
    ~MyVector(){
        delete[] arr;
    }
    //push back

    void push_back(int value){
        if(size == capacity){
            capacity *= 2;
            int* newArr = new int[capacity];
            cout<<"Called"<<endl;
            //copy old elements
            for(int i = 0; i < size; i++){
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;

        }
        arr[size] = value;
        size++;
    }

    //update by index
    void updateByIndex(int index,int value){
        //handling edge case
        if(index >= size || index < 0){
            cout<<"Invalid index"<<endl;
            return;
        }

        //update value
        arr[index] = value;
    }

    //updateByValue
    void updateByValue(int oldValue,int newValue){
        bool found = false;
        for(int i = 0; i < size; i++){
            if(arr[i] == oldValue){
                arr[i] = newValue;
                found = true;
                cout<<"Updated value successfully"<<endl;
                break;
            }
        }
        if(!found){
            cout<<"Value not found to update"<<endl;
        }
    }

    //pop
    void pop(){
        if(size == 0){
            cout<<"Array is empty"<<endl;
            return;
        }

        size--;
    }

    //deleteBy index
    void deleteByIndex(int index){
        if(index >= size || index < 0){
            cout<<"Invalid index"<<endl;
            return;
        }

        //finding that index
        for(int i = index; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }

    //deleteByValue
    void deleteByValue(int value){
        if(size == 0 ){
            cout<<"Array is empty"<<endl;
            return;
        }
        //finding that value
        for(int i = 0; i < size; i++){
            if(arr[i] == value){
                for(int j = i; j < size - 1; j++){
                    arr[j] = arr[j+1];
                }
                size--;
                break;
            }
        }
    }
    //display
    void display(){
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deleteMem(){
        cout<<"Delete Mem is called"<<endl;
        delete[] arr;
    }
};

int main(){
    MyVector v1,v2;
    
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.display();


}