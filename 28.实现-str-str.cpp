/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "" || haystack == needle) return 0;
        int range = (int(haystack.size()) - int(needle.size()));
        if (haystack == "" || range < 0) return -1;
        int i;
        for(i =0 ; i <= range; i++){
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
        return -1;
    }
};
// @lc code=end

