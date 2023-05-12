class Solution {
public: 
    
    
    int solveMem(int index,int buy,vector<int>& prices,int k,vector<vector<vector<int>>>& dp){
        
        if(index >= prices.size()){
            return 0;
        } 
        if(k==0){
            return 0;
        } 
        if(dp[index][buy][k]!=-1){
            return dp[index][buy][k];
        }  
        
        int profit = 0;
        
        if(buy==1){
            int buy = -prices[index] + solveMem(index+1,0,prices,k,dp); 
            int skip = 0 + solveMem(index+1,1,prices,k,dp); 
            profit = max(buy,skip);
        } 
        else{
            int sell = prices[index] + solveMem(index+1,1,prices,k-1,dp); 
            int skip = 0 + solveMem(index+1,0,prices,k,dp); 
            profit = max(sell,skip);
        } 
        
        return dp[index][buy][k] = profit;
    }
    
    
    
    
    
    
    int maxProfit(int k, vector<int>& prices) { 
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1))); 
        
        return solveMem(0,1,prices,k,dp);
    }
};