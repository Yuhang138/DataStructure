#include<iostream>
using namespace std;
struct Node{
    Node(int data=0): data_(data),pre_(nullptr),next_(nullptr){}
    int data_;
    Node* pre_;
    Node* next_;
};
class Doublelink{
    public:
    Doublelink(){
        head_=new Node();
    }
    ~Doublelink(){
        Node* p=head_;
        while(p!=nullptr){
            head_=head_->next_;
            delete p;
            p=head_;
        }
    }
    public:
    void InsertHead(int val){
        Node* node=new Node(val);
        node->next_=head_->next_;
        node->pre_=head_;
        if(head_->next_!=nullptr){
          head_->next_->pre_=node;
        }
        head_->next_=node;
    }
    void InsertTail_(int val){
        Node* node=new Node(val);
        Node* p=head_;
        while(p->next_!=nullptr){
            p=p->next_;
        }
        node->pre_=p;
        p->next_=node;
    }
    void show()const{
        Node* p=head_->next_;
        while(p!=nullptr){
            cout<<p->data_<<" ";
        }
        cout<<endl;
    }
    bool Remove(int& val){
        Node* p=head_->next_;
        while(p!=nullptr){
            if(p->data_==val){
                p->pre_->next_=p->next_;
                if(p->next_!=nullptr){
                    p->next_->pre_=p->pre_;
                }
                delete p;
                return true;
            }
            else{
                p=p->next_;
            }
        }
        return false;
    }
    private:
    Node* head_;
};
int main(){




    return 0;
}