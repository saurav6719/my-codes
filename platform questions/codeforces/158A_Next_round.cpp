#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int ans = 0;

    vector<int> input(n);
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        input[i] = a;
    }
    int check = input[k-1];
    for(int i = 0; i<n; i++){
        if(input[i]<check){
            break;
        }
        if(input[i] <= 0) continue;
        ans++;
    }
    cout<<ans;


    return 0;
}