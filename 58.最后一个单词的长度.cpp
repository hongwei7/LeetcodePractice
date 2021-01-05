/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int j = s.size() - 1;
        for(; j >= 0 ; j--){
            if(s[j] != ' ')
                break;
        }
        for(int i = j; i >= 0; i--){
            if(s[i] == ' ')
                return count;
            count++;
        }
        return count;
    }
};
// @lc code=end

