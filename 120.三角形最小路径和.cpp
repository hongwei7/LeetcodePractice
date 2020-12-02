/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size()));
        dp[0][0] = triangle[0][0];
        int mindp = INT_MAX;
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j < i + 1; j++){
                if(j == 0)dp[i][j] = dp[i-1][0] + triangle[i][j];
                else if(j == i)dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        for(int i = 0; i < triangle[triangle.size()-1].size(); i++){
            mindp = min(mindp, dp[triangle.size()-1][i]);
        }
        return mindp;
    }
};
// @lc code=end

