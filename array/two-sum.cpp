#include <vector>
#include <iostream>

using namespace std;

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.


// Runs in O(n^2) time
class NaiveSolution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
		for(int i = 0; i < nums.size(); i++) {
			for(int j = i + 1; j < nums.size() - 1; j++) {
				if(nums[i] + nums[j] == target) {
					vector<int> ind{i, j};
					return ind;
				}
			}
		}
		vector<int> ind{0, 0};
		return ind;
    }
};

// TESTING
int main() {
	vector<int> input{2, 7, 11, 15};
	int tar = 9;
	NaiveSolution ns;
	vector<int> output = ns.twoSum(input, tar);
	cout << output[0] << " and " << output[1] << endl;
	return 0;
}
