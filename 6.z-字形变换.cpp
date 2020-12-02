/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string r ="";
        for (int k = 0; k < numRows; k++)
        {
            for (int i = k; i < s.size(); i += 2 * (numRows - 1))
            {
                r.append(1, s[i]);
                if (i + 2 * (numRows - k - 1) < s.size() && k != 0 && k != numRows - 1)
                    r.append(1, s[i + 2 * (numRows - k - 1)]);
            }
        }
        return r;
    }
};
// @lc code=end

