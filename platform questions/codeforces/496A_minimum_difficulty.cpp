#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int max_diff = 0;
    for(int i = 0; i < n-1; i++){
        max_diff = max(max_diff, input[i+1] - input[i]);
    }
    int i = 0;
    int j = 2;
    int ans = INT_MAX;
    bool flag = true;
    while(j<n){
        ans = min(ans, input[j] - input[i]);
        if(ans < max_diff){
            ans = max_diff;
            break;
        }
        i++;
        j++;
    }

    cout<<ans;
    return 0;

}