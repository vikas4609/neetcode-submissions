class Solution {
    void dfs(vector<int>& candidates, int i, vector<int>& subset, vector<vector<int>>& result, int target){
        if(target == 0){
            result.push_back(subset);
            return;
        }
        if(target<0 || i>=candidates.size()){
            return;
        }
        subset.push_back(candidates[i]);
        dfs(candidates,i+1,subset,result,target-candidates[i]);
        subset.pop_back();
        int count = i;
        while(count<candidates.size()-1 && candidates[count+1]==candidates[count]){
            count++;
        }
        dfs(candidates,count+1,subset,result,target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        dfs(candidates,0,subset,result, target);
        return result;
    }
};
