#include<iostream>
using namespace std;

void printArr(int *arr,int length){
    for(int i = 0; i < length;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

void updateArr(int *arr,int length,int oldvalue,int newvalue){
    if(length == 0){
        cout<<"Array is empty"<<endl;
        return;
    }

    for(int i = 0; i < length; i++){
        if(arr[i] == oldvalue){
            arr[i] = newvalue;
            cout<<"Value updated fort index  :"<< i << " old value: "<<oldvalue <<" new value is:"<<newvalue<<endl; 
            break;
        }
    }

}
void deleteArr(int *arr,int &length,int valueToDel){
    if(length == 0){
        cout<<"Array is empty"<<endl;
        return;
    }
    for(int i = 0; i < length; i++){
        if(arr[i] == valueToDel){
            for(int j = i;  j < length - 1; j++){
                arr[j] = arr[j + 1];
            }
            length--;  // Decrease length after deletion
            break;  // Stop after deleting the first occurrence
        }
    }
}
int main(){
   cout<<"Enter number";
   int num,length;
   cout<<"Enter length of array: ";
   cin>>length;
    int *arr = new int[length];
   for(int i = 0; i < length; i++){
    cout<<"Enter "<< i + 1 << " number: ";
    cin>>num;
    arr[i] = num;
   }
   printArr(arr,length);
   updateArr(arr,length,3,6);
   printArr(arr,length);
   deleteArr(arr,length,2);
   printArr(arr,length);
   delete[] arr;  // Free memory at the end

}