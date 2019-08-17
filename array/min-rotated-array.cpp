#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minRotatedArray(vector<int>& nums) {
        int lhs, rhs;
        vector<int> lhs_temp, rhs_temp;

        if (nums.size() > 3) {
            if (nums[0] > nums[nums.size()-1]) {
                lhs_temp = vector<int>(nums.begin(), nums.begin() + nums.size() / 2);
                rhs_temp = vector<int>(nums.begin() + nums.size() / 2, nums.end());
                lhs = minRotatedArray(lhs_temp);
                rhs = minRotatedArray(rhs_temp);
                return lhs != -1 ? lhs : rhs;
            }
        } else if (nums.size() == 3) {
            if (nums[1] > nums[2]) return nums[2];
            else if (nums[0] > nums[1]) return nums[1];          
        } else if (nums.size() == 2) {
            if (nums[0] > nums[1]) return nums[1];
        }
        return -1;
    }
};

// TESTING
int main() {
    // Expected output: 2, 0, 1
    Solution s;
    vector<int> nums1 = {7, 9, 11, 17, 18, 2, 4, 5};
    vector<int> nums2 = {2, 5, 9, 0, 1};
    vector<int> nums3 = {5, 6, 7, 8, 1, 3};
    cout << "TEST CASE 1 OUTPUT: " << s.minRotatedArray(nums1) << endl;
    cout << "TEST CASE 2 OUTPUT: " << s.minRotatedArray(nums2) << endl;
    cout << "TEST CASE 3 OUTPUT: " << s.minRotatedArray(nums3) << endl;
    return 0;
}