#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Array{
  public:
  Array(int size=10):mCap(size),mCur(0){
    mpArr=new int[mCap]();
  }
  ~Array(){
    delete[]mpArr;
    mpArr=nullptr;
  };
  public:
  void push_back(int val){
    if(mCur==mCap){
     expand(2*mCap);
    }
    mpArr[mCur++]=val;
  };//末尾添加元素
  void pop_back(){
    if(mCur==0)return;
    mCur--;
  };//末尾删除元素
  void insert(int pos,int val){
    if(pos<=0||pos>mCur){
      return;
    }
    if(mCur==mCap){
      expand(2*mCap);
    }
    for(int i=mCur-1;i>=pos-1;i--){
      mpArr[i+1]=mpArr[i];
    }
    mpArr[pos-1]=val;
  };//按位置添加元素
  void erase(int pos){
    if(pos<=0||pos>=mCur){
      return;
    }
    for(int i=pos;i<mCur;i++){
      mpArr[i-1]=mpArr[i];
    }
    mCur--;
  };//按位置删除
  int find(int val){
         for(int i=0;i<mCur;i++){
          if(mpArr[i]==val)return i;
         }
        return -1;
  };//查询元素
  void show()const{
    for(int i=0;i<mCur;i++){
      cout<<mpArr[i]<<" ";
    }
    cout<<endl;
  }
  private:
  void expand(int size){
    int* p=new int[size]();
    memcpy(p,mpArr,sizeof(int)*mCap);
    delete[]mpArr;
    mpArr=p;
    mCap=size;
  }
  private:
  int* mpArr;//指针指向可扩容数组内存
  int mCap;//容量
  int mCur;//数组中有效元素个数
};
int main(){
   Array arr;
   srand(time(NULL));
   for(int i=0;i<10;i++){
    arr.push_back(rand()%100);
   }
   arr.show();
    arr.insert(1,100);
    arr.show();
    arr.insert(10,200);
    arr.show();
    arr.pop_back();
    arr.show();
    arr.erase(1);
    arr.show();
   system("pause");
  return 0;
}