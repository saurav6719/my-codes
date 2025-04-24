/**
 *    author: Saurav
 *    created: 2024.10.27 19:50:09
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

    vector<int> ans(n);


    if(n==5){
        cout<<5<<endl;
        vector<int> ans2 = {2, 1, 3, 4, 5};

        for(auto ele : ans2){
            cout<<ele<<" ";
        } 
        cout<<endl;
        return;

    }
    if(n==6){
        cout<<7<<endl;
        vector<int> ans2 = {1,2,4,6,5,3};

        for(auto ele : ans2){
            cout<<ele<<" ";
        } 
        cout<<endl;
        return;

    }
    if(n==7){

        cout<<7<<endl;
        vector<int> ans2 = {2,4,5,1,3,6,7};

        for(auto ele : ans2){
            cout<<ele<<" ";
        } 
        cout<<endl;
        return;


    }
    if(n==8){
        cout<<15<<endl;
        vector<int> ans2 = {2,4,5,1,3,6,7, 8};

        for(auto ele : ans2){
            cout<<ele<<" ";
        } 
        cout<<endl;
        return;

    }

    if(n==9){
        cout<<9<<endl;
        vector<int> ans2 = {2,4,5,6,7,1,3,8,9};

        for(auto ele : ans2){
            cout<<ele<<" ";
        } 
        cout<<endl;
        return;

    }
    if(n & 1){
        ans[n-1] = n;
        ans[n-2] = n-1;
        ans[n-3] = 1;
        ans[n-4] = 3;

        set<int> st;
        for(int i = 1; i<=n; i++){
            st.insert(i);
        }


        st.erase(n);
        st.erase(n-1);
        
        st.erase(1);
        st.erase(3);

        for(int i = 0; i<n-4; i++){
            ans[i] = *st.begin();
            st.erase(st.begin());
        }

    }
    else{
        int logtwo = log2(n);

        int lastpower = pow(2, logtwo);
        ans[n-1] = lastpower;
        ans[n-2] = lastpower-1;
        ans[n-3] = lastpower-2;
        ans[n-4] = 1;
        ans[n-5] = 3;

        set<int> st;
        for(int i = 1; i<=n; i++){
            st.insert(i);
        }

        st.erase(lastpower);
        st.erase(lastpower-1);
        st.erase(lastpower - 2);
        st.erase(1);
        st.erase(3);

        for(int i = 0; i<n-5; i++){
            ans[i] = *st.begin();
            st.erase(st.begin());
        }
    }

    int res = 0;


    for(int i= 1; i<=n; i++){
        if(i & 1){
            res = res & ans[i-1];
        }
        else res = res | ans[i-1];
    }

    cout<<res<<endl;

    for(auto ele : ans){
        cout<<ele<<" ";
    }

    cout<<endl;

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

