#include<iostream>
using namespace std;
class SeqStack{
    public:
    SeqStack(int mcap_=10): mtop(0),mcap(mcap_){
        mpStack=new int[mcap];
    }
   ~SeqStack(){
    delete []mpStack;
    mpStack=nullptr;
   }
    private:
   int* mpStack;
   int  mtop;//栈顶(用整形下标表示更方便)
   int mcap;//栈空间大小
   public:
   void push(int val){
    if(mtop==mcap){
        expand(2*mcap);
    }
    mpStack[mtop++]=val;
   }//入栈
   void pop(){
    if(mtop==0){
        throw "Stack is empty!";
        mtop--;
    }
   }//出栈
   int top() const{
      if(mtop==0)
      throw "Stack is empty!";
      return mpStack[mtop-1];
   }//返回栈顶元素
   bool empty() const{
      return mtop==0;
   }//判断栈是否为空
   int size(){
    return mtop;
   }
   private:
   void expand(int size){
    int* p= new int[size];
    memcpy(p,mpStack,mtop*sizeof(int));
    delete []mpStack;
    mpStack=p;
    mcap=size;
   }
};
int main(){
   int arr[]={12,4,56,7,89,31,53,73};
   SeqStack s;
   for(int i:arr){
    s.push(i);
   }
system("pause");
    return 0;
}