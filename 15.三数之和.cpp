/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> r(3);
        vector<vector<int>> result(0);
        int n = nums.size();
        int L, R;
        if (n < 3)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            if (nums[i] > 0)
                break;
            L = i + 1;
            R = n - 1;
            while (L < R)
            {
                while (nums[i] + nums[L] + nums[R] == 0)
                {
                    if (nums[L] == nums[L + 1] && L + 1 < R)
                    {
                        L++;
                        continue;
                    }
                    if (nums[R] == nums[R - 1] && L < R - 1)
                    {
                        R--;
                        continue;
                    }
                    r[0] = nums[i];
                    r[1] = nums[L];
                    r[2] = nums[R--];
                    result.push_back(r);
                    break;
                }
                if (nums[i] + nums[L] + nums[R] > 0)
                {
                    R--;
                    continue;
                }
                if (nums[i] + nums[L] + nums[R] < 0)
                {
                    L++;
                    continue;
                }
            }
        }
        return result;
    }
};
// @lc code=end

