/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> occ;
        int n = s.size();
        if (!n)
            return 0;
        int max = 0;
        int i = 0, j = 0;
        for (; i < n; i++)
        {
            if (occ.find(s[i]) == occ.end())
            {
                occ.insert(s[i]);
            }
            else
            {
                while (occ.find(s[i]) != occ.end())
                {
                    occ.erase(s[j++]);
                }
                occ.insert(s[i]);
            }
            if (max < i - j)
                max = i - j;
        }
        return max + 1;
    }
};
// @lc code=end

