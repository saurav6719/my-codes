#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string, int> m;
    //insertion method 1
    pair<string , int> p;
    p.first = "saurav";
    p.second = 88;
    m.insert(p);

    //insertion method 2 ;
    m["harsh"] = 89;
    m["vivek"] = 90;

    // display without auto 
    for(pair<string,int> p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    

    // display with auto 
    for(auto p  : m){
        cout<<p.first<<" "<<p.second<<endl;
    }

    //erase 
    m.erase("saurav");

    // size

    cout<<m.size()<<endl;

    //find

    if(m.find("saurav")!= m.end()){
        cout<<"exists"<<endl;
    }
    else{
        cout<<"DNE"<<endl;
    }

    return 0;
}