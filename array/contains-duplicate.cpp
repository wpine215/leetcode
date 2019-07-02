#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Hash table implementation, O(n) time and space
        unordered_set<int> nm(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nm.find(nums[i]) != nm.end())
                return true;
            else
                nm.insert(nums[i]);
        }
        return false;
    }
};

// TESTING
int main() {
    // Expected output: true
	Solution s;
	vector<int> nums = {1, 2, 3, 1};
	
	int output = s.containsDuplicate(nums);
	cout << output << endl;
	return 0;
}