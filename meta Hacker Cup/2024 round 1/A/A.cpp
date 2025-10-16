/**
 *    author: Saurav
 *    created: 2025.10.15 12:50:09
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
#define printset(s)
#define printpp(v)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
// #define int long long int
#define ld long double
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<ld,ld>
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<pp> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first>>input[i].second;
    }

    ld lo = 0.000000001;
    ld hi = 1e9;

    for(int i =0 ; i<n; i++){
        ld lowest_speed = (ld) (i+1) / input[i].second;
        ld highest_speed = (ld) (i+1) / input[i].first;
        lo = max(lo, lowest_speed);
        hi = min(hi, highest_speed);
    }

    if(lo <= hi){
        cout<<fixed<<setprecision(9)<<lo<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
/* logic ends */

void main_() {
    // implement your solution here
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}

static void run_main() {
    main_();
    exit(0);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    size_t stsize = 1024ULL * 1024ULL * 1024ULL; // 1 GiB stack
    char *stack = (char *)malloc(stsize);
    if (!stack) {
        cerr << "Failed to allocate stack memory\n";
        return 1;
    }

    char *send = stack + stsize;
    // Align to 16 bytes (required by AArch64 ABI)
    send = (char *)((uintptr_t)send & -16LL);

#if defined(__aarch64__)
    asm volatile(
        "mov sp, %0\n"     // Set new stack pointer (sp = send)
        "blr %1\n"         // Branch with link to run_main
        :
        : "r"(send), "r"(run_main)
        : "sp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x30"
    );
#else
    // fallback for x86 or others
    asm volatile(
        "mov %0, %%rsp\n"
        "call *%1\n"
        :
        : "r"(send), "r"(run_main)
    );
#endif
    return 0;
}
