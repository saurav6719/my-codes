/**
 *    author: Saurav
 *    created: 2024.10.19 20:38:43
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
    int n,q;
    cin>>n>>q;
    vector<int> input(n);
    for(int i=0 ; i<n; i++){
        cin>>input[i];
    }
    string str;
    cin>>str;

    map<pp,int> mp;

    set<pp> lrset;

    for(int i = 1; i<n; i++){
        if(str[i] == 'R' and str[i-1] == 'L'){

            debug(i);
            debug(i-1);
            mp[{i-1,i}] = 0;
            lrset.insert({i-1,i});
        }
    }


    int openc = 0;

    set<int> st;

    map<pp, int>  mp2;



    for(int i  = 0; i<n; i++){

        if(i>0){
            mp2[{i-1,i}] = openc;
            if(lrset.count({i-1, i}))mp[{i-1,i}] = openc;
        }

        int actual = input[i];
        int should = i+1;
        // st.insert(input[i]);
        if(st.count(should) == 0) openc++;
        if(input[i] > i+1) openc++;
        if(input[i] < i+1) openc--;
        st.insert(input[i]);
        if(st.count(should)) openc--;
        
    }



    int totalsum =0;
    for(auto x : mp){
        totalsum += x.second;
    }

    for(auto ele : mp){
        debug(ele.first.first);
        debug(ele.first.second);
        debug(ele.second);
    }

    // for(auto ele : mp2){
    //     debug(ele.first.first);
    //     debug(ele.first.second);
    //     debug(ele.second);
    // }

    debug(totalsum);




    while(q--){
        int idx;
        cin>>idx;

        idx --;
        if(mp.count({idx, idx+1})){
            totalsum -= mp[{idx, idx+1}];
            debug(totalsum);
            mp.erase({idx, idx+1});
        }
        else if(mp.count({idx-1, idx})){
            totalsum -= mp[{idx-1, idx}];
            mp.erase({idx-1, idx});
        }

        if(str[idx] == 'L') str[idx] = 'R';
        else str[idx] = 'L';

        if(mp2.count({idx, idx+1}) and str[idx] == 'L' and str[idx+1] == 'R'){
            mp[{idx, idx+1}] = mp2[{idx, idx+1}];
            totalsum += mp2[{idx, idx+1}];
        }
        if(mp2.count({idx-1, idx}) and str[idx] == 'R' and str[idx-1] == 'L'){
            mp[{idx-1, idx}] = mp2[{idx-1, idx}];
            totalsum += mp2[{idx-1, idx}];
        }

        debug(totalsum);

        if(totalsum == 0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

