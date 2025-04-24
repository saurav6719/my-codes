/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

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
    int n;cin>>n;
    int k;cin>>k;
    string str;
    cin>>str;

    sort(str.begin(), str.end());

    map<char,int> mp;
    for(auto ele : str){
        mp[ele]++;
    }

    if(mp.size() == 1){
        auto one = *mp.begin();
        char ch = one.first;
        int freq = one.second;
        if(freq == k){
            cout<<ch<<endl;
            return;
        }
        else{
            int least = freq / k;
            if(freq % k != 0) least++;

            for(int i = 0; i<least; i++){
                cout<<ch;
            }cout<<endl;
            return;
        }
    }

    if(mp.size() == 2){
        auto one = *mp.begin();
        char ch1 = one.first;
        int freq1 = one.second;

        auto two = *mp.rbegin();
        char ch2 = two.first;
        int freq2 = two.second;

        if(freq1 > k){
            for(int i = 0; i<(freq1 - (k - 1)); i++){
                cout<<ch1;
            }
            for(int i = 0; i<freq2; i++){
                cout<<ch2;
            }
            cout<<endl;
            return;
        }

        if(freq1==k){
            cout<<ch1;
            int least = freq2 / k;
            if(freq2 % k !=0 ) least++;
            for(int i = 0; i<least; i++){
                cout<<ch2;
            }
            cout<<endl;
            return;

        }

        if(freq1 < k){
            cout<<ch2<<endl;
            return;
        }
    }

    if(mp.size() > 2){
        auto one = *mp.begin();
        char ch1 = one.first;
        int freq1 =one.second;
        auto it = mp.begin();
        advance(it, 1);
        auto two = *it;

        char ch2 = two.first;
        int freq2 = two.second;

        if(freq1 < k){
            cout<<str[k-1]<<endl;
            return;
        }
        if(freq1 >= k){
            for(int i = 0; i<(freq1 - (k-1)); i++){
                cout<<ch1;
            }

            for(auto ele : mp){
                if(ele.first == ch1)continue;
                for(int i = 0; i<ele.second; i++){
                    cout<<ele.first;
                }
            }

            cout<<endl;
            return;
        }
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}