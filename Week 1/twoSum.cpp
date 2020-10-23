class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end()) //finding if target-num is already present in map..means we found the pair
            {
                v.push_back(m[target-nums[i]]); //retrieve the index of previous value that we stored in map
                v.push_back(i); //and this current index where we are already..this will serve as 2nd index
                return v;
            }
            m[nums[i]]=i; //if value not found in map..store its number and its index
        }

        return v;
    }
};