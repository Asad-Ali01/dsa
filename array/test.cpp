#include <iostream>
using namespace std;

int main() {

    while(true){

        int* arr = new int[1000000];

        cout << "Memory allocated" << endl;

        delete[] arr;
    }

    return 0;
}