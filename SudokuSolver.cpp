// 37. Sudoku Solver
//
// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// Empty cells are indicated by the character '.'.
//
// You may assume that there will be only one unique solution.

class Solution {
public:
    bool solveSud(vector<vector<char>>& board, int index){
        if(index == 81)
            return true;
        int i = index/9;
        int j = index%9;

        if(board[i][j] != '.')
        	return solveSud(board,index+1);

        else
	        for(char k = '1'; k <= '9'; k++){
	        	if(check(board,i,j,k)){
	        		board[i][j] = k;
	        		if(solveSud(board,index+1))
	        			return true;
	        		else
	        			board[i][j] = '.';
	        	}
	        }
        return false;
    }

    bool check(std::vector<vector<char> > &board, int row, int col, char temp){
    	for(int i =0; i < 9; i++){
    		if(board[row][i] == temp)
    			return false;

    		if(board[i][col] == temp)
    			return false;

    		int x = (row/3)*3 + i/3;
    		int y = (col/3)*3 + i%3;

    		if(board[x][y] == temp)
    			return false;
    	}
    	return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSud(board,0);
    }
};
