/**
 *    author: Saurav
 *    created: 2024.10.16 19:02:25
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
    vector<int> input(n+1);
    vector<int> overallfreq(201, 0);

    vector<vector<int> > freq2(201, vector<int> ());

    for(int i=1;i<=n;i++){
        cin>>input[i];
        overallfreq[input[i]] ++;
        freq2[input[i]].push_back(i);
    }

    vector<vector<int> > freq(201, vector<int> (n+1,0));
    for(int i =1; i<=n; i++){
        int ele = input[i];
        freq[ele][i] = 1;
    }
    for(int i=1; i<=200; i++){
        for(int j=1; j<=n; j++){
            freq[i][j] += freq[i][j-1];
        }
    }

    print2d(freq);

    int ans = 1;

    for(int i = 1; i<= 200; i++){
        //first block is i 
        for(int j = 1; j<=overallfreq[i]/2; j++){
            // taking i jth times 
            int starting = freq2[i][j-1];
            int ending = freq2[i][overallfreq[i]-j];

            // if(i==1 and j==2) debug(starting) , debug(ending) ;

            for(int k = 1; k<=200; k++){
                //taking most frequent element from starting +1 to ending - 1
                // if(i==1 and j==2 and k==2){
                //     debug(freq[k][ending-1]) ;
                //     debug(freq[k][starting]) ;
                // }
                if((starting + 1) > (ending - 1)){
                    ans = max(ans , 2*j);
                    continue;
                }
                
                ans = max(ans , 2*j + freq[k][ending-1] - freq[k][starting]);
            }
        }
    }
    cout<<ans<<endl;
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

