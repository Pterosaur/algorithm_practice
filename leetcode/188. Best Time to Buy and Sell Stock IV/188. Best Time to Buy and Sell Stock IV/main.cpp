//188. Best Time to Buy and Sell Stock IV
//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most k transactions.

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k == 0 || prices.empty()) {
			return 0;
		}
		k = min(k * 2, (int)prices.size());
		vector<int> buy_cache(k, INT_MIN);
		vector<int> sell_cache(k, INT_MIN );


		for (int i = 0; i < prices.size(); i++) {
			for (int j = 0; j < k; j++) {
				if (j > i) {
					break;
				}
				int buy_profit  = j == 0 ? -prices[i] : sell_cache[j - 1] - prices[i];
				int sell_profit = j == 0 ? 0 : buy_cache[j - 1] + prices[i];
				if (buy_profit > buy_cache[j]) {
					buy_cache[j] = buy_profit;
				}
				if (sell_profit > sell_cache[j]) {
					sell_cache[j] = sell_profit;
				}
			}
		}

		return *max_element(sell_cache.begin(), sell_cache.end());
	}
};

int main() {
	Solution s;
	vector<int> vet = {1,2};
	int max = s.maxProfit(1, vet);
	return 0;
}