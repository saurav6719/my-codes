#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
void toh(int n, char source, char destination, char helper){ // a source b helper c destination
 if(n==0) return ;
    toh(n-1 , source, helper , destination );
    cout<<source<<" "<<destination<<endl;
    toh(n-1 , helper , destination , source);
}
int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    toh(n, '1', '3' , '2');
    return 0;
}