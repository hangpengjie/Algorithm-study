#include<bits/stdc++.h>
using namespace std;
// 107. 超快速排序
// https://www.acwing.com/problem/content/109/
// 归并排序求逆序对
const int N = 500050;
int a[N],b[N];
long long  merge_sort(int l, int r)
{
    if(l >= r)  return 0;
    int mid = (l + r) >> 1;
    long long ans = merge_sort(l, mid) + merge_sort(mid+1, r); 
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
    cin>>n;
    while (n)
    {
        for(int i=0; i<n; ++i)  cin>>a[i];  
        cout<<merge_sort(0, n-1)<<endl;
        cin>>n;
    }
}