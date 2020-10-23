class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]); 
        
        while (l < r) {
            if (!isalnum(s[l])) 
                l++;
            else if (!isalnum(s[r])) 
                r--;
            else {
                if (s[l++] != s[r--]) return false;
            }
                
        }
        return true;
    }
};