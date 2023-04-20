

🔴 难度等级（不会做）

😊会

- [排序算法](#排序算法)
  - [快速排序](#快速排序)
  - [堆排序](#堆排序)
- [优先队列+贪心](#优先队列贪心)
  - [LCP 30. 魔塔游戏](#lcp-30-魔塔游戏)
  - [LCP 32. 批量处理任务](#lcp-32-批量处理任务)
- [动态规划](#动态规划)
  - [LCP 31. 变换的迷宫](#lcp-31-变换的迷宫)
  - [312. 戳气球](#312-戳气球)
  - [410. 分割数组的最大值](#410-分割数组的最大值)
  - [6100. 统计放置房子的方式数](#6100-统计放置房子的方式数)
- [字典树](#字典树)
  - [440. 字典序的第K小数字](#440-字典序的第k小数字)
- [二叉树+DP](#二叉树dp)
  - [LCP 34. 二叉树染色](#lcp-34-二叉树染色)
- [数学](#数学)
  - [172. 阶乘后的零](#172-阶乘后的零)
- [位运算](#位运算)
  - [剑指 Offer II 001. 整数除法](#剑指-offer-ii-001-整数除法)
  - [Dasha and Nightmares](#dasha-and-nightmares)
  - [982. 按位与为零的三元组](#982-按位与为零的三元组)
- [并查集](#并查集)
  - [ P1111修复公路 - 洛谷](#-p1111修复公路---洛谷)
  - [P3958 \[NOIP2017 提高组\] 奶酪 - 洛谷 ](#p3958-noip2017-提高组-奶酪---洛谷-)
  - [685. 冗余连接 II](#685-冗余连接-ii)
  - [924. 尽量减少恶意软件的传播](#924-尽量减少恶意软件的传播)
- [线段树](#线段树)
  - [307. 区域和检索 - 数组可修改](#307-区域和检索---数组可修改)
  - [LCP 05. 发 LeetCoin](#lcp-05-发-leetcoin)
- [广度优先搜索](#广度优先搜索)
  - [LCP 09. 最小跳跃次数](#lcp-09-最小跳跃次数)
  - [675. 为高尔夫比赛砍树](#675-为高尔夫比赛砍树)
- [拓扑排序](#拓扑排序)
  - [310. 最小高度树](#310-最小高度树)
- [滑动窗口](#滑动窗口)
  - [30. 串联所有单词的子串](#30-串联所有单词的子串)
- [二分](#二分)
  - [ 寻找两个正序数组的中位数](#-寻找两个正序数组的中位数)
- [Rolling Hash](#rolling-hash)
  - [Remove Two Letters](#remove-two-letters)
- [换根DP](#换根dp)
  - [统计可能的树根数目](#统计可能的树根数目)
  - [Problem - 219D - Codeforces](#problem---219d---codeforces)
- [求逆序对](#求逆序对)
  - [暴力求解](#暴力求解)
  - [归并排序](#归并排序)
  - [树状数组](#树状数组)



# 排序算法

## 快速排序

```java
public class Solution {
    public static void main(String[] args) {
        int[] nums = new int[]{102,32,43,43,5,656,657,5665,65,56,5,567,78,1,23,455,6};
        new Solution().sort(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]+" ");
        }
    }


    public void sort(int[] nums){
        quickSort(nums,0,nums.length-1);
    }
    private void quickSort(int[] nums, int left, int right){
        if(left < right){
            int k = partition(nums,left,right);
            quickSort(nums,left,k-1);
            quickSort(nums,k+1,right);
        }
    }
    private int partition(int[] nums, int left, int right){
        int pix = nums[left];
        while (left < right){
            while (left < right && nums[right] >= pix){
                right --;
            }
            if(left < right)    nums[left] = nums[right];
            while (left < right && nums[left] < pix){
                left ++;
            }
            if(left < right)    nums[right] = nums[left];
        }
        nums[left] = pix;
        return left;
    }
}
```



## 堆排序

```java
public class Solution {
    public static void main(String[] args) {
        int[] nums = new int[]{102,32,43,43,5,656,657,5665,65,56,5,567,78,1,23,455,6};
        new Solution().sort(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]+" ");
        }
    }


    public void sort(int[] nums){
        int len = nums.length - 1;
        int beginIndex = (len - 1) >> 1;
        for (int i = beginIndex; i >= 0; i--) {
            maxHeapify(nums,i,len);
        }


        for (int i = len; i >= 0; i--) {
            swap(nums,0,i);
            maxHeapify(nums,0,i-1);
        }

    }
    private void maxHeapify(int[] nums, int index, int len){
        int li = (index << 1) + 1;
        int ri = li + 1;
        int cMax = li;
        if(li > len)    return;
        if(ri <= len && nums[ri] > nums[li]){
            cMax = ri;
        }
        if(nums[cMax] > nums[index]){
            swap(nums,cMax,index);
            maxHeapify(nums,cMax,len);
        }
    }


    private void swap(int[] nums,int i, int j){
        if(i == j)  return;
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }

}
```





# 优先队列+贪心



## [LCP 30. 魔塔游戏](https://leetcode-cn.com/problems/p0NxJO/)

![image-LCP 30. 魔塔游戏](./images/LCP%2030.%20魔塔游戏.png)



```java
class Solution {
    public int magicTower(int[] nums) {
        int ans = 0;
        long now = 1L;
        long last = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
    
        for(int i=0; i<nums.length; ++i){
            if(nums[i] < 0) pq.offer(nums[i]);
            now += nums[i];
            // 当现在的血量 now 小于1时，需要进行调整，否则死亡
            // 每次调整都会将已经遍历过的最小值调整到末尾
            if(now <= 0){
                // 记录总共调整的怪物的血量总和(肯定都是负数滴)
                last += pq.peek();
                // 每次移除最小值
                now -= pq.poll(); 
                ans ++;
            }
        }

        // 经历过所有房间之后的血量大于 0 才会通过
        if(now + last > 0)  return ans;
        return -1;
    }
}
```

## [LCP 32. 批量处理任务](https://leetcode-cn.com/problems/t3fKg1/)

🔴🔴🔴🔴🔴🔴

```java
class Solution {
        public int processTasks(int[][] tasks) {
        int[][] newTasks = new int[tasks.length + 1][];
        //按起点排序
        Arrays.sort(tasks, (task1, task2) -> task1[0] - task2[0]);        
        System.arraycopy(tasks, 0, newTasks, 0, tasks.length);
        newTasks[tasks.length] = new int[]{1000000001, 1000000001, 1};
        int res = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int[] task : newTasks) {
            while (!pq.isEmpty() && pq.peek()[0] + res < task[0]) {
                if (pq.peek()[0] + res >= pq.peek()[1]) {
                    pq.poll();
                }else {
                    res += Math.min(pq.peek()[1], task[0]) - (pq.peek()[0] + res);
                }
            }
            pq.offer(new int[]{task[1] - task[2] + 1 - res,task[1] + 1});
        }
        return res;
    }
}
```



# 动态规划

## [LCP 31. 变换的迷宫](https://leetcode-cn.com/problems/Db3wC1/)

🔴🔴🔴🔴🔴

```java
class Solution {
    public boolean escapeMaze(List<List<String>> maze) {
        // 时间
        int t = maze.size();    
        // 长
        int m = maze.get(0).size();
        // 宽
        int n = maze.get(0).get(0).length();
        // 0未使用 1使用临时卷轴 2使用永久卷轴 3使用完
        boolean[][][][] dp = new boolean[t][m][n][4];
        for(int i=0; i<4; ++i){
            dp[0][0][0][i] = true;
        }
        // 转移方向
        int[][] dire = new int[][] { { 0, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
        // 使用永久卷能到达方向
        boolean[][][] can = new boolean[m][n][2];
        for(int i=1; i<t; ++i){
            for(int j=0; j<m; ++j){
                for(int k=0; k<n; ++k){
                    dp[i][j][k][2] |= can[j][k][0];
                    dp[i][j][k][3] |= can[j][k][1];
                    // 当前为空地的话，直接转移即可
                    if (maze.get(i).get(j).charAt(k) == '.') {
                        for (int l = 0; l < 4; ++l) {
                            for (int p = 0; p < 5; ++p) {
                                int dx = j + dire[p][0], dy = k + dire[p][1];
                                if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                                    dp[i][j][k][l] |= dp[i - 1][dx][dy][l];
                                }
                            }
                        }
                        // 否则，只能使用卷轴转移,也就是之前要没使用过相应卷轴
                    } else {
                        for (int p = 0; p < 5; ++p) {
                            int dx = j + dire[p][0], dy = k + dire[p][1];
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                                // 假如该点可以使用永久卷轴转移得到的话，意味着今后所有的时间，该点对拥有永久卷轴的状态均是开放的
                                // 如果直接修改dp数组记录的话，意味着再乘个T，会超时，故用额外数组记录作优化
                                // 使用永久卷轴
                                if (dp[i - 1][dx][dy][0]) {
                                    can[j][k][0] = true;
                                    can[j][k][1] = true;
                                } else if (dp[i - 1][dx][dy][1]) {
                                    can[j][k][1] = true;
                                }
                                // 0是不用指望能转移得到了
                                dp[i][j][k][1] |= dp[i - 1][dx][dy][0];
                                dp[i][j][k][2] |= dp[i - 1][dx][dy][0];
                                dp[i][j][k][3] |= dp[i - 1][dx][dy][0] | dp[i - 1][dx][dy][1] | dp[i - 1][dx][dy][2];
                            }
                        }
                    }
                }
            }
        }
        return dp[t - 1][m - 1][n - 1][3];

    }
}
```



## [312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)

🔴🔴🔴🔴🔴

```java
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] temp = new int[n+2];
        temp[0] = 1;
        temp[n+1] = 1;
        for(int i=0; i<n; ++i)  temp[i+1] = nums[i];
        // dp[i][j] 表示（i - j）开区间内最大值
        int[][] dp = new int[n+2][n+2];

        for(int len = 3; len <= n+2; ++len){
            // 左端点
            for(int i=0; i <= n+2-len; ++i){
                int res = 0;
                // k为最后一个破的气球
                for(int k=i+1; k<i+len-1; ++k){
                    res = Math.max(res, dp[i][k]+temp[i]*temp[k]*temp[i+len-1]+dp[k][i+len-1]);
                }
                dp[i][i+len-1] = res;
            }
        }
        return dp[0][n+1];

     }
}
```



## [410. 分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/)

🔴😒😜

```java
class Solution {
    public int splitArray(int[] nums, int m) {
        int n = nums.length;
        // dp[i][j] 表示前i个分成j组的尽量小的各自和的最大值
        int[][] dp = new int[n+1][m+1];
        int[] sub = new int[n+1];
        for(int i=0; i<n; ++i){
            dp[i+1][1] = dp[i][1] + nums[i];
            sub[i+1] = dp[i+1][1];
        }
        for(int i=2; i<=n; ++i){
            for(int j=2; j<=Math.min(i, m); ++j){
                dp[i][j] = Integer.MAX_VALUE;
                for(int k=j-1; k<i; ++k){
                    dp[i][j] = Math.min(dp[i][j], Math.max(dp[k][j-1], sub[i]-sub[k]));
                }
            }
        }
        return dp[n][m];
    }
}
```





## [6100. 统计放置房子的方式数](https://leetcode.cn/problems/count-number-of-ways-to-place-houses/)



🔴🔴🔴

```java
import java.util.*;

public class Solution {
    public int countHousePlacements(int n) {
       long[][] dp = new long[n+1][2];
       long mod = 1000000007;
       dp[1][0] = 1;
       dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
            dp[i][1] = dp[i-1][0];
        }
        long ans = ((dp[n][1] + dp[n][0]) % mod);
        return (int) (ans * ans % mod);
    }
}
```



# 字典树

## [440. 字典序的第K小数字](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/)

🔴🔴🔴🔴🔴

```java
class Solution {
	public int findKthNumber(int n, int k) {
    	int cur=1;//第一字典序小的(就是1)
    	int prefix=1;// 前缀从1开始
    	while(cur<k) {
    		int tmp=count(n,prefix); //当前prefix峰的值
    		if(tmp+cur>k) {// 找到了
    			prefix*=10; //往下层遍历
    			cur++;//一直遍历到第K个推出循环
    		}else {
    			prefix++;//去下个峰头(前缀)遍历
    			cur+=tmp;//跨过了一个峰(前缀) 
    		}
    	}//退出循环时 cur==k 正好找到
    	return prefix;
    }

	private int count(int n, int prefix) {
          	//不断向下层遍历可能一个乘10就溢出了, 所以用long
		long cur=prefix;
		long next=cur+1;//下一个前缀峰头
		int count=0;
		while(cur<=n) {
			count+=Math.min(n+1,next)-cur;//下一峰头减去此峰头
			 // 如果说刚刚prefix是1，next是2，那么现在分别变成10和20
	        // 1为前缀的子节点增加10个，十叉树增加一层, 变成了两层
	        
	        // 如果说现在prefix是10，next是20，那么现在分别变成100和200，
	        // 1为前缀的子节点增加100个，十叉树又增加了一层，变成了三层
			cur*=10;
			next*=10; //往下层走
		}
		return count;
	}
}
```



# 二叉树+DP

## [LCP 34. 二叉树染色](https://leetcode-cn.com/problems/er-cha-shu-ran-se-UGC/)

🔴🔴🔴

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  
    public int maxValue(TreeNode root, int k) {
       int[] ans = dfs(root, k);
       int max = 0;
       for(int i=0; i<=k; ++i)  max = Math.max(max, ans[i]);
       return max;
    }

    public int[] dfs(TreeNode root, int k){
        // dp[i]（i>0） 表示当前点加上连续染色 i-1 个点所获得的最大值
        // dp[0]表示不染当前点所获得最大值
        int[] dp = new int[k+1];
        if(root == null)    return dp;

        int l[] = dfs(root.left, k);
        int r[] = dfs(root.right, k);

        int ml = 0;
        int mr = 0;

        for(int i=0; i<=k; ++i){
            ml = Math.max(ml, l[i]);
            mr = Math.max(mr, r[i]);
        }
        
        dp[0] = ml + mr;


        for(int i=1; i<=k; ++i){
            for(int j=0; j<i; ++j){
                // 左边染 j 个 右边染 i - 1 -j 个
                dp[i] = Math.max(dp[i], root.val+l[j]+r[i-1-j]);
            }
        }

        return dp;
        
    }

}
```



# 数学

## [172. 阶乘后的零](https://leetcode-cn.com/problems/factorial-trailing-zeroes/)

😜😜

```java
class Solution {
    public int trailingZeroes(int n) {
        int ans = 0;
        for(int i=5; i<=n; i+=5){
            ans += digit(i);
        }
        return ans;
    }
    // 求包含5的数量
    // 25->2  125->3   225->2
    public int digit(int k){
        if(k % 5 == 0)  return 1+digit(k/5);
        else return 0;
    }
}
```

🔴

```java
class Solution {
    public int trailingZeroes(int n) {
        int ans = 0;
        while(n != 0){
            n = n/5;
            ans += n;
        }
        return ans;
    }
    
}
/*
补充一下以130为例出现的数：

第一次：5，10，15，…，130，至少包含1个5的数为26个

第二次：25，50，75，100，125，至少包含2个5的数有这5个

第三次：125，它至少包含3个5（其实也只包含3个5）
*/
```



# 位运算

## [剑指 Offer II 001. 整数除法](https://leetcode-cn.com/problems/xoh6Oh/)

🔴

```java
class Solution {
    public int divide(int a, int b) {
        if(a == 0 || b == 1)  return a;
        if(a == -2147483648 && b == -1)  return 2147483647;
        int flag = 1;
        if((a < 0 && b > 0) || (a > 0 && b < 0))    flag = -1;
        // 转变为负数 防止溢出
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        // 快速减法
        while(a <= b){
            int base = 1;
            int div = b;
            while(a - div <= div){
                div <<= 1;
                base <<= 1;
            }
            ans += base;
            a -= div;
            
        }
        return flag == 1 ? ans : -ans;
         
    }
    
}
```



## [Dasha and Nightmares](https://codeforces.com/contest/1800/problem/F)

🔴🔴🔴

```c++
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int,int>;
using PLL = pair<LL ,LL>;
using PULL = pair<ULL ,ULL>;
const int INF = 0X3F3F3F3F;
const int MOD = 1e9+7;
inline int mod(int x) { return x >= MOD ? x - MOD : x; }

// 2023-03-03 16:16:05


int main() {
    int n;
    cin>>n;
    string s;
    // v[0] 存储字符串长度为偶数的信息
    vector<vector<PII>> v(2);
    for (int i = 0; i < n; ++i) {
        cin>>s;
        // sum 中某位指的的某个字母是否存在
        // mask 中某位指的是某个字母的个数是奇数还是偶数
        int sum = 0, mask = 0,k = 0;
        for (const auto &it: s){
            k = it - 'a';
            sum |= (1 << k);
            mask ^= (1 << k);
        }
        v[s.size() & 1].push_back({sum,mask});
    }
    // 存储某个状态下奇数长度的字符串个数
    vector<int> cnt(1<<26, 0);
    LL  ans = 0;
    for (int i = 0; i < 26; ++i) {
        int all = ((1 << 26) - 1) ^ (1 << i);
        for (const auto &[sum,mask]: v[1]){
            if(!((sum>>i) & 1)) ++cnt[mask];
        }
        for (const auto &[sum,mask]: v[0]){
            // 到达这里时nightmare的长度肯定是偶数了，当cnt[all ^ mask]不为0时说明一定满足第三和第四条件了
            // be careful !!!
            if(!((sum>>i) & 1)) ans += cnt[all ^ mask];
        }
        for (const auto &[sum,mask]: v[1]){
            if(!((sum>>i) & 1)) --cnt[mask];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
```



## [982. 按位与为零的三元组](https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/)

🔴

```c++
// 一般版本
//leetcode submit region begin(Prohibit modification and deletion)
// 2023-03-04 20:31:39
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(1<<16,0);
        unordered_map<int,int> m;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
            for (int j = 0; j < n; ++j) {
                ++cnt[nums[i]&nums[j]];
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << 16); ++i) {
            for (int j = 0; j < n; ++j) {
                if(i & nums[j]){

                }else{
                    ans += cnt[i];
                }
            }
        }
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


// 优化版本 见题解！！
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(1 << 16);
        for (int x: nums) {
            for (int y: nums) {
                ++cnt[x & y];
            }
        }
        int ans = 0;
        for (int x: nums) {
            x = x ^ 0xffff;
            for (int sub = x; sub; sub = (sub - 1) & x) {
                ans += cnt[sub];
            }
            ans += cnt[0];
        }
        return ans;
    }
};

```





# 并查集

## [ P1111修复公路 - 洛谷](https://www.luogu.com.cn/problem/P1111)
😊😊

```java
package my.stu;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static int[] parent;
    static int[] rank;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        parent = new int[N+1];
        rank = new int[N+1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        int[][] a = new int[M][3];
        for (int i = 0; i < M; i++) {
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
            a[i][2] = sc.nextInt();
        }

        // 按照时间从小到大排序
        Arrays.sort(a, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });
        
        int ans = 0;
        for (int[] ints : a) {
            // 加入失败则说明两个是联通的 
            // 成功则说明原本不连通，现在联通了 需要更新 ans
            if(union(ints[0], ints[1])) ans = ints[2];
        }
        
        int k = find(1);
        for (int i = 2; i <= N; i++) {
            // 若存在两个网络则说明存在两个村庄不互通
            if(find(i) != k){
                System.out.println(-1);
                return;
            }
        }
        System.out.println(ans);

    }
    public static int find(int x){
        if(x == parent[x])  return x;
        return parent[x] = find(parent[x]);
    }
    public static boolean union(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] > rank[y])   parent[y] = x;
        else {
            if(rank[x] == rank[y])  rank[y]++;
            parent[x] = y;
        }
        return true;
    }

}

```





## [P3958 [NOIP2017 提高组] 奶酪 - 洛谷 ](https://www.luogu.com.cn/problem/P3958#submit)
😊😊

```java
package my.stu;

import sun.nio.ch.ThreadPool;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.concurrent.ThreadPoolExecutor;

public class Main {
    static int[] parent;
    static int[] rank;
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        // T组数据
        int T = sc.nextInt();
        while (T-- > 0){

            int n = sc.nextInt();
            int h = sc.nextInt();
            int r = sc.nextInt();
            long[][] arr = new long[n][3];
            long bet = (((long) r * (long) r)) << 2;
            for (int i = 0; i < n; i++) {
                arr[i][0] = sc.nextLong();
                arr[i][1] = sc.nextLong();
                arr[i][2] = sc.nextLong();
            }
            // 第n+1项为与底部相连  parent[n]
            // 第n+2项为与顶部相连  parent[n+1]
            parent = new int[n+2];
            rank = new int[n+2];
            for (int i = 0; i < n + 2; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
            for (int i = 0; i < n; i++) {
                // 与底部相连加入底部
                if(arr[i][2] <= r)  union(i, n);
                // 与顶部相连加入顶部
                if(arr[i][2] + r >= h)  union(i, n+1);
                for (int j = 0; j < i; j++) {
                    long dis = (arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0])
                            +  (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1])
                            +  (arr[i][2] - arr[j][2]) * (arr[i][2] - arr[j][2]);
                    if(dis <= bet){
                        union(i, j);
                    }
                }
            }
            // 底部和顶部属于同一个网络则说明可以从底部到达顶部
            if(find(n) == find(n+1)) System.out.println("Yes");
            else System.out.println("No");


        }


    }
    public static int find(int x){
        if(x == parent[x])  return x;
        return parent[x] = find(parent[x]);
    }
    public static boolean union(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y) return false;
        if(rank[x] > rank[y])   parent[y] = x;
        else {
            if(rank[x] == rank[y])  rank[y]++;
            parent[x] = y;
        }
        return true;
    }



}

```



## [685. 冗余连接 II](https://leetcode-cn.com/problems/redundant-connection-ii/)

🔴🔴🔴

```java
class Solution {

    int[] parent;

    public int[] findRedundantDirectedConnection(int[][] edges) {
        int[] ans = new int[2];
        int n = edges.length;
        parent = new int[n+1];
        
        for(int i=0; i<=n; ++i){
            parent[i] = i;
        }
        UnionFind uf = new UnionFind(n+1);
        // 是否发生冲突(入度为2)
        int conf = -1;
        // 是否有环
        int cycle = -1;
        for(int i=0; i<n; ++i){
            int[] edge = edges[i];
            int from = edge[0];
            int to = edge[1];
            // 存在入度为2的点
            if(to != parent[to]){
                conf = i;
            }else{
                // 存在环
                parent[to] = from;
                if(uf.find(from) == uf.find(to)){
                    cycle = to;
                }else{
                    uf.union(from, to);
                }
            }
            
        }
        // 没有冲突 一定存在环的情况
        if(conf < 0){
            return new int[]{parent[cycle], cycle};
        }
        
        int[] confEdge = edges[conf];
        
        if(cycle < 0){
            // 不连接上冲突点无环，说明可行，删除第二个入度
            //System.out.println(conf+" "+confEdge[0]+" "+confEdge[1]+"+++");
            return new int[]{confEdge[0], confEdge[1]};
        }else{
            // 不连接上冲突点有环, 说明第一个入度需要删除
            //System.out.println(conf+" "+confEdge[0]+" "+confEdge[1]+" ");
            return new int[]{parent[confEdge[1]], confEdge[1]};
        }

    }


   
}
class UnionFind {
    int[] ancestor;

    public UnionFind(int n) {
        ancestor = new int[n];
        for (int i = 0; i < n; ++i) {
            ancestor[i] = i;
        }
    }

    public void union(int index1, int index2) {
        ancestor[find(index1)] = find(index2);
    }

    public int find(int index) {
        if (ancestor[index] != index) {
            ancestor[index] = find(ancestor[index]);
        }
        return ancestor[index];
    }
}


```



## [924. 尽量减少恶意软件的传播](https://leetcode-cn.com/problems/minimize-malware-spread/)

😒😒




```java
class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        int ans = 1000;
        int n = graph.length;
        UnionFind uf = new UnionFind(n);
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(graph[i][j] == 1){
                    uf.union(i, j);
                }
            }
        }
        // 先从小到大排个序
        Arrays.sort(initial);
        // 记录某个网络被污染的个数
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0; i<initial.length; ++i){
            int par = uf.find(initial[i]);
            int count = map.getOrDefault(par, 0)+1;
            map.put(par, count);
        }

        // 指向合适的网络图的根
        int pos = -1;
        // 合适的网络图中节点的数量
        int num = -1;

        Set<Integer> set = map.keySet();

        // 答案不唯一
        Set<Integer> posSet = new HashSet<>();

        for(int key : set){
            // 网络图中污染源大于 1 不考虑
            if(map.get(key) > 1)    continue;
            // 网络图中污染源 == 1 考虑该网络图中的数量是否是最大的
            int count = uf.map.get(key);
            if(count > num) {
                //System.out.println("---"+key+" "+count);
                pos = key;
                num = count;
                posSet.clear();
                posSet.add(key);
            }
            else if(count == num){
                posSet.add(key);
            }
        }
        
        // set = uf.map.keySet();
        // for(int key : set){
        //     System.out.println(key+" "+uf.map.get(key));
        // }

        // 全都是污染源大于 1 的 直接返回initial[0]
        if(pos == -1)   return initial[0];
        for(int i=0; i<initial.length; ++i){
            int par = uf.find(initial[i]);
            // 第一个最优解 索引一定是最小的（之前排序了）
            if(posSet.contains(par) ){
                ans = initial[i];
                break;
            }
        }
        return ans;

    }
}
class UnionFind{
    int[] parent;
    // 记录网络图中节点数目
    Map<Integer, Integer> map;
    public UnionFind(int capity){
        parent = new int[capity];
        map = new HashMap<>();
        for(int i=0; i<capity; ++i){
            parent[i] = i;
            map.put(i, 1);
        }
    }

    public int find(int x){
        return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }

    public void union(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)  return;
        parent[y] = x;
        map.put(x, map.get(x)+map.get(y));
        map.remove(y);
    }
}

```



# 线段树

## [307. 区域和检索 - 数组可修改](https://leetcode-cn.com/problems/range-sum-query-mutable/)

😊😊

```java
class NumArray {
    int[] nums;
    int[] ans;
    public NumArray(int[] nums) {
        this.nums = nums;
        if(nums.length != 0){
            this.ans = new int[nums.length << 2];
            buildTree(0, 0, nums.length - 1);
        }
    }
    
    // 单点更新
    public void update(int index, int val) {
        update(index, val, 0, 0, nums.length - 1);
    }
    
    public int sumRange(int left, int right) {
        return query(0, 0, nums.length - 1, left, right);
    }

    // 建树
    private void buildTree(int node, int left, int right){
        if(left == right){
            ans[node] = nums[left];
            return;
        }
        int mid = (left + right) >> 1;
        buildTree((node << 1) + 1, left, mid);
        buildTree((node << 1) + 2, mid + 1, right);
        ans[node] = ans[(node << 1) + 1] + ans[(node << 1) + 2];
        return;
    }
    // 单点更新
    private void update(int index, int val, int node, int left, int right){
        // 不在范围内直接退出
        if(index < left || index > right)   return;
        if(left == right){
            nums[left] = val;
            ans[node] = val;
            return;
        }
        int mid = (left + right) >> 1;
        update(index, val, (node << 1) + 1, left, mid);
        update(index, val, (node << 1) + 2, mid + 1, right);
        ans[node] = ans[(node << 1) + 1] + ans[(node << 1) + 2];
        return;

    }

    private int query(int node, int left, int right, int L, int R){
        if(L <= left && right <= R) return ans[node];
        int res = 0;
        int mid = (left + right) >> 1;
        if(L <= mid)    res += query((node << 1) + 1, left, mid, L, R);
        if(R >  mid)    res += query((node << 1) + 2, mid + 1, right, L, R);
        return res;
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
```





## [LCP 05. 发 LeetCoin](https://leetcode-cn.com/problems/coin-bonus/)

🔴🔴😊

```java
class Solution {
    // 分配唯一标记
    int vis = 1;
    public int[] bonus(int n, int[][] leadership, int[][] operations) {
        Tree[] tree = new Tree[n+1];
        // 先建立层级关系
        for(int[] ship : leadership){
            if(tree[ship[0]] == null)   tree[ship[0]] = new Tree(ship[0]);
            if(tree[ship[1]] == null)   tree[ship[1]] = new Tree(ship[1]);
            tree[ship[0]].children.add(tree[ship[1]]);
        }
        // 表示映射
        int[] trans = new int[n+1];
        // 表示每个点的下属总数
        int[] sum = new int[n+1];
        // 建立映射以及计算每个点的所有下属总数
        dfs(tree[1], trans,sum);
        // 线段树
        TreeNode root = new TreeNode(n);
        List<Integer> res = new ArrayList<>();
        for(int[] operation : operations){
            if(operation[0] == 1)   root.update(1, 1, n, trans[operation[1]], trans[operation[1]], operation[2]);
            else if(operation[0] == 2)  root.update(1, 1, n, trans[operation[1]], trans[operation[1]]+sum[operation[1]], operation[2]);
            else{
                res.add(root.query(1, 1, n, trans[operation[1]],trans[operation[1]]+sum[operation[1]]));
            }
        }
        int[] ans = new int[res.size()];
        for(int i=0; i<ans.length; ++i){
            ans[i] = res.get(i);
        }
        return ans;



    }
    public int dfs(Tree tree, int[] trans, int[] sum){
        // 分配唯一 id
        trans[tree.id] = vis++;
        for(int i=0; i<tree.children.size(); ++i){
            sum[tree.id] += dfs(tree.children.get(i), trans, sum);
        }
        return sum[tree.id] + 1;
    }
    

    
}
class Tree{
    int id;
    List<Tree> children;
    public Tree(int id){
        this.id = id;
        children = new ArrayList<>();
    }
}
class TreeNode{
    int[] mask;
    int[] res;
    int mod;
    public TreeNode(int n){
        mask = new int[n << 2];
        res = new int[n << 2];
        mod = 1000000007;
    }

    public void update(int index, int left, int right, int L, int R, int value){

        if(L <= left && right <= R){
            mark(index, left, right, value);
            return;
        }
        pushDown(index, left, right);
        int mid = (left + right) >> 1;
        if(L <= mid) update(getLeft(index), left, mid, L, R, value);
        if(R > mid) update(getRight(index), mid+1, right, L, R, value);
        pushUp(index);
    }
    public int query(int index, int left, int right, int L, int R){
        if(L <= left && right <= R)  return res[index];
        pushDown(index, left, right);
        int mid = (left + right) >> 1;
        int ans = 0;
        if(L <= mid)    ans = query(getLeft(index), left, mid, L, R)%mod;
        if(R > mid)     ans = (ans + query(getRight(index), mid+1, right, L, R))%mod;
        return ans;
    }

    // 左孩子
    public int getLeft(int x){
        return x << 1;
    }
    // 右孩子
    public int getRight(int x){
        return (x << 1) | 1;
    }
    // 懒惰标记
    public void mark(int index, int left, int right,int value){
        mask[index] += value;
        res[index] = (res[index]+(right - left + 1) * value)%mod;
    }
    // 计算当前点总和
    public void pushUp(int x){
        res[x] = (res[getLeft(x)] + res[getRight(x)])%mod;
    }
    // 向下传播标记
    public void pushDown(int index, int left, int right){
        int mid = (left + right) >> 1;
        mark(getLeft(index), left, mid, mask[index]);
        mark(getRight(index), mid+1, right, mask[index]);
        mask[index] = 0;
    }

}
```



# 广度优先搜索

## [LCP 09. 最小跳跃次数](https://leetcode-cn.com/problems/zui-xiao-tiao-yue-ci-shu/)

😜😜

```java
class Solution {
    public int minJump(int[] jump) {
        int n = jump.length;
        Queue<Integer> queue = new LinkedList<>();
        // [0 ~ low-1]均被搜索到，没必要再搜索
        int low = 0;
        // 跳转次数
        int deep = 0;

        queue.offer(0);
        // 保存该点是否已经搜索到
        boolean[] vis = new boolean[n];
        while(!queue.isEmpty()){
            // 次数+1
            deep++;
            int size = queue.size();
            for(int i=0; i<size; ++i){
                int node = queue.poll();
                // 已经搜索到该点 将vis[node]设置为true
                vis[node] = true;
                // 可以越出边界 返回步数
                if(node + jump[node] >= n)  return deep;
                // 向右跳转的目的地未被搜索 那么就去搜索
                if(!vis[node + jump[node]]) queue.offer(node + jump[node]);
                // 向左搜索
                while(low < node){
                    // 该点未被搜索到 加入队列
                    if(!vis[low]) queue.offer(low++);
                    // 否则跳过
                    else low++;
                }
            }
        }
        // 没啥用 为了不报错
        return 0;
    }
}
```

## [675. 为高尔夫比赛砍树](https://leetcode.cn/problems/cut-off-trees-for-golf-event/)

🔴🔴😜

```java
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        new Solution().cutOffTree(new ArrayList<List<Integer>>(){{
            add(new ArrayList<Integer>(){{add(1);add(2);add(3);}});
            add(new ArrayList<Integer>(){{add(0);add(0);add(4);}});
            add(new ArrayList<Integer>(){{add(7);add(6);add(5);}});
        }});
    }

    int[] dy = new int[]{1,-1,0,0};
    int[] dx = new int[]{0,0,1,-1};
    // 返回值 [0] -> 坐标  (tx<<16)+ty
    //       [1] -> 步数
    private int[] bfs(int x,int y,int[][] arr, int tar){
        if(arr[x][y] == tar){
            return new int[]{(x<<16)+y,0};
        }
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offer((x <<16) + y);
        Set<Integer> set = new HashSet<>();
        set.add((x <<16) + y);
        int deep = 0;
        while (!queue.isEmpty()){
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int cx = queue.poll();
                int cy = cx & 0xffff;
                cx >>= 16;
                if(arr[cx][cy] == tar) return new int[]{(cx << 16)+cy,deep};
                for (int j = 0; j < 4; j++) {
                    int tx = cx + dx[j];
                    int ty = cy + dy[j];
                    if(tx < 0 || tx >= arr.length || ty < 0 || ty >= arr[0].length || arr[tx][ty] == 0 ){
                        continue;
                    }
                    if(set.contains((tx << 16) + ty)){
                        continue;
                    }
                    set.add((tx << 16) + ty);
                    queue.offer((tx << 16) + ty);
                }
            }
            deep++;
        }
        return new int[]{-1,-1};


    }
    public int cutOffTree(List<List<Integer>> forest) {
        int m = forest.size();
        int n = forest.get(0).size();
        int[][] arr = new int[m][n];
        PriorityQueue<Integer> pq  = new PriorityQueue<>(((o1, o2) -> o1-o2));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = forest.get(i).get(j);
                if(arr[i][j] > 1)   {
                    pq.offer(arr[i][j]);
                }
            }
        }
        if(arr[0][0] == 0)   return -1;
        int cx = 0;
        int cy = 0;
        int res = 0;
        while (!pq.isEmpty()){
            // 从当前位置搜索下一个最小数
            int[] t = bfs(cx,cy,arr,pq.poll());
            if(t[0] == -1)  return -1;
            cx = t[0] >> 16;
            cy = t[0] & 0xffff;
            arr[cx][cy] = 1;
            res += t[1];
        }
        return res;

    }
}
```





# 拓扑排序

## [310. 最小高度树](https://leetcode-cn.com/problems/minimum-height-trees/)

🔴😒

```java
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> ans = new ArrayList<Integer>();
        if (n == 1) {
            ans.add(0);
            return ans;
        }
        int[] degree = new int[n];
        List<Integer>[] adj = new List[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        Queue<Integer> queue = new ArrayDeque<Integer>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                queue.offer(i);
            }
        }
        int remainNodes = n;
        while (remainNodes > 2) {
            int sz = queue.size();
            remainNodes -= sz;
            for (int i = 0; i < sz; i++) {
                int curr = queue.poll();
                for (int v : adj[curr]) {
                    degree[v]--;
                    if (degree[v] == 1) {
                        queue.offer(v);
                    }
                }
            }
        }
        while (!queue.isEmpty()) {
            ans.add(queue.poll());
        }
        return ans;
    }
}


```



# 滑动窗口

## [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)

😜😋

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        Map<String, Integer> map = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        for(String word : words){
            map.put(word, map.getOrDefault(word, 0)+1);
        }
        int n = s.length();
        int p = words[0].length();
        for(int i=0; i<p; ++i){
            Map<String, Integer> tmp = new HashMap<>();
            int cnt = 0;
            // 每p个为一组进行扫描
            // j表示以j为结尾的子字符串能匹配多少words cnt为计数值
            for(int j=i+p-1; j<n; j+=p){
                String cur = s.substring(j-p+1, j+1);
                if(map.getOrDefault(cur, -1) == -1){
                    tmp.clear();
                    cnt = 0;
                    continue;
                }
                // 未把cur使用完或者未使用直接加入tmp并更新计数值即可
                if(map.getOrDefault(cur, -1) > tmp.getOrDefault(cur, 0)){
                    tmp.put(cur, tmp.getOrDefault(cur, 0)+1);
                    cnt++;
                }else{
                    // 计算出起始位置
                    int left = j-p+1-cnt*p;
                    // 当把cur使用完了那么就需要左指针向右移动
                    while(map.get(cur) == tmp.get(cur)){
                        String del = s.substring(left, left+p);
                        tmp.put(del, tmp.get(del)-1);
                        left += p;
                        cnt--;
                    }
                    tmp.put(cur, tmp.getOrDefault(cur, 0)+1);
                    cnt++;
                }
                // 以当前j为结尾的子字符串完全匹配words 计算出左指针加入答案即可
                if(cnt == words.length){
                    ans.add(j-cnt*p+1);
                }
            }
        }
        //ans.sort();
        return ans;
    }
}
```



# 二分

## [ 寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)

🔴🔴😒

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int left = (m+n+1) / 2;
        int right = (m+n+2) / 2;
        return (findKth(nums1,0,nums2,0,left) + findKth(nums1,0,nums2,0,right))/2.0;
    }
    // i -> nums1 起始位置 
    // j -> nums2 起始位置
    private int findKth(int[] nums1, int i, int[] nums2, int j, int k){
        if(i >= nums1.length)   return nums2[j+k-1];
        if(j >= nums2.length)   return nums1[i+k-1];
        if(k == 1)  return Math.min(nums1[i], nums2[j]);
        int m1 = (i + k / 2 - 1 < nums1.length) ? nums1[i+k/2-1] : Integer.MAX_VALUE;
        int m2 = (j + k / 2 - 1 < nums2.length) ? nums2[j+k/2-1] : Integer.MAX_VALUE;
        if(m1 < m2){
            return findKth(nums1, i+k/2, nums2, j, k-k/2);
        }else{
            return findKth(nums1, i, nums2, j+k/2, k-k/2);
        }
    }
}
```





# Rolling Hash



## [Remove Two Letters](https://codeforces.com/contest/1800/problem/D)

🔴🔴

```c++
#include <bits/stdc++.h>
using namespace std;
using UC= unsigned char;
using US = unsigned short;
using UI = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int,int>;
using PLL = pair<long long ,long long>;
const int INF = 0X3F3F3F3F;
const int MOD = 1e9+7;
inline int mod(int x) { return x >= MOD ? x - MOD : x; }
// 2023-03-03 11:08:58
// START CUT
const int K = 2;
typedef array<int, K> vec;
vec P = {342325337, 342325331};
// vec P = {(int)1e9 + 7, (int)1e9 + 9};
vec operator *(const vec& a, const vec& b) {
    return {(int)(1LL * a[0] * b[0] % MOD), (int)(1LL * a[1] * b[1] % MOD)};
}
vec operator +(const vec& a, const vec& b) {
    return {mod(a[0] + b[0]), mod(a[1] + b[1])};
}
vec operator -(const vec& a, const vec& b) {
    return {mod(a[0] + MOD - b[0]), mod(a[1] + MOD - b[1])};
}
vec operator *(const vec& a, int b) { return a * vec{b, b}; };
vec operator +(const vec& a, int b) { return a + vec{b, b}; };
vec operator -(const vec& a, int b) { return a - vec{b, b}; };
 
struct RollingHash {
    vector<vec> p, pre;
    RollingHash(const string& s) {
        int n = s.size();
        p.resize(n + 1);
        pre.resize(n + 1);
        p[0] = {1, 1};
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] * P + (s[i] - 'a');
            p[i + 1] = p[i] * P;
        }
    }
    // 求s[L] ~ s[R-1]的hash
    vec query(int L, int R) {
        return pre[R] - pre[L] * p[R - L];
    }
};
// END CUT
 
int main() {
    int cas;
    cin >> cas;
    while (cas--) {
        int n;
        string s;
        cin >> n >> s;
        RollingHash H(s);
        set<vec> A;
        for (int i = 0; i + 2 <= n; ++i) {
            auto L = H.query(0, i);
            auto R = H.query(i + 2, n);
            auto cur = H.p[n - i - 2] * L + R;
            A.insert(cur);
        }
        cout << A.size() << '\n';
    }
    return 0;
}
```



# 换根DP

## [统计可能的树根数目](https://leetcode.cn/problems/count-number-of-possible-root-nodes/)

🔴

```c++
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int,int>;
using PLL = pair<LL ,LL>;
using PULL = pair<ULL ,ULL>;
const int INF = 0X3F3F3F3F;
const int MOD = 1e9+7;
inline int mod(int x) { return x >= MOD ? x - MOD : x; }

// 2023-03-06 11:12:56
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1, cnt = 0,ans = 0;;
        vector<vector<int>> g(n);
        set<PII> f;
        for (const auto &edge: edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        for (const auto &guess: guesses) f.insert({guess[0], guess[1]});
        vector<bool> used(n,false);
        used[0] = true;
        // 以0为根时记录有多少被猜出来了
        function<void(int)> dfs_tree = [&](int node){
            for (const auto &nxt: g[node]){
                if(used[nxt]) continue;
                if(f.find({node, nxt}) != f.end())  ++cnt;
                used[nxt] = true;
                dfs_tree(nxt);
                used[nxt] = false;
            }
        };
        dfs_tree(0);
        if(cnt >= k)    ++ans;
        // 换根
        function<void(int,int)> dfs = [&](int node,int cnt){
            for (const auto &nxt: g[node]){
                if(used[nxt]) continue;
                // 这里必须申请一个新变量存储cnt，
                // 如果直接对cnt操作是错误的，直接对cnt操作可以理解为nxt的兄弟节点会影响nxt节点
                int p = cnt;
                if(f.find({node, nxt}) != f.end())  --p;
                if(f.find({nxt,node}) != f.end())   ++p;
                if(p >= k) ++ans;
                used[nxt] = true;
                dfs(nxt, p);
            }
        };
        dfs(0,cnt);
        return ans;

    }
};


```



## [Problem - 219D - Codeforces](https://codeforces.com/problemset/problem/219/D)

🔴

```c++
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int,int>;
using PLL = pair<LL ,LL>;
using PULL = pair<ULL ,ULL>;
const int INF = 0X3F3F3F3F;
const int MOD = 1e9+7;
inline int mod(int x) { return x >= MOD ? x - MOD : x; }

// 2023-03-06 11:12:56
// https://leetcode.cn/problems/count-number-of-possible-root-nodes/
//class Solution {
//public:
//    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
//        int n = edges.size() + 1, cnt = 0,ans = 0;;
//        vector<vector<int>> g(n);
//        set<PII> f;
//        for (const auto &edge: edges){
//            g[edge[0]].push_back(edge[1]);
//            g[edge[1]].push_back(edge[0]);
//        }
//
//        for (const auto &guess: guesses) f.insert({guess[0], guess[1]});
//        vector<bool> used(n,false);
//        used[0] = true;
//        function<void(int)> dfs_tree = [&](int node){
//            for (const auto &nxt: g[node]){
//                if(used[nxt]) continue;
//                if(f.find({node, nxt}) != f.end())  ++cnt;
//                used[nxt] = true;
//                dfs_tree(nxt);
//                used[nxt] = false;
//            }
//        };
//        dfs_tree(0);
//        if(cnt >= k)    ++ans;
//        function<void(int,int)> dfs = [&](int node,int cnt){
//            for (const auto &nxt: g[node]){
//                if(used[nxt]) continue;
//                int p = cnt;
//                if(f.find({node, nxt}) != f.end())  --p;
//                if(f.find({nxt,node}) != f.end())   ++p;
//                if(p >= k) ++ans;
//                used[nxt] = true;
//                dfs(nxt, p);
//            }
//        };
//        dfs(0,cnt);
//        return ans;
//
//    }
//};

int main() {
    int n = 0,cnt = 0;
    set<PII> s;
    cin>>n;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        s.insert({a,b});
    }
    vector<bool> used(n+1,false);
    used[1] = true;
    function<void(int)> dfs_1 = [&](int node){
        for (const auto &nxt: g[node]){
            if(used[nxt]) continue;
            if(s.find({node, nxt}) == s.end())    ++cnt;
            used[nxt] = true;
            dfs_1(nxt);
            used[nxt] = false;
        }
    };
    dfs_1(1);
    int ans = cnt;
    vector<int> v = {1};
    function<void(int, int)> dfs_2 = [&](int node, int cnt){
        for (const auto &nxt: g[node]){
            if(used[nxt]) continue;
            int p = cnt;
            if(s.find({node, nxt}) == s.end())    --p;
            else    ++p;
            if(p == ans){
                v.push_back(nxt);
            }else if(p < ans){
                ans = p;
                v.clear();
                v.push_back(nxt);
            }
            used[nxt] = true;
            dfs_2(nxt, p);
        }
    };
    dfs_2(1,cnt);
    sort(v.begin(),v.end());
    cout<<ans<<endl;
    for (const auto &item: v){
        cout<<item<<' ';
    }


    return 0;
}

```



# 求逆序对

## 暴力求解

略

## 归并排序

```c++
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
            ans += mid - i + 1;	// [i,mid]中的每个值都比a[j]大 故应增加逆序对mid - i + 1个
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
```



## 树状数组

// TODO