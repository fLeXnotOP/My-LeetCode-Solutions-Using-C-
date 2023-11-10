class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) { 
        unordered_map<int,vector<int>> mp; 
        
        for(auto p:adjacentPairs){
            mp[p[0]].push_back(p[1]); 
            mp[p[1]].push_back(p[0]);
        } 
        
        vector<int> ans;
        for(auto node : mp){
            if(node.second.size()==1){
                ans.push_back(node.first); 
                ans.push_back(node.second[0]); 
                break;
            }
        } 
        
        while(ans.size()<mp.size()){
            int lastElement = ans[ans.size()-1]; 
            int secondLast = ans[ans.size()-2]; 
            
            vector<int> neighbours = mp[lastElement]; 
            
            if(neighbours[0]!=secondLast){
                ans.push_back(neighbours[0]);
            } 
            else{
                ans.push_back(neighbours[1]);
            }
        } 
        
        return ans;
    }
};