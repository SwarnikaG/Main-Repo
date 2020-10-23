class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==0) return ans;
        sort(intervals.begin(),intervals.end(),comp);
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(ans[ans.size()-1][1]<intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans[ans.size()-1][1]=max(intervals[i][1],ans[ans.size()-1][1]);
            }
        }
        return ans;
    }
};  