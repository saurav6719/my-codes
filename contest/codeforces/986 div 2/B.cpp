/**
 *    author: Saurav
 *    created: 2024.11.10 21:03:56
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

int countTermsLessThan(int a, int d, int size, int c) {
    // If the common difference is zero, check if the first term is less than c
    if (d == 0) {
        if (a < c) return size; // All terms are the same and less than c
        else return 0;          // All terms are the same but not less than c
    }

    // Calculate the maximum n such that the n-th term is less than c
    int n_max = floor((double)(c - a) / d + 1);

    // The result is the minimum of n_max and the size of the AP
    return min(n_max, size);
}


void solve(){
    int n,b,c;
    cin>>n>>b>>c;

    if(b==0){
        if(c>=n-2 and c< n){
            cout<<n-1<<endl;
            return;
        }
        else if(c>= n){
            cout<<n<<endl;
            return; 
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }

    int start = c;
    int end = c + (n-1) * b;

    int perstart = 0;
    int perlast = n-1;

    int chotethann = 0;


    int xx = n - start;

    if(xx<0){
        cout<<n<<endl;
        return;
    }
    else{
        int chote = xx / b;
        if(xx%b!=0){
            chote++;
        }

        chotethann = chote;
        cout<<n-chotethann<<endl;
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

