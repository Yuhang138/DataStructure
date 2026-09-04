#include<iostream>
using namespace std;
class LinkQueue{
public:
    LinkQueue()
    {
        head_=new Node();
        head_->pre_=head_;
        head_->pre_=head_;
    }
    ~LinkQueue()
    {
        Node*p=head_->next_;
        while(p!=head_)
        {
            head_->next_=p->next_;
            p->next_->pre_=head_;
            delete p;
            p=head_->next_;
        }
        delete head_;
        head_=nullptr;
    }
    void push(int val)
    {   Node*p=head_->pre_;
        Node*node=new Node(val);
        node->next_=head_;
        p->next_=node;
        node->pre_=p;
        head_->pre_=node;
    }
    void pop()
    {
        Node*p=head_->next_;
            head_->next_=p->next_;
            p->next_->pre_=head_;
            delete p;
    }
    int front() const
    {
        if(head_->next_==head_){
         throw"queue is empty";
        }
        return head_->next_->data_;
    }
    int back() const
    {
        if(head_->next_==head_){
         throw"queue is empty";
        }
        return head_->pre_->data_;
    }
    bool empty() const
    {
      return head_->next_==head_;
    }
    
private:
    struct Node
{
    Node(int data=0):
    data_(data),
    next_(nullptr)
    {}
    int data_;
    Node*next_;
    Node*pre_;
};
Node* head_;
};
int main(){
    int arr[]={12,4,56,7,89,31,53,75};
LinkQueue que;
for(int v:arr){
    que.push(v);
}
cout<<que.front()<<endl;
cout<<que.back()<<endl;
que.push(100);
que.push(200);
system("pause");
}