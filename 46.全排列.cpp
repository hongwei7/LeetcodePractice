/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    void solve(vector<int>& nums, unordered_set<int>& exist, vector<int>&now, vector<vector<int>>& result){
        for(auto num : nums){
            if(exist.count(num) == 0){
                exist.insert(num);
                now.push_back(num);
                if(now.size() == nums.size()){
                    result.push_back(now);
                }
                else{
                    solve(nums, exist, now, result);
                }
                now.pop_back();
                exist.erase(num);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0)return result;
        unordered_set<int> exist;
        vector<int> now;
        solve(nums, exist, now, result);
        return result;
    }
};
// @lc code=end

