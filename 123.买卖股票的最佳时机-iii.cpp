/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = INT_MIN;
        dp[0][1][1] = INT_MIN;
        for(int i = 1; i < prices.size(); i++){
            for(int k = 0; k < 2; k++){
                int temp = (k != 0) ? dp[i - 1][k-1][0] : 0;
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], temp - prices[i]);
                //cout << dp[i][k][0] << " " << dp[i][k][1] << endl;
            }
        }
        return max(dp[prices.size() - 1][0][0], dp[prices.size() - 1][1][0]);
    }
};
// @lc code=end

