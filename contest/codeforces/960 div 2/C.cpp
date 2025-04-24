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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);

    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> maxi(n);
    map<int,int> mp;
    int curr = 0;
    for(int i = 0; i<n; i++){
        mp[input[i]]++;
        if(mp[input[i]] >=2){
            curr = max(curr, input[i]);
        }
        maxi[i] = curr;
    }

    print(maxi);

    vector<int> freq(n);
    map<int,int> mp2;

    for(int i= 0; i<n; i++){
        mp2[maxi[i]]++;
        freq[i] = mp2[maxi[i]];
    }

    print(freq);




    int sum = 0;

    for(int i = 0; i<n; i++){
        sum += input[i];
    }

    for(int i = 0; i<n; i++){
        sum += maxi[i];
    }

    vector<int> maxi2(n);
    map<int,int> mp3;
    int curr2 = 0;
    for(int i = 0; i<n; i++){
        mp3[maxi[i]]++;
        if(mp3[maxi[i]] >=2){
            curr2 = max(curr2, maxi[i]);
        }
        maxi2[i] = curr2;
    }

    print(maxi2);


    for(int i = 0; i<n; i++){
        sum += (maxi2[i] * (n-i));
    }

    cout<<sum<<endl;

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

