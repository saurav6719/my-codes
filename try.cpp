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


vector<int> validSequence(string word1, string word2) {
    map<char,vector<int> > mp;

    for(int i = 0; i<word1.size(); i++){
        mp[word1[i]].push_back(i);
    }

    int last = 0;
    int tochange = -1;
    for(int i = 1; i<word2.size(); i++){
        char ch = word2[i];
        // debug(ch);
        vector<int> &v = mp[ch];
        int lb = lower_bound(v.begin(), v.end(), last+1) - v.begin();

        if(lb == v.size()){
            // nhi hai 
            tochange = i;
            break;
        }
        else{
            last = v[lb];
        }
    }
    debug(tochange);
    if(tochange != -1){
        int last2 = -1;

        for(int i = tochange ; i>=0; i--){
            if(word2[i] != word2[tochange]){
                tochange = i+1;
                break;
            }
        }
        debug(tochange);


        vector<int> ans;
        for(int i = 0; i<word2.size(); i++){
            char ch = word2[i];
            if(i==tochange){
                if(word1[ans.back()+1] == word2[tochange])tochange++;
                ans.push_back(ans.back() + 1);
                last2 = ans.back();
            }
            else{
                vector<int> &v = mp[ch];
                int lb = lower_bound(v.begin(), v.end(), last2+1) - v.begin();

                if(lb == v.size()){
                    return {};
                }
                else{
                    ans.push_back(v[lb]);
                    last2 = v[lb];
                }
            }
        }

        return ans;
    }
    else{
        int last2 = -1;
        
        vector<int> ans;
        if(word1[0] == word2[0]){

            int kahabreak = -1;
            for(int i = 0; i<word2.size(); i++){
                if(word1[i] == word2[i]){
                    ans.push_back(i);
                    last2 = i;
                }
                else{
                    kahabreak = i;
                    ans.push_back(i);
                    last2 = i;
                    break;
                }
            }

            // debug(kahabreak);

            if(kahabreak != -1){

                for(int i = kahabreak+1; i<word2.size(); i++){
                    char ch = word2[i];
                    vector<int> &v = mp[ch];
                    int lb = lower_bound(v.begin(), v.end(), last2+1) - v.begin();
                    // print(ans);


                    if(lb == v.size()){
                        return {};
                    }


                    else{
                        ans.push_back(v[lb]);
                        last2 = v[lb];
                    }
                }
            }

            // print(ans);
        }
        else{
            ans.push_back(0);
            last2 = 0;

            for(int i = 1; i<word2.size(); i++){
                char ch = word2[i];
                vector<int> &v = mp[ch];
                int lb = lower_bound(v.begin(), v.end(), last2+1) - v.begin();

                if(lb == v.size()){
                    return {};
                }

                else{
                    ans.push_back(v[lb]);
                    last2 = v[lb];
                }
            }

        }
        return ans;
    }
}


void solve(){
    string a = "effgiihrhhagiie";
    string b = "ihihh";

    vector<int> ans = validSequence(a,b);
    print(ans);
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

