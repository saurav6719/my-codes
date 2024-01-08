#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;

// leetcode -> https://leetcode.com/problems/implement-trie-prefix-tree/

class Node{
    public:
    char data;
    bool terminal;
    unordered_map<char,Node*> children;
    Node(char data){ // node constructor
        this -> data = data;
        this -> terminal = false;
    }
    void makeTerminal(){
        this -> terminal = true;
    }
    bool isTerminal(){
        return (this -> terminal == true);
    }
};
class Trie {
public:


    Node * root;
    Trie() {
        
        root = new Node('\0');
    }

    
    void insert(string word) {
        Node * curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i]; // current character to be check or inserted
            if(curr -> children.count(ch)) curr = curr -> children[ch];
            else {
                Node * child = new Node(ch);
                curr -> children[ch] = child;
                curr = child;
            }
        }
        curr -> makeTerminal();
    }
    
    bool search(string word) {
        Node * curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(! curr -> children.count(ch)) return false;
            else curr = curr -> children[ch];
        }
        if(curr -> terminal == true) return true;
        return false;
    }
    
    bool startsWith(string word) {
        Node * curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(! curr -> children.count(ch)) return false;
            else curr = curr -> children[ch];
        }
        return true;
    }
};

void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    
}
int32_t main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}