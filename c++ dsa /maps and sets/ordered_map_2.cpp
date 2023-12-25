#include<iostream>
#include<map>
using namespace std;
int  main(){
    map<string, int> m;
    m["saurav"] = 30;
    m["shivam"] = 10;
    m["shreya"] = 20;
    
    for(auto ele : m){
        cout<<ele.first<<' ';
    }
    cout << endl;
    for(auto ele : m){
        cout<<ele.second<<' ';
    }
    cout<<endl;

    
    return 0;

}
