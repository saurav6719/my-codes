/**
 *    author: Saurav
 *    created: 2024.11.09 13:30:33
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
    int xx = log2(n);

    if(n==2){
        cout<<1<<endl;
        cout<<0<<endl;
        return;
    }

    if(n==3){
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }


    cout<<xx<<endl;
    int curr = 1; 

    

    int currentnumberofbacteria = 1;
    for(int i = 0; i < xx-2; i++){
        currentnumberofbacteria += curr;
        cout<<curr<<" ";
        curr *= 2;
    }

    int madetotal = 2*currentnumberofbacteria-1;

    debug(madetotal);

    int requiredbacteria = n - (pow(2, xx) - 1);
    debug(requiredbacteria);

    if(requiredbacteria <= currentnumberofbacteria){
        cout<<0<<" ";

        int uptilnow = madetotal + currentnumberofbacteria;

        debug(uptilnow);
        int tomake = n - uptilnow;

        cout<<requiredbacteria<<" ";
    }

    else if(requiredbacteria > currentnumberofbacteria and requiredbacteria < 2*currentnumberofbacteria){
        cout<<requiredbacteria - currentnumberofbacteria<<" ";
        currentnumberofbacteria += requiredbacteria - currentnumberofbacteria;
        int uptilnow = madetotal + currentnumberofbacteria;
        int tomake = n - uptilnow;

        int extramake = tomake - currentnumberofbacteria;

        cout<<extramake<<" ";
    }

    else{
        cout<<currentnumberofbacteria<<" ";
        currentnumberofbacteria += currentnumberofbacteria;
        int uptilnow = pow(2, xx) - 1;
        int tomake = n - uptilnow;


        int extramake = tomake - currentnumberofbacteria;

        cout<<extramake<<" ";

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

