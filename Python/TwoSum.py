class Solution:
    def twoSum(self, nums:list[int],target: int) -> List[int]:
        x = {}
        for idx, i in enumerate(nums):
            if x.get(i) is not None:
                return[x.get(i), idx]
            x [target-i] = idx