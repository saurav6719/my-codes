#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(int a, int b) {
    return a > b; // Compare in descending order
}
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    int sum = 0;
    for(int i = 0; i<n ; i++){
        int a;
        cin>>a;
        input[i] =a;
        sum+= a;
    }
    sort(input.begin(), input.end(), compare );
    int req = 0;
    int ans = 0;
    for(int i = 0; i< n ; i++){
        req += input[i];
        if(req > (sum/2)) {
            ans = i+1;
            break;
        }
    }
    cout<<ans;

    return 0;
}