class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int check;
        for(int i=0;i<nums.size();i++){
            check=0;
            for(int j=1;j<nums.size();j++){
                if(nums[i]<nums[int(i+j)%nums.size()]){
                    ans.push_back(nums[int(i+j)%nums.size()]);
                    check=1;
                    break;
                }
            }
            if(check==0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};