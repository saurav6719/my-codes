#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
class hashing{
    vector<list<int> > hashtable;
    int buckets; // size of hash table

    public:
    hashing(int size){
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key){
        return key % buckets;
    }

    void insert(int key){
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }
    list<int>:: iterator searching(int key){
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }

    void del(int key){
        int idx = hashvalue(key);
        if(searching(key) != hashtable[idx].end()){
            hashtable[idx].erase(searching(key));
        }
        else{
            cout<<"Key is not present"<<endl;
        }
    }

};
int main(){

    return 0;
}