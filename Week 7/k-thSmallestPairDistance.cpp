class Solution {
public:
    
    bool helper(int mid , vector<int>& a , int& k){
        //to find how many pairs exists
        int n=a.size();
        int j=1;
        int total=0;
        for(int i=0;i<n;i++){
            while(j<n && a[j]-a[i]<=mid) j++;
            j--;
            int x=(j-i);
            total+=x;
        }
        return (total>=k); //true if total is greater or equal to the given k
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff=nums[n-1]-nums[0]; //using binary search and so finding the diff because largest diff can be max-min
        int l=0; //min diff i.e left bracket
        int r=diff; //max diff i.e right bracket
        while(l<r){
            int mid=(l+r)/2;
            if(helper(mid,nums,k))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};