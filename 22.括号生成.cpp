/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> solve(int state, vector<string> present, int k, int n, int L)
    {
        if (k == n)
            return present;

        vector<string> Lpresent;
        vector<string> Rpresent;
        if (state < n && L < n / 2 - 1)
            for (int i = 0; i < present.size(); i++)
            {
                Lpresent.push_back(present[i] + '(');
            }
        Lpresent = solve(state + 1, Lpresent, k + 1, n, L + 1);
        if (state > 0)
        {
            for (int i = 0; i < present.size(); i++)
            {
                Rpresent.push_back(present[i] + ')');
            }
            Rpresent = solve(state - 1, Rpresent, k + 1, n, L);
        }
        for (auto str : Rpresent)
        {
            Lpresent.push_back(str);
        }
        return Lpresent;
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if (n == 0)
            return result;
        result.push_back("(");
        result = solve(1, result, 1, 2 * n, 0);
        return result;
    }
};
// @lc code=end

