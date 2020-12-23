/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool check(string& s){
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
    void solve(string& s, vector<string>& nows, int now, vector<vector<string>>&result){
        if(now == s.size()){
            result.push_back(nows);
            return;
        }
        for(int i = s.size() - now; i > 0; i--){
            string temp = s.substr(now, i);
            // cout << temp << " " << check(temp) << endl;
            if(!check(temp)){
                continue;
            }
            else{
                nows.push_back(temp);
                solve(s, nows, now + i, result);
                nows.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.size() == 0)return result;
        vector<string> nows;
        solve(s, nows, 0, result);
        return result;
    }
};
// @lc code=end

