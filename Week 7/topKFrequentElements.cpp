class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //first store the frequencies 
        vector<int> ans;
        priority_queue<pair<int,int>> minheap; //heap should be made with freq i.e highest freq to least freq
        for (auto& x : nums) {
            mp[x]++;
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            minheap.push({i->second,i->first}); //note : second is kept at initial position 
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(minheap.top().second); //top element of heap consist of a pair which has freq at initial place and then the number..so insert second in ans vector
            minheap.pop();
        }
       return ans;
    }
};