#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool Priority(char ch,char top){
    if((ch=='*'||ch=='/')&&(top=='+'||top=='-'))
    return true;
    if(top=='('&&ch!=')')
    return true;
        return false;
    
}
string MiddleToEndExpr(string expr){
  string result;
  stack<char>s;
  for(char ch: expr){
    if(ch<='9'&&ch>='0'){
      result.push_back(ch);
    }
    else{
        for(;;){
        if(s.empty()||ch=='('){
            s.push(ch);
            break;
        }
        else{
           
            char top=s.top();
            if(Priority(ch,top))//比较当前符号和栈顶符号的优先级
            {
                s.push(ch);
                break;//优先级大先入栈
            }
            else{
                s.pop();//优先级小，先出栈，后继续循环比较
                if(top=='(')//ch遇见'）',一直出栈，直到（
                break;
                result.push_back(top);
            }
        
    }
    }
}
  }
  while(!s.empty()){
    result.push_back(s.top());
    s.pop();
  }

}
int main(){








    return 0;
}