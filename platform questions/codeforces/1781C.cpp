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

bool cmp(pair<int,char> &a, pair<int, char> &b){
    return a.first > b.first;
}
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;

    map<char,int> mp;

    for(auto ele : str){
        mp[ele]++;
    }


    vector<int> poss;

    for(int i = 1; i<=26; i++){
        if(n % i == 0){
            poss.push_back(n/i);
        }
    }

    print(poss);
    printmap(mp);  
    set<char> st;
    for(char i = 'a'; i<='z'; i++ ){
        st.insert(i);
    }

    

    vector<pair<int,char> > v;
    for(auto ele: mp){
        v.push_back({ele.second , ele.first});
        st.erase(ele.first);
    }

    sort(v.begin(), v.end(), cmp);

    int ans = INT_MAX;
    int res = -1;

    string toprintfinally;

    for(int i = 0; i<poss.size(); i++){

        
        int curr = poss[i];
        int charrequired = n / curr;

        string final = "";
        int j = 0;
        while(final.size() < n and j<v.size()){
            char ch = v[j].second;
            for(int k = 0; k<curr; k++){
                final += ch;
            }
            j++;
        }

        if(final.size() < n){
            while(final.size() < n){
                char ch =*st.begin();
                for(int k = 0; k<curr; k++){
                    final += ch;
                }
                st.erase(ch);
            }
        }

        print(final);

        map<char,int> mpfinal;
        for(auto ele : final){
            mpfinal[ele]++;
        }
        map<char,int> mp2 = mp;

        string copied = str;

        vector<int> tochange;

        for(int i = 0; i<n; i++){
            char original = copied[i];
            if(mpfinal[original] > 0){
                mpfinal[original]--;
                continue;
            }
            tochange.push_back(i);
        }

        string tochangestring = "";
        for(auto ele : mpfinal){
            char ch = ele.first;
            int freq = ele.second;

            for(int i = 0; i<freq; i++){
                tochangestring += ch;
            }
        }

        debug(tochange.size());
        if(tochange.size() < ans){
            res = tochange.size();
            ans = tochange.size();

            for(int i = 0; i<tochange.size(); i++){
                int index = tochange[i];
                copied[index] = tochangestring[i];
            }

            toprintfinally = copied;
        }

    }
    cout<<res<<endl;
    cout<<toprintfinally<<endl;


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

