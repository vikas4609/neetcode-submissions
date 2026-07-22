class Solution {
public:

    bool dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int wordIndex){
        cout<<"in dfs"<<board[i][j]<<" "<<i<<" "<<j<<" "<<wordIndex<<"\n";//1,2
        if(wordIndex == word.length()){
            return true;
        }
        if(i>0 && !visited[i-1][j] && board[i-1][j] == word[wordIndex]){
            visited[i-1][j] = true;
            if(dfs(i-1,j,board,visited,word,wordIndex+1)){
                return true;
            }
            visited[i-1][j] = false;
        }
        if(j>0 && !visited[i][j-1] && board[i][j-1] == word[wordIndex]){
            visited[i][j-1] = true;
            if(dfs(i,j-1,board,visited,word,wordIndex+1)){
                return true;
            }
            visited[i][j-1] = false;
        }
        if(i<board.size()-1 && !visited[i+1][j] && board[i+1][j] == word[wordIndex]){
            cout<<"yaha aana tha"<<board[i+1][j]<<"\n";
            visited[i+1][j] = true;
            if(dfs(i+1,j,board,visited,word,wordIndex+1)){
                return true;
            }
            visited[i+1][j] = false;
        }
        if(j<board[0].size()-1 && !visited[i][j+1] && board[i][j+1] == word[wordIndex]){
            cout<<"sec yaha aana tha"<<board[i][j+1]<<"\n";
            visited[i][j+1] = true;
            if(dfs(i,j+1,board,visited,word,wordIndex+1)){
                return true;
            }
            visited[i][j+1] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //cout<<board[i][j]<<"\n";
                if(board[i][j]==word[0]){
                    cout<<"inside"<<board[i][j]<<"\n";
                    visited[i][j] = true;
                    if(dfs(i,j,board,visited,word,1)){
                        cout<<"return inside"<<board[i][j]<<"\n";
                        return true;
                    }
                    cout<<"false case inside"<<board[i][j]<<"\n";
                    for(auto& row: visited){
                        fill(row.begin(),row.end(),false);
                    }
                }
            }
        }
        return false;
    }
};
