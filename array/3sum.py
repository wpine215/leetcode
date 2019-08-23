class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triplets = []
        lookback = set()
        for i in nums:
            for j in [x for x in nums if x != i]:
                if -(i + j) in lookback:
                    triplets.append([i, j, -(i+j)])
                lookback.add(j)
            lookback.clear()
        return triplets

# Current issue: solution set contains duplicate triplets when it should not