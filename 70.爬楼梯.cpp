/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        int pre1 = 1, pre2 = 2, now = 2;
        for(int i = 2; i < n; i ++){
            now = pre1 + pre2;
            pre1 = pre2;
            pre2 = now;
        }
        return now;
    }
};
// @lc code=end

