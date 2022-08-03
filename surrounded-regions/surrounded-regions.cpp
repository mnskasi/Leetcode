class Solution {
public:
    void temp (int x, int y, vector<vector<int> > &visited,vector<vector<char>>& board, int & flag) {
        if (x == 0 || x == board.size()-1) {
            flag = -1;
        }
        if (y == 0 || y == board[0].size()-1) {
            flag = -1;
        }
        visited[x][y] = 1;
        board[x][y] = 'a';
        if (x != 0 ) {
            if (board[x -1][y] == 'O' && visited[x-1][y] == 0)
            temp(x -1,y,visited, board,flag);
        }
        if (x != board.size() -1 ) {
            if (board[x +1][y] == 'O' && visited[x+1][y] == 0)
            temp(x +1,y,visited, board,flag);
        }
        if (y != 0 ) {
            if (board[x][y - 1] == 'O' && visited[x][y - 1] == 0)
            temp(x,y-1,visited, board,flag);
        }
        if (y != board[0].size() - 1 ) {
            if (board[x][y+1] == 'O' && visited[x][y+1] == 0)
            temp(x,y+1,visited, board,flag);
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int> > visited(board.size(), vector<int> (board[0].size(),0));
        for (int i =0; i< board.size();i++) {
            for (int j=0;j< board[0].size();j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    int flag =1;
                    temp(i,j,visited,board,flag);
                    if (flag == 1) {
                        for (int p =0;p< board.size();p++) {
                            for (int q =0;q< board[0].size();q++) {
                                if (board[p][q] == 'a'){
                                    board[p][q] = 'X';
                                }
                            }
                        }
                    } else {
                        for (int p =0;p< board.size();p++) {
                            for (int q =0;q< board[0].size();q++) {
                                if (board[p][q] == 'a'){
                                    board[p][q] = 'O';
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
};