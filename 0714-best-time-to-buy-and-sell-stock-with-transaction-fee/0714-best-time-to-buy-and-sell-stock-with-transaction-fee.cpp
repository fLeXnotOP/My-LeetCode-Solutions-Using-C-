class Solution {
public: 
    
    int solveMem(int index,int buy,vector<int>& prices,vector<vector<int>>& dp,int fees){
        if(index>=prices.size()){
            return 0;
        } 
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        } 
        
        int profit =0; 
        
        if(buy==1){
            int buy = -prices[index] + solveMem(index+1,0,prices,dp,fees); 
            int skip = 0 + solveMem(index+1,1,prices,dp,fees); 
            
            profit = max(buy,skip);
        } 
        else{
            int sell = prices[index] - fees + solveMem(index+1,1,prices,dp,fees); 
            int skip = 0 + solveMem(index+1,0,prices,dp,fees); 
            
            profit = max(sell,skip);
        }  
        
        
        return dp[index][buy]=profit;
        
        
    }
    
    
    
    
    
    
    int maxProfit(vector<int>& prices, int fee) { 
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1)); 
        
        return solveMem(0,1,prices,dp,fee);
    }
};