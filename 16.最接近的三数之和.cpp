/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        int t, l, r;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                t = nums[i] + nums[l] + nums[r];
                if (abs(t - target) < abs(result - target))
                {
                    result = t;
                }
                if (t - target > 0)
                    r--;
                else
                    l++;
            }
        }
        return result;
    }
};
// @lc code=end

