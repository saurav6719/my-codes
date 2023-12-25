#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    //insert  O(1)
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // display
    for(int x : s){
        cout<<x<<" ";
    }
    cout<<endl;
    
    // erase  O(1)
    s.erase(2);

    //size
    cout<<s.size()<<endl;

    //exists or not O(1)
    int target = 40;
    if(s.find(target) != s.end()) cout<<"exists"<<endl;
    if(s.find(target) == s.end()) cout<<"does not exists"<<endl;

    return 0;
}