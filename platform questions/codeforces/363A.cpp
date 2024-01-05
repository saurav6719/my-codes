#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<string> v;


    //for 0  -> 
    v.push_back("O-|-OOOO");
    v.push_back("O-|O-OOO");
    v.push_back("O-|OO-OO");
    v.push_back("O-|OOO-O");
    v.push_back("O-|OOOO-");
    v.push_back("-O|-OOOO");
    v.push_back("-O|O-OOO");
    v.push_back("-O|OO-OO");
    v.push_back("-O|OOO-O");
    v.push_back("-O|OOOO-");
    if(n==0) cout<<v[0];
    else {
        while(n){
        int last_digit = n%10;
        n = n/10;
        cout << v[last_digit] << endl;
    }
    }
    return 0;
}