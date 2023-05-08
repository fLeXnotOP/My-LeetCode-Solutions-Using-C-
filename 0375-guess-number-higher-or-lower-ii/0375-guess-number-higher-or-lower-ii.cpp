class Solution {
public:
    
    // dp vector contains minimum of maximum guess losses in range L and H
    int dp[201][201];
    
    // returns minimum of maximum guess losses in range L and H
    int getMinimum(int l, int h)
    {
        // base case: L>=H then there is no way to guess wrong and so loss is 0
        if(h<=l) return 0;
        
        // return precalculated values
        if(dp[l][h]!=-1) return dp[l][h];
        
        // min of max guess loss 
        int res = INT_MAX;
        
        // guess value from L to H
        for(int i=l;i<=h;i++)
        {
            // guess number i and it is wrong, so the possible losses are
            // i+getMinimum(l,i-1) and i+getMinimum(i+1,h) and we take the max loss
            // get minimum loss between res and max guess loss
            res = min(res, i + max(getMinimum(l,i-1),getMinimum(i+1,h)));
        }
        
        return dp[l][h] = res;
    }
    
    int getMoneyAmount(int n){
        
        memset(dp,-1,sizeof(dp));
        
        return getMinimum(1,n);
    }
};