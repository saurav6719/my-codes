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
        int n,k;
        cin>>n>>k;
        int start = 1;
        int gap = 2;
        int ans;
        while(k>0){
            int nums = (n+start)/gap;
            if(nums<k) {
                k-=nums;
                start *=2;
                gap *=2;
            }
            else{
                int start2= start;
                int gap2 = gap;
                for(int i = 2; i<=k; i++){
                    start2 += gap2;
                }
                ans = start2;
                break;
            }
        }
        cout<<ans<<endl;

    }
    int32_t main(){
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