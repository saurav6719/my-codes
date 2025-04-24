/**
 *    author: Saurav
<<<<<<< HEAD
 *    created: 2025.04.16 21:14:00
=======
 *    created: 2025.02.01 17:26:27
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
 *    We stop at Candidate Master in 2025
 **/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
<<<<<<< HEAD
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
=======
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
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
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
<<<<<<< HEAD
bool check (string &str, int k){
	int n = str.size();
	vector<int> blocks;
    int i = 0;
    while(i<n){
        int j = i;
        while(j<n and str[j] == str[i]){
            j++;
        }
        blocks.push_back(j-i);
        i = j;
    }

	for(auto ele : blocks){
		if(ele >= k){
			return false;
		}
	}
	return true;
}
void solve(){
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;

	// reverse every possible substring 

	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			string temp = str;
			reverse(temp.begin() + i, temp.begin() + j + 1);
			if(check(temp, k)){
				cout<<"YES"<<endl;
				return;
			}
		}
	}

	cout<<"NO"<<endl;
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
=======
void solve(){
    
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
}
/* logic ends */

<<<<<<< HEAD
=======
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

>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
