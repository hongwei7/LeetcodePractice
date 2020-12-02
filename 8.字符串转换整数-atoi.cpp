/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        long x = 0;
        int nsigned = 0;  //记录是否已经读取到符号 -1为加号 +1为减号
        int numbered = 0; //记录是否已经读取过数字
        char t;
        for (int i = 0; i < str.size(); i++)
        {
            t = str[i];
            if (t == '-' || t == '+')
            {
                if (nsigned != 0 || numbered == 1)
                    break;
                else
                {
                    if (t == '-')
                        nsigned = 1;
                    else
                        nsigned = -1;
                }
            }
            else if (t == ' ' && numbered == 0 && nsigned == 0)
                continue;
            else if ((t < '0' || t > '9'))
            {
                if (numbered == 1)
                    break;
                else
                    return 0;
            }
            else
            {
                x = 10 * x + t - '0';
                if ((nsigned != 1) && x > INT_MAX)
                    return INT_MAX;
                if ((nsigned == 1) && -x < INT_MIN)
                    return INT_MIN;
                numbered = 1;
            }
        }
        if (nsigned == 1)
            x = -x; //跳出循环后若已经读取到减号,则取负数
        return x;
    }
};
// @lc code=end

