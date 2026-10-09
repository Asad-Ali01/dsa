#include<iostream>
using namespace std;
int main(){
   int row = 5;
   for(int a = 1; a <= row;a++){
    for(int b = 1; b <= a;b++){
        cout<<"*";
    }
    for(int c = 1;c <= row - a;c++){
        cout<<" ";
        cout<<" ";
    }
    
   for(int d = 1;d <= a; d++){
        cout<<"*";
    }
    cout<<endl;
   }

   for(int a = 1; a < row ;a++){
    for(int b = row; b > a; b-- ){
        cout<<"*";
    }
    for(int c = 1; c <= a;c++){
        cout<<" ";
        cout<<" ";
        
    }
    for(int d = row; d > a;d--){
        cout<<"*";
    }
    cout<<endl;
   }
}
