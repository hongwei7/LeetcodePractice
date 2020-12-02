/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        for(i = nums.size() -2; i >= 0 ; i--){
            if (nums[i] < nums[i+1]){
                break;
            }
        }
        if(i != -1){
            for(j = nums.size() - 1; j > i; j--){
                if(nums[j] > nums[i]){
                    int t = nums[i];
                    nums[i] = nums[j];
                    nums[j] = t;
                    break;
                }
            }
        }
        reverse(nums.begin () + i + 1, nums.end());
        return;
    }
};
// @lc code=end

