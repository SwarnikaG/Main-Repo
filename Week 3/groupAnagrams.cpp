class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mymap;
        vector<vector<string>> groups;
        
        int n = strs.size();
        string original;
        for(int i=0;i<n;i++){
            original = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(original);
        }
        for(auto itr:mymap){
            groups.push_back(itr.second);
        }
        
        return groups;
    }
};