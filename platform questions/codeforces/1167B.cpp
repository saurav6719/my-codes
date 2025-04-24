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
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    vector<int> ans;
    set<int> st;
    vector<int> input = {4,8,15,23,16,42};

    int q = 4;
    
    cout<<"? "<<1<<" "<<2<<endl;
    cout<<flush;
    int res1;
    cin>>res1;
    ans.push_back(res1);

    cout<<"? "<<2<<" "<<3<<endl;
    cout<<flush;
    int res2;
    cin>>res2;
    ans.push_back(res2);

    cout<<"? "<<4<<" "<<5<<endl;
    cout<<flush;
    int res3;
    cin>>res3;
    ans.push_back(res3);
    

    cout<<"? "<<5<<" "<<6<<endl;
    cout<<flush;
    int res4;
    cin>>res4;
    ans.push_back(res4);

    vector<int> v(7);

    map<int,pair<int,int> > mp;

    for(int i = 0; i<6; i++){
        for(int j = i+1;j<6; j++){
            int ele = input[i]*input[j];
            mp[ele] = {input[i],input[j]};
        }
    }


    int aa = ans[0];
    int bb = ans[1];

    set<int> st1;
    set<int> st2;

    pair<int,int> aaa = mp[aa];
    st1.insert(aaa.first);
    st1.insert(aaa.second);

    pair<int,int> bbb = mp[bb];
    st2.insert(bbb.first);
    st2.insert(bbb.second);
    for(auto ele : st1){
        if(st2.count(ele)){
            v[2] = ele;
        }
    }


    v[1] = aa/ v[2];
    v[3] = bb/ v[2];

    int cc = ans[2];
    int dd = ans[3];

    set<int> st3;
    set<int> st4;

    pair<int,int> ccc = mp[cc];
    st3.insert(ccc.first);
    st3.insert(ccc.second);

    pair<int,int> ddd = mp[dd];
    st4.insert(ddd.first);
    st4.insert(ddd.second);

    for(auto ele : st3){
        if(st4.count(ele)){
            v[5] = ele;
        }
    }


    v[4] = cc/ v[5];
    v[6] = dd/ v[5];

    cout<<"!";
    for(int i=1; i<=6; i++){
        cout<<" "<<v[i];
    }

    cout<<endl;
    cout<<flush;
    return;

}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

