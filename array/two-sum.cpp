#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution {
    public:
    vector<int> twoSumNaive(vector<int>& nums, int target) {
		// Brute force method, O(n^2) time
		for(int i = 0; i < nums.size(); i++) {
			for(int j = i + 1; j < nums.size() - 1; j++) {
				if(nums[i] + nums[j] == target) {
					vector<int> ind{i, j};
					return ind;
				}
			}
		}
		return vector<int> {0};
    }

	vector<int> twoSum(vector<int>& nums, int target) {
		// Two-pass hash table, O(n) time
		unordered_map<int, int> nm;
		for(int i = 0; i < nums.size(); i++) {
			// Create hash table with number as key and its index as value
			nm.insert({nums[i], i});
		}
		for(int i = 0; i < nums.size(); i++) {
			// For each number, check whether (target - num) is in the hash table
			// Also check to make sure the same element is not used twice
			// If it is, return the indices of the first and second addends
			if(nm.find(target - nums[i]) != nm.end() && i != nm.at(target - nums[i]))
				return vector<int> {i, nm.at(target - nums[i])};
		}
		return vector<int> {0};
	}

	vector<int> twoSumOptimized(vector<int>& nums, int target) {
		// Accomplishes above solution in only one for loop
		// At each iteration, checks for previously entered values
		unordered_map<int, int> nm;
		for(int i = 0; i < nums.size(); i++) {
			if(nm.find(target - nums[i]) != nm.end() && i != nm.at(target - nums[i]))
				return vector<int> {nm.at(target - nums[i]), i};
			nm.insert({nums[i], i});
		}
		return vector<int> {0};
	}
};

// TESTING
int main() {
	vector<int> input{2, 7, 11, 15};
	int tar = 9;

	Solution s;
	vector<int> output = s.twoSum(input, tar);

	cout << output[0] << " and " << output[1] << endl;
	return 0;
}
