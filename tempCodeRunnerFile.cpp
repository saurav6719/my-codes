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
#define printset(s)
#define printpp(v)
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
string f(int swap, char ch){
    if(swap == 1){
        if(ch == 'L') return "R";
        else if(ch == 'R') return "L";
        else if(ch == 'U') return "D";
        else if(ch == 'D') return "U";
        else return string(1, ch);
    }
    else{
        if(ch == 'L') return "L";
        else if(ch == 'R') return "R";
        else if(ch == 'U') return "U";
        else if(ch == 'D') return "D";
        else return string(1, ch);
    }
}

string findPath(int n, int m, vector<vector<char>>& a, int startx, int starty, int goalx, int goaly) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({startx, starty});
    visited[startx][starty] = true;

    vector<vector<char>> parent(n, vector<char>(m, ' '));
    vector<pp> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // R, D, L, U
    char dirChars[] = {'R', 'D', 'L', 'U'};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == goalx && y == goaly) {
            string path;
            while (parent[x][y] != ' ') {
                path += parent[x][y];
                if (parent[x][y] == 'R') y--;
                else if (parent[x][y] == 'D') x--;
                else if (parent[x][y] == 'L') y++;
                else if (parent[x][y] == 'U') x++;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i].first;
            int newY = y + directions[i].second;

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && a[newX][newY] != '*' && !visited[newX][newY]) {
                visited[newX][newY] = true;
                parent[newX][newY] = dirChars[i];
                q.push({newX, newY});
            }
        }
    }
    return ""; // No path found
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    int goalx = -1, goaly = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 'F'){
                goalx = i;
                goaly = j;
                break;
            }
        }
    }

    int currx = 0;
    int curry = 0;

    int swapLR = -1;
    int swapUD = -1;

    if(n==1){
        // i just need to check if LR is swapped or not
        cout<<"R"<<endl<<flush;
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x == 0 and y == 0){
            swapLR = 1;
        }
        else{
            swapLR = 0;
        }

        currx = x;
        curry = y;

        while(currx != goalx and curry != goaly){
            // i need to move right
            cout<<f(swapLR, 'R')<<endl<<flush;
            cin>>x>>y;
            x--;
            y--;
            if(x == goalx and y == goaly){
                break;
            }
            currx = x;
            curry = y;
        }
        return;
    }

    if(m==1){
        // i just need to check if UD is swapped or not
        cout<<"D"<<endl<<flush;
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x == 0 and y == 0){
            swapUD = 1;
        }
        else{
            swapUD = 0;
        }

        currx = x;
        curry = y;

        while(currx != goalx and curry != goaly){
            // i need to move down
            cout<<f(swapUD, 'D')<<endl<<flush;
            cin>>x>>y;
            x--;
            y--;
            if(x == goalx and y == goaly){
                break;
            }
            currx = x;
            curry = y;
        }
        return;
    }

    {
        if(a[0][1] == '.'){
            // swapLR can be found out here 
            cout<<"R"<<endl<<flush;
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            if(x == 0 and y == 0){
                swapLR = 1;
            }
            else{
                swapLR = 0;
            }
            if(swapLR == 0){
                // i am at 0 1 i need to move left
                cout<<"L"<<endl<<flush;
                cin>>x>>y;
                x--;
                y--;
            }
        }
    }
    {
        if(a[1][0] == '.'){
            // swapUD can be found out here 
            cout<<"D"<<endl<<flush;
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            if(x == 0 and y == 0){
                swapUD = 1;
            }
            else{
                swapUD = 0;
            }
            if(swapUD == 0){
                // i am at 1 0 i need to move up
                cout<<"U"<<endl<<flush;
                cin>>x>>y;
                x--;
                y--;
            }
        }
    }

    while(swapLR == -1){
        // go down until you find a . cell in the right 
        if(a[currx][curry + 1] != '*'){
            cout<<"R"<<endl<<flush;
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            if(x == currx and y == curry){
                swapLR = 1;
            }
            else{
                swapLR = 0;
            }
            currx = x;
            curry = y;
            break;
        }
        if(a[currx][curry] == 'F') return;

        cout<<f(swapUD, 'D')<<endl<<flush;
        int x,y;
        cin>>x>>y;
        x--;
        y--;        
        currx = x;
        curry = y;
    }

    while(swapUD == -1){
        // go right until you find a . cell in the down
        if(a[currx + 1][curry] != '*'){
            cout<<"D"<<endl<<flush;
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            if(x == currx and y == curry){
                swapUD = 1;
            }
            else{
                swapUD = 0;
            }
            currx = x;
            curry = y;
            break;
        }
        if(a[currx][curry] == 'F') return;

        cout<<f(swapLR, 'R')<<endl<<flush;
        int x,y;
        cin>>x>>y;
        x--;
        y--;        
        currx = x;
        curry = y;
    }


    // ab dono swaps mil gaye hain
    // ab BFS se path nikaal lo
    string path = findPath(n, m, a, currx, curry, goalx, goaly);
    // ab path ko print kar do
    for(char ch : path){
        cout<<f(swapLR, ch)<<endl<<flush;
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x == goalx and y == goaly){
            break;
        }
        currx = x;
        curry = y;
    }
    // ab last cell tak pahunch gaye hain
    return;
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

