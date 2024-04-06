// /*
//   ------------------------------------------
//  |                                        |
//  |      Code Crafted by Saurav     |
//  |                                        |
//   ------------------------------------------
//     \        ,     ,        /
//       \      |     |      /
//          \   \___/   /
//            \  -----  /
//              \_____/
  
//   Happy coding! 
// */

// /* includes and all */

// #include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
// #define print(v) do { \
//                     cout << "vect--" << #v << " = [ "; \
//                     for (int i = 0; i < v.size(); i++) { \
//                         cout << v[i] << " "; \
//                     } \
//                     cout << " ]" << endl; \
//                 } while(0)
// #else
// #define debug(x)
// #define print(v)
// #endif
// #define endl "\n"
// #define int long long int
// #define mod 1000000007
// #define mn(a,b,c) min(a,min(b,c))
// #define mx(a,b,c) max(a,max(b,c))
// using namespace std;

// /* write core logic here */
// void solve(){
//     int correct[] ={4,2,1,4,4,4,1,1,3,2,4,4,3,1,3,1,2,2,2,1,1,4,1,4,3,2,2,2,3,1,1,1,3,2,1,3,2,1,1,3,1,3,4,2,1,3,4,3,4,1,4,2,2,3,3,2,2,1,3,3,4,2,4,3,1,1,4,2,4,4,2,4,3,2,1};
//     cout<<sizeof(correct)/ sizeof(correct[0]); 
//     vector<int> attempt (200,-1);
//     for(int i = 1; i<=75; i++){
//         int ele;
//         cin>>ele;
//         int val; cin>>val;
//         attempt[200-ele] = val;
//     }

//     //print(attempt);
//     int start = -1;
//     for(int i = 0; i<199;i++){
//         if(attempt[i] != -1){
//             start = i ;
//             break;
//         }
//     }

//     debug(start);
//     int attemptstart = 34;
//     int correctstart = 74;
//     int marks = 0;
//     while(correctstart >=0){
//         if(correct[correctstart] == attempt[attemptstart]){
//             marks += 4;
//         }
//         else marks -=1;

//         attemptstart++;
//         correctstart--;
//     }

//     cout<<marks;

// }
// /* logic ends */

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt" , "w" , stderr);
//     #endif
//     int t;
//     //cin>>t;
//     t = 1;
//     while(t--){
//         solve();
//     }
// return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> correctOptions = {4, 2, 1, 4, 4, 4, 1, 1, 3, 2, 4, 4, 3, 1, 3, 1, 2, 2, 2, 1, 1, 4, 1, 4, 3, 2, 2, 2, 3, 1, 1, 1, 3, 2, 1, 3, 2, 1, 1, 3, 1, 3, 4, 2, 1, 3, 4, 3, 4, 1, 4, 2, 2, 3, 3, 2, 2, 1, 3, 3, 4, 2, 4, 3, 1, 1, 4, 2, 4, 4, 2, 4, 3, 2, 1};
    vector<int> markedOptions = {3, 4, 2, 1, 4, 2, 3, 2, 4, 3, 3, 4, 2, 4, 4, 2, 3, 4, 3, 4, 2, 1, 4, 2, 1, 3, 2, 3, 3, 1, 2, 1, 3, 4, 2, 3, 2, 4, 3, 2, 2, 4, 4, 2, 4, 4, 2, 4, 3, 3, 3, 2, 2, 2, 1, 3, 4, 2, 4, 2, 4, 3, 2, 2, 2, 3, 4, 4, 3, 2, 4, 3, 4, 3, 4, 3, 2, 4, 4, 3, 4, 4, 3, 4, 2, 4, 3};

    int totalMarks = 0;

    // Check each answer
    for (size_t i = 0; i < correctOptions.size(); ++i) {
        if (correctOptions[i] == markedOptions[i]) {
            // Correct answer
            totalMarks += 4;
        } else {
            // Incorrect answer
            totalMarks -= 1;
        }
    }

    cout << "Total Marks: " << totalMarks << endl;

    return 0;
}


