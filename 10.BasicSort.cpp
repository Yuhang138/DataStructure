#include<iostream>
#include<String>
#include<vector>
using namespace std;
//插入排序  时间复杂度：最坏、平均 O(n^2) 最好：O(n) 空间：O(1) 稳定性：稳定
void InsertSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int val=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]<=val)
            {
                break;
            }
            arr[j+1]=arr[j];

        }
        arr[j+1]=val;
    }
}
//希尔排序
void ShellSort(int arr[],int size){
for(int gap=size/2;gap>0;gap/=2){
    for(int i=gap;i<size;i++){
        int val=arr[i];
        int j=i-gap;
        for(;j>=0;j-=gap){
            if(arr[j]<=val){
                break;
            }
            arr[j+gap]=arr[j];
        }
        arr[j+gap]=val;
    }
}
}
//快速排序
//快排分割处理函数
int Partation(int arr[],int l,int r)
{   //记录基准数
    int val=arr[l];
    //一次快排处理 时间复杂度O(n)*O(logn)=O(nlogn)  最坏 O(n^2) 空间：O(logn) 递归深度所占用的栈内存
    while(l<r)
    {
        while(l<r&&arr[r]>val)//从R开始往前找第一个小于val的数字放到L的地方L++
        {
            r--;
        }
        if(l<r)
        {
            arr[l]=arr[r];
            l++;
        }
        while(l<r&&arr[l]<val)//从L开始往后找第一个大于val的数字,放到R的地方,R--
        {
          l++;
        }
        if(l<r)
        {
           arr[r]=arr[l];
           r--;
        }
    }
    //l==r的位置，就是放基准数的位置
    arr[l]=val;
    return l;
}
void QuickSort(int arr[],int begin,int end){//快排函数接口
    if(begin>=end)//快排递归结束条件
    {
        return;
    }
    //优化一：当[begin,end]序列的元素个数小到一定数量，采用插入排序
    /*例：
    if(end-begin<=50)
    {
    //InsertSort(arr,begin,end);此处的快速排序函数要改写一下方便适配新的参数
    return;
    }
    */
   //优化二：采用三数取中法，取合适基准数  mid=(L+R)/2
    //在[begin,end]区间的元素做一次快排分割处理
    int pos=Partation(arr,begin,end);

    //对基准数的左右两边继续分别进行快排
    QuickSort(arr,begin,pos-1);
    QuickSort(arr,pos+1,end);
}
void QuickSort(int arr[], int size)
{
	return QuickSort(arr, 0, size - 1);
}


//归并排序 时间复杂度：O(n*logn) 空间复杂度：O(n)
//归并过程函数
void Merge(int arr[],int l,int m,int r)
{
    int* p=new int[r-l+1];
    int i=l;
    int j=m+1;
    int index=0;
    while(i<=m&&j<=r){
        if(arr[i]<=arr[j]){
            p[index++]=arr[i++];
        }
        else{
            p[index++]=arr[j++];
        }
    }
    while(i<=m){
        p[index++]=arr[i++];
    }
    while(j<=r){
        p[index++]=arr[j++];
    }
    for(i=0,j=l;j<=r;i++,j++)//把合并结果拷贝到原始数组arr[l,r]区间内
    {
        arr[j]=p[i];
    } 
    delete[]p;
}
//归并排序递归接口
void MergeSort(int arr[],int begin,int end){
    //递归结束条件
    if(begin>=end)
    {
        return;
    }
    int mid=(begin+end)/2;
    //先递
    MergeSort(arr,begin,mid);
    MergeSort(arr,mid+1,end);
    //再归并
    Merge(arr,begin,mid,end);
}
void MergeSort(int arr[],int size){
     MergeSort(arr,0,size-1);
}
//堆的下沉调整
void siftDown(int arr[],int i,int size)
{
    int val=arr[i];
    while(i<=(size-1-1)/2)//这里有点问题
    {
        int child=2*i+1;
        if(child+1<size&&arr[child+1]>arr[child])
        {
            child+=1;//比较左右孩子的大小，如果右孩子大于左孩子，更新child
        }
        if(arr[child]>val)//如果孩子比val大，那么下沉
        {
            arr[i]=arr[child];
            i=child;//i继续指向它的孩子
        }
        else{
            break;//如果满足堆性质则说明位置正确，退出循环
        }
    }
    arr[i]=val;

}
//堆排序
void HeapSort(int arr[],int size)
{
    int n=size-1;
    for(int i=(n-1)/2;i>=0;i--){
        siftDown(arr,i,size);;
    }
    //把堆顶元素和末尾元素进行交换,从堆顶开始进行下沉操作
    for(int i=n;i>0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        siftDown(arr,0,i);

    }
}
//基数排序 时间复杂度：O(nd)  空间复杂度：O(n)  稳定性：稳定
void RadixSort(int arr[],int size)
{
    int Maxdata=abs(arr[0]);
    for(int i=1;i<size;i++){
        if(abs(arr[i])>Maxdata)
        {
            Maxdata=abs(arr[i]);
        }
    }
    int len=to_string(Maxdata).size();
    vector<vector<int>>vecs;
    int mod=10;
    int dev=1;
    for(int i=0;i<len;mod*=10,dev*=10,i++)
    {
        vecs.resize(20);
        for(int j=0;j<size;j++)
        {//得到当前元素第i个位置的数字
            int index=arr[j]%mod/dev+10;
            vecs[index].push_back(arr[j]);
        }
        int idx=0;
        for(auto vec:vecs)
        {
            for(int v:vec)
            {
                arr[idx++]=v;
            }
        }
        vecs.clear();
    }

}