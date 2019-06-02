/*
题目描述:
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。
e.g. 
input  : [7,1,5,3,6,4]
output : 5
解释 : 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5, 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

e.g. 
input  : [7,6,4,3,1]
output : 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 实质就是找到前(n-1)天的最小值 和 第n天的差值则为第n天的价格
        // 第n天最佳价格即为 Max(best_profit(n), best_profit(n-1))
        int len = prices.size();
        if(!len) return 0;
        int min_price=prices[0];
        int max_profit = 0;
        for(int k=1; k<len;k++){
            int curt_profit = prices[k] - min_price;
            // update max_profit
            if(curt_profit > max_profit) max_profit = curt_profit;
            if(prices[k] < min_price) min_price = prices[k];
        }
        return max_profit;
    }
};