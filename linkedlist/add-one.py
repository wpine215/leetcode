class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        for i in range(len(digits) - 1, -1, -1):
            carry, digits[i] = divmod(digits[i] + carry, 10)
        while carry != 0:
            carry, temp = divmod(carry, 10)
            digits.insert(0, temp)
        return digits