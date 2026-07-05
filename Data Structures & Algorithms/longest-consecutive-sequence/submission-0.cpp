class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        int answer = 0;
        while(i<nums.size()){
            int count = 1;
            int j;
            for(j=i+1;j<nums.size();j++){
                if(nums[j] == nums[j-1]+1){
                    count++;
                }else if (nums[j] == nums[j-1]){
                    continue;
                }else{
                    break;
                }
            }
            if(count>answer){
                answer = count;
            }
            i = j;
        }
        return answer;
    }
};
