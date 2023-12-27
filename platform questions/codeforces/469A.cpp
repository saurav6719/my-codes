// i wanna be the guy
#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main(){
    int n;
    cin>>n;
    int p;
    cin>>p;
    bool flag =  true;
    vector<int> pinput;
    for(int i = 0; i<p; i++){
        int a;
        cin>>a;
        pinput.push_back(a);
    }
    int q;
    cin>>q;
    vector<int> qinput;
    for(int i = 0; i<q; i++){
        int a;
        cin>>a;
        qinput.push_back(a);
    }
    vector<int> ans(n+5,-1);
    for(int i = 0; i< p ; i++){
        ans[pinput[i]] = 1;
    }
    for(int i = 0; i< q ; i++){
        ans[qinput[i]] = 1;
    }
    for(int i = 1; i<= n ; i++){
        if(ans[i] == -1) {
            flag = false;
            cout<<"Oh, my keyboard!";
            break;
        }
    }
    if(flag) cout<<"I become the guy.";



    return 0;

}
