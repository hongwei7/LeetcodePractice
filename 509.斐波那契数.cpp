/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int N)
    {
        if (N == 0)
            return 0;
        int dp[30];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < N; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N - 1];
    }
};
// @lc code=end

