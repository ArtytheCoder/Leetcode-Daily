class Solution {
public:
    bool judgeSquareSum(long int c) {
         for(long int a=0; a*a<=c ; a++){
             double m= c-a*a;
         double b = sqrt(m);
             if(b == int(b)){
                 return true;
             }
         }
        return false;
    }
};