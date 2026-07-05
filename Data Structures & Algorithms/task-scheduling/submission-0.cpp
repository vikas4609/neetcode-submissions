class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26,0);
        for(int i=0;i<tasks.size();i++){
            hash[tasks[i]-65]++;
        }
        int max=0;
        int mxcount = 0;
        for(int i=0;i<26;i++){
            if(hash[i] > max){
                mxcount = 1;
                max = hash[i];
            }else if(hash[i] == max){
                mxcount++;
            }
        }
        int ans = (n+1)*(max-1)+mxcount;
        if(tasks.size()>ans){
            return tasks.size();
        }
        return ans;
    }
};
