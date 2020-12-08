/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return false;
		int top = 0, bottom = matrix.size(), left = 0, right = matrix[0].size();
        int mid;
        int row = -1;
        while(top < bottom){
            mid = top + (bottom - top) / 2;
            if(matrix[mid][0] <= target && matrix[mid][matrix[0].size() - 1] >= target){
				row = mid;
                break;
            }
            else if(matrix[mid][0] > target){
                bottom = mid;
            }
            else{
                top = top + 1;
            }
        }
        cout << row << endl;
        if(row == -1)return false;
        while(left < right){
            //cout << left << " " << right << " " << left + (right - left)/2 << endl;
            mid = left + (right - left) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

