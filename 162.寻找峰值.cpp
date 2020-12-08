// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem162.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int left, int right){
        int mid = left + (right - left) / 2;
        if(left < right){
            if(nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
            return search(nums, left, right);
        }
        return left;
    }
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        return search(nums, left, right);
    }
};
// @lc code=end

