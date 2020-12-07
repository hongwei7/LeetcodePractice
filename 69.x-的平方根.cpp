/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long left = 0, right = INT_MAX, mid, ans = right;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(mid * mid == x){
                return mid;
            }
            else if(x < mid * mid){
                right = mid - 1;
            }
            else{
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

