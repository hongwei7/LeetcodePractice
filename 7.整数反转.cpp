/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long y = 0;
        int max = 0x7fffffff, min = 0x80000000; //2^31-1=2147483647,-2^31=-2147483648
        while (x != 0)
        {
            y = 10 * y + x % 10;
            x = x / 10;
        }
        return y > max || y < min ? 0 : y;
    }
};
// @lc code=end

