/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        string con = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            for (int j = 0; j < con.size(); j++)
            {
                if (strs[i][j] != con[j])
                {
                    con = con.substr(0, j);
                    break;
                }
            }
        }
        return con;
    }
};
// @lc code=end

