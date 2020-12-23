/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    void solve(vector<int>& path, int now, int n, int k, vector<vector<int>>& result){
        if(k == 0){
            if(n == 0){
                result.push_back(path);
            }
            return;
        }
        for(int i = now; i <= 9; i++){
            if(i > n)return;
            path.push_back(i);
            solve(path, i + 1, n - i, k - 1, result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if(k == 0 || n == 0){
            return result;
        }
        vector<int> path;
        int now = 1;
        solve(path, now, n, k, result);
        return result;
    }
};
// @lc code=end

