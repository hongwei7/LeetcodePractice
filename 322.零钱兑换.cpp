/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
// @lc code=end

