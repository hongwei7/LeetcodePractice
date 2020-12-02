#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int dp = 0;
        int minPrices = prices[0];
        for(int i = 1; i < prices.size(); i++){
            dp = max(dp, -minPrices + prices[i]);
            minPrices = min(minPrices, prices[i]);
        }
        return dp;
    }
};
// @lc code=end

