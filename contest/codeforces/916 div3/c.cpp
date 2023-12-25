#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
  int t;
  cin>>t;

    for(int i= 0;i<t;i++){

    
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> first(n);
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            first[i] = a;
        }
        vector<int> second(n);
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            second[i] = a;
        }

        int mx =second[0];
        int count = 0;
        int ans = first[0];
        for(int i = 0; i<n;i++){
            if(i==k)  break;
            if(i>0) first[i] += first[i-1];
            ans = first[i];
            if(second[i] > mx) mx = second[i];
            // remaining quest = k-i-1
            int remain = k-i-1;
            if(remain > 0){
             ans += (remain * mx);  
            }
            count = max(count, ans);
        }
        cout<<count<<endl;

    }
    
    return 0;
}