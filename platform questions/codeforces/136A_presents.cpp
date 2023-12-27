#include<iostream>
#include<vector>

using namespace std;
int main(){
    

    int n;
    cin>>n;
    vector<int> input(n+1);
    vector<int> output(n+1);
    for(int  i = 1; i<= n ; i++){
        int a;
        cin>>a;
        input[i] = a;
        output[input[i]] = i;
    }
    for(int i = 1; i<=n ; i++){
        cout<<output[i]<<" ";
    }
    return 0;
}