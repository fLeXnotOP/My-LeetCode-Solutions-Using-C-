class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        int n = nums.size();
        unordered_map<int,int> frequency(n); 
        
        for(int i=0;i<nums.size();i++){ 
            frequency[nums[i]]++;
            
        } 
        
        int result = INT_MAX;
        
        for(int i=0;i<n;i++){
            if(frequency[nums[i]]==1){
                result = nums[i];
            }
        } 
        return result;
    }
};