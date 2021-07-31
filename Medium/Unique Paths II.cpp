//problem link: https://leetcode.com/problems/unique-paths-ii/
//Topics: DP,Matrix

//DFS+Backtracking
    void dfs(int i,int j,int m,int n,int &cnt,vector<vector<int>> &vis,vector<vector<int>> obstacleGrid)
    {
        if(i>=m||j>=n)
            return ;
        if(obstacleGrid[i][j]==1||vis[i][j]==1)
            return;
        if(i==m-1&&j==n-1)
            cnt++;
        vis[i][j]=1;
        dfs(i+1,j,m,n,cnt,vis,obstacleGrid);
        dfs(i,j+1,m,n,cnt,vis,obstacleGrid);
        vis[i][j]=0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int cnt=0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1)
            return 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        dfs(0,0,m,n,cnt,vis,obstacleGrid);
        return cnt;
        }

//Bottom-Up Dp
