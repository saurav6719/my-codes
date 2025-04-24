/**
 *    author: Saurav
 *    created: 2024.11.30 21:48:35
 **/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<pp> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i].first;
        input[i].second = i;
    }

    set<int> onepos;
    set<int> zeropos;

    set<int> twopos;
    for(int i=0;i<n;i++){
        if(input[i].first==1){
            onepos.insert(i);
        }else if(input[i].first==0){
            zeropos.insert(i);
        }else{
            twopos.insert(i);
        }
    }

    int onecnt = 0;
    int zerocnt = 0;
    int twocnt = 0;

    for(int i=0;i<n;i++){
        if(input[i].first==1){
            onecnt++;
        }else if(input[i].first==0){
            zerocnt++;
        }else{
            twocnt++;
        }
    }

    vector<pp> sorted = input;
    sort(sorted.begin(),sorted.end());
    vector<pp> ans;


    for(int i = n-1; i>=0; i--){
        int required = sorted[i].first;
        int actual = input[i].first;
        if(required == 2 and actual == 1){
            int temp1 = i+1;
            int temp2 = *twopos.begin()+1;
            ans.push_back({temp1,temp2});
            twopos.erase(twopos.begin());
            twopos.insert(i);
            onepos.erase(i);
            onepos.insert(temp2-1);
            swap(input[i],input[temp2-1]);
        }
        if(required == 1 and actual == 0){
            int temp1 = i+1;
            int temp2 = *onepos.begin()+1;
            ans.push_back({temp1,temp2});
            onepos.erase(onepos.begin());
            onepos.insert(i);
            zeropos.erase(i);
            zeropos.insert(temp2-1);
            swap(input[i],input[temp2-1]);
        }
        if(required == 2 and actual == 0){
            int temp1 = i+1;
            int temp2 = *onepos.begin()+1;
            ans.push_back({temp1,temp2});
            onepos.erase(onepos.begin());
            onepos.insert(i);
            zeropos.erase(i);
            zeropos.insert(temp2-1);
            swap(input[i],input[temp2-1]);

            temp1 = i+1;
            temp2 = *twopos.begin()+1;
            ans.push_back({temp1,temp2});
            twopos.erase(twopos.begin());
            twopos.insert(i);
            onepos.erase(i);
            onepos.insert(temp2-1);
            swap(input[i],input[temp2-1]);
        }
    }

    cout<<ans.size()<<endl;

    for(auto x : ans){
        cout<<x.first<<" "<<x.second<<endl;
    }

}
/* logic ends */

signed main(){
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

