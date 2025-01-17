/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double quickMul(double x, long long N) {
        if(N == 0)return 1.0;
        else{
            double y = quickMul(x, N / 2);
            if(N % 2 == 0){
                return y * y;
            }
            else return y * y * x;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
// @lc code=end

