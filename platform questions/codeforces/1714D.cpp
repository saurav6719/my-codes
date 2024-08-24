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
    string text;
    cin>>text;
    int sz = text.size();

    int n;
    cin>>n;
    vector<string> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }


    vector<vector<int> > pos(n, vector<int> ());

    for(int i =0; i<n; i++){
        string curr = input[i];
        for(int j = 0; j<sz; j++){
            if(text[j] == curr[0]){
                string ss = text.substr(j, curr.size());
                if(ss == curr){
                    pos[i].push_back(j);
                }
            }
        }
    }

    print2d(pos);

    vector<int> prefix(sz+15, 0);
    int ans = 0;

    vector<pp> res;

    vector<int> xxxx(sz+15, 0);

    for(int i = 1; i<=sz; i++){
        int currov = -5;
        int curridx = -1;
        int sizetochange = -1;

        int whichstring = -1;
        for(int j = 0; j<n; j++){
            string currstring= input[j];
            int currsize = currstring.size();
            for(auto ele : pos[j]){
                debug(ele);
                int curr = 0;
                curr += prefix[ele + currsize -1];
                debug(curr);
                if(ele > 0) curr -= prefix[ele -1];
                debug(curr);
                int canchange = currsize - curr;
                debug(canchange);
                if(canchange > currov){
                    currov  = canchange;
                    curridx = ele;
                    sizetochange = currsize;
                    whichstring = j;
                }
                if(canchange == currov and ele < curridx){
                    currov  = canchange;
                    curridx = ele;
                    sizetochange = currsize;
                    whichstring = j;
                }
            }
        }

        debug(currov);
        debug(curridx);
        debug(sizetochange);
        debug(whichstring);

        for(int a = curridx ; a<curridx + sizetochange; a++){
            xxxx[a] = 1;
        }

        prefix[0] = xxxx[0];

        for(int a = 1; a<=prefix.size() - 1; a++){
            prefix[a] = xxxx[a] + prefix[a-1];
        }
        print(prefix);
        res.push_back({whichstring, curridx});

        if(prefix[sz-1] == sz) break;
    }

    if(prefix[sz-1] != sz) {
        cout<<-1<<endl;
        return;
    }

    cout<<res.size()<<endl;

    for(auto ele : res){
        cout<<ele.first+1<<" "<<ele.second+1<<endl;
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

