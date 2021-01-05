/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string read(string s){
        string result = "";
        int count = 0;
        char temp = s[0];
        for(auto si : s){
            if(si != temp){
                result += count + '0';
                result += temp;
                count = 1;
                temp = si;
            }else{
                count++;
            }
        }
        result += count + '0';
        result += temp;
        return result;
    }
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n; i++){
            result = read(result);
        }
        return result;
    }
};
// @lc code=end

