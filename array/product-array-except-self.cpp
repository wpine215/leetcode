#include <iostream>
#include <vector>
using namespace std;

// Given an array nums of n integers where n > 1, return an array output,
// such that output[i] is equal to the product of all the elements of nums except nums[i].

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        int forward_multiplier = nums[0];
        int reverse_multiplier = nums[nums.size() - 1];
        // Make sure the first output variable starts at 1 if non-zero (0, if zero)
        output[0] = nums[0] ? 1 : 0;

        // Iterate through the array forwards,
        // setting each element in output[] equal to the product
        // of all previous elements (excluding self) in num[]
        for(int i = 1; i < nums.size(); i++) {
            output[i] = forward_multiplier;
            forward_multiplier *= nums[i];
        }
        // Iterate through the array in reverse,
        // multiplying each element in output[] by the product
        // of all the following elements (excluding self) in num[]
        for(int j = nums.size() - 2; j >= 0; j--) {
            output[j] *= reverse_multiplier;
            reverse_multiplier *= nums[j];
        }
        return output;
    }

    vector<int> productExceptSelfOptimized(vector<int>& nums) {
        // Same as above, but only uses one multiplier var (init @ 1)
        // And starts each for loop one iteration earlier
        // Therefore, uses less memory and time (doesn't need ternary if statement)
        // 99% time percentile with this version vs. 87% (above version)
        vector<int> output(nums.size());
        int multiplier = 1;

        for(int i = 0; i < nums.size(); i++) {
            output[i] = multiplier;
            multiplier *= nums[i];
        }

        multiplier = 1;
        for(int j = nums.size()-1; j >= 0; j--) {
            output[j] *= multiplier;
            multiplier *= nums[j];
        }
        return output;
    }
};

// TESTING
int main() {
	vector<int> input{1, 2, 3, 4};

	Solution s;
	vector<int> output = s.productExceptSelf(input);

    cout << "[";
	for(auto i : output){
        cout << i << ", ";
    }
    cout << endl;
	return 0;
}