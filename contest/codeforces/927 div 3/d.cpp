#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>
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
    char ch;
    cin>>ch;
    
    set<int> S;
    set<int> C;
    set<int> H;
    set<int> D;
    vector<string> ans;

    for(int i = 0 ; i<2*n; i++){
        string ele;
        cin>>ele;
        if(ele[1] == 'S') S.insert(ele[0]);
        if(ele[1] == 'C') C.insert(ele[0]);
        if(ele[1] == 'H') H.insert(ele[0]);
        if(ele[1] == 'D') D.insert(ele[0]);
    }

    set<int> trump;
    if(ch=='S') trump = S;
    if(ch=='C') trump = C;
    if(ch=='D') trump = D;
    if(ch=='H') trump = H;
    bool one = false;
    bool two = false;
    bool three = false;
    bool four = false;
    bool oddc = false;
    bool odds = false;
    bool oddh = false;
    bool oddd = false;
    debug(ch);
    if(ch != 'C' ){
        if(C.size() % 2 == 1) oddc = true;
        for (auto it = C.begin(); it != C.end();) {
            if (C.size() <= 1 and oddc) {
                break;
            }

            string str = "";
            str += *it;
            str += 'C';
            ans.push_back(str);

            // Increment the iterator before erasing
            auto temp = it;
            ++it;

            // Erase the element using the temporary iterator
            C.erase(temp);
        }
        if(C.size() == 1) one = true;
    }

    if(ch != 'D' ){
        if(D.size() % 2 == 1) oddd = true;
        for (auto it = D.begin(); it != D.end();) {
            if (D.size() <= 1 and oddd) {
                break;
            }

            string str = "";
            str += *it;
            str += 'D';
            debug(str);
            ans.push_back(str);

            // Increment the iterator before erasing
            auto temp = it;
            ++it;

            // Erase the element using the temporary iterator
            D.erase(temp);
        }
        if(D.size() == 1) two = true;
    }
    if(ch != 'H' ){
        if(H.size() % 2 == 1) oddh = true;
        for (auto it = H.begin(); it != H.end();) {
            if (H.size() <= 1 and oddh) {
                break;
            }

            string str = "";
            str += *it;
            str += 'H';
            ans.push_back(str);

            // Increment the iterator before erasing
            auto temp = it;
            ++it;

            // Erase the element using the temporary iterator
            H.erase(temp);
        }
        if(H.size() == 1) three = true;
    }
    if(ch != 'S' ){
        if(S.size() % 2 == 1) odds = true;
        
        for (auto it = S.begin(); it != S.end();) {
            if (S.size() <= 1 and odds) {
                break;
            }

            string str = "";
            str += *it;
            str += 'S';
            ans.push_back(str);

            // Increment the iterator before erasing
            auto temp = it;
            ++it;

            // Erase the element using the temporary iterator
            S.erase(temp);
        }
        if(S.size() == 1) four = true;
    }
    int rem = 0;
    vector<int> trump2;
    for(auto ele : trump){
        trump2.push_back(ele);
    }
    int xx = 0;
    if(one) rem++;
    if(two) rem++;
    if(three) rem++;
    if(four) rem++;
    //debug(rem);
    if (ch=='S'){
        if(rem > S.size()){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    if (ch=='C'){
        if(rem > C.size()){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    if (ch=='H'){
        if(rem > H.size()){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    if (ch=='D'){
        if(rem > D.size()){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }

    if(one){
        for(auto ele : C){
            string str = "";
            str += ele;
            str += 'C';
            ans.push_back(str);
            //debug(str);
        }
        
            string str = "";
            str += trump2[xx];
            str += ch;
            ans.push_back(str);
            xx++;
            //debug(str);
            
        
    }
    if(two){
        for(auto ele : D){
            string str = "";
            str += ele;
            str += 'D';
            ans.push_back(str);
            //debug(str);
            
        }
        
            string str = "";
            str += trump2[xx];
            str += ch;
            ans.push_back(str);
            //debug(str);
            xx++;
        
    }
    if(three){
        for(auto ele : H){
            string str = "";
            str += ele;
            str += 'H';
            ans.push_back(str);
            //debug(str);
        }
        
            string str = "";
            str += trump2[xx];
            str += ch;
            ans.push_back(str);
            //debug(str);
            xx++;
        
    }
    if(four){
        for(auto ele : S){
            string str = "";
            str += ele;
            str += 'S';
            ans.push_back(str);
            //debug(str);
        }
        
            string str = "";
            str += trump2[xx];
            str += ch;
            ans.push_back(str);
            //debug(str);
            xx++;
        
    }
    int aa = trump.size() - xx ;
    if(aa & 1){
        cout<<"IMPOSSIBLE";
        return;
    }
    while(xx<trump.size()){
        string str = "";
            str += trump2[xx];
            str += ch;
            ans.push_back(str);
            xx++;
        
    }
    
    for(int i = 0; i<ans.size(); i+=2){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }

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