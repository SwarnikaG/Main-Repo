class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0 || n==1) 
        return n; 
  
        // To store index of next unique element 
        int index_next_uniq_elem = 0; 
  
    for (int i=0; i < n-1; i++) 
        if (nums[i] != nums[i+1]) 
            nums[index_next_uniq_elem++] = nums[i]; 
  
    nums[index_next_uniq_elem++] = nums[n-1]; //need to store last unique element of your vector
  
    return index_next_uniq_elem; 
    }
};