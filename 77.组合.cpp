/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void solve(vector<int>&nums, int x, vector<vector<int>>& result, vector<int>& now, int k){
        if(nums.size() - x < k)return;
        if(0 == k){
            result.push_back(now);
            return;
        }
        if(x <= nums.size() - 1){
            now.push_back(nums[x]);
            solve(nums, x + 1, result, now, k - 1);
            now.pop_back();
            solve(nums, x + 1, result, now, k);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n == 0 || k == 0)return result;
        vector<int> nums;
        for(int i = 1; i <=n; i++){
            nums.push_back(i);
        }
        vector<int> now;
        solve(nums, 0, result, now, k);
        return result;
    }
};
// @lc code=end

