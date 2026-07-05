class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string tempstr = strs[i];
            sort(tempstr.begin(),tempstr.end());
            mp[tempstr].push_back(strs[i]);
        }
        vector<vector<string>> answer;
        for(const auto& it : mp){
            answer.push_back(it.second);
        }
        return answer;
    }
};
