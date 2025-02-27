/**
 *    author: Saurav
 *    created: 2025.02.23 02:00:20
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
bool poss;
int dp[101][2][2][101];
bool f(int i, int turn, int sum, int howmanyodd, int totalodd, int totaleve, vector<int> &a, int n){
    if(i == n){
        if(sum % 2 == 0){
            debug(sum);
            debug(i);
            return true;
        }
        return 0;
    }

    // if(dp[i][turn][sum][howmanyodd] != -1) return dp[i][turn][sum][howmanyodd];

    debug(i);
    debug(turn);
    debug(sum);
    debug(howmanyodd);
    //picking odd 
    int remainingodd = totalodd - howmanyodd;
    if(remainingodd > 0){
        int newsum = sum;
        if(turn == 0){
            //alice turn
            newsum = 1-newsum;
        }

        bool xx = f(i+1, 1-turn , newsum , howmanyodd+1, totalodd, totaleve, a, n);
        if(turn == 0){
            if(xx) return 1;
        }
        if(turn == 1){
            if(!xx) return  0;
        }
    }

    //picking even 
    int pickedeven = i - howmanyodd;
    int remainingeven = totaleve - pickedeven;
    if(remainingeven >  0){
        bool xx = f(i+1, 1-turn , sum , howmanyodd, totalodd, totaleve, a, n);
        if(turn == 0){
            if(xx) return  1;
        }
        if(turn == 1){
            if(!xx) return  0;
        }
    }

    if(turn == 0) return  1;
    else return  0;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    poss= false;

    int ec = 0;
    int oc = 0;
    

    for(int i = 0; i<101; i++){
        for(int j = 0; j<2; j++){
            for(int k = 0; k<2; k++){
                for(int l = 0; l<101; l++){
                    dp[i][j][k][l] =-1;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(a[i] % 2 == 0){
            ec++;
        }
        else oc++;
    }

    int xx = f(0, 0, 0, 0, oc, ec, a, n);
    if(xx){
        cout<<"Alice"<<endl;
    }
    else cout<<"Bob"<<endl;
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

