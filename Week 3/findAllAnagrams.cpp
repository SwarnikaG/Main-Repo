class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> curhash(26,0);
        vector<int> phash(26,0);
        int n = s.size();
        int window = p.size();
        
        if(n<window){
            return ans;
        }
        int leftidx = 0, rightidx = 0;
        //creating map for first window
        while(rightidx<window)
        {
            phash[p[rightidx]-'a'] +=1;
            curhash[s[rightidx++]-'a'] +=1;
        }
        rightidx -=1;
        //using sliding window technique
        while(rightidx<n)
        {
            if(phash == curhash)
                ans.push_back(leftidx);
            rightidx+=1;
            if(rightidx!=n)
                curhash[s[rightidx]-'a'] +=1;//moving our window one step forward
            curhash[s[leftidx]-'a'] -=1; //and decreasing it by one step and also decreasing the value from map of that character
            leftidx+=1;
        }
        return ans;
    }
};