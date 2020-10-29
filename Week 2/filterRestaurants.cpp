class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>> v;
        for(int i = 0; i < restaurants.size(); i++) {
            if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                if(veganFriendly == 1 && restaurants[i][2] == 0)
                    continue;
                v.push_back({ restaurants[i][1], restaurants[i][0] });
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int> ans;
        for(auto a:v){
            ans.push_back(a.second);
        }
        return ans;
    }
};
