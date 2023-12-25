#include <iostream>
using namespace std;
int f(int *array, int index, int lenght){
    if(index == (lenght-1)) return array[index];
    return max(array[index] , f(array, index+1 , lenght));
    
}
int main(){
    int arr[]={2,42,23,29,51};
    cout<<f(arr, 0, 5);
}

//logic
//hmm first index ko baki sab k maximum se compare kr rhe but baki sab k amaximum bhi hame nhi pta to hmm recursion se baki sab ka maximum nikal rhe . 
//base case hmara ye hai ki last element jo hoga yo to khud me maximum hi hoga n 