#include<iostream>
#include<stack>
#include<string>
using namespace std;
int priority(char ch){
    if (ch == '+' or ch == '-') return 1;
    else return 2;
}
string answer(string val1  , string val2, char ch){
    string s= "";
    s.push_back(ch);
    s += val1;
    s += val2;
    return s;
}

int main(){
    string s = "2+6*4/8-3";
    stack<string> val;
    stack <char> op;
    int x = s.size();
    for(int i = 0; i< x; i++){
        if((s[i]) >= 48 and s[i] <= 57){
            val.push(to_string(s[i] -48) );
        }
        else {
            if(op.size() == 0) op.push(s[i]);
            else if(s[i] == '(') op.push(s[i]);
            else if(op.top() == '(') op.push(s[i]);
            else if(s[i] == ')'){
                while(op.top() != '('){
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    char oper = op.top();
                    op.pop();
                    string ans = answer(val1,val2,oper);
                    val.push(ans);  
                }
                op.pop();
            }
            else if(priority(op.top()) < priority(s[i]) ) op.push(s[i]);
            else {
                while(op.size()>0 and priority(op.top()) >= priority(s[i])){
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    char oper = op.top();
                    op.pop();
                    string ans = answer(val1,val2,oper);
                    val.push(ans);
                    
                }
                op.push(s[i]);
            }
        }
    }
    while(val.size() > 1 and op.size() > 0){
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    char oper = op.top();
                    op.pop();
                    string ans = answer(val1,val2,oper);
                    val.push(ans);  
    }
    cout<<val.top()<<endl;
    return 0;
}