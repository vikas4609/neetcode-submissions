class Solution {
    void dfs(vector<int>& nums, int i, vector<vector<int>>& result, vector<int>& subset, int target){
            // cout<<"target: "<<target;
            if(target == 0){
                result.push_back(subset);
                // subset.clear();
                return;
            }else if(target <= 0 || i>=nums.size()){
                // subset.clear();
                return;
            }
            // cout<<"target: "<<target;
            if(nums[i] > target){
                dfs(nums,i+1,result,subset,target);
            }else {
                int x = target/nums[i];//x=5
                for(int j=0;j<x;j++){
                    subset.push_back(nums[i]);
                }//[3,3,3,3,3]
                while(x >= 0){
                    // cout<<"x: "<<x;
                    dfs(nums,i+1,result,subset,target-(x*nums[i]));
                    if(x>0){
                        subset.pop_back();
                    }
                    x--;
                }
            }
            return;
        }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // cout<<"call hua";
        vector<int> subset;
        vector<vector<int>> result;
        dfs(nums,0,result,subset,target);
        return result;
    }
};
