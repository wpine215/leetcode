class Solution:
    def threeSum(self, nums):
        nums.sort()
        triplets = []
        for i in range(len(nums) - 2):
            if nums[i] > 0: break
            if i > 0 and nums[i] == nums[i-1]: continue

            lhs = i + 1
            rhs = len(nums) - 1
            while lhs < rhs:
                attempt = nums[i] + nums[lhs] + nums[rhs]

                if attempt < 0:
                    lhs += 1
                elif attempt > 0:
                    rhs -= 1
                else:
                    triplets.append([nums[i], nums[lhs], nums[rhs]])
                    while lhs < rhs and nums[lhs] == nums[lhs + 1]:
                        lhs += 1
                    while lhs < rhs and nums[rhs] == nums[rhs - 1]:
                        rhs -= 1
                    lhs += 1
                    rhs +=1
        return triplets

def main():
    s = Solution()
    nums_ = [-2, 1, 3, -1, 6, 5, 4, -3]
    res = s.threeSum(nums_)
    print(res)

if __name__ == "__main__":
    main()

