class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==NULL || grid.size()==0 || grid[0].size()==0)
            return 0;
        
        int result = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){ //initially considering result perimeter as 4
                    result+=4;
                if(i>0 && grid[i-1][j] == 1){ //checking for top block
                    result-=2;
                }
                if(j>0 && grid[i][j-1] == 1){ //checking for left block
                    result-=2;
                }
                }
            }
        }
        
        return result;
    }
};