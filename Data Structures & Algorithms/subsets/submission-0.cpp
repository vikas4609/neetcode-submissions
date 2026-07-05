class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int k = pow(2,n) - 1;
        cout<<"k: "<<k;
        while(k){
            int bin = k;
            vector<int> vec;
            int i=0;
            while(bin){
                if(bin%2){
                    vec.push_back(nums[i]);
                }
                i++;
                bin = bin >> 1;
            }
            k--;
            res.push_back(vec);
        }
        res.push_back({});
        return res;
    }
};
