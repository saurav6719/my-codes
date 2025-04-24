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

void solvee(){
    int n;
    cin>>n;
    string str;
    cin>>str;

    cout<<str<<endl;
}
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    if(n==1 or n==3){
        cout<<"NO"<<endl;
        return;
    }

    if(n==2){
        if(str[0] == str[1]){
            cout<<"RH"<<endl;
            return;
        }
        else {
            cout<<"NO"<<endl;
            return;
        }
    }



    vector<int> north;
    vector<int> south;
    vector<int> west;
    vector<int> east;
    for(int i = 0; i<n; i++){
        if(str[i] == 'N') north.push_back(i);
        if(str[i] == 'E') east.push_back(i);
        if(str[i] == 'W') west.push_back(i);
        if(str[i] == 'S') south.push_back(i);
    }
    vector<char> ans(n);

    print(north);
    print(south);
    print(east);
    print(west);   
    if(north.size() > 0 and north.size() %2 == 1){
        if(south.size() > 0 and south.size() %2 == 1){
            ans[north[0]] = 'R';
            ans[south[0]] = 'R';
            north.erase(north.begin());
            south.erase(south.begin());
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
        
    }

    if(south.size() > 0 and south.size() %2 == 1){
        if(north.size() > 0 and north.size() %2 == 1){
            ans[north[0]] = 'R';
            ans[south[0]] = 'R';
            north.erase(north.begin());
            south.erase(south.begin());
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    
    print(north);
    print(south);

    if(east.size() > 0 and east.size() %2 == 1){
        if(west.size() > 0 and west.size() %2 == 1){
            ans[east[0]] = 'H';
            ans[west[0]] = 'H';
            east.erase(east.begin());
            west.erase(west.begin());
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }

    if(west.size() > 0 and west.size() %2 == 1){
        if(east.size() > 0 and east.size() %2 == 1){
            ans[east[0]] = 'H';
            ans[west[0]] = 'H';
            east.erase(east.begin());
            west.erase(west.begin());
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    
    bool c1 = false;
    for(int i = 0; i<north.size(); i++){
        if(!c1){
            ans[north[i]] = 'R';
            c1 = true;
        }
        else{
            ans[north[i]] = 'H';
            c1 = false;
        }
    }

    bool c2 = false;
    for(int i = 0; i<south.size(); i++){
        if(!c2){
            ans[south[i]] = 'R';
            c2 = true;
        }
        else{
            ans[south[i]] = 'H';
            c2 = false;
        }
    }

    bool c3 = false;
    for(int i = 0; i<east.size(); i++){
        if(!c3){
            ans[east[i]] = 'R';
            c3 = true;
        }
        else{
            ans[east[i]] = 'H';
            c3 = false;
        }
    }

    bool c4 = false;
    for(int i = 0; i<west.size(); i++){
        if(!c4){
            ans[west[i]] = 'R';
            c4 = true;
        }
        else{
            ans[west[i]] = 'H';
            c4 = false;
        }
    }

    for(int i = 0; i<n; i++){
        cout<<ans[i];
    }

    cout<<endl;




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
       solve();
    }
return 0;
}

