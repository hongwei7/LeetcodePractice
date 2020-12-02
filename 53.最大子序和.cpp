/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = nums[0];
        int maxS = pre;
        for(int i = 1; i < nums.size(); i++){
            pre = max(pre + nums[i], nums[i]);
            maxS = max(maxS, pre);
        }
        return maxS;
    }
};
// @lc code=end

