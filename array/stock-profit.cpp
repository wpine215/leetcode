#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfitNaive(vector<int>& prices) {
		// O(n^2) time
		int tmp = 0;
		for(int i = 0; i < prices.size(); i++) {
			int subtmp = 0;
			for(int j = 0; j < i; j++) {
				if(prices[i] - prices[j] > subtmp)
					subtmp = prices[i] - prices[j];
			}
			if(subtmp > tmp)
				tmp = subtmp;
		}
		return tmp;
    }

	int maxProfit(vector<int>& prices) {
		// O(n) time
		int min = INT32_MAX;
		int localmax = INT32_MIN;
		int mp = 0;
		for(int i = 0; i < prices.size(); i++) {
			if(prices[i] < min) {
				min = prices[i];
				localmax = prices[i];
			}
			if(prices[i] > localmax) {
				localmax = prices[i];
			}
			if(localmax - min > mp)
				mp = localmax - min;
		}
		return mp;
	}

	int maxProfitOptimized(vector<int>& prices) {
		// Same as above but removes redundant if statement and extra variable
		int min = INT32_MAX;
		int mp = 0;
		for(int i = 0; i < prices.size(); i++) {
			if(prices[i] < min)
				min = prices[i];
			else if(prices[i] - min > mp)
				mp = prices[i] - min;
		}
		return mp;
	}
};

// TESTING
int main() {
    // Expected output: 5
	Solution s;
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	
	int output = s.maxProfitOptimized(prices);
	cout << output << endl;
	return 0;
}