class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<int,pair<int,int>> charToIndex; 
        int n = s.size();
        
        for(int i=0;i<n;i++){
            charToIndex[s[i]] = {-1,-1};
        } 
        
        
        for(int i=0;i<n;i++){
            if(charToIndex[s[i]].first==-1){
                charToIndex[s[i]].first=i;
            }
        } 
        
        for(int i=n-1;i>=0;i--){
            if(charToIndex[s[i]].second==-1){
                charToIndex[s[i]].second=i;
            }
        } 
        
        
        int ans=0; 
        
        for(auto p:charToIndex){
            char c = p.first; 
            int startIndex = p.second.first; 
            int endIndex = p.second.second; 
            
            unordered_set<int> st; 
            
            for(int i=startIndex+1;i<endIndex;i++){
                st.insert(s[i]);
            } 
            
            ans+=st.size();
        } 
        
        
        return ans;
        
        
    }
};