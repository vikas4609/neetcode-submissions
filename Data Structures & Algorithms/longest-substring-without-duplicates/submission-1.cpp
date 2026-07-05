class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<pair<int,int>> vec(256,{0,-1});
        int i=0,j=0;
        int answer = 0;
        while(j<s.length()){
            if(vec[s[j]].first == 1){
                if((j-i)>answer){
                    answer = j-i;
                }
                while(i<=vec[s[j]].second){
                    vec[s[i]].first--;
                    vec[s[i]].second = -1;
                    i++;
                }
            }
            vec[s[j]].first++;
            vec[s[j]].second = j;
            j++;
        }
        if((j-i) > answer){
            answer = j-i;
        }
        return answer;
    }
};
