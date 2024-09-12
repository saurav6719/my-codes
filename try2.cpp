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
vector<int>  vectordivide2(vector<int> &v){
    vector<int> ans;
    int currrem = 0;
    for(int i = 0; i<v.size(); i++){
        int ele = v[i];
        ele += (currrem*10);
        ans.push_back(ele/2);
        
        currrem = ele % 2;
    }


    vector<int> newans;
    int lo = 0;
    while(ans[lo] == 0)lo++;
    for(int i = lo ; i<ans.size(); i++){
        newans.push_back(ans[i]);
    }

    ans = newans;

    return ans;
}

vector<int> sub(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();

    reverse(b.begin(), b.end());
    while(b.size() < a.size()){
        b.push_back(0);
    }
    reverse(b.begin(), b.end());

    // print(a);
    // print(b);

    n = a.size();

    vector<int> ans;
    int carry =0;
    for(int i = n-1; i>=0; i--){
        int up = a[i];
        int down = b[i];
        if(carry){
            if(a[i] == 0){
                up = 9;
                carry = 1;
            }   
            else{
                up--;
                carry = 0;
            }
        }

        if(down <= up){
            ans.push_back(up - down);
            continue;
        }
        else{
            up += 10;
            ans.push_back(up-down);
            carry = 1;
        }
    }

    reverse(ans.begin(), ans.end());
    vector<int> newans;
    int lo = 0;
    while(ans[lo] == 0)lo++;
    for(int i = lo ; i<ans.size(); i++){
        newans.push_back(ans[i]);
    }

    ans = newans;

    return ans;
}

int f(int a, vector<int> &b){
    if(b.size() == 1){
        int xx = pow(a, b.back());
        return xx;
    }

    vector<int> firsthalf = vectordivide2(b);
    vector<int> secondhalf = sub(b, firsthalf);


    return ((f(a,firsthalf) % 1337) * (f(a,secondhalf) % 1337) % 1337);
}

int superPow(int a, vector<int>& b) {
    return f(a,b);
}

void solve(){


    vector<int> b = {1,0};
    int a = 2;

    vector<int> firsthalf = vectordivide2(b);
    print(firsthalf);
    debug(firsthalf.size());

    vector<int> secondhalf = sub(b, firsthalf);

    print(firsthalf);
    debug(firsthalf.size());

    print(secondhalf);


    vector<int> c = {5};
    cout<<f(a,firsthalf);
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

