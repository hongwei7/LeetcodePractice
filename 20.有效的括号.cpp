/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> a;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                a.push(s[i]);
            }
            else
            {
                if (a.empty())
                    return false;
                if (!(a.top() == s[i] - 1 || a.top() == s[i] - 2))
                    return false;
                a.pop();
            }
        }
        if (!a.empty())
            return false;
        return true;
    }
};
// @lc code=end

