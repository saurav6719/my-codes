#include<iostream>
using namespace std;
bool palindrome(int num, int *temp){
    if(num>=0 and num<=9){
        int lastDigitOfTemp = (*temp % 10);
        *temp/=10;
        return (num == lastDigitOfTemp);
        
    }
    bool result= (palindrome(num/10 , temp) and ((num%10) == ((*temp) % 10)));
    *temp/=10;
    return result;
    

}
int main(){
    int num=12621;
    int another_num=num;
    int *temp=&another_num;
    cout<<palindrome(num, temp);

    return 0;
}