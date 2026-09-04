#include<iostream>
using namespace std;
//节点类型
struct Node{
    Node(int data=0):data_(data),next_(nullptr){}
    int data_;
    Node* next_;
};
//单链表代码实现
class Clink{
    public:
    Clink(){
        head_=new Node();//head_初始化指向头节点
    }
    ~Clink(){
        Node* p=head_;
        while(p!=nullptr){
            head_=head_->next_;
            delete p;
            p=head_;
        }
       head_=nullptr;
    }//节点释放
    public:
    //尾插法O(n)
    void InsertTail(int val){
        //找到末尾节点
        Node* p=head_;
        while(p->next_!=nullptr){
            p=p->next_;
        }
        //生成新节点
        Node* node=new Node(val);
        //把新节点挂在尾节点后面
        p->next_=node;
    }
    //头插法O(1)
    void InsertHead(int val){
        Node* node=new Node(val);
        node->next_=head_->next_;
        head_->next_=node;
    }
    //链表结点的删除
    void Remove(int val){
        if(head_->next_==nullptr)return;
        //第一种先找目标结点的前一个结点（自己想的）
        Node* p=head_->next_;
        /*while(p->next_!=nullptr){
            if(p->next_->data_==val){
                Node* temp=p->next_;
                p->next_=temp->next_;
                delete temp;
                return;
            }
            p=p->next_;
        }*/
       //第二种用双指针（视频方法）
       Node* q=head_;
       while(p!=nullptr){
        if(p->data_==val){
        q->next_=p->next_;
        delete p;
        return;
        }
        else{
        q=q->next_;
        p=p->next_;
        }
       }
    }
    void RemoveAll(int val){
     Node* p=head_->next_;
     Node* q=head_;
     while(p!=nullptr){
        if(p->data_==val){
            q->next_=p->next_;
           p=q->next_;
        }
        else{
         q=q->next_;
         p=p->next_;
        }
     }

    }//删除多个节点
    //打印链表
    void show(){
        Node* p=head_->next_;
        while(p!=nullptr){
            cout<<p->data_<<" ";
            p=p->next_;
        }
    }
    bool find(int val){
   Node* p=head_->next_;
   while(p!=nullptr){
    if(p->data_==val)return true;
    else p=p->next_;
   }
   return false;
    }//搜索
    private:
Node* head_;//指向链表的头节点
friend void ReverseLink(Clink &link);
friend bool GetLastKNode(Clink& link,int k,int& val);
friend void MergeLink(Clink& link1,Clink& link2);
};
void ReverseLink(Clink& link){
   Node* p=link.head_->next_;
   if(link.head_==nullptr)return;
   link.head_=nullptr;
   while(p!=nullptr){
    Node* q=p->next_;
    p->next_=link.head_->next_;
    link.head_->next_=p;
    p=q;
   }
}//单链表逆序
bool GetLastKNode(Clink& link,int k,int& val){
    if(k==0)return false;
Node* p=link.head_;
for(int i=0;i<k;i++){
    p=p->next_;
    if(p==nullptr){
        return false;
    }
    Node* pre=link.head_;
    while(p!=nullptr){
        pre=pre->next_;
        p=p->next_;
    }
    val=pre->data_;
    return true;
}
}//求倒数第K个节点
void MergeLink(Clink& link1,Clink& link2){
    Node* p=link1.head_->next_;
    Node* q=link2.head_->next_;
    Node* last=link1.head_;
    link2.head_=nullptr;
    while(p!=nullptr&&q!=nullptr){
        if(p->data_<q->data_){
            last->next_=p;
            last=p;
            p=p->next_;
        }
        else{
            last->next_=q;
            last=q;
            q=q->next_;
        }
    }
    if(p==nullptr){
        last->next_=q;
    }
    else{
        last->next_=p;
    }
}//合并两个有序链表
bool  IslinkHasCircle(Node *head_,int& val){
    Node* fast=head_;
    Node* slow=head_;
    while(fast!=nullptr&&fast->next_!=nullptr){
        fast=fast->next_->next_;
        slow=slow->next_;
        if(fast=slow){
            fast=head_;
            while(fast!=slow){
                fast=fast->next_;
                slow=slow->next_;
            }
            val=fast->data_;
    return true;
        }
    }
    return false;
}//判断单链表是否存在环，如果存在返回环的入口值
bool IsLinkHasMerge(Node* head1,Node*head2,int& val){
    Node* p=head1->next_;
    Node* q=head2->next_;
    int cnt1=0,cnt2=0;
    while(p!=nullptr){
        cnt1++;
        p=p->next_;
    }
    while(q!=nullptr){
        cnt2++;
        q=q->next_;
    }
    p=head1;
    q=head2;
    if(cnt1>cnt2){
        int offset=cnt1-cnt2;
        while(offset--){
         p=p->next_;
        }
    }
    if(cnt1<cnt2){
         int offset=cnt2-cnt1;
        while(offset--){
         q=q->next_;
        }
    }
    while(p!=nullptr&&q!=nullptr){
        if(p==q){
            val=p->data_;
            return true;
        }
        else{
            p=p->next_;
            q=q->next_;
        }
    }
    return false;
}
int main(){
    Clink link1;
    srand(time(NULL));
    for(int i=0;i<10;i++){
        int val=rand()%100+1;
        link1.InsertTail(val);
        cout<<val<<" ";
    }
    cout<<endl;
    link1.show();
    cout<<endl;
    Clink link2;
     for(int i=0;i<10;i++){
        int val=rand()%100+1;
        link2.InsertHead(val);
        cout<<val<<" ";
    }
    cout<<endl;
    link2.show();
    link2.InsertTail(200);
    cout<<endl;
    link2.show();
    cout<<endl;
    link2.Remove(200);
    link2.show();
system("pause");
}