#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int s;
    int n;
    cin>>s;
    cin>>n;
    bool flag = false;
    vector<vector<int> > input(n,vector<int> (2));
    for(int i = 0; i<n; i++){
        cin>>input[i][0]>>input[i][1];
    }
    sort(input.begin(), input.end());
    for(int i = 0; i<n; i++){
        if(s<=input[i][0]){
            flag = true;
            break;
        }
        else{
            s+= input[i][1];
        }
    }
    if(flag == true) cout<<"NO";
    else cout<<"YES";
    return 0;
}