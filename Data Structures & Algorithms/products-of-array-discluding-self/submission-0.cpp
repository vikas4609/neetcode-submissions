class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroc = 0;
        int zeroi = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroc++;
                zeroi = i;
            }else {
                product = product*nums[i];
            }
        }
        int n = nums.size();
        vector<int> answer(n,0);
        if(zeroc == 0){
            for(int i=0;i<nums.size();i++){
                answer[i] = product/nums[i];
            }
        }else if (zeroc == 1){
            answer[zeroi] = product;
        }
        return answer;
    }
};
