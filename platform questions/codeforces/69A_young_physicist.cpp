#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> helper(3,0);
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        helper[0] += a;
        helper[1] += b;
        helper[2] += c;
    }
    if(helper[0] == 0 and helper[1] == 0 and helper[2] == 0) cout<<"YES";
    else cout<<"NO";
    return 0;
}