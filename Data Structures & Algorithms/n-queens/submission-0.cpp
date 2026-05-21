class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string blank="";
        for(int i=0;i<n;i++) {
            blank+=".";
        }
        vector<string> blank_board;
        for(int i=0;i<n;i++) {
            blank_board.push_back(blank);
        }
        vector<vector<string>> ans;
        vector<bool> cols(n, false), negDiag(n*2, false), posDiag(n*2, false);
        backtrack(ans, blank_board, 0, n, cols, negDiag, posDiag);
        return ans;

    }

    void backtrack(vector<vector<string>>& ans, vector<string>& board, int r, int n, vector<bool>& cols, vector<bool>& negDiag, vector<bool>& posDiag) {
        if(r==n) {
            ans.push_back(board);
            return ;
        }

        for(int c=0;c<n;c++) {
            if(cols[c] || negDiag[r-c+n] || posDiag[r+c]) {
                continue ;
            }
            board[r][c]='Q';
            cols[c]=true;
            negDiag[r-c+n]=true;
            posDiag[r+c]=true;

            backtrack(ans, board, r+1, n, cols, negDiag, posDiag);

            
            cols[c]=false;
            negDiag[r-c+n]=false;
            posDiag[r+c]=false;
            board[r][c]='.';
        }
    }
};
