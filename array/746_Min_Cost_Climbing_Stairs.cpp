/**
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * Once you pay the cost, you can either climb one or two steps.
 * You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
 * Example:
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 *
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 */

#include <iostream>
#include <vector>

using namespace std;
/**
 * This method has some problems!!!
 * @param cost
 * @return
 */
int minCostClimbingStairs(vector<int>& cost)
{
    if(cost.size() < 3)
        return min(cost[0], cost[1]);
    int costs = 0;
    int i = 0;
    cout << "index: " << cost.size()-1 << endl;
    for (i = cost.size(); i > 1;)
    {
        if(cost[i-2] <= cost[i -1])
        {
            costs+=cost[i-2];
            i = i-2;
            cout << "index: " << i << endl;
        } else
        {
            costs+=cost[i-1];
            i = i-1;
            cout << "index: " << i << endl;
        }
    }
//    costs+=cost[i];
    return costs;
}

/**
 * Dynamic programing method
 * @param cost
 * @return
 */
int minCostClimbingStairs_dp(vector<int>& cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    for (int i = 2; i < n + 1; ++i) {
        dp[i] = min(dp[i- 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }
//    for (int j = 0; j < dp.size(); ++j)
//    {
//        cout << "dp[" << j << "] = " << dp[j] << endl;
//    }
    return dp.back();
}

int main()
{
    vector<int> cost({1,100,1,1,1,100,1,1,100,1});//6
    vector<int> cost1({0,0,1,1}); //1
    vector<int> cost2({0,2,2,1}); //2

    cout << "dp_method->The min cost is: " << minCostClimbingStairs_dp(cost1) << endl;
    cout << "general method->The min cost is: " << minCostClimbingStairs(cost1) << endl;
    return 0;
}