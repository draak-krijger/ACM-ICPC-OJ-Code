# 2010 Tokyo: Balloon Collecting

## Solution
基本解法为动态规划。设dp[i][ball]表示处理了第i个球，当前车上载有的气球数目为ball个的时候，所行走的最短距离。在每次dp前先 判断时间是否允许，如果无论怎样都解决不了就抛出NG。否则进行dp。dp[i][0]在计算完dp[i][1]、dp[i][2]、dp[i][3]之 后处理。在可以接到下一个球的情况下，易得载有越多的球回到原点越好，答案越优。 
