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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int big = max(a,b);
        int small = min(a,b);

        int diff = big - small;
        //debug(diff);
        bool one = false;
        bool two = false;
        if(diff > 6){
            for(int i = big ; (i<= small + 12); i++){
                if((i% 12 == c%12) or (i%12 == d%12)){
                    if(one == false) one = true;
                    else two = true;
                }
            }
        }
        else{
            for(int i = small ; i<=big; i++){
                if(i% 12 == c%12 or i%12 == d%12){
                    if(one == false) one = true;
                    else two = true;
                }
            }
        }

        if((one == false and two == false) or (one == true and two == true)) {
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;



        
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

