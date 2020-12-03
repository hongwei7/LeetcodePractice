// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem174.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n-1){
                    dp[i][j] = 1;
                }
                else if(i == m-1){
                    dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j+1]);
                }
                else if(j == n-1){
                    dp[i][j] = max(1, dp[i+1][j] - dungeon[i+1][j]);
                }
                else{
                    dp[i][j] = max(1, min(dp[i+1][j] - dungeon[i+1][j], dp[i][j+1] - dungeon[i][j+1] ));
                }
            }
        }
        return max(1, dp[0][0] - dungeon[0][0]);
    }
};
// @lc code=end

