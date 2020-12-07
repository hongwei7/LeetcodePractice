/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    void binarySearch(vector<int>& nums, int target, int& maxi, int& mini, int left, int right){
        int mid;
        if(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                maxi = (maxi <= mid)? mid: maxi;
                mini = (mini >= mid)? mid: mini;
            }
            binarySearch(nums, target, maxi, mini, left, mid - 1);
            binarySearch(nums, target, maxi, mini, mid + 1, right);
        }
        return;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int left = 0, right = nums.size() - 1;
        int maxi = INT_MIN, mini = INT_MAX;
        binarySearch(nums, target, maxi, mini, left, right);
        result.push_back((mini == INT_MAX)? -1: mini);
        result.push_back((maxi == INT_MIN)? -1: maxi);
        return result;
    }
};
// @lc code=end

