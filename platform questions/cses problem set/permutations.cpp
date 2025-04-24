    #include<iostream>
    #include<vector>
    #include<string>
    #include<climits>
    #include<cmath>
    #include<algorithm>
    #include<unordered_map>
    #include<unordered_set>
    #ifndef ONLINE_JUDGE
    #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
    #else
    #define debug(x)
    #endif
    #define endl "\n"
    #define int long long int
    #define mod 1000000007
    #define mn(a,b,c) min(a,min(b,c))
    #define mx(a,b,c) max(a,max(b,c))
    using namespace std;
    void solve(){
        int n;
        cin>>n;
        int cnt = 2;
        if(n>1 and n<4){
            cout<<"NO SOLUTION";
            return;
        }
        vector<int> output(n);

        for(int i = 0; i<=n/2-1; i++){ //odd numbers aa gye
            output[i] = cnt;
            cnt+=2;
        }
        cnt = 1;

        for(int i = n/2;i<n;i++){
            output[i] = cnt;
            cnt+=2;
        }


        for(int  i = 0 ;i < n ; i++){
            cout<<output[i]<<" ";
        }




    }
    int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE
            freopen("Error.txt" , "w" , stderr);
        #endif
        int t;
        //cin>>t;
        t = 1;
        while(t--){
            solve();
        }
    return 0;
    }