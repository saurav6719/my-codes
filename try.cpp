/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
 *    We stop at Candidate Master in 2025
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int query(int idx){
    cout<<"? "<<idx<<endl;
    cout<<flush;
    int x;
    cin>>x;
    return x;
}

bool iscycle(vector<int> &a, vector<int> &b) {
    int n = a.size();
    if (n != b.size()) return false;

    for (int shift = 0; shift < n; ++shift) {
        if (b[shift] == a[0]) {
            bool match = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[(i + shift) % n]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
    }

    return false;
}

void printans(int ans1, int ans2){
    if(ans1 == -1){
        cout<<"! -1"<<endl;
        cout<<flush;
        return;
    }
    cout<<"! "<<ans1<<" "<<ans2<<endl;
    cout<<flush;
    return;
}

void solve(){
    int n,k;
    cin>>n>>k;

    if(n==2*k){
        printans(k,k);
        return;
    }

    vector<int> firstk(1, n+1);
    for(int i =1 ; i<=k; i++){
        firstk.push_back(query(i));
    }
    vector<int> lastk;
    for(int i = n-k+1; i<=n; i++){
        lastk.push_back(query(i));
    }

    if(n <= 3*k){
        int a = 0;
        int b = n+1;

        deque<int> dqa;
        map<int,int> mp;
        for(int i = 1; i<=k; i++){
            int ele = firstk[i];
            dqa.push_back(ele);
        }
        for(int i = 1; i<=n; i++){
            int x = query(i);
            mp[i] = x;
            if(x != dqa.front()) break;
            else {
                a++;
                dqa.push_back(dqa.front());
                dqa.pop_front();
            }
        }
        deque<int> dqb;
        for(auto ele : lastk){
            dqb.push_front(ele);
        }
        for(int i = n; i>=1; i--){
            int x ;
            if(mp.find(i) != mp.end()){
                x = mp[i];
            }
            else{
                x = query(i);
            }
            if(x != dqb.front()) break;
            else {
                b--;
                dqb.push_back(dqb.front());
                dqb.pop_front();
            }
        }
        debug(a);
        debug(b);

        if(a > b){
            printans(-1, 5);
            return;
        }
        else{
            a = min(a, n-k);
            printans(a, n-a);
            return;
        }
    }
    

    {
        vector<int> v;
        for(int i = 1; i<=k; i++){
            v.push_back(firstk[i]);
        }
        if(iscycle(v, lastk)){
            printans(-1, 5);
            return;
        }
    }

    
    int idx;
    {
        //finding idx which is different in both 
        int curroriginalidx = n;
        for(int i = k-1; i>=0; i--){
            int b = lastk[i];
            int originalidx = curroriginalidx;
            int modi = originalidx % k;
            if(modi == 0) modi = k;
            int a = firstk[modi];
            if(a != b){
                idx = originalidx % k;
                break;
            }
            curroriginalidx--;
        }
    }
    debug(idx);

    int lo = 1; int hi = (n-k) / k;
    int max = 0;
    while(lo <= hi){
        int mid = (lo + hi)/ 2;
        int index = mid * k;
        index += idx;
        if(index > n - k){
            hi = mid - 1;
            continue;
        }
        int modi = index % k;
        if(modi == 0) modi = k;
        int honachahiye = firstk[modi];
        int hai = query(index);
        if(honachahiye == hai){
            max = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    debug(max);

    {   
        int curr = max*k;
        while(true){
            int index = curr;
            int modi = index % k;
            if(modi == 0) modi = k;
            int honachahiye = firstk[modi];
            int hai = query(index);
            if(honachahiye != hai){
                break;
            }
            else {
                max = curr;
            }
            curr++;
            if(curr > n-k){
                break;
            }
        }
    }
    //either answer is max or -1
    debug(max);

    if(max == k){
        printans(max, n-max);
        return;
    }
    {
        //checking if answer is -1
        vector<int> ekpichese;
        for(int i = max-1; i< max-1+k; i++){
            ekpichese.push_back(query(i));
        }

        if(iscycle(lastk, ekpichese)){
            printans(-1, 5);
        }
        else{
            printans(max, n-max);
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

