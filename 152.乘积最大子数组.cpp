/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = INT_MIN;
        vector<int> dp1(nums.size()), dp2(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                dp1[i] = nums[0];
                dp2[i] = nums[0];
            }
            else {
                dp1[i] = max(dp1[i - 1] * nums[i], max(nums[i], dp2[i-1] * nums[i]));
                dp2[i] = min(dp2[i - 1] * nums[i], min(nums[i], dp1[i-1] * nums[i]));
            }
            maxP = max(maxP, dp1[i]);
        }
        return maxP;
    }
};
// @lc code=end

