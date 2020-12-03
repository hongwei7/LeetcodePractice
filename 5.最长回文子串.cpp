/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:

    string longestPalindrome(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        string result;
        for(int len = 0; len < s.size(); len++){
            for(int i = 0,j = i + len; j < s.size(); i++,j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else{
                    if(i + 1 == j){
                        dp[i][j] = dp[i][j-1]&&(s[i] == s[j]);
                    }
                    else{
                        dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                    }
                }
                if(dp[i][j] && result.size() < j - i + 1){
                    result = s.substr(i, j - i + 1);
                }
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return result;
    }
};
// @lc code=end

