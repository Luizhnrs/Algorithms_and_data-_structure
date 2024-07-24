class BinarySearch:
    def search(self, nums:list[int],target: int) -> int:
        l,r = 0

        while l <= r:
            m = (l+r)//2

            if num[m] > target:
                r = m - 1
            elif num[m] < target:
                l = m + 1
            else:
                return m
            
            return -1