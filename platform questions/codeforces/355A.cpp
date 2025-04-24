#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int k;
    int d;
    cin>>k;
    cin>>d;
    int n = d;
    string str = to_string(n);
    
    for(int i = 0; i<k-1; i++){
        str += '0';
    }
    if(d>0) cout<<str;
    else if(d==0 and k == 1 ) cout<<"0"; 
    else cout<<"No solution";

}