class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxm = 0;
        for(int i=0;i<piles.size();i++){
            if(maxm<piles[i]){
                maxm = piles[i];
            }
        }
        int l = 1;
        int r = maxm;
        while(l<r){
            int mid = (l+r)/2;
            int count = 0;
            for(int i=0;i<piles.size();i++){
                count = count + (piles[i]%mid==0 ? (piles[i]/mid) : ((piles[i]/mid)+1));
            }
            if(count > h){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
