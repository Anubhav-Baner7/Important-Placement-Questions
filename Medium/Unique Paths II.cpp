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

//Recursive+Memoition
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>> &obstacleGrid)
    {
        if(i>=m||j>=n||obstacleGrid[i][j])
            return 0;
        if(i==m-1&&j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=solve(i+1,j,m,n,dp,obstacleGrid)+solve(i,j+1,m,n,dp,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
     vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp,obstacleGrid);
        }
//TC:O(m*n)
//SC:O(m*n)
