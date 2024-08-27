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
int nextPowerOf2(unsigned int n) {
    if (n == 0)
        return 1;

    if ((n & (n - 1)) == 0)  // If n is already a power of 2
        return n << 1;

    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return n + 1;
}

bool isPowerOf2(unsigned int n) {
    // A number is a power of 2 if it has exactly one bit set in its binary representation.
    // The condition (n & (n - 1)) == 0 checks if exactly one bit is set.
    return n > 0 && (n & (n - 1)) == 0;
}



void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += input[i];
    }

    if(sum % n != 0){
        cout<<"no"<<endl;
        return;
    }
    int to_make = sum / n;

    vector<int> plus;
    vector<int> minus;

    for(int i = 0; i<n; i++){
        int ele = input[i];
        if(ele < to_make){
            int diff = to_make - ele;
            int xx = nextPowerOf2(diff);
            plus.push_back(xx);
            minus.push_back(xx - diff);
        }
        else if(ele == to_make){
            plus.push_back(1);
            minus.push_back(1);
        }
        else{
            int diff = ele - to_make;
            int xx = nextPowerOf2(diff);
            minus.push_back(xx);
            plus.push_back(xx - diff);
        }
    }

    map<int,int> pluss;
    map<int,int> minuss;
    for(auto ele : plus){
        if(!isPowerOf2(ele)){
            cout<<"no"<<endl;
            return;
        }
        pluss[ele]++;
    }
    for(auto ele : minus){
        if(!isPowerOf2(ele)){
            cout<<"no"<<endl;
            return;
        }
        minuss[ele]++;
    }

    for(auto ele : pluss){
        if(ele.second != minuss[ele.first]){
            cout<<"no"<<endl;
            return;
        }
    }

    cout<<"yes"<<endl;




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

