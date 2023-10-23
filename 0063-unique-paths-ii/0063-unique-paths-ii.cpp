class Solution {
public:  
    int solveMemo(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 || j<0 || grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solveMemo(i-1,j,grid,dp);
        int left=solveMemo(i,j-1,grid,dp);
        
        return dp[i][j]=up+left;
    } 
    
    int solveTabu(int m,int n,vector<vector<int>>&grid){
        vector<vector<int>>dp(m,vector<int>(n,0));
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(grid[i][j]==1) continue;
                 if(i==0 && j==0 ) dp[i][j]=1;
                 else{
                     int up=0,left=0;
                     if(i>0) up=dp[i-1][j];
                     if(j>0) left=dp[i][j-1];
                     
                     dp[i][j]=up+left;
                 }
             }
         }
         return dp[m-1][n-1];

    }
    

    
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { 
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1)); 
        
        return solveTabu(m,n,obstacleGrid);
    }
};