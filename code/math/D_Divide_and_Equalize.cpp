#include<bits/stdc++.h>
# define MULTI
//# define INIT
using namespace std;
#include<math.h>
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

// 题目: D. Divide and Equalize 
// 链接: https://codeforces.com/contest/1881/problem/D
/**
 * 赛中没做出来，好气
 * 由题意可知经过一次变换后 ai % x == 0   ai /= x    aj *= x  根据观察那么变换后 ai * aj 是不变的
 * 也就是说 x 是 ai 的因子，转移给了 aj，根据数学知识可知任何一个合数都可以表示为质数的乘积
 * 那么问题来了，ai 的一部分因子（可以表示为质数相乘）转移给了 aj ，数组中最终的质因子总数是不变的！
 * 答案也就显而易见了
 * 求出所有数的质因子以及每个质因子的个数，最终的每个质因子的个数模 n 必须等于 0 才能将数组中所有数都转变为相等的数
*/


const int N = 1e4+10;

void slove(){
    int n,a;
    cin >> n;
    // 质因子 -> 质因子个数
    unordered_map<int,int> cnt;
    // 求 num
    auto f = [&](int num){
        for(int i=2; i<=sqrt(num); ++i){
            while(num % i == 0){
                cnt[i]++;
                num /= i;
            }
        }
        if(num == 1) return;
        cnt[num]++;
    };
    for(int i=1; i<=n; ++i){
        cin >> a;
        f(a);
    }
    for(auto &it : cnt){
        // 模 n 不为 0 不可能转化为相等的数
        if(it.second % n){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

# ifdef INIT
void init(){
  
}
# endif

int main()
{
    # ifdef INIT
    init();
    # endif

    int cas = 1;
    # ifdef MULTI
    cin >> cas;
    # endif

    while (cas--){
        slove();
    }
    
}


