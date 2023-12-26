#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

bool customComparator(const std::pair<std::pair<int, int>, int>& a, const std::pair<std::pair<int, int>, int>& b){
    if (a.first.first != b.first.first) {
        return a.first.first > b.first.first; // Sort by decreasing order of first.first
    } else {
        return a.first.second > b.first.second; // If first.first is the same, sort by decreasing order of first.second
    }
    }
int main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        vector<int> alice_input(n);
        for(int i=0;i<n;i++){
            cin>>alice_input[i];
        }
        vector<int> bob_input(n);
        for(int i=0;i<n;i++){
            cin>>bob_input[i];
        }
        vector<pair<pair<int,int> , int> > alice(n);
        vector<pair<pair<int,int> , int> > bob(n);

        for(int i = 0; i<n; i++){
            (alice[i].first).first = alice_input[i];
            (alice[i].first).second = bob_input[i]; 
            alice[i].second = i;
        }

        for(int i = 0; i<n; i++){
            (bob[i].first).first = bob_input[i];
            (bob[i].first).second = alice_input[i]; 
            bob[i].second = i;
        }

        
        
        

        sort(bob.begin(), bob.end(),customComparator);
        sort(alice.begin(), alice.end(),customComparator);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i<n and j<n and alice[i].first.first == bob[j].first.second and alice[i].first.second == bob[j].first.first) {
                    alice[i].second = j;
                    bob[j].second = i;
                }
            }
        }
    

        int i = 0;
        int j = 0;
        int chance = 0;
        while(i<n and j<n){
            while(i<n and (alice[i].first.first == 0 or alice[i].first.second ==0)) i++;
            if(i>=n) break;
            while(j<n and (bob[j].first.first == 0 or bob[j].first.second == 0)) j++;
            if(j>=n) break;
            if(chance %2 ==0){
                if(alice[i].first.first < bob[j].first.first){
                    bob[j].first.first = 0;
                    bob[j].first.second --;
                    int temp = bob[j].second;
                    alice[temp].first.first --;
                    alice[temp].first.second = 0;
                }
                else if(alice[i].first.first == bob[j].first.first){
                        int sub = 0;
                        // samne wali ki le lo 
                        sub +=0;
                        sub -= bob[j].first.second - 1;

                        int sub2 = 0;
                        // khud ko bachao
                        sub2 += 0;
                        sub2 -= alice[i].first.second - 1;
                        if(sub > sub2){ // maa chod do 
                            bob[j].first.first = 0;
                            bob[j].first.second --;
                            int temp = bob[j].second;
                            alice[temp].first.first --;
                            alice[temp].first.second = 0;
                        }
                        else{
                            alice[i].first.first --;
                            alice[i].first.second = 0;
                            int temp = alice[i].second;
                            bob[temp].first.first = 0;
                            bob[temp].first.second --;
                        }
                        
                }
                else{
                    alice[i].first.first --;
                    alice[i].first.second = 0;
                    int temp = alice[i].second;
                    bob[temp].first.first = 0;
                    bob[temp].first.second --;
                }
                chance++;
            }
            else{
                if(bob[j].first.first < alice[i].first.first){
                    alice[i].first.first = 0;
                    alice[i].first.second --;
                    int temp = alice[i].second;
                    bob[temp].first.first --;
                    bob[temp].first.second = 0;
                }
                else if(bob[j].first.first == alice[i].first.first){
                        int sub = 0;
                        // samne wali ki le lo
                        sub +=0;
                        sub -= alice[i].first.second - 1;

                        int sub2 = 0;
                        sub2 += 0;
                        sub2 -= bob[j].first.second - 1;
                        if(sub < sub2){ // maa chod do 
                            alice[i].first.first = 0;
                            alice[i].first.second --;
                            int temp = alice[i].second;
                            bob[temp].first.first --;
                            bob[temp].first.second = 0;
                        }
                        else{
                            bob[j].first.first --;
                            bob[j].first.second = 0;
                            int temp = bob[j].second;
                            alice[temp].first.first = 0;
                            alice[temp].first.second --;
                        }
                        
                }
                else{
                    bob[j].first.first --;
                    bob[j].first.second = 0;
                    int temp = bob[j].second;
                    alice[temp].first.first = 0;
                    alice[temp].first.second --;
                }
                chance++;
            }
        }
        long long int ans = 0;
        for(int k = 0;k<n;k++){
            ans+= alice[k].first.first;
            ans-= alice[k].first.second;
        }
        cout<<ans<<endl;

    }



    return 0;
}