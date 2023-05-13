class Solution {
	public:
		const int M = 1e9+7;
		vector<int> arr;
		int solve(int low,int high,int zero,int one,int i) {
            if(i>high) return 0;
            if(arr[i]!=-1) return arr[i];
            int ans = 0;
            if(i>=low && i<=high) {
                ans +=1 ;
            }
            return arr[i] = (ans + solve(low,high,zero,one,i+zero)+solve(low,high,zero,one,i+one))%M;
    }
	
    int countGoodStrings(int low, int high, int zero, int one) {
        arr.resize(high+1,-1);
        return solve(low,high,zero,one,0)%M;		
    }
};