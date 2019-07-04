#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = 0;
		int rsum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] + rsum > 0)
				rsum += nums[i];
			else
				rsum = 0;
			if (rsum > max)
				max = rsum;
		}
		return max;		
	}
};

// TESTING
int main() {
	// Expected output: 6
	Solution s;
	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	
	int output = s.maxSubArray(nums);
	cout << "Output: " << output << endl;
	return 0;
}