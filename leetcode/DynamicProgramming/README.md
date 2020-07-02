# DP问题三步走
https://zhuanlan.zhihu.com/p/91582909
- 1. 找到二维数组元素含义
- 2. 找关系式
- 3. 确定初始值

# DP问题总结
https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns
* 到达目标的最小代价

routes[i] = min(routes[i-1], routes[i-2], ... , routes[i-k]) + cost[i]

* 共有几种方案

routes[i] = routes[i-1] + routes[i-2], ... , + routes[i-k]

* 区间合并

dp[i][j] = dp[i][k] + result[k] + dp[k+1][j]

* 字符串相关
```
// i - indexing string s1
// j - indexing string s2
if (s1[i-1] == s2[j-1]) {
  dp[i][j] = /*code*/;
} else {
  dp[i][j] = /*code*/;
}
```

* 决策问题

dp[i][j] = max({dp[i][j], dp[i-1][j] + arr[i], dp[i-1][j-1]});