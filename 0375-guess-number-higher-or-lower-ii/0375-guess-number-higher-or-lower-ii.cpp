class Solution {
public:
    
    // dp vector contains minimum of maximum guess losses in range L and H
    
    // returns minimum of maximum guess losses in range L and H
    int getMinimum(int start, int end,vector<vector<int>>& dp)
    {
        // base case: L>=H then there is no way to guess wrong and so loss is 0
        if(start>=end){
            return 0;
        }
        
        // return precalculated values
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
        // min of max guess loss 
        int res = INT_MAX;
        
        // guess value from L to H
        for(int i=start;i<=end;i++)
        {
            // guess number i and it is wrong, so the possible losses are
            // i+getMinimum(l,i-1) and i+getMinimum(i+1,h) and we take the max loss
            // get minimum loss between res and max guess loss
            res = min(res, i + max(getMinimum(start,i-1,dp),getMinimum(i+1,end,dp)));
        }
        
        return dp[start][end] = res;
    }
    
    int getMoneyAmount(int n){
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return getMinimum(1,n,dp);
    }
};