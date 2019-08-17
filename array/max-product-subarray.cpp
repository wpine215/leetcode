#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int runningProd = 1;
		int currentMax = nums[0];
		int firstNeg = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				// Since the current number is not 0, we can continue
				runningProd *= nums[i];

				// document this bs later
				if (firstNeg == 0) {
					firstNeg = nums[i];
				} else if (firstNeg > 0) {
					firstNeg *= nums[i];
				}

				// If the current number by itself is greater than current max, update it
				if (nums[i] > currentMax) currentMax = nums[i];
				// If the running product is greater than the current max, update it
				if (runningProd > currentMax) currentMax = runningProd;
				// If the subarray has had a negative number, and the running product excluding that first negative number
				// is greater than the current max, update it
				if (firstNeg < 0 && runningProd / firstNeg > currentMax) currentMax = runningProd / firstNeg;
			} else {
				// Current number is zero, reset variables
				runningProd = 1;
				firstNeg = 0;
				// If current max is negative, then it is updated to zero
				if (currentMax < 0) currentMax = 0;
			}
			cout << "RUNNING PROD: " << runningProd << endl;
			cout << "FIRST NEG: " << firstNeg << endl;
		}
		return currentMax;
	}
};

// TESTING
int main() {
	// Expected output: 
	Solution s;
	// vector<int> nums = {2, -5, -2, -4, 3};
	vector<int> nums = {-2, 0, -1};
	
	int output = s.maxProduct(nums);
	cout << output << endl;
	return 0;
}