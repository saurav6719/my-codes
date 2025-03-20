/**
 *    author: Saurav
 *    created: 2025.03.19 20:48:03
 *    We stop at Candidate Master in 2025
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
    vector<int> input(n);

    for(auto &x : input){
        cin>>x;
    }

    vector<int> diffarr;

    for(int i=1; i<n; i++){
        diffarr.push_back(input[i]-input[i-1]);
    }

    vector<int> baad(n);
    baad[n-1] = 1;
    baad[n-2] = 1;

    if(input[n-2] >= input[n-1]){
        baad[n-2] = 0;
    }

    for(int i = n-3; i>=0; i--){
        int agla = input[i+2] - input[i+1];
        int abhi = input[i+1] - input[i];
        if(abhi <= 0){
            baad[i] = 0;
            continue;
        }
        if(baad[i+1] == 0){
            baad[i] = 0;
            continue;
        }
        int a = agla;
        int b = abhi*2;
        if(a > b){
            baad[i] = 1;
        }
        else{
            baad[i] = 0;
        }
    }

    // print(baad);

    vector<int> phle(n);
    phle[0] = 1;
    phle[1] = 1;
    if(input[1] <= input[0]){
        phle[1] = 0;
    }

    for(int i = 2; i<n; i++){
        int pichla = input[i-1] - input[i-2];
        int abhi = input[i] - input[i-1];
        if(abhi <= 0){
            phle[i] = 0;
            continue;
        }

        
        if(phle[i-1] == 0){
            phle[i] = 0;
            continue;
        }

        int a = pichla*2;
        int b = abhi;
        if(a > b){
            phle[i] = 0;
        }
        else{
            phle[i] = 1;
        }
    }

    // print(phle);

    {
        if(baad[1] == 1){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    {
        for(int i = 1; i<n-1; i++){
            // ith index hataya
            int a = phle[i-1];
            int b = baad[i+1];
            if(a != 1 or b != 1){
                cout<<0;
                continue;
            }
            int diff1 = input[i+1] - input[i-1];
            if(diff1 <= 0){
                cout<<0;
                continue;
            }
            int pichladiff = -1e15;
            if(i-2 >=0){
                pichladiff = input[i-1] - input[i-2];
            }
            int agladiff = 1e15;

            if(i+2 < n){
                agladiff = input[i+2] - input[i+1];
            }

            if(pichladiff*2 <= diff1 and diff1*2 <= agladiff){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }

    {
        if(phle[n-2] == 1){
            cout<<1;
        }
        else{
            cout<<0;
        }
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

