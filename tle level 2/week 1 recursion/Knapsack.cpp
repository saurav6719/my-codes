#include<iostream>
#include<vector>
using namespace std;
vector<int> result;
void rec(vector<pair<int,int> > &input,int n, int w , int i, int current , int value){
 
    // base case
    if(i>=n){
        result.push_back(value);
        return;
    }
 
    if(((current + input[i].first) > w)){
        rec(input,n,w,i+1,current, value); // not included
    }
    else{
        rec(input,n,w,i+1,current, value); // not included
        rec(input,n,w,i+1,current+input[i].first, value+input[i].second); // included
    }
 
}
int main(){
    
    int n;
    cin>>n;
    vector<pair<int,int> > input(n);
    int w;
    cin>>w;
    for (int i = 0; i < n; i++) {
        cin >> input[i].first;
        cin >> input[i].second;
    }
 
    rec(input,n,w,0,0,0);
    int ans = result[0];
    for(int i = 1; i<result.size(); i++){
        ans = max(ans,result[i]);
    }
 
    cout<<ans;
 
    return 0;
}