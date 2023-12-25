#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int c;
    cin>>c;
    vector<int> input;
    for(int i = 0; i<n ; i++){
        int ele;
        cin>>ele;
        input.push_back(ele);
    }
    int ans = 0;
    for(int i = 1; i<n; i++){
        if(input[i] < input[i-1]){
            ans = max(ans , input[i-1] - input[i] - c);
        }
    }
    
    cout<<ans;
    return 0;
}// 6 100
/// 10 9 8 7 6 5