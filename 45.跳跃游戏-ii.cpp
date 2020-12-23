/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int decide(vector<int>& nums, int energy, int now){
        if(now == nums.size() - 1){
            return 0;
        }
        int maxEnergy = 0, maxI = 0;
        for(int i = now + 1; i <= energy + now && i < nums.size(); i++){
            // cout << i << endl;
            if(i == nums.size() - 1)return 1;
            if(maxEnergy <= nums[i]){
                maxEnergy = nums[i];
                maxI = i;
            }
        }
        cout << "move to " << maxI  << " energy " << maxEnergy << endl;
        return decide(nums, maxEnergy, maxI) + 1;
    }
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)return 0;
        int energy = nums[0];
        return decide(nums, energy, 0);
    }
};
// @lc code=end

