/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution
{
public:
    void swap(char &i, char &j)
    {
        char temp = i;
        i = j;
        j = temp;
    }
    string solve(string s)
    {
        unordered_set<char> k;
        if (s.size() <= 1)
            return s;
        string tail;
        for (int i = 1; i < s.size(); i++)
        {
            //cout << s[0] << " " << s[i] << endl;
            if (s[0] != s[i] && k.find(s[i]) == k.end())
            {
                k.insert(s[i]);
                swap(s[1], s[i]);
                tail = solve(s.substr(1, s.size() - 1));
                if (tail == "")
                {
                    swap(s[1], s[i]);
                    continue;
                }
                else
                    return s[0] + tail;
            }
        }
        return "";
    }
    string reorganizeString(string S)
    {
        unordered_set<char> k;
        for (int i = 0; i < S.size(); i++)
        {
            if (k.find(S[i]) == k.end())
            {
                k.insert(S[i]);
                swap(S[0], S[i]);
                string result = solve(S);
                swap(S[0], S[i]);
                if (result != "")
                    return result;
            }
        }
        return "";
    }
};
// @lc code=end

