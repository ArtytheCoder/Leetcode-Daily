class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        right = 0
        sum_curr = 0
        res = float('inf')

        for right in range(0, len(nums)):
            sum_curr += nums[right]

            while sum_curr >= target:
                res = min(res, right - left + 1)
                sum_curr -= nums[left]
                left += 1

        return res if res != float('inf') else 0