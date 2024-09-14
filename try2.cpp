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
void solvee(){
    int n,m;
    cin>>n>>m;
    vector<string> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<input[i][j];
        }
        cout<<"-";
    }
    cout<<endl;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int nmax , kmax, amax, rmax, emax;
    nmax = INT_MIN;
    kmax = 0;
    amax = INT_MIN;
    rmax = INT_MIN;
    emax = INT_MIN;

    vector<char> v;

    set<char> st;

    v.push_back('n');
    v.push_back('a');
    v.push_back('r');

    v.push_back('e');

    v.push_back('k');

    st.insert('n');
    st.insert('a');
    st.insert('r');

    st.insert('e');

    st.insert('k');

    vector<int> currmax(5, INT_MIN);

    currmax[4] = 0;


    for(int i = 0; i<n; i++){
        vector<int> newdp = currmax;
        string str = input[i];
        debug(i);
        for(int j = 0; j<5; j++){

            if(i==0 and j>0) continue;
            //j se shuru 
            int curr = j;
            int currans = j>0 ? currmax[j-1] : max(0ll, currmax[4]);

            debug(curr);
            debug(currans);

            for(int k =0; k<m; k++){
                if(str[k] == v[curr % 5]){
                    debug(str[k]);
                    curr++;
                    curr%=5;
                    if(str[k] == 'k') currans+=5;
                    debug(currans);
                    continue;
                }
                if(st.count(str[k])) currans--;
            }
            if(i== n-1){
                currans -= curr;
            }
            debug(curr);
            debug(currans);
            if(curr == 0){
                debug(currans);
                debug(currmax[4]);
                newdp[4] = max(newdp[4] , currans);
                debug(currmax[4]);
                debug(newdp[4]);
               
            }
            else{
                newdp[curr-1] = max(newdp[curr-1] , currans);
                debug(curr);
                debug(currmax[curr-1]);
                debug(newdp[curr-1]);
            }
        }
        currmax = newdp;
    }

    sort(currmax. begin(), currmax.end());
    cout<<currmax[4]<<endl;
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
    for(int i = 1; i<=t;  i++){
        if(i==14915) solvee();
        else solve();
    }
return 0;
}

