class Solution {
public: 
    bool canMakeArithmeticProgression(vector<int>& arr) {
	int n = arr.size(), mini = INT_MAX, maxi = INT_MIN;
	for(auto &it : arr)
		mini = min(mini, it), maxi = max(maxi, it);

	if((maxi - mini) % (n-1) != 0) return false;  // check for existence of an A.P.
	int diff = (maxi - mini) / (n-1);

	int i = 0;
	while(i < n) {
		if(arr[i] == mini + i*diff) i++;
		else if((arr[i] - mini) % diff != 0) return false;
		else{
			int pos = (arr[i] - mini) / diff;
			if(arr[pos] == arr[i]) return false; // check for duplicates
			swap(arr[i], arr[pos]);
		}
	}
	return true;
}
};