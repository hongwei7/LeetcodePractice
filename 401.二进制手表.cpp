/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
public:
    void backtrack(int n, int now, string nowt, string nowm, vector<string>& result){
        if (n == 0)
        {
            if (nowt == "")
            {
                nowt = "0";
            }
            if (nowm == "")
            {
                nowm = "0";
            }
            if (stoi(nowm) < 10)
            {
                nowm = "0" + nowm;
            }
            result.push_back(nowt + ":" + nowm);
            return;
        }
        if(now == 10){
            return;
        }
        if(now <= 3){
            int t1 = (nowt == "") ? pow(2, now) : stoi(nowt) + pow(2, now);
            if(t1 < 12){
                backtrack(n - 1, now + 1, to_string(t1), nowm, result);
            }
            backtrack(n, now + 1, nowt, nowm, result);
        }
        if(now >= 4){
            int t2 = (nowm == "") ? pow(2, now - 4) : stoi(nowm) + pow(2, now - 4);
            if(t2 <= 59){
                backtrack(n - 1, now + 1, nowt, to_string(t2), result);
            }
            backtrack(n, now + 1, nowt, nowm, result);
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        backtrack(num, 0, "", "", result);
        return result;
    }
};
// @lc code=end

