/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    bool check(vector<string>& map, int row, int col, int n){
        for(int i = 0; i < n; i++){
            if(i != row && map[i][col] == map[row][col])return false;
        }
        for(int i = 0; i < n; i++){
            if(i != col && map[row][i] == map[row][col])return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(map[i][j] == map[row][col])return false;
        }
        for(int i = row + 1, j = col + 1; i < n && j < n; i++, j++){
            if(map[i][j] == map[row][col])return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(map[i][j] == map[row][col])return false;
        }
        for(int i = row + 1, j = col - 1; i < 0 && j >= 0; i++, j--){
            if(map[i][j] == map[row][col])return false;
        }
        return true;
    }
    void solve(vector<string>& map, int row, int col, int n, int& result){
        map[row][col] = 'Q';
        // cout << endl;
        // for(auto row : map){
        //     cout << row << endl;
        // }
        if(check(map, row, col, n)){
            if(row == n - 1){
                result++;
            }
            else{
                solve(map, row + 1, 0, n, result);
            }
        }
        if(col < n - 1){
            map[row][col] = '.';
            solve(map, row, col + 1, n, result);
        }
        map[row][col] = '.';
        return;
    }
    int totalNQueens(int n) {
        int result = 0;
        if(n == 0)return result;
        string temp = "";
        for(int i = 0; i <n; i++){
            temp += ".";
        }
        vector<string> map(n, temp);
        solve(map, 0, 0, n, result);
        return result;
    }
};
// @lc code=end

