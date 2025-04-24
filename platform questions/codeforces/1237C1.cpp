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

struct point{
    int x;
    int y;
    int z;
};

bool cmp(pair<point, int>  &a, pair<point, int> &b){
    if(a.first.x == b.first.x){
        if(a.first.y == b.first.y){
            return (a.first.z) < (b.first.z);
        }
        else{
            return (a.first.y) < (b.first.y);
        }
    }
    return (a.first.x) < (b.first.x);
}

bool check(const point& a, const point& b, const point& check1) {
    // Compute the bounding box coordinates
    int minX = std::min(a.x, b.x);
    int maxX = std::max(a.x, b.x);
    int minY = std::min(a.y, b.y);
    int maxY = std::max(a.y, b.y);
    int minZ = std::min(a.z, b.z);
    int maxZ = std::max(a.z, b.z);

    // Check if check1 is outside the bounding box
    if (check1.x < minX || check1.x > maxX ||
        check1.y < minY || check1.y > maxY ||
        check1.z < minZ || check1.z > maxZ) {
        return true; // check1 is outside the bounding box
    }

    return false; // check1 is inside or on the boundary of the bounding box
}

int duri (point &a, point &b){
    return ((abs(a.x - b.x)) + (abs(a.y - b.y)) + (abs(a.z - b.z)));
}


void solve(){
    int n;
    cin>>n;

    vector<pair<point, int> > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first.x;
        cin>>input[i].first.y;
        cin>>input[i].first.z;
        input[i].second = i;
    }

    vector<int> distance(n+5);
    while(input.size() > 2){
        point a = input[0].first;
        int dist = INT_MAX;
        int currpt = -1;
        for(int i = 1;i<input.size(); i++){
            if(duri(a, input[i].first) < dist){
                dist = duri(a, input[i].first);
                currpt = i;
            }
        }   

        cout<<input[0].second+1<<" "<<input[currpt].second+1<<endl;
        input.erase(input.begin());
        input.erase(input.begin()+currpt-1);
    }

    cout<<input[0].second+1<<" "<<input[1].second+1<<endl;



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

