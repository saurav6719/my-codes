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
    map<string,int> firsttwo;
    map<string,int> lasttwo;
    map<string,int> firstlast;
    map<string,int> all;

    int ans = 0;
    

    int i = 0;
    int j = 1;
    int k = 2;

    while(k<n){
        string ft = "";
        string lt = "";
        string fl = "";
        string al = "";
        ft += to_string(input[i]);
        ft += 'a';
        ft += to_string(input[j]);
        ft += 'b';
        //debug(ft);

        lt += to_string(input[j]);
        lt += 'c';
        lt += to_string(input[k]);
        lt += 'd';
        //debug(lt);
        

        fl += to_string(input[i]);
        fl += 'e';
        fl += to_string(input[k]);
        fl += 'f';
       // debug(fl);

        al += to_string(input[i]);
        al += 'g';
        al += to_string(input[j]);
        al += 'h';
        al += to_string(input[k]);
        al += 'i';
        //debug(al);

        

        if(firsttwo.count(ft)){
            ans += firsttwo[ft];
            //debug(ans);
            if(all.count(al)){
                ans -= all[al];
            }
            //debug(ans);
        }

        firsttwo[ft]++;

        if(lasttwo.count(lt)){
            ans += lasttwo[lt];
            if(all.count(al)){
                ans -= all[al];
            }
        }

        lasttwo[lt]++;

        if(firstlast.count(fl)){
            ans += firstlast[fl];
            if(all.count(al)){
                ans -= all[al];
            }
        }

        firstlast[fl]++;

        i++;j++;k++;
        //debug(ans);
        all[al]++;
    }
    cout<<ans<<endl;
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

