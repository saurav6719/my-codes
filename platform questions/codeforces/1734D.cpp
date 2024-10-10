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
bool left(vector<int> &input, int k){
    int n = input.size();
    if(k==0) {
        return true;
    }

    int i = k;
    int sum= 0; 
    sum += input[i];


    int j = k+1;

    int maxi = sum;

    int sum_copy = sum;

    while(j<n){
        sum_copy += input[j];
        j++;
        maxi = max(maxi , sum_copy);
    }

    
    
    while(j<n){
        if(i==0) return true;
        if(sum + input[i-1] >= 0){
            sum += input[i-1];
            i--;
        }

        else{
            sum += input[j]; j++;
            if(sum < 0) return false;
        }
    }   

    return false;
}

bool right(vector<int> &input, int k){
    int n = input.size();
    if(k==n-1) {
        return true;
    }

    int i = k;
    int sum= 0; 
    sum += input[i];

    int j = k-1;
    
    while(j>=0){
        if(i==n-1) return true;
        
        if(sum + input[i+1] >= 0){
            sum += input[i+1];
            i++;
        }
        else{
            sum += input[j]; j--;
            if(sum < 0) return false;
        }
    }   
    return false;
}


void solvee(){
    int n,k;
    cin>>n>>k;
    k--;



    vector<int> input(n);
    for(int i = 0; i <n; i++){
        cin>>input[i];
    }

    cout<<n<<"b"<<k<<"c";
    for(auto ele : input){
        cout<<ele<<"a";
    }
    cout<<endl;
}

void solve(){
    int n,k;
    cin>>n>>k;
    k--;

    vector<int> input(n);
    for(int i = 0; i <n; i++){
        cin>>input[i];
    }

    if(k==0 or k==n-1){
        cout<<"YES"<<endl;
        return;
    }

    //left

    bool xx = left(input, k);
    bool yy = right (input, k);

    if(xx or yy ){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;   


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
        // if(i==469) solvee();
        solve();
    }
return 0;
}

