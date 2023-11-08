class Solution {
public:  
    
    int solve(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(index==prices.size()){
            return 0;
        } 
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }  
        
        int profit = 0;
        
        if(buy==1){
            int buy = -prices[index] + solve(index+1,0,prices,dp); 
            int skip = 0 + solve(index+1,1,prices,dp); 
            
            profit = max(buy,skip);
        } 
        else{
            int sell = prices[index] + solve(index+1,1,prices,dp); 
            int skip = 0 + solve(index+1,0,prices,dp); 
            
            profit = max(sell,skip);
        } 
        return dp[index][buy] = profit;
    } 
    
    int solveTab(vector<int>& prices){
        int n = prices.size(); 
        
        vector<int> curr(2,0); 
        vector<int> next(2,0);
        
        
        for(int index = n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                
                int profit = 0; 
                
                if(buy==1){
                    int buy = -prices[index] + next[0]; 
                    int skip = 0 + next[1]; 
                    profit = max(buy,skip);
                } 
                else{
                    int sell = prices[index] + next[1]; 
                    int skip = 0 + next[0]; 
                    profit = max(sell,skip);
                } 
                
                curr[buy] = profit;
            } 
            next=curr;
        } 
        
        return next[1];
        
    }
    
    int maxProfit(vector<int>& prices) {  
        //int n = prices.size();
        //vector<vector<int>> dp(n,vector<int>(2,-1));
        return solveTab(prices);
    }
};