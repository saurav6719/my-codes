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
void solvvee(){
    int n;
    cin>>n;
    vector<int> topic(n);
    vector<int> difficulty(n);
    for(int i = 0; i<n; i++){
        cin>>topic[i]>>difficulty[i];
    }

    for(int i = 0; i<n; i++){
        cout<<topic[i]<<"n"<<difficulty[i]<<"m";
    }
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    vector<int> topic(n);
    vector<int> difficulty(n);
    for(int i = 0; i<n; i++){
        cin>>topic[i]>>difficulty[i];
    }

    map<int,int> mptopic;
    map<int,int> mpdiff;

    for(int i =0; i<n; i++){
        mptopic[topic[i]]++;
        mpdiff[difficulty[i]]++;
    }

    int total = n*(n-1)*(n-2) / 6;
    debug(total);
    map<int,int> difficultymap;
    map<int,int> topicmap;

    for(int i =0; i<3; i++){
        difficultymap[difficulty[i]]++;
        topicmap[topic[i]]++;
    }

    for(int i= 0; i<n; i++){
        int currtopic = topic[i];
        debug(currtopic);
        int currdifficulty = difficulty[i];
        debug(currdifficulty);
        int nottake = (mptopic[currtopic]- 1) * (mpdiff[currdifficulty] -1);
        total -= nottake; 
    }
    cout<<total<<endl;
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

