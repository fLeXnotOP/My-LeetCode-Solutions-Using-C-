class Solution {
public: 
    
    int solveMem(vector<vector<int>>& triangle,vector<vector<int>>& dp,int i,int j){
        
        //base case 
        if(i==triangle.size()-1){
            return triangle[i][j];
        } 
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        } 
        
        
        int bottom_left = triangle[i][j]+solveMem(triangle,dp,i+1,j); 
        int bottom_right = triangle[i][j]+solveMem(triangle,dp,i+1,j+1); 
        
        return dp[i][j] = min(bottom_left,bottom_right);
        
        
    }
    
    
    
    
    
    
    
    int minimumTotal(vector<vector<int>>& triangle) { 
        int m = triangle.size(); 
        
        vector<vector<int>> dp(m,vector<int>(m,-1)); 
        
        return solveMem(triangle,dp,0,0);
    }
};