class Solution {
public: 
        
    int solveTab(string a,string b){
        vector<int> curr(b.length()+1,0); 
        vector<int> next(b.length()+1,0);
        
        for(int index1 = a.length()-1;index1>=0;index1--){
            for(int index2 = b.length()-1;index2>=0;index2--){
                int ans = 0; 
                
                if(a[index1]==b[index2]){
                    ans = 1 + next[index2+1]; 
                } 
                else{
                    ans = max(next[index2],curr[index2+1]);
                } 
                curr[index2]=ans;
            } 
            next=curr;
        } 
        return next[0];
    }
    
    
    int longestPalindromeSubseq(string s) { 
        string revStr = s; 
        reverse(revStr.begin(),revStr.end()); 
        int ans = solveTab(s,revStr); 
        
        return ans;
        
    }
};