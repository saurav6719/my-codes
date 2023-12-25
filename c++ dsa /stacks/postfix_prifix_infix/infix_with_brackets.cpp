#include<iostream>
#include<stack>
#include<string>
using namespace std;
int priority(char ch){
    if (ch == '+' or ch == '-') return 1;
    else return 2;

}
int answer(int a , int b, char oper){
    if (oper == '+' ) return a + b;
    else if (oper == '-' ) return a - b;
    else if (oper == '*' ) return a * b;
    else return a / b;
}

int main(){
    string s = "((8 + 6) - 14 / 7) - (( 4 + 3 ) * 5) + 9 * 3";
    stack<int> val;
    stack <char> op;
    int x = s.size();
    for(int i = 0; i< x; i++){
        if((s[i]) >= 48 and s[i] <= 57){
            val.push(s[i] -48 );
        }
        else {
            if(op.size() == 0) op.push(s[i]);
            else if(s[i] == '(') op.push(s[i]);
            else if(op.top() == '(') op.push(s[i]);
            else if(s[i] == ')'){
                while(op.top() != '('){
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    char oper = op.top();
                    op.pop();
                    int ans = answer(val1,val2,oper);
                    val.push(ans);  
                }
                op.pop();
            }
            else if(priority(op.top()) < priority(s[i]) ) op.push(s[i]);
            else {
                while(op.size()>0 and priority(op.top()) >= priority(s[i])){
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    char oper = op.top();
                    op.pop();
                    int ans = answer(val1,val2,oper);
                    val.push(ans);
                    
                }
                op.push(s[i]);
            }
        }
    }
    while(val.size() > 1 and op.size() > 0){
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    char oper = op.top();
                    op.pop();
                    int ans = answer(val1,val2,oper);
                    val.push(ans);  
    }

    cout<<val.top();
    
    

    return 0;
}