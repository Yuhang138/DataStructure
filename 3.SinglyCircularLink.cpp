#include<iostream>
using namespace std;
//单项循环链表
   class SinglyCircleLink{
    public:
    SinglyCircleLink(){
    head_=new Node();
    Tail_=head_;
    head_->next_=head_;
    }
    ~SinglyCircleLink(){
        Node* p=head_->next_;
        while(p!=head_){
            head_->next_=p->next_;
            delete p;
            p=head_->next_;
        }
        delete head_;
    }
    public:
void InsertTail(int val){
   Node* node=new Node(val);
   node->next_=head_;
   Tail_->next_=head_;
   Tail_=node;
   }//尾插法
void InsertHead(int val){
    Node* node=new Node(val);
    node->next_=head_->next_;
    head_->next_=node;
    if(node->next_=head_)Tail_=node;
}
void Remove(int val){
    Node* q=head_;
    Node* p=head_->next_;
    while(p!=head_){
        if(p->data_==val){
            q->next_=p->next_;
            delete p;//找到删除节点
            if(q->next_=head_)Tail_=q;
        }
        else{
            q=p;
            p=p->next_;
        }
    }
}
bool Find(int val){
    Node* p=head_->next_;
    while(p!=head_){
        if(p->data_==val)return true;
        p=p->next_;
    }
    return false;
}
void show() const{
    Node* p=head_->next_;
    while(p!=head_){
        cout<<p->data_<<"";
        p=p->next_;
    }
    cout<<endl;
}
    private:
    struct Node{
        Node(int data=0):data_(data),next_(nullptr){}
        int data_;
        Node* next_;
    };
    Node* head_;
    Node* Tail_;
   };
 
int main(){
    return 0;
}