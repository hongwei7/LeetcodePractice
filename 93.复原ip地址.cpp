/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    void backtrack(string& s, int now,string nows, int remain, vector<string>& result){
        if(remain == 0){
            if(now == s.size()){
                // cout << nows << endl;
                result.push_back(nows);
            }
            return;
        }
        string dot = (nows.size()!=0)? ".": "";
        if(s[now] != '0' && now + 2 < s.size() && (stoi(s.substr(now,3)) <= 255 )){
            // cout << (stoi(s.substr(now,3)) ) << " " << (stoi(s.substr(now,3)) < 255 ) << endl;
            backtrack(s, now + 3, nows + dot + s.substr(now,3), remain - 1, result);
        }
        if(s[now] !='0' && now + 1 < s.size()){
            backtrack(s, now + 2, nows + dot + s.substr(now, 2), remain - 1, result);
        }
        if(now < s.size()){
            backtrack(s, now + 1, nows + dot + s[now], remain - 1, result);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.size() < 4)return result;
        backtrack(s, 0, "", 4, result);
        return result;
    }
};
// @lc code=end

