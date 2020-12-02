/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            for(int l = 0; l < 2; l++){
                if(l == 0)dp[l] = max(dp[0], dp[1] + prices[i]);
                else dp[l] = max(dp[1], dp[0] - prices[i]);
            }
        }
        return dp[0];
    }
};
// @lc code=end

