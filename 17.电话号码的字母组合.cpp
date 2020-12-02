/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> solve(int i, string numbers, unordered_map<char, string> letters, vector<string> result)
    {
        string map_letters = letters[numbers[i]];
        if (i == numbers.size())
            return result;
        vector<string> new_result;
        for (int j = 0; j < map_letters.size(); j++)
        {
            for (auto r : result)
            {
                new_result.push_back(r + map_letters[j]);
            }
        }
        return solve(i + 1, numbers, letters, new_result);
    }
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mapping;
        mapping['1'] = "";
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
        vector<string> result;
        if (digits == "")
            return result;
        result.push_back("");
        return solve(0, digits, mapping, result);
    }
};
// @lc code=end

