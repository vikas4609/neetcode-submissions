class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res(n+1);
        res[0].push_back({""});
        for(int k=1;k<=n;k++){
            for(int i=0;i<k;i++){
                for(int x=0;x<res[i].size();x++){
                    for(int y=0;y<res[k-i-1].size();y++){
                        res[k].push_back("(" + res[i][x] + ")" + res[k-i-1][y]);
                    }
                }
            }
        }
        return res[n];
    }
};
