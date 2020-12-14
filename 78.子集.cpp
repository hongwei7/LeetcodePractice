/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
    vector<vector<int>> combine(vector<int> nums, int k) {
        vector<vector<int>> result;
        if(k == 0)return result;
        vector<int> now;
        solve(nums, 0, result, now, k);
        return result;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> t;
        result.push_back(t);
        for(int i = 1; i <= nums.size(); i++){
            vector<vector<int>> temp = combine(nums, i);
            for(auto item : temp){
                result.push_back(item);
            }
        }
        return result;
    }
};
// @lc code=end

