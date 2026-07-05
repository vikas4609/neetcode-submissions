class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec;
        for(const auto& it:mp){
            pair<int, int> p{it.first,it.second};
            vec.push_back(p);
        }
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
        vector<int> answer;
        for(int i=0;i<k;i++){
            answer.push_back(vec[i].first);
        }
        return answer;
    }
};
