    int max(int x, int y) {
	    return (x > y) ? x : y;
    }

class Solution {

public:
    int maxProfit(vector<int>& prices) {
    int diff = INT_MAX;
    int n = prices.size();
    int max_so_far = 0;
	for (int i = 0; i <n; i++)
	{
		// update max if current element is greater than the maximum element
		if (prices[i] < diff)
			diff = prices[i];

		// if the current element is less than the maximum element,
		// then update the difference if required
		else if (prices[i] - diff > max_so_far)
			max_so_far = prices[i] - diff;
	}

	return max_so_far;
    }
};