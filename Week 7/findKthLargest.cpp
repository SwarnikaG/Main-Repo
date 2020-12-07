class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> minheap;

        for(int elem : nums) {
            if(minheap.size() < k) {
                minheap.push(elem);
            } else if(elem > minheap.top()) {
                minheap.pop();
                minheap.push(elem);
            }
        }
        return minheap.top();
    }
};