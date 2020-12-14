/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    void solve(vector<int>& nums, int target, int x, vector<vector<int>>& result, vector<int>& now){ 
        if(target == 0){
            result.push_back(now);
            return;
        }
        if(x == nums.size())return;
        if(x < nums.size() - 1){
            int t = x + 1;
            while(t != nums.size() && nums[t] == nums[x])t++;
            if(t != nums.size() && nums[t] != nums[x])solve(nums, target, t, result, now);
        }
        if(target >= nums[x]){
            now.push_back(nums[x]);
            solve(nums, target - nums[x], x + 1, result, now);
            now.pop_back();
        }
    }
        vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() == 0)return result;
        sort(nums.begin(), nums.end());
        vector<int> now;
        solve(nums, target, 0, result, now);
        return result;
    }
};
// @lc code=end

