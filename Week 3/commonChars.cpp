class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        for (auto s : A) {
            vector<int> cnt1(26, 0);
            for (auto c : s){
                ++cnt1[c - 'a'];   
            } 
            for (auto i = 0; i < 26; ++i) {
               cnt[i] = min(cnt[i], cnt1[i]); 
            }
        }
        for (auto i = 0; i < 26; ++i)
            for (auto j = 0; j < cnt[i]; ++j) 
                res.push_back(string(1, i + 'a'));
        return res;
    }
};


/*
for understanding the flow of each portion
vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        for (auto s : A) {
            for(int x=0;x<cnt.size();x++){
                cout<<cnt[x]<<" ";
            }
            cout<<endl;
            vector<int> cnt1(26, 0);
            for (auto c : s){
                ++cnt1[c - 'a'];   
            } 
            for(int x=0;x<cnt1.size();x++){
                cout<<cnt1[x]<<" ";
            }
            cout<<endl;
            for (auto i = 0; i < 26; ++i) {
               cnt[i] = min(cnt[i], cnt1[i]); 
            }
            cout<<"After finding minimum from cnt and cnt1"<<endl;
            for(int x=0;x<cnt.size();x++){
                cout<<cnt[x]<<" ";
            }
            cout<<endl;
            cout<<"Loop Break"<<endl;
        }
        for (auto i = 0; i < 26; ++i)
            for (auto j = 0; j < cnt[i]; ++j) 
                res.push_back(string(1, i + 'a'));
        return res;
    }
*/