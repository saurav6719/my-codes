/**
 *    author: Saurav
 *    created: 2024.11.14 23:42:16
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
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());

    debug(sum);

    bool zerofound = false;

    int totalzerro = 0;

    int pushedzero = 0;

    while(arr.size() > 1 and sum > 0){

        if(arr.size() == 2 and arr[0] == 0){
            cout<<arr[1]<<endl;
            return ;
        }
        print(arr);
        vector<int> newarr;
        for(int i = 1; i < arr.size(); i++){
            newarr.push_back(arr[i] - arr[i-1]);
            if(newarr.back() == 0){
                totalzerro++;
            }
        }
        sort(newarr.begin(), newarr.end());
        int zerocnt = 0;
        for(int i=0;i<newarr.size();i++){
            if(newarr[i] == 0){
                zerocnt++;
            }
        }
        vector<int> xx;
        for(auto ele : newarr){
            if(ele != 0){
                xx.push_back(ele);
            }
        }
        if(zerocnt > 0){
            zerofound = true;
        }
        if(zerofound and pushedzero < totalzerro){
            xx.push_back(0);
            pushedzero++;
        }
        sort(xx.begin(), xx.end());
        arr = xx;
        sum = 0;
        for(auto ele : arr){
            sum += ele;
        }
    }
    if(sum == 0){
        cout<<0<<endl;
        return ;
    }
    else if(arr.size() == 1) {
        cout<<arr[0]<<endl;
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

