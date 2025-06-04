/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
 *    We stop at Candidate Master in 2025
 **/

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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
struct soldier{
    int cost;
    int damage;
    int health;
};
struct CustomCompare {
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<0>(a) != get<0>(b))
            return get<0>(a) > get<0>(b); // ascending by first
        if(get<1>(a)  != get<1>(b))
            return get<1>(a) < get<1>(b);     // descending by second
        return get<2> (a) > get<2> (b);
    }
};

bool sortcmp(soldier &a, soldier &b){
    if(a.cost != b.cost){
        return a.cost < b.cost;
    }
    if(a.damage * a.health != b.damage * b.health){
        return a.damage * a.health > b.damage * b.health;
    }
    return a.health > b.health;
}
void solve(){
    int n,c;
    cin>>n>>c;

    vector<soldier> v(n);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CustomCompare> pq;

    for(int i = 0; i<n; i++){
        cin>>v[i].cost>>v[i].damage>>v[i].health;
    }

    sort(v.begin(), v.end(), sortcmp);

    for(int i= 0; i<n; i++){
        pq.push({v[i].cost , v[i].damage * v[i].health, i});
        debug(i);
        debug(v[i].cost);
    }

    int bnachuke = 0;

    vector<pp> capacityofsoldiers;

    while(!pq.empty()){
        auto [cost, capacity, index] = pq.top();
        pq.pop();

        debug(cost);
        debug(capacity);
        debug(index);

        if(capacity < bnachuke + 1){
            // push next 
            int currstrength = capacity;
            int toadd = bnachuke + 2 - currstrength;
            int unitsrequired = toadd / (v[index].damage * v[index].health);
            if(toadd % (v[index].damage * v[index].health) != 0) unitsrequired++;

            int nextcost = cost + (v[index].cost * unitsrequired);
            if(nextcost > c) continue;
            int nextcapacity = capacity + (v[index].damage * v[index].health * unitsrequired);
            int nextindex = index;
            pq.push({nextcost, nextcapacity, nextindex});
            continue;
        }
        if(capacity == bnachuke + 1 and bnachuke != 0) {
            // push next 
            int currstrength = capacity;
            int toadd = bnachuke + 2 - currstrength;
            int unitsrequired = toadd / (v[index].damage * v[index].health);
            if(toadd % (v[index].damage * v[index].health) != 0) unitsrequired++;

            int nextcost = cost + (v[index].cost * unitsrequired);
            if(nextcost > c) continue;
            int nextcapacity = capacity + (v[index].damage * v[index].health * unitsrequired);
            int nextindex = index;
            pq.push({nextcost, nextcapacity, nextindex});
            continue;
        }

        capacityofsoldiers.push_back({capacity - 1, cost});
        bnachuke = capacity - 1;

        {
            // push next 
            // int nextcost = cost + v[index].cost;
            // int nextcapacity = capacity + v[index].damage * v[index].health;
            // int nextindex = index;
            // if(nextcost <= c) pq.push({nextcost, nextcapacity, nextindex});

            //
            int currstrength = capacity;
            int toadd = bnachuke + 2 - currstrength;
            int unitsrequired = toadd / (v[index].damage * v[index].health);
            if(toadd % (v[index].damage * v[index].health) != 0) unitsrequired++;

            int nextcost = cost + (v[index].cost * unitsrequired);
            if(nextcost > c) continue;
            int nextcapacity = capacity + (v[index].damage * v[index].health * unitsrequired);
            int nextindex = index;
            pq.push({nextcost, nextcapacity, nextindex});
        }
    }
    printpp(capacityofsoldiers);
    vector<int> temp;
    for(auto ele : capacityofsoldiers){
        temp.push_back(ele.first);
    }

    int m;
    cin>>m;
    while(m--){
        int damage;
        int health;
        cin>>damage>>health;

        if(temp.empty()){
            cout<<-1<<" ";
            continue;
        }

        if((damage*health) > temp.back()){
            cout<<-1<<" ";
            continue;
        }

        int strength = damage * health;

        int lb = lower_bound(temp.begin(), temp.end(), strength) - temp.begin();

        cout<<capacityofsoldiers[lb].second<< " ";
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

