/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
       reverse(matrix.begin(), matrix.end());
       int i,j;
       for( i=0;i<n;i++){
           for(j=0;j<i;j++){
               swap(matrix[i][j],matrix[j][i]);
           }
       }
    }
};
// @lc code=end

