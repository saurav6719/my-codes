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
string getbinary(int x){
    bitset<32> b(x);
    return b.to_string();
}

long long binaryToDecimal(const std::string& bin) {
    return std::bitset<64>(bin).to_ullong();
}

void solve(){

    vector<int> fibonacci;

    int n,p;
    cin>>n>>p;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    fibonacci.push_back(1);
    fibonacci.push_back(1);
    fibonacci.push_back(2);
    for(int i = 0; i<p; i++){
        int a = fibonacci.back();
        int b = fibonacci[fibonacci.size() - 2];
        int xx = a + b;
        xx %= mod;
        fibonacci.push_back(xx);
    }

    for(int i = 1; i<fibonacci.size(); i++){
        fibonacci[i] += fibonacci[i-1];
        fibonacci[i] %= mod;
    }


    sort(arr.begin(), arr.end());
    set<int> st;
    set<int> avail;

    avail.insert(0);

    st.insert(arr[0]);
    for(int i = 1; i<n; i++){

        string xx = getbinary(arr[i]);
        int toput = true;

        print(xx);

        while(xx.size() > 2){
            // debug(binaryToDecimal(xx));
            if(st.count(binaryToDecimal(xx))) {
                toput = false;
                break;
            }

            if(xx.back() == '0'){
                if(xx[xx.size() - 2] != '0'){
                    break;
                }
                else{
                    xx.pop_back();
                    xx.pop_back();
                }
            }

            else{
                xx.pop_back();
            }
        }

        if(toput){
            avail.insert(i);
            st.insert((arr[i]));
        }
    }
    int ans = 0;


    for(auto ele : st){
        // cout<<ele<<endl;
        int xx = log2(ele);
        int times = p - xx;
        if(times<=0) continue; 
        ans += fibonacci[times-1];
        ans %= mod;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

