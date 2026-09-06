#include<iostream>
#include<vector>
#include<list>
using namespace std;

class HashTable
{
public:
    HashTable(int size=primes_[0],double loadFactor=0.75)
    :useBucketNum_(0)
    ,loadFactor_(loadFactor)
    ,primeIdx_(0)
    {
        if(size!=primes_[0])
        {
            for(;primeIdx_<PRIME_SIZE;primeIdx_++)
            {
                if(primes_[primeIdx_]>=size)
                   break;
            }
            if(primeIdx_==PRIME_SIZE)
            {
                primeIdx_--;
            }
        }
        table_.resize(primes_[primeIdx_]);
    }
public:
//增加元素 不能重复插入key
void insert(int key)
{
 //判断扩容
    double factor=useBucketNum_*1.0/table_.size();
    cout<<"factor:"<<factor<<endl;
    if(factor>loadFactor_)
    {
        expand();
    }
}
private:
    vector<list<int>>table_;//哈希表的数据结构
    int useBucketNum_;//记录桶的个数
    double loadFactor_;//记录哈希表的装载因子

    static const int PRIME_SIZE=10;//素数表的大小
    static int primes_[PRIME_SIZE];//素数表
    int primeIdx_;//当前使用的素数的下标
    
};
int HashTable::primes_[PRIME_SIZE]={3,7,23,47,97,251,443,911,1471,42773};
