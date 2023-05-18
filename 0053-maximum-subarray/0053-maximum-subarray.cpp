class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        if(nums.size()==0){
            return 0;
        }
        int max_including_current=nums[0]; 
        int max_sum=nums[0];  
        
        for(int i=1;i<nums.size();i++){ 
            int n=nums[i];
            max_including_current=max(max_including_current+n,n); 
            max_sum=max(max_sum,max_including_current);
        } 

        return max_sum; 

    } 

};