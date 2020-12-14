/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    void solve(vector<int>& nums, int target, int x, vector<vector<int>>& result, vector<int>& now){ 
        if(target == 0){
            result.push_back(now);
            return;
        }
        if(x < nums.size() - 1){
            solve(nums, target, x + 1, result, now);
        }
        if(target >= nums[x]){
            now.push_back(nums[x]);
            solve(nums, target - nums[x], x, result, now);
            now.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() == 0)return result;
        vector<int> now;
        solve(nums, target, 0, result, now);
        return result;
    }
};
// @lc code=end

