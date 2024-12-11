/**
 *    author: Saurav
 *    created: 2024.12.11 01:59:33
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
    int n,a,b,c;
    cin>>n>>a>>b>>c;


    int x = a-b+c;
    if(x%2 != 0 or x<0){
        cout<<"NO"<<endl;
        return;
    }
    x /= 2;

    int y = b+c-a;

    if(y%2 != 0 or y<0){
        cout<<"NO"<<endl;
        return;
    }


    vector<pp> ans;

    y /= 2;
    int curr1 = 1;
    int curr2 = 4;
    int acopy = a;

    debug(x);
    debug(y);

    if(x >= a){

        if(a+b != c){
            cout<<"NO"<<endl;
            return;
        }
        for(int i = 0; i<a-1; i++){
            ans.push_back({curr1,curr2});
            curr1 = curr2;
            curr2++; 
        }
        ans.push_back({curr1,2});

        curr1 = 2;

        for(int i = 0; i<x-a; i++){
            if(i== x-a-1){
                if(y==0){
                    ans.push_back({curr1,3});
                    break;
                }
            }

            ans.push_back({curr1,curr2});
            curr1 = curr2;
            curr2++;
        }

        for(int i = 0; i<y-1; i++){
            ans.push_back({curr1,curr2});
            curr1 = curr2;
            curr2++;
        }

        if(y!=0) {
            ans.push_back({curr1,3});
        }

        for(int i = 0; i<n-1-(x+y); i++){
            ans.push_back({3,curr2});
            curr2++;
        }

    }

    else{

        curr1 = 1;
        curr2 = 4;

        int newstart = 1;
        for(int i = 0; i<x; i++){

            if(i== x-1){
                if(y==0){
                    ans.push_back({curr1,3});
                    newstart = 3;
                    break;
                }
            }
            ans.push_back({curr1,curr2});
            curr1 = curr2;
            curr2++;
            newstart = curr1;
        }

        for(int i = 0; i<y-1; i++){
            ans.push_back({curr1,curr2});
            curr1 = curr2;
            curr2++;
        }

        if(y!=0) {
            ans.push_back({curr1,3});
        }

        curr1 = newstart;

        for(int i = 0; i<acopy-x- 1; i++){
            ans.push_back({curr1,curr2});
            curr1 = curr2;
            curr2++;
        }
        ans.push_back({curr1,2});


        for(int i = 0; i<n-1-(a+y); i++){
            ans.push_back({2,curr2});
            curr2++;
        }
    }


    for(auto ele : ans){
        if(ele.first > n or ele.second > n){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

    for(auto ele : ans){
        cout<<ele.first<<" "<<ele.second<<endl;
    }

    return;

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

