/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int amax;
        amax = min(height[j], height[i]) * (j - i);
        while (i < j)
        {
            amax = max(amax, (min(height[j], height[i]) * (j - i)));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return amax;
    }
};
// @lc code=end

