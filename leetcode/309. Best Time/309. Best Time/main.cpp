//309. Best Time to Buy and Sell Stock with Cooldown
//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//Example :
//
//	prices = [1, 2, 3, 0, 2]
//	maxProfit = 3
//	transactions = [buy, sell, cooldown, buy, sell]
//
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit_n2(vector<int>& prices) {
		vector<int> cache(prices.size(), 0);
		int max_profit = 0;
		for (int i = 0; i < prices.size(); i++) {
			int cur_max_profit = 0;
			for (int j = 0; j < i; j++) {
				int profit = 0;
				profit = (prices[i] > prices[j] ? (prices[i] - prices[j]) : 0) + (j > 1 ? cache[j - 2] : 0);
				cur_max_profit = max(cur_max_profit, profit);
				cur_max_profit = max(cur_max_profit, cache[j]);
			}
			cache[i] = cur_max_profit;
			max_profit = max(max_profit, cur_max_profit);
		}
		return max_profit;
    }



    int maxProfit(vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}

		struct state {
			int sell;
			int buy;
			int cold;
		};
		state last_s = { 0,-prices.front(), 0 }, cur_s = { 0 };
		
		for (int i = 1; i < prices.size(); i++) {
			cur_s.sell = max(last_s.sell+ prices[i] - prices[i - 1], last_s.buy + prices[i]);
			cur_s.buy = max(last_s.buy, last_s.cold) - prices[i];
			cur_s.cold = max(max(last_s.sell, last_s.cold),last_s.buy);
			last_s = cur_s;
		}

		return max(cur_s.buy, max(cur_s.sell, max(cur_s.cold, 0)));
    }

};



int main() {
	Solution s;
	vector<int> vet = {1,2,3,0,2};
	//vector<int> vet = { 6,1,6,4,3,0,2 };
	s.maxProfit(vet);
	return 0;
}