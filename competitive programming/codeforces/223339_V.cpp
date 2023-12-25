#include<iostream>
#include<vector>
using namespace std;
bool flag = false;
void f(vector<int> &input, int n, int i, int x, int sum){
    //  base case 
    if(sum == x and i == n-1){
        flag = true;
        return;
    }
    if(i>=n-1) return;
    f(input,n,i+1,x,sum+input[i+1]);
    f(input,n,i+1,x,sum-input[i+1]);

}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> input(n);
    for(int i = 0; i<n ; i++){
        int a;
        cin>>a;
        input[i] = a;
    }

    f(input,n,0,x,input[0]);
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}