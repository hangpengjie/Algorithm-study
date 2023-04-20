#include<bits/stdc++.h>
using namespace std;
// 108. 奇数码问题
// https://www.acwing.com/problem/content/110/
// 把二维数组展开成一维，将空格向上移动时，相当于某个数向他后面的n-1个数交换了位置，n-1是偶数所以逆序对的变化也只能是偶数
// 逆序对数的奇偶性相同才能进行转换。
// 结论的充分性不会证明。。。
const int N = 505*505;
int a[N],b[N],c[N];
long long  merge_sort(int a[N],int b[N],int l, int r)
{
    if(l >= r)  return 0;
    int mid = (l + r) >> 1;
    long long ans = merge_sort(a,b,l, mid) + merge_sort(a,b,mid+1, r); 
    int i = l, j = mid+1, k = 0;
    while (i <= mid && j <= r)
    {
        if(a[i] <= a[j])    b[k++] = a[i++];
        else{
            b[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid)    b[k++] = a[i++];
    while (j <= r)  b[k++] = a[j++];
    
    for(i=l,j=0; i<=r; ++i,++j){
        a[i] = b[j];
    }
    return ans;
}
int main()
{
    int n;
    while (cin>>n)
    {
        int k = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int t;
                cin>>t;
                if(t)   a[k++] = t;
            }
        }
        k = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int t;
                cin>>t;
                if(t)   b[k++] = t;
            }
        }
        long long  t1 = merge_sort(a,c,0,n*n-2);
        long long t2 = merge_sort(b,c,0,n*n-2);
        if((t1&1)^(t2&1)){
            cout<<"NIE"<<endl;
        }else{
            cout<<"TAK"<<endl;
        }
    }
    
}