/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)return 0;
        int left = 0, right = nums.size(), mid;
        while(left < right){
            mid = left + ( (right - left) / 2 );
            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                right = mid;
            }
            else{
                left = mid + 1;
            }                
        }
        return left;
    }
};
// @lc code=end

