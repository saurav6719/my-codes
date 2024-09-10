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

class Transaction{
    public: 
    map<string, set<string> > userbank;
    set<string> username;
    map<string, set<int> > userstimestamp;
    set<string> banksname;
    map<string ,map<int , int> > timestampbalance;
    map<string, int> userscurrentbalance;
    // set<int> 
    

    void initialise(vector<string> names, vector<int> startbalance, vector<vector<string> > banks){
        int n = names.size();
        for(int i = 0; i<n; i++){

            string user = names[i];
            userstimestamp[user].insert(0);
            username.insert(user);
            int startbb = startbalance[i];
            userscurrentbalance[user] = startbb;
            timestampbalance[user][0] = startbb;
            for(int j = 0; j<banks[i].size(); j++){
                userbank[user].insert(banks[i][j]);
                banksname.insert(banks[i][j]);
            }
        }
    }

    string post(int timestamp, string sendersname, string recieversname, int amount){
        if(banksname.count(sendersname) and banksname.count(recieversname)){
            return "FAILURE";
        }

        if(banksname.count(sendersname) and userbank[recieversname].count(sendersname) == 0){
            return "FAILURE";
        }
        if(banksname.count(recieversname) and userbank[sendersname].count(recieversname) == 0){
            return "FAILURE";
        }

        if(banksname.count(sendersname) and username.count(sendersname)){
            return "FAILURE";
        }

        if(banksname.count(recieversname) and username.count(recieversname)){
            return "FAILURE";
        }

        

        if(banksname.count(sendersname) == 0){
            if(userscurrentbalance[sendersname] < amount ){
                return "FAILURE";
            }
        }

        if(username.count(sendersname)){

            // cout<<"GHSUGIQ"<<endl;
            userscurrentbalance[sendersname] -= amount;
            timestampbalance[sendersname][timestamp] = userscurrentbalance[sendersname];
            userstimestamp[sendersname].insert(timestamp);
        }

        if(username.count(recieversname)){
            userscurrentbalance[recieversname] += amount;
            timestampbalance[recieversname][timestamp] = userscurrentbalance[recieversname];
            userstimestamp[recieversname].insert(timestamp);

            // cout<<"HJKH"<<endl;

            for(auto ele2 : userstimestamp[recieversname]){
                debug(ele2);
            }
        }

        return "SUCCESS";
    }

    string get (int timestamp, string currusername){

        if(username.count(currusername) == 0){
            return "FAILURE";
        }

        set<int> st = userstimestamp[currusername];
        for(auto ele : st){
            debug(ele);
        }
        auto  lb = userstimestamp[currusername].lower_bound(timestamp);
        if(lb != userstimestamp[currusername].end() and *lb == timestamp) lb++;
        lb--;
        int time = *(lb);
        
        int money = timestampbalance[currusername][time];
        return to_string(money) ;
    }
};
void solve(){
    int n;
    cin>>n;
    int initcnt = 0;
    vector<string> commands(n);

    for(int i = 0; i<n; i++){
        cin>>commands[i];
        
    }

    print(commands[0]);

    vector<string> ipg;

    vector<string> names;
    vector<int> startbalance;
    vector<vector<string> > banks;



    Transaction T;

    // cout<<"YES"<<endl;

    for(auto str : commands){
        string cmd = "";

        int i = 0;
        while(str[i] != ','){
            cmd += str[i];
            i++;
        }
        i++;

        print(cmd);

        if(cmd == "INIT"){
            ipg.push_back("INIT");
            initcnt ++;
            string name = "";
            
            while(i<str.size() and str[i] != ','){
                name += str[i];
                i++;
            }

            names.push_back(name);

            i++;
            string startb = "";

            while(str[i] != ','){
                startb += str[i];
                i++;
            }



            i++;

            int startbbb = stoi(startb);

            startbalance.push_back(startbbb);

            vector<string> userbank;
            
            while(i<str.size()){
                int j = i;
                string currbank ="";
                while(j<str.size() and str[j] != ','){
                    currbank += str[j];
                    j++;
                }
                userbank.push_back(currbank);
                i = j+1;
            }

            banks.push_back(userbank);
        }



        else if(cmd == "POST"){
            if(ipg.back() == "INIT"){
                T.initialise(names, startbalance, banks);
            }
            ipg.push_back("POST");

            string timestamp = "";

            while(i<str.size() and str[i] != ','){
                timestamp += str[i];
                i++;
            }

            print(timestamp);

            int timestampint = stoi(timestamp);

            i++;

            string sendersname = "";

            while(i<str.size() and str[i] != ','){
                sendersname += str[i];
                i++;
            }

            i++;

            string recieversname = "";

            while(i<str.size() and str[i] != ','){
                recieversname += str[i];
                i++;
            }

            print(sendersname);
            print(recieversname);

            i++;

            string amount = "";

            while(i<str.size() and str[i] != ','){
                amount += str[i];
                i++;
            }

            i++;

            int amountint = stoi(amount);

            string ans = T.post(timestampint,  sendersname,  recieversname, amountint);

            cout<<ans<<endl;

        }
        else{
            if(ipg.back() == "INIT"){
                T.initialise(names, startbalance, banks);
            }
            ipg.push_back("GET");

            string timestamp = "";

            while(i<str.size() and str[i] != ','){
                timestamp += str[i];
                i++;
            }

            int timestampint = stoi(timestamp);

            i++;

            string getuser = "";

            while(i<str.size() and str[i] != ','){
                getuser += str[i];
                i++;
            }

            cout<<T.get(timestampint, getuser)<<endl;
        }
    }


    for(auto ele4 : T.username){
        print(ele4);
    }

    for(auto ele3 : T.banksname){
        print(ele3);
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

