#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// O(n) time, one pass approach (no divide and conquer)
		// max is the global maximum (initialized to first element), rsum is the running sum (init @ 0)
		int max = nums[0];
		int rsum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] + rsum > 0) {
				// If adding the current number to the running sum will NOT cause it to go negative,
				// the number is added to rsum, and if rsum is now greater than the global max, max is updated
				rsum += nums[i];
				if (rsum > max) max = rsum;
			} else {
				// If current number + rsum WILL go negative, rsum is reset to 0,
				// and if the current number is greater than the global max, max is updated
				rsum = 0;
				if (nums[i] > max) max = nums[i];
			}
		}
		return max;		
	}
};

// TESTING
int main() {
	// Expected output: 6, 6
	Solution s;
	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> nums2 = {-3, -2, 1, 2, 2, 0, 1, 0};
	
	int output = s.maxSubArray(nums);
	cout << s.maxSubArray(nums) << "," << s.maxSubArray(nums2) << endl;
	return 0;
}