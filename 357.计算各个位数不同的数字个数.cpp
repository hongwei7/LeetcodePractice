/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        n = min(n, 10);
        int ans = 10, base = 9, sum = 9;
        for (int i = 1; i < n; ++i)
        {
            ans += sum *= base--;
        }
        return ans;
    }
};
                                    // @lc code=end
