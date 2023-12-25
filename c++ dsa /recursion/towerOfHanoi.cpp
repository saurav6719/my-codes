#include<iostream>
using namespace std;
void toh(int n, char source, char destination, char helper){ // a source b helper c destination
 if(n==0) return ;
    toh(n-1 , source, helper , destination );
    cout<<source<<" -> "<<destination<<endl;;
    toh(n-1 , helper , destination , source);
}
int main(){
    toh(3, 'A', 'C' , 'B');
    return 0;
}