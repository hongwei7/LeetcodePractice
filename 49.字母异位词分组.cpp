/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string& si : strs){
            string t = si;
            sort(t.begin(), t.end());
            map[t].push_back(si);
        }
        vector<vector<string>>result;
        for(auto i = map.begin(); i != map.end(); i++){
            result.push_back(i->second);
        }
        return result;
    }
};
// @lc code=end

