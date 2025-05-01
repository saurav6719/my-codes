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
void solvee(){
    int n,k;
    cin>>n>>k;
    cout<<n<<"-"<<k<<endl;
    return;
}
void solve(){
    int n,k;
    cin>>n>>k;
    set<int> uniques;
    string s = to_string(n);
    for(auto i : s){
        uniques.insert(i - '0');
    }
    if(uniques.size() <= k){
        cout<<n<<endl;
        return;
    }
    set<char> taken;
    string maked = "";
    int i = 0;
    bool bigger = false;
    while(k>0 and i < s.size()){
        if(taken.count(s[i])){
            // isko le lo no problem
            maked += s[i];
            i++;
            continue;
        }
        else{
            if(k==1) break;
            maked += s[i];
            taken.insert(s[i]);
            i++;
            k--;
            continue;
        }
    }

    string cc = maked;
    print(cc);
    int remainingsize = s.size() - maked.size();
    int yahape = -1;
    bool nayaliya = false;

    for(int i = 0; i<=9; i++){
        set<char> temp = taken;
        string tempcc = cc;
        tempcc += (char)(i + '0');
        temp.insert((char)(i + '0'));
        debug(tempcc);
        while(tempcc.size() < s.size()){
            tempcc += (*temp.rbegin());
            debug(*temp.rbegin());
        }

        int tempn = stoi(tempcc);
        debug(i);
        debug(tempn);
        if(tempn >= n){
            yahape = i;
            if(taken.count(i + '0') == 0){
                nayaliya = true;
            }
            taken.insert((char)(i + '0'));
            break;
        }
    }
    debug(yahape);
    debug(nayaliya);
    if(nayaliya == false){
        for(int i = 0; i<=9; i++){
            if(taken.count(i) == 0){
                taken.insert(i + '0');
                break;
            }
        }
    }

    cc += yahape + '0';
    print(cc);
    bool bigtaken = false;
    if(cc.back() > s[cc.size() - 1]){
        bigtaken = true;
    }
    debug(bigtaken);
    bool isback = false;

    // while(cc.size() < s.size()){
    //     if(bigtaken){
    //         cc += (*taken.begin());
    //     }
    //     else{
    //         if(s[cc.size()] == '9'){
    //             isback =  true;
    //             cc.pop_back();
    //             break;
    //         }
    //         char ch = *lower_bound(taken.begin(), taken.end(), s[cc.size()]);
    //         cc += ch;
    //         if(ch > s[cc.size() - 1]){
    //             bigtaken = true;
    //         }
    //     }
    // }

    while(cc.size() < s.size()){
        // yaha pe konsa mincharacter loge 
        for(int i = 0; i<=9; i++){
            string cctemp = cc;
            if(taken.count(i + '0') == 0) continue;
            cctemp += (char)(i + '0');
            while(cctemp.size() < s.size()){
                cctemp += (*taken.rbegin());
            }
            if(stoi(cctemp) >= n){
                cc += (char)(i + '0');
                break;
            }
        } 
    }

    int finalans = stoi(cc);

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
        if(i == 1012){
            solvee();
        }
        else{
            solve();
        }
    }
return 0;
}

