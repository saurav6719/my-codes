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
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
class Node{
    public:
    char data;
    bool terminal;
    unordered_map<char,Node*> children;
    int wordsStartingWith;
    int wordsEndingWith;
    Node(char data){
        this -> data = data;
        this -> terminal = false;
        this -> wordsStartingWith = 0;
        this -> wordsEndingWith = 0;
    }


};
class Trie{

    public:
    Node * root;
    Trie(){
        // Write your code here.
        root = new Node('\0');
    }


    void insert(string &word){
        // Write your code here.
        Node * curr = root;
        for(int i =0; i<word.size();i++){
            char ch = word[i];
            if(curr -> children.count(ch)) {
                curr = curr -> children[ch];
                curr -> wordsStartingWith++;
            }
            else{
                Node * child = new Node(ch);
                curr -> children[ch] = child;
                curr = child;
                curr -> wordsStartingWith++;
            }
        }
        curr -> terminal = true;
        curr -> wordsEndingWith++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node * curr = root;
        int ans = INT_MAX;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(curr -> children.count(ch) == 0) return 0;
            else{
                curr = curr -> children[ch];
                ans = min(ans, curr -> wordsStartingWith);
            }
        }
        ans = min(ans, curr -> wordsEndingWith);
        return ans;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node * curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(curr -> children.count(ch) == 0) return 0;
            else{
                curr = curr -> children[ch];
            }
        }
        return curr -> wordsStartingWith;
    }

    void erase(string &word){
        // Write your code here.
        Node * curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            curr = curr -> children[ch];
            curr -> wordsStartingWith--;
        }
        curr -> wordsEndingWith--;
    }
};

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