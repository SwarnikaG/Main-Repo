class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        
        int chars[26] = { 0 };
        for(int i = 0; i<s.length(); i++) 
            chars[s[i] - 'a']++;
        for(int i = 0; i<t.length(); i++) {
            chars[t[i] - 'a']--;
            if(chars[t[i] - 'a'] < 0)
                return false;
        }
    
        return true;
        
    }
};