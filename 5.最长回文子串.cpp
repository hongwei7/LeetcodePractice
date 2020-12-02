/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string tokenize(const std::string &s)
    {
        if (!s.size())
        {
            return "";
        }
        std::stringstream ss;
        ss << s[0];
        for (int i = 1; i < s.size(); i++)
        {
            ss << '|' << s[i];
        }
        return ss.str();
    }
    string longestPalindrome(string s)
    {
        s = tokenize(s);
        //cout << s << endl;
        int max_pa_length = 0;
        string max_pa_str = s.substr(0, 1);
        int pa_length;
        int i, j;
        for (i = 0; i < s.size(); i++)
        {
            pa_length = (s[i] == '|') ? 0 : 1;
            for (j = 1; i - j >= 0 && i + j < s.size(); j++)
            {
                if (s[i - j] == '|')
                    continue;
                if (s[i - j] == s[i + j])
                {
                    pa_length += 2;
                }
                else
                {
                    break;
                }
            }
            if (pa_length > max_pa_length)
            {
                max_pa_length = pa_length;
                max_pa_str = s.substr(i - j + 1, 2 * j - 1);
            }
        }
        std::stringstream ss;
        for (int i = 0; i < max_pa_str.size(); i++)
        {
            if (max_pa_str[i] != '|')
                ss << max_pa_str[i];
        }
        return ss.str();
    }
};
// @lc code=end

