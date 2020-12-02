/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int maxk, vector<int> &prices)
    {
        if(prices.size() <= 1 || maxk ==0)return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(maxk, vector<int>(2)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        for (int k = 1; k < maxk; k++)
        {
            dp[0][k][0] = INT_MIN;
            dp[0][k][1] = INT_MIN;
        }
        for (int i = 1; i < prices.size(); i++)
        {
            for (int k = 0; k < maxk; k++)
            {
                int temp = (k != 0) ? dp[i - 1][k - 1][0] : 0;
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], (temp < 0) ? dp[i - 1][k][1] : temp - prices[i]);
            }
        }
        int maxPro = INT_MIN;
        for (int i = 0; i < maxk; i++)
        {
            maxPro = max(maxPro, dp[prices.size() - 1][i][0]);
        }
        
        return maxPro;
    }
};
// @lc code=end

