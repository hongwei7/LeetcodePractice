/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int energy = 1;
        for(int i = 0; i < nums.size(); i++){
            energy--;
            energy=max(energy, nums[i]);
            if(energy==0){
                return i==nums.size()-1;
            }
        }
        return true;
    }
};
// @lc code=end

