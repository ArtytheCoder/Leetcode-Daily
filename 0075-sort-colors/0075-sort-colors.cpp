class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size= nums.size(), temp= 0;
        for(int stp =0 ; stp < size; stp++){
            for(int i=0; i< size - stp -1; i++){
                if( nums[i] > nums[i+1])
                {
                    temp=nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                }
            }
        } 
    }
};