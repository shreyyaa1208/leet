class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int aheadNotBuy, aheadBuy, CurBuy, curNoBuy;
        aheadNotBuy=aheadBuy=0;
        for(int ind=n-1;ind>=0;ind--){
            curNoBuy=max(prices[ind]-fee+aheadBuy,
            0+aheadNotBuy);
  CurBuy=max(-prices[ind]+aheadNotBuy,
             0+aheadBuy);
             aheadBuy=CurBuy;
             aheadNotBuy=curNoBuy;  
        }
        return aheadBuy;
    }
};