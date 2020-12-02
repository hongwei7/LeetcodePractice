/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result(2);
        map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap.find(target - nums[i]) != hashmap.end() && hashmap[target - nums[i]] != i)
            {
                result[1] = i;
                result[0] = hashmap[target - nums[i]];
                return result;
            }
            hashmap[nums[i]] = i;
        }
        return result;
    }
};
// @lc code=end

