/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)return 1;
        sort(nums.begin(), nums.end());
        if(nums[0]>1)return 1;
        int result = 0;
        for(int i = 0; i <nums.size(); i++){
            if(nums[i] > result){
                if(result + 1 != nums[i])
                    return result + 1;
                else{
                    result ++;
                }
            }
            else if(nums[i]>=0){
                result = nums[i];
            }
        }
        return (result>=0)?result + 1: 1;
    }
};
// @lc code=end

