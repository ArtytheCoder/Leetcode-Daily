class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int first=0 , last=0;;
        for(int i=0;i<nums.size();i++) 
            last=max(last,nums[i]);
            long long int ans=INT64_MAX;
        while(first<=last)
        {
            int mid=(first+last)/2;
            long long int sum=0;
            for(int i=0;i<nums.size();i++){
                sum+= 1LL*abs(nums[i]-mid)*cost[i];
            }
            long long int sum1=0;
            for(int i=0;i<nums.size();i++)
            {
                sum1+=1LL*abs(nums[i]-mid+1)*cost[i];
            }
            if(sum>sum1)
            {
                last=mid-1;
            }
            else
            first=mid+1;
            ans=min({ans,sum,sum1});
        }

        return ans;
    }
};