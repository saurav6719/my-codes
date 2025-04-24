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

// link -> https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Node{
    public: 
    Node * left;  // represents 0
    Node * right; // represnts 1
    Node(){
        this -> left = NULL;
        this -> right = NULL;
    }
};
class Solution {
public:
    int maxXorpair(Node * head, int value){ // finding xor pair maximum value
        int curr_xor = 0;
        Node * curr = head;
        for(int i = 31;i>=0;i--){
            int bit = (value>>i) & 1;   // 0 or 1
            if(bit == 0){ // our target is 1
                if(curr -> right){
                    curr = curr -> right;
                    curr_xor += (1<<i);
                }
                else{
                    curr = curr -> left;
                }
            }
            else{ // our target is 0
                if(curr -> left){
                    curr = curr -> left;
                    curr_xor += (1<<i);
                }
                else{
                    curr = curr -> right;
                }
            }
        }
        return curr_xor;
    }

    void insert(Node * head, int value){
        Node * curr = head;
        for(int i = 31;i>=0;i--){
            int bit = (value>>i) & 1;
            if(bit == 0){
                if(curr -> left == NULL){
                    curr -> left = new Node();
                }
                curr = curr -> left;
            }
            else{
                if(curr -> right == NULL){
                    curr -> right = new Node();
                }
                curr = curr -> right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        Node * head = new Node();
        insert(head, nums[0]);
        int ans = 0;
        for(int i = 1; i<nums.size();i++){
            ans = max(ans, maxXorpair(head,nums[i]));
            insert(head,nums[i]);
        }
        return ans;
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