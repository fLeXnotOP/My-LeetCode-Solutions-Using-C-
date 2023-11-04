class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastmoment=0; 
        
        for(auto l : left){
            lastmoment = max(lastmoment,l);
        } 
        
        for(auto r : right){
            lastmoment = max(lastmoment,n-r);
        } 
        
        return lastmoment;
        
        
    }
};