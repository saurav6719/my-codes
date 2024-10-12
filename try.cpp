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
int f(vector<int> &input, int a, int b, int c){
    if(a==b or b==c) return 1e15;
    if(a <= 0 or c>= input.size()) return 1e15;

    if(a<= 0 or b<=0 or c>=0) return 1e15;
    if(a>=b or b>=c) return 1e15;
    if(a>=input.size() or b>=input.size() or c>=input.size()) return 1e15;

    int i= 1;
    vector<int> temp;
    int sum = 0;
    while(i<=a){
        sum += input[i];
        i++;
    }
    temp.push_back(sum);
    sum = 0;
    while(i<=b){
        sum += input[i];
        i++;
    }
    temp.push_back(sum);
    sum = 0;
    while(i<=c){
        sum += input[i];
        i++;
    }
    temp.push_back(sum);
    sum = 0;
    while(i<=input.size()){
        sum += input[i];
        i++;
    }
    temp.push_back(sum);
    sort(temp.begin(), temp.end());
    return temp[3] - temp[0];
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n+1);
    int tsum = 0;
    for(int i =1 ; i<=n; i++){
        cin>>input[i];
        tsum += input[i];
    }
    int tomake = tsum / 4;

    int a= 0;
    int b = 0;
    int c = 0;
    int sum = 0;
    int i = 0;
    while(i<=n){
        sum += input[i];
        if(sum + input[i+1] > tomake and a == 0){
            a = i;
            sum = 0;
            i++;
            continue;
        }
        if(sum + input[i+1] > tomake and b == 0){
            b = i;
            sum = 0;
            i++;
            continue;
        }
        if(sum + input[i+1] > tomake and c == 0){
            c = i;
            sum = 0;
            i++;
            continue;
        }
        i++;
    }

    if(c==0) c = n-1;

    debug(a);
    debug(b);
    debug(c);
    int res = 1e15;


    for(int i =-2; i<=2; i++){
        for(int j = -2; j<=2; j++){
            for(int k = -2; k<=2; k++){
                int ans = f(input, a+i, b+j, c+k);
                res = min(res, ans);
            }
        }
    }

    cout<<res<<endl;


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

