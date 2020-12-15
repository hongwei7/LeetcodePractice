/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:

    vector<int> grayCode(int n) {
        vector<int> result;
        vector<int> now(n, 0);
        solve(0, now, result);
        return result;
    }
};
// @lc code=end

