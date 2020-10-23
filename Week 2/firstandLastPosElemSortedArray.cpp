class Solution {
public:
    int findFirstOccurrence(vector<int>& nums, int N, int x)
    {
        int low = 0, high = N - 1;
        int result = -1;
        while (low <= high)
        {
            int mid = (low + high)/2;
            if (x == nums[mid])
            {
                result = mid;
                high = mid - 1;
            }
            else if (x < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return result;
    }
    
    int findLastOccurrence(vector<int>& nums, int N, int x)
    {
        int low = 0, high = N - 1;
        int result = -1;

        while (low <= high)
        {
            int mid = (low + high)/2;
            if (x == nums[mid])
            {
                result = mid;
                low = mid + 1;
            }
            else if (x < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstIndex = findFirstOccurrence(nums, n, target);
        int lastIndex = findLastOccurrence(nums, n, target);

        vector<int> v;
        v.push_back(firstIndex);
        v.push_back(lastIndex);
        return v;
    }
};




