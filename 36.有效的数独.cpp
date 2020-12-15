/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> set;
        for(int i=0; i<9;i++){
            set.clear();
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(set.find(board[i][j])==set.end()){
                    set.insert(board[i][j]);
                }
                else{
                    return false;
                }
            }
            set.clear();
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                if(set.find(board[j][i])==set.end()){
                    set.insert(board[j][i]);
                }
                else{
                    return false;
                }
            }
            set.clear();
            for(int j =0;j<9;j++){
                int i1=i%3*3+j%3;
                int j1=i/3*3+j/3;
                if(board[i1][j1]=='.')continue;
                if(set.find(board[i1][j1])==set.end()){
                    set.insert(board[i1][j1]);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

