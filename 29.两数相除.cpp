/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        //cout << INT_MAX << " " << INT_MIN << endl;
        if(dividend == 0)return 0;
        int sign = (dividend >= 0) ? 1 : 0;
        dividend = (dividend > 0) ? ( 0 - dividend ) : dividend;
        sign = (sign == (divisor >= 0))? 1 : -1;
        divisor = (divisor > 0) ? (0 - divisor) : divisor;
        int result = 0;
        for (; dividend <= 0;  )
        {
            if(result >= INT_MAX && sign == 1)
                return INT_MAX;
            else if(-result <= INT_MIN && sign == -1)
                return INT_MIN;
            result++;
            dividend -= divisor;
            //cout << dividend << " " << result << endl;
        }
        
        return (result - 1) * sign;

    }
};
// @lc code=end

