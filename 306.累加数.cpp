// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem306.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
class Solution {
public:
    bool backtrack(string & num, long left, long right, int now){
        if(now == num.size()){
            return true;
        }
        for (int i = now; i <= num.size(); i++){
            long temp = stol(num.substr(now, i - now + 1), nullptr);
            // cout << left << " + " << right << " = " << temp << endl;
            if(left + right == temp){
                // cout << left << " + " << right << " = " << temp << endl;
                if(backtrack(num, right, temp, i + 1)){
                    return true;
                }
                else return false;
            }
            if (num[now] == '0')
                return false;
            if(left + right < temp){
                return false;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        for (int i = 0; i < num.size() - 1; i++)
        {
            string t1 = num.substr(0, i + 1);
            for (int j = i + 2; j < num.size(); j++)
            {
                string t2 = num.substr(i + 1, j - i - 1);
                // cout << t1 << " " << t2 << " : ";
                long l = stol(t1, nullptr);
                long r = stol(t2, nullptr);
                // cout << l << " " << r << endl;
                if (backtrack(num, l, r, j))
                {
                    return true;
                }
                if(r == 0){
                    break;
                }
            }
            if(num[0] == '0'){
                break;
            }
        }
        return false;
    }
};
// @lc code=end

