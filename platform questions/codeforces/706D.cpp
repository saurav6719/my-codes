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
struct TrieNode{
    int val;
    TrieNode * left;
    TrieNode * right;
    TrieNode * parent;
    TrieNode(){
        val = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class Trie{
    TrieNode * root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insertnode(int n){
        TrieNode * temp = root;
        for(int i=30;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit){
                if(temp->right == NULL){
                    temp->right = new TrieNode();
                    temp->right->parent = temp;
                }
                temp = temp->right;
            }else{
                if(temp->left == NULL){
                    temp->left = new TrieNode();
                    temp->left->parent = temp;
                }
                temp = temp->left;
            }
        }
        temp->val = n;
    }
    void deletenode(int n){
        TrieNode * temp = root;
        for(int i=30;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        temp->val = 0;
        while(temp->parent != NULL){
            if(temp->left == NULL && temp->right == NULL){
                TrieNode * par = temp->parent;
                if(par->left == temp){
                    par->left = NULL;
                }else{
                    par->right = NULL;
                }
                delete temp;
                temp = par;
            }else{
                break;
            }
        }
    }
    int query(int n){
        TrieNode * temp = root;
        for(int i=30;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit){
                if(temp->left != NULL){
                    temp = temp->left;
                }else{
                    temp = temp->right;
                }
            }else{
                if(temp->right != NULL){
                    temp = temp->right;
                }else{
                    temp = temp->left;
                }
            }
        }
        return n^temp->val;
    }
};

void solve(){
    int q;
    cin>>q;
    map<int,int> mp;
    Trie Trie;
    Trie.insertnode(0);

    while(q--){
        char type;
        cin>>type;

        if(type == '+'){
            int ele;
            cin>>ele;
            mp[ele]++;
            Trie.insertnode(ele);
        }
        else if(type == '-'){
            int ele;
            cin>>ele;
            mp[ele]--;
            if(mp[ele] == 0) Trie.deletenode(ele);
        }
        else{
            int ele;
            cin>>ele;
            cout<<Trie.query(ele)<<endl;
        }
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

