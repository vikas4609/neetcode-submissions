class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vec(26,0);
        int start=0;
        int end=0;
        vec[s[end]-65]++;
        int answer = 0;
        while(end<s.length()){
            int maxm = 0;
            for(int i=0;i<26;i++){
                if(vec[i]>maxm){
                    maxm = vec[i];
                }
            }
            if((end-start+1)-maxm <=k){
                if(answer < (end-start+1)){
                    answer = end-start+1;
                }
                end++;
                if(end<s.length()){
                    vec[s[end]-65]++;
                }
            }else {
                vec[s[start]-65]--;
                start++;
            }
        }
        return answer;
    }
};
