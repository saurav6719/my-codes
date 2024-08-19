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
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;
    int n = str1.size();
    int t;
    cin>>t;
    int q;
    cin>>q;

    set<int> differences;

    for(int i = 0; i<n; i++){
        if(str1[i] != str2[i]){
            differences.insert(i);
        }
    }

    map<int,int> currentblocked;

    // for(auto ele : differences){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;
    for(int i = 1; i<=q; i++){
        int type;
        cin>>type;

        if(type == 3){

            // for(auto ele : differences){
            //     cout<<ele<<" ";
            // }

            // cout<<endl;
            
            debug(i-t);


            if(currentblocked.count(i-t)){
                // cout<<"igui"<<endl;
                int xx = currentblocked[i-t];
                currentblocked.erase(i-t);
                if(str1[xx] != str2[xx]){
                    differences.insert(xx);
                }
            }


            if(differences.size() == 0){
                cout<<"YES"<<endl;
                continue;
            }
            else {
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(type == 2){

            if(currentblocked.count(i-t)){
                int xx = currentblocked[i-t];
                currentblocked.erase(i-t);
                if(str1[xx] != str2[xx]){
                    differences.insert(xx);
                }
            }

            int first;
            cin>>first;
            int firstpos; 
            cin>>firstpos;
            int second;
            cin>>second;
            int secondpos;
            cin>>secondpos;

            firstpos--;
            secondpos--;

            if(differences.count(firstpos)){
                differences.erase(firstpos);
            }

            if(differences.count(secondpos)){
                differences.erase(secondpos);
            }

            char ch1;
            char ch2;
            if(first==1){
                ch1 = str1[firstpos];
            }
            else ch1 = str2[firstpos];

            if(second == 1){
                ch2 = str1[secondpos];
            }
            else ch2 = str2[secondpos];

            if(first == 1 and second == 1){
                str1[firstpos] = ch2;
                str1[secondpos] = ch1;
            }

            if(first == 1 and second == 2){
                str1[firstpos] = ch2;
                str2[secondpos] = ch1;
            }

            if(first == 2 and second == 1){
                str2[firstpos] = ch2;
                str1[secondpos] = ch1;
            }

            if(first == 2 and second == 2){
                str2[firstpos] = ch2;
                str2[secondpos] = ch1;
            }

            if(str1[firstpos] != str2[firstpos]){
                differences.insert(firstpos);
            }

            if(str1[secondpos] != str2[secondpos]){
                differences.insert(secondpos);
            }
        }

        if(type == 1){
            
            if(currentblocked.count(i-t)){
                int xx = currentblocked[i-t];
                currentblocked.erase(i-t);
                if(str1[xx] != str2[xx]){
                    differences.insert(xx);
                }
            }
            int pos;cin>>pos;
            pos--;

            if(differences.count(pos)){
                differences.erase(pos);
            }

            currentblocked[i] = pos;
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

