class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> > arr(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        if (obstacleGrid[0][0] == 1) {
            arr[0][0] = 0;
        } else {
            arr[0][0] = 1;
        }
        for (int i=1;i<obstacleGrid.size();i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            arr[i][0] = arr[0][0];
        }
        for (int i=1;i<obstacleGrid[0].size();i++) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            arr[0][i] = arr[0][0];
        }
        for (int i=1;i< obstacleGrid.size();i++) {
            for (int j=1;j < obstacleGrid[0].size();j++) {
                if (obstacleGrid[i][j] == 1) {
                    arr[i][j] = 0;
                } else {
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
                }
            }
        }
        return arr[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};