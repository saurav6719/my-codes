/**
 *    author: Saurav
 *    created: 2024.10.21 23:45:25
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


void solvee(){
    int n;
    int k;
    cin>>n>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    cout<<n<<"-"<<k<<"-?";

    for(auto ele : input){
        cout<<ele<<"x";
    }
    cout<<endl;
    exit(0);
    return;

}

int f(int curr, int last , int n , int gcd){
    if(last == 0){
        return min ( n , (curr / gcd) + 1);
    }
    else{
        return (min(n, (curr / gcd) + 1)) - min(n , (last / gcd) + 1);
    }
}
void solve(){
    int n;
    int k;
    cin>>n>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }


    if(n==1){
        if(k<=input[0]){
            cout<<k-1<<endl;
            return;
        }
        else{
            cout<<k<<endl;
            return ;
        }
    }

    int gcd = input[0];
    for(int i = 1; i<n; i++){
        gcd = __gcd(input[i] , gcd);
    }

    vector<int> newv;
    int curre = 0;
    for(int i = 0; i<n; i++){
        newv.push_back(curre);
        curre+= gcd;
    }

    print(newv);

    if(k==1){
        set<int> st;
        for(auto ele : newv) st.insert(ele);
        for(int i = 0; i<=3e5; i++){
            if(st.count(i) == 0){
                cout<<i<<endl;
                return;
            }
        }
        
        
    }

    


    int curr = k- 1;
    int last = 0;

    debug(curr);

    while(true){
        int beechme = f(curr, last, n, gcd);
        debug(beechme);
        if(beechme == 0) break;

        last = curr;
        curr += beechme ;

        if(curr == last) break;
    }

    cout<<curr<<endl;

    

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
    for(int i = 1; i<=t; i++){
        
        solve();
    }
return 0;
}

