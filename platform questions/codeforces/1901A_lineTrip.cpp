#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        vector<int> input(n);
        for(int i = 0; i< n ; i++){
            int a;
            cin>>a;
            input[i] = a;
        }
        int ans = INT_MIN;
        int first = input[0];
        int last = 2 * (x - input[n-1]);
        for(int i = 0; i<n-1; i++){
            ans = max(ans, (input[i+1] - input[i]));
        }
        ans = max(ans, max(first,last));
        cout<<ans<<endl;//2 5 1 4
        }
    return 0;
}