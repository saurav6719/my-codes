#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> correct(n);
    for(int i = 0; i<n; i++){
        cin>>correct[i];
    }
    vector<int> wrong(m);
    for(int i = 0; i<m; i++){
        cin>>wrong[i];
    }
    int ans;
    sort(correct.begin(), correct.end());
    sort(wrong.begin(), wrong.end());
    int wrongMin = wrong[0];
    int correctMax = correct[n-1];
    int correctMin = correct[0];
    correctMin *= 2;
    int result = max(correctMin , correctMax);
    if(correctMax >= wrongMin) ans = -1;

    else if(correctMin >= wrongMin) ans = -1;
    else ans = result;

    cout<<ans;
   
    return 0;
}
