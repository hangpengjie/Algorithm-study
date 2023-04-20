#include<bits/stdc++.h>
using namespace std;
// https://mirror.codeforces.com/contest/1111/problem/B
// 贪心算法 排序后从小到大依次删除每个数，记录最大值即可
// 注意输出格式
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> arr(n);
    double sum = 0;
    for(int i=0; i<n; ++i)  {
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    double avg = 0;
    for(int i=0; i<n && m > 0; ++i){
        long long t = n - i - 1;
        double a = sum - arr[i] + min(t * k, (long long)m - 1);
        double b = sum + min((t + 1) * k, (long long)m);
        avg = max(max(a == 0 ? 0 : a / t, b / (t + 1)),avg);
        sum -= arr[i];
        --m;
        
    }
    
    printf("%.6f\n",avg);
    //cout<<sum / (r - l + 1)<<endl;
}