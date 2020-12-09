/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp(envelopes.size(), 1);
        int maxn = 0;
        auto comp = [](const vector<int>& v1, const vector<int>& v2) -> bool {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        int i = 0;
        for(auto big : envelopes){
            for(int j = 0; j < i; j++){
                if(big[0] > envelopes[j][0] && big[1] > envelopes[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxn = max(maxn, dp[i]);
            i++;
        }
        return maxn;
    }
};
// @lc code=end

