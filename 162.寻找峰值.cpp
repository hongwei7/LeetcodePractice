/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		if(nums.size() <= 1)return 0;
        if(nums.size() == 2)return nums[1] > nums[0];
        int left = 0, right = nums.size();
        int mid;
        while(left < right){
			mid = left + (right - left) / 2;
            //cout <<left<<right<<mid<<endl;
            if(mid == 0)return 0;
            if(mid == nums.size() - 1)return (nums[mid]>nums[mid - 1])? mid: mid - 1;
            if(nums[mid] > nums[mid + 1] && nums[mid - 1] < nums[mid]){
				return mid;
            }
            else if(nums[mid] > nums[mid + 1]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

