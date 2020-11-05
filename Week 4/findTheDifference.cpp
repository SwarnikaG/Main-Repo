class Solution {
public:
    char findTheDifference(string s, string t) {
        //use XOR to find extra character
        int ans = t[0]; 
        int i = 1;
        while(i < t.length()){
            ans ^= s[i-1]^t[i];
            i++;
        }
        
        return ans;
    }
};