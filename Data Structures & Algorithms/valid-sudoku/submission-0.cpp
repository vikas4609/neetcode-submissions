class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> vec(9,0);

        //row check
        for(int i=0;i<9;i++){
            fill(vec.begin(), vec.end(), 0);
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    vec[board[i][j] - '1']++;
                    if(vec[board[i][j] - '1'] >= 2){
                        return false;
                    } 
                }
            }
        }

        //column check
        for(int i=0; i<9; i++){
            fill(vec.begin(), vec.end(), 0);
            for(int j=0;j<9;j++){
                if(board[j][i] != '.'){
                    vec[board[j][i] - '1']++;
                    if(vec[board[j][i] - '1'] >= 2){
                        return false;
                    }
                } 
            }
        }

        //box check
        //0,0  0,1  0,2
        //1,0  1,1  1,2
        //2,0  2,1  2,2

        //0,3  0,4  0,5
        //1,3  1,4. 1,5
        //2,3  2,4  2,5

        for(int i=0; i<9; i=i+3){
            for(int j=0; j<9; j=j+3){
                fill(vec.begin(), vec.end(), 0);
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l] != '.'){
                            vec[board[k][l] - '1']++;
                            if(vec[board[k][l] - '1'] >= 2){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
