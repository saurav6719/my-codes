/**
 *    author: Saurav
 *    created: 2025.01.06 18:02:53
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
int query(int i, int j){
    cout<<"? "<<i<<" "<<j<<endl;
    cout<<flush;
    int x;
    cin>>x;
    return x;
}
void printl(int x, int y){
    cout<<"! "<<x<<" "<<y<<endl;
    cout<<flush;

}
void solve(){
    int n;
    cin>>n;

    set<int> st;
    for(int i = 1; i<=n; i++){
        st.insert(i);
    }

    while(st.size() > 2){
        auto temp = st.begin();
        int one = *temp;
        temp++;

        int two = *temp;

        temp++;
        int three = *temp;


        int query1 = query(one, three);
        int query2 = query(two, three);

        if(query1 == query2){
            st.erase(three);
        }
        else if(query1 < query2){
            st.erase(one);
        }
        else{
            st.erase(two);
        }
    }

    auto temp = st.begin();
    int x = *temp;
    temp++;
    int y = *temp;

    printl(x, y);

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

