#include<iostream>
#include<unordered_map>
using namespace std;
class HashMap{
    private:
    unordered_map<string,int> hashmap;
    public:
    void push(string key,int value){
        if(hashmap.find(key) != hashmap.end()){
            cout<<"Key already exists"<<endl;
            return;
        }
        hashmap[key] = value;
        cout<<"Successfully value "<< value<< " inserted in key: "<<key<<endl;
    }
    int ValueByKey(string key){
        if(hashmap.find(key) == hashmap.end()){
            cout<<"Key not found"<<endl;
            return -1;
        }
        return hashmap[key];
    }

    bool searchByKey(string key){
        if(hashmap.find(key) == hashmap.end()){
            cout<<key<< " not found"<<endl;
            return false;
        }
        return true;
    }

    void traversal(){
        if(hashmap.empty()){
            cout<<"Hashmap is empty"<<endl;
            return;
        }
        for(const auto& [key,value]: hashmap){
            cout<<key<<"-> "<<value<<endl;
        }
    }

    void deleteByKey(string key){
         if(hashmap.empty()){
            cout<<"Hashmap is empty"<<endl;
            return;
        }
         if(hashmap.find(key) == hashmap.end()){
            cout<<key<< " not found"<<endl;
          return;
        }
        hashmap.erase(key);
    }

    size_t size(){
            return hashmap.size();
    }
};
int main(){
   HashMap h;
   h.push("Apple",2);
   h.push("Orange",2);
//    h.deleteByKey("Apple");
if(h.searchByKey("Applae")){
    cout<<"Key found"<<endl;
}
cout<<h.size()<<endl;
   h.traversal();
}