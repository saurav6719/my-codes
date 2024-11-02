/**
 *    author: Saurav
 *    created: 2024.11.02 21:32:41
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

long long f(long long n){
    if(n < 0) return 0;
    long long m = n % 4;
    if(m == 0) return n;
    if(m == 1) return 1;
    if(m == 2) return n + 1;
    return 0;
}

int firstGreaterOrEqualInAP(int a, int d, int target) {
    // If the target is less than or equal to the starting number `a`
    if (target <= a) return a;

    // Calculate the position (n) where the AP term is >= target
    int n = ceil(static_cast<double>(target - a) / d);

    // Return the term at position n in the AP: a + n * d
    return a + n * d;
}


int lastLessOrEqualInAP(int a, int d, int target) {
    // If the target is less than the starting number `a`, return a
    if (target < a) return a;

    // Calculate the position (n) where the AP term is <= target
    int n = (target - a) / d;

    // Return the term at position n in the AP: a + n * d
    return a + n * d;
}

string getbinary(int x){
    bitset<64> b(x);
    return b.to_string();
}

long long binaryToDecimal(const std::string& bin) {
    return std::bitset<64>(bin).to_ullong();
}

int integer_log2(long long x){
    if(x <= 0){
        // Undefined for non-positive integers
        return 0;
    }
    int res = 0;
    while(x >>= 1){
        res++;
    }
    return res;
}


void solve(){
    int l,r,i,k;
    cin>>l>>r>>i>>k;

    if(i==0){
        cout<<0<<endl;
        return;
    }
    int modi = (1ll<<i);
    debug(modi);

    int total = f(r) ^ f(l-1);
    debug(total);

    int reqmod = k % modi;
    debug(reqmod);
    int start = firstGreaterOrEqualInAP(reqmod, modi, l);
    debug(start);
    int end = lastLessOrEqualInAP(reqmod, modi, r);
    debug(end);

    int cnt = 0;
    if(start <= end){
        cnt = ((end - start) / modi) + 1;
    }

    debug(cnt);

    if(cnt == 0){
        cout<<total<<endl;
        return;
    }
    if (cnt & 1){

        int noofcheckbits = integer_log2(reqmod) + 1;

        string startbinary = getbinary(start);
        reverse(startbinary.begin(), startbinary.end());

        string news = "";

        for(int i = noofcheckbits; i < 64; i++){
            news += startbinary[i];
        }

        reverse(news.begin(), news.end());

        int newstart = binaryToDecimal(news);

        debug(newstart);

        int newxor =( f(newstart + cnt - 1) ^ f(newstart - 1));

        newxor = (newxor << noofcheckbits);

        newxor += reqmod;

        cout<<(total ^ newxor)<<endl;


    }
    else{
        int noofcheckbits =  integer_log2(reqmod) + 1;

        debug(noofcheckbits);
        string startbinary = getbinary(start);
        reverse(startbinary.begin(), startbinary.end());

        string news = "";

        for(int i = noofcheckbits; i < 64; i++){
            news += startbinary[i];
        }

        reverse(news.begin(), news.end());

        int newstart = binaryToDecimal(news);

        debug(newstart);

        int newxor = (f(newstart + cnt - 1) ^ f(newstart - 1));

        newxor = newxor << noofcheckbits;

        // newxor += reqmod;

        cout<<(total ^ newxor)<<endl;
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

