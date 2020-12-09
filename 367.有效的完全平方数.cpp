/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)return true;
        int left = 1, right = num / 2 + 1;
        long mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(mid * mid == num){
                return true;
            }
            else if(mid * mid < num){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return false;
    }
};
// @lc code=end

