class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //maintain visited bool arrays for each row,column and 3x3 grid, that too for each digit.
        bool a[9][9]={false},b[9][9]={false},c[3][3][9]={false};
        int n;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(isdigit(board[i][j])){//it returns a non-zero value for ‘0’ to ‘9’ and zero for others.
                    //cout<<"board["<<i<<"]["<<j<<"] :"<<board[i][j]<<endl;
                    n=board[i][j]-'1'; 
                    //cout<<"n : "<<n<<endl;
                    if(a[i][n]||b[j][n]||c[i/3][j/3][n])return false;
                    a[i][n]=b[j][n]=c[i/3][j/3][n]=true;
                }
            }
        }
        return true;
    }
};

/*
    This array can store upto 12 elements (2x3x2)
    int test[2][3][2] = {
                            {
                                {1, 2},
                                {3, 4},
                                {5, 6}
                            }, 
                            {
                                {7, 8}, 
                                {9, 10}, 
                                {11, 12}
                            }
                        };
*/