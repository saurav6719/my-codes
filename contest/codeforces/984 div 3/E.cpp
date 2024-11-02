/**
 *    author: Saurav
 *    created: 2024.11.02 20:03:39
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
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int> >input(n+1, vector<int> (m+1));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin>>input[i][j];
        }
    }
    for(int i= 2 ; i<=n; i++){
        for(int j= 1; j<=m; j++){
            input[i][j] |= input[i-1][j];
        }
    }

    print2d(input);

    map<int,vector<int>  >mp;
    for(int j = 1; j<=m; j++){
        vector<int> v;
        for(int i = 1; i<=n; i++){
            v.push_back(input[i][j]);
        }
        mp[j] = v;
    }

    while(q--){
        int m;
        cin>>m;

        map<int,pp> query;
        for(int i = 1; i<=m; i++){
            int r;
            cin>>r;
            char ch;
            cin>>ch;
            int val;
            cin>>val;

            if(query.find(r) == query.end()){
                if(ch == '<'){
                    query[r] = {0,val-1};
                }
                else{
                    query[r] = {val+1,1000000000000};
                }
            }
            else{
                if(ch == '<'){
                    query[r].second = min(query[r].second,val-1);
                }
                else{
                    query[r].first = max(query[r].first,val+1);
                }
            }
        }
        int currmini = 0;
        int currmaxi = n-1;
        bool flag = false;


        for(auto ele : query){

            int row = ele.first;
            vector<int> &v = mp[row];
            debug(row);
            print(v);
            int mini = ele.second.first;
            int maxi = ele.second.second;
            debug(mini);
            debug(maxi);
            int minilb = lower_bound(v.begin(),v.end(),mini) - v.begin();
            int maxilb = upper_bound(v.begin(),v.end(),maxi) - v.begin();

            debug(minilb);
            debug(maxilb);

            

            if(minilb == v.size()){
                cout<<-1<<endl;
                flag = true;
                break;
            }
            if(minilb > maxilb){
                cout<<-1<<endl;
                flag = true;
                break;
            }

            

            if(maxilb < v.size() and v[maxilb] > maxi){
                maxilb--;
                if(maxilb < minilb){
                    cout<<-1<<endl;
                    flag = true;
                    break;
                }
            }
            debug(minilb);
            debug(maxilb);
            currmini = max(currmini,minilb);
            currmaxi = min(currmaxi,maxilb);

            debug(currmini);
            debug(currmaxi);

            if(currmini > currmaxi){
                flag = true;
                cout<<-1<<endl;
                break;
            }

        }
        if(flag) continue;
        cout<<currmini + 1 << endl;

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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

