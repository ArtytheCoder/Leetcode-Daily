class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a>0 || b>0 || c>0){
            int bita =a&1, bitb = b&1, bitc = c&1;
            if(bitc == 0){
                ans +=  (bita + bitb);
            }
            else{
                if(bita ==0 && bitb ==0)
                    ans++;
            }
            a >>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};