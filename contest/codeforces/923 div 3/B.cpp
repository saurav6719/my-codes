#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i =0; i<n; i++){
        cin>>input[i];
    }
    int count = 0;
    vector<char> ans(n);
    unordered_map<char,int> mp;
    unordered_set<char> st;
    for(int i = 0 ; i<n; i++){
        if(input[i] == 0){
            //cout<<",,"<<endl;
            ans[i] = (count + 'a');
            mp[count+'a']++;
            st.insert(count+'a');
            count++;
        }
        else if(input[i] == 1){
            //cout<<",,,"<<endl;
            for(auto ele : st){
                ans[i] = ele;
                mp[ele]++;
                st.erase(ele);
                break;
            }
        }
        else{
            int put = input[i];
            for(auto ele : mp){
                //cout<<",,,,"<<endl;
                if(ele.second == put){
                    debug(ele.first);
                    ans[i] = ele.first;
                    mp[ans[i]]++;
                    break;
                }
            }
        }
    }
    // for(auto ele : mp){
    //         cout<<ele.first<<" "<<ele.second<<", ";
    // }
    string answer = "";
    for(int i = 0; i<n; i++){
        answer+= ans[i];
    }
    cout<<answer<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}