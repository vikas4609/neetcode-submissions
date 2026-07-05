class Solution {
    void dfs(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& result){
        if(i>=nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i+1,subset,result);
        subset.pop_back();
        int count = i;
        while(count<nums.size()-1 && nums[count+1]==nums[count]){
            count++;
        }
        dfs(nums,count+1,subset,result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        vector<vector<int>> result;
        dfs(nums,0,subset,result);
        return result;
    }
};
