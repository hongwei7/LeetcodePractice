/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> gather;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (j == nums2.size())
            {
                gather.push_back(nums1[i++]);
            }
            else if (i == nums1.size())
            {
                gather.push_back(nums2[j++]);
            }
            else if (nums1[i] < nums2[j])
            {
                gather.push_back(nums1[i++]);
            }
            else
                gather.push_back(nums2[j++]);
        }
        if (gather.size() % 2)
            return gather[gather.size() / 2];
        else
        {
            double r = gather[gather.size() / 2] + gather[gather.size() / 2 - 1];
            return r / 2;
        }
    }
};
// @lc code=end

