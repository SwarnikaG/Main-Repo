class Solution {
public:
    int majorityElement(vector<int>& nums) {
	map<int, int> map;
	int n = nums.size();
//store each element's frequency in a map
	for (int i = 0; i < n; i++) {
		map[nums[i]]++;
	}

	//return the element if its count is more than n/2
	for (auto it: map) {
		if (it.second > n/2) {
			return it.first;
		}
	}

	/* for (int i = 0; i < n; i++)
	{
		if (++map[A[i]] > n/2)
			return A[i];
	} */

	// return -1 if no majority element is present
	return -1;
    }
};