class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ret; 
        
        for(int i=0;i<rowIndex+1;i++){
            vector<int> row(i+1,1); 
            for(int j=1;j<i;j++){
                row[j] = ret[i-1][j] + ret[i-1][j-1];
            } 
            ret.push_back(row);
        } 
        
        vector<int> ans = ret[rowIndex]; 
        
        return ans;
    }
}; 

