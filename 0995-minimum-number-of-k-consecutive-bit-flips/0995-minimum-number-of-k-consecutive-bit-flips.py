from typing import List

class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        flipped = [False] * len(nums)
        valid_flip_window = 0
        
        flip_count = 0
        for i in range(len(nums)):
            if i >= k:
                if flipped[i-k]:
                    valid_flip_window -= 1
            
            if valid_flip_window % 2 == nums[i]:
                if i+k > len(nums):
                    return -1
                
                valid_flip_window += 1
                flipped[i] = True
                flip_count += 1
        
        return flip_count
