#include<iostream>
#include<map>
using namespace std;
int  main(){
    map<int, int> m;
    m[2] = 30;
    m[3] = 10;
    m[1] = 20;
    
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
