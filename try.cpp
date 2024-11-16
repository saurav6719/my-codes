/**
 *    author: Saurav
 *    created: 2024.11.17 01:14:26
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
int f1(int start, int end, int d){
    // kitne term baad jaake end se chota hoga 
    if(end > start) return 0;
    int total = start - end;
    int ans = total/d + 1;
    return ans;
}

int sumofap(int start, int end , int d){
    int n = f1(start, end, d);
    end = start - (n-1) * d;
    int ans = n*(start + end)/2;
    return ans;
}

bool poss1(int mid, vector<int> &a, vector<int> &b, int k){
    int n = a.size();
    int cnt = 0;
    // debug(mid);
    for(int i = 0; i<n; i++){
        int start = a[i];
        int end = mid;
        if(mid == 13){
            debug(i);
            debug(f1(start, end, b[i]));
        }
        cnt += f1(start, end, b[i]);
    }
    // debug(cnt);
    return cnt >= k;
}

int poss2(int mid, vector<int> &a, vector<int> &b, int k,  int minimum){
    int ans = 0;
    int n = a.size();
    int currtaken = 0;

    debug(mid);

    for(int i = 0; i<n; i++){
        if(currtaken >= k) break;
        int times = f1(a[i], minimum+1, b[i]);
        debug(a[i]);
        debug(minimum+1);
        debug(f1(a[i], minimum+1, b[i]));
        debug(i);
        debug(ans);
        debug(times);

        if(currtaken + times > k){
            int left = k - currtaken;
            ans += sumofap(a[i] , a[i] - (left - 1) *b[i] , b[i]);
            debug(a[i]);
            debug(a[i] - (left - 1) *b[i]);
            debug(sumofap(a[i] , a[i] - (left - 1) *b[i] , b[i]));
        }
        else{
            ans += sumofap(a[i], minimum +1, b[i]);

            debug(a[i]);
            debug(minimum+1);

            debug(sumofap(a[i], minimum +1, b[i]));
        }
        currtaken += times;
    }

    if(currtaken < k){
        return -1e9;
    }

    debug(ans);
    return ans;
}

int f2(int minimum , vector<int> &a, vector<int> &b, int k){
    int lo = 1;
    int hi = k;
    int currans = k * minimum;

    debug(currans);

    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        // mai minimum ko mid times le rha hu 


        int temp = poss2(mid, a, b, k - mid, minimum);

        if(temp + (mid * minimum)  > currans){
            currans = temp + (mid * minimum);
            debug(currans);
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    return currans;
}

void solvee(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int xx = 0;

    for(int i = 0; i<n; i++){
        xx += f1(a[i] , 1, b[i]);
    }

    k = min(k, xx);

    debug(k);

    cout<<n<<":";
    cout<<k<<":";

    for(int i = 0; i<n; i++){
        cout<<a[i]<<"->"<<b[i]<<",";
    }
    cout<<endl;

}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int xx = 0;

    for(int i = 0; i<n; i++){
        xx += f1(a[i] , 1, b[i]);
    }

    k = min(k, xx);

    debug(k);


    int lo = 0;
    int hi = 1e9;
    int ans = 1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(poss1(mid, a, b, k)){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    debug(ans);

    // now finding ans kitni baar lenge to maximise our score 

    int minimum = ans;

    debug(minimum);

    int finalans = f2(minimum, a, b, k);

    cout<<finalans<<endl;


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

