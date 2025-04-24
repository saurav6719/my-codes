/**
 *    author: Saurav
 *    created: 2024.11.02 20:03:53
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
    string str;
    cin>>str;

    set<int> st;
    for(int i = 0; i+3<str.size(); i++){
        string s = "";
        s+= str[i];
        s += str[i+1];
        s += str[i+2];
        s += str[i+3];
        if(s == "1100") st.insert(i);
    }

    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        int val;
        cin>>val;
        --x;
        str[x] = val + '0';
        if(x-3 >= 0){
            string s = "";
            s+= str[x-3];
            s += str[x-2];
            s += str[x-1];
            s += str[x];
            if(s == "1100") st.insert(x-3);
            else st.erase(x-3);
        }
        if(x-2 >=0 and x+1 < str.size()){
            string s = "";
            s+= str[x-2];
            s += str[x-1];
            s += str[x];
            s += str[x+1];
            if(s == "1100") st.insert(x-2);
            else st.erase(x-2);
        }
        if(x-1 >=0 and x+2 < str.size()){
            string s = "";
            s+= str[x-1];
            s += str[x];
            s += str[x+1];
            s += str[x+2];
            if(s == "1100") st.insert(x-1);
            else st.erase(x-1);
        }
        if(x+3 < str.size()){
            string s = "";
            s+= str[x];
            s += str[x+1];
            s += str[x+2];
            s += str[x+3];
            if(s == "1100") st.insert(x);
            else st.erase(x);
        }
        if(st.empty()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
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

