class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return 0;
        
        int rows = matrix.size();
        int column = matrix[0].size();
        
        int left = 0;
        int right = rows*column-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            int midElem = matrix[mid/column][mid%column];
            if(midElem==target){
                return true;
            }
            else {
                if(target<midElem)
                    right = mid-1;
                else
                    left = mid+1;
            }       
        }
        return false;
    }
};