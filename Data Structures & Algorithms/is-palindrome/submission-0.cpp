class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c : s){
            if(('a'<=c && c<='z') || ('0'<=c && c<='9')){
                str = str+c;
            }else if('A'<=c && c<='Z'){
                str = str + (char)(int(c) + 32);
            }
        }
        int start=0;
        int end=str.length()-1;
        while(start<=end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
