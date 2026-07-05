class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        int i=0,j=s1.length()-1;
        while(j<s2.length()){
            string temp = s2.substr(i,j-i+1);
            sort(temp.begin(),temp.end());
            if(temp == s1){
                return true;
            }
            i++;
            j++;
        }
        return false;
    }
};
