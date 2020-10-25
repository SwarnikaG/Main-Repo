class Solution {
public:
    static bool compare(string first,string second)
    {
        string one = first+second;
        string two = second+first;
        //cout<<"Comparing "<<one<<" and "<<two<<endl;
        int i=0;
        while(one[i] && two[i])
        {
            //cout<<"Comparing one[i] "<<one[i]<<" and two[i] "<<two[i]<<endl;
            if(one[i]>two[i])
                return true;
            else if(one[i]<two[i])
                return false;
            ++i;
        }

        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        int len = nums.size(), resLen = 0, pos = 0;
        string ns[len];
        // populating ns
        for (int i = 0; i < len; i++) {
            ns[i] = to_string(nums[i]);
            resLen += ns[i].size();
        }
        // creating a properly sized string
        string res(resLen, '0');
        sort(ns, ns + len, compare);
        if (ns[0] == "0") return "0";
        for (string s: ns) {
            for (char c: s) res[pos++] = c;
        }
        return res;
    }
};