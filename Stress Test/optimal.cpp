/**
 *    author: Saurav
<<<<<<< HEAD
 *    created: 2025.04.19 00:19:45
=======
 *    created: 2025.03.14 00:27:37
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
 *    We stop at Candidate Master in 2025
 **/

/* includes and all */

<<<<<<< HEAD
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
=======
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
<<<<<<< HEAD
using namespace std;

/* write core logic here */

bool cmp(int a, int b, map<int,int> &mp){
    return mp[a] < mp[b];
}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    set<int> st;

    for(int i = 0; i<n; i++){
        cin>>input[i];
        st.insert(input[i]);
    }

    vector<int> v;
    for(auto ele : st){
        v.push_back(ele);
    }

    int reqmex = -1;

    for(int i = n; i>=0; i--){
        int chhote = lower_bound(v.begin(), v.end(), i) - v.begin();
        chhote--;
        int chahiyeaur = i - chhote - 1;
        if(k>=chahiyeaur){
            reqmex = i;
            break;
        }
    }

    map<int,int> mp;
    for(auto ele : input){
        if(ele >= reqmex){
            mp[ele]++;
        }
    }

    vector<int> v2;
    for(auto ele : input){
        if(ele >= reqmex){
            v2.push_back(ele);
        }
    }

    sort(v2.begin(), v2.end(), [&](int a, int b){
        return cmp(a, b, mp);
    });

    int i = 0;

    while(k-- and i<v2.size()){
        i++;
    }

    set<int> remaining;

    for(int j = i; j<v2.size(); j++){
        remaining.insert(v2[j]);
    }

    int ans = remaining.size();

    cout<<ans<<endl;
=======

/* write core logic here */

class SegmentTree {
	private:
		int n;
		vector<ordered_set<int>> st;
	
		void build(int node, int l, int r, const vector<int> &arr) {
			if (l == r) {
				st[node].insert(arr[l]);
				return;
			}
			int mid = (l + r) / 2;
			build(2 * node + 1, l, mid, arr);
			build(2 * node + 2, mid + 1, r, arr);
			merge(st[2 * node + 1], st[2 * node + 2], st[node]);
		}
	
		void merge(const ordered_set<int> &left, const ordered_set<int> &right, ordered_set<int> &parent) {
			parent = left;  // Copy left child
			for (int x : right) parent.insert(x);  // Merge right child
		}
	
		void updateUtil(int node, int l , int r, int idx, int oldval, int newval) {
			if (l == r) {
				st[node].clear();
				st[node].insert(newval);
				return;
			}
			int mid = (l + r) / 2;
			if (idx <= mid) {
				updateUtil(2 * node + 1, l, mid, idx, oldval, newval);
			} else {
				updateUtil(2 * node + 2, mid + 1, r, idx, oldval, newval);
			}
			st[node].erase(st[node].find(oldval));
			st[node].insert(newval);
		}
	
		int queryUtil(int node, int l, int r, int start, int end, int x) {
			if (start > r || end < l) {
				return 0;
			}
			if (start <= l && r <= end) {
				return st[node].order_of_key(x + 1);
			}
			int mid = (l + r) / 2;
			return queryUtil(2 * node + 1, l, mid, start, end, x) + 
				   queryUtil(2 * node + 2, mid + 1, r, start, end, x);
		}
	
	public:
		SegmentTree(const vector<int> &arr) {
			n = arr.size();
			st.resize(4 * n);
			build(0, 0, n - 1, arr);
		}
	
		void update(int idx, int oldval, int newval) {
			updateUtil(0, 0, n - 1, idx, oldval, newval);
		}
	
		int query(int start, int end, int x) {
			return queryUtil(0, 0, n - 1, start, end, x);
		}

		void prints(){
			for(auto x : st){
				for(auto y : x){
					cout<<y<<" ";
				}
				cout<<endl;
			}
		}
};

struct queries{
	int l , r , x , idx;
};

bool cmp(queries &a, queries &b){
	return a.r < b.r ;
}
void solve(){
	int n;
	cin>>n;
	vector<int> input(n);

	for(auto &x : input){
		cin>>x;
	}

	int q;
	cin>>q;

	vector<queries> query(q);
	for(int i = 0; i<q; i++){
		cin>>query[i].l>>query[i].r>>query[i].x;
		query[i].l-- , query[i].r-- ;
		query[i].idx = i ;
	}

	sort(query.begin(), query.end(), cmp);

	map<int,int> lastoccurence;

	int queryidx = 0;

	vector<int> arr(n, 1e9+5);
	SegmentTree st(arr);
	

	vector<int> ans(q);

	for(int i =0; i<n; i++){
		int curr = input[i];
		if(lastoccurence.find(curr) == lastoccurence.end()){
			st.update(i, 1e9+5, curr);
		}
		else{
			st.update(lastoccurence[curr], curr, 1e9+5);
			st.update(i, 1e9+5, curr);
		}

		lastoccurence[curr] = i;

		while(queryidx < q and query[queryidx].r == i){
			ans[query[queryidx].idx] = st.query(query[queryidx].l, query[queryidx].r, query[queryidx].x);
			queryidx++;
		}
	}

	for(auto x : ans){
		cout<<x<<endl;
	}
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c

}
/* logic ends */

signed main(){
<<<<<<< HEAD
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

=======
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
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
