/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    int getnum(vector<int> now){
        int result = 0;
        for(auto i : now){
            result = 2*result + i;
        }
        return result;
    }
    void solve(int x, vector<int> now, vector<int>& result){
        if(x == now.size()){
            result.push_back(getnum(now));
            return;
        }
        now[x] = 0;
        solve(x + 1, now, result);
        now[x] = 1;
        solve(x + 1, now, result);
    }
    vector<int> grayCode(int n) {
        vector<int> result;
        vector<int> now(n, 0);
        solve(0, now, result);
        return result;
    }
};
// @lc code=end

