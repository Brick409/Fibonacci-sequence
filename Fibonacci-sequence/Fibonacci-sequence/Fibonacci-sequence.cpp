// Fibonacci-sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <malloc.h>

using namespace std;

vector<int> memo; //记录之前计算过的f(n)

int num = 0;

/* 计算斐波那契数列的值 */
/* 记忆化搜索的方法（自顶向下的解决问题），之前出现过的就直接存在memo数组中 */
int fib(int n)
{
    num++;
    if (n==0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (memo[n]==-1)
    {
        memo[n] = fib(n - 1) + fib(n - 2);
    }


    return memo[n];
}
/*
动态规划：将原问题拆解成若干个子问题，同时保存子问题的答案，
使得每个子问题只求解一次，最终获得原问题的答案。
*/
/* 自底向上的解决问题，之前出现过的就直接存在memo数组中 */
int fib2(int n)
{
    vector<int> tmpMemo(n + 1, -1);
    tmpMemo[0] = 0;
    tmpMemo[1] = 1;
    for (int i = 2; i <= n;i++)
    {
        tmpMemo[i] = tmpMemo[i - 1] + tmpMemo[i - 2];
    }
    return tmpMemo[n];
}

/* 有一个楼梯，总共有n阶台阶。每一次，可以上一个台阶，也可以上两个台阶。
问，爬上这样的一个楼梯，一共有多少不同的方法？
例如：n=3时，可以爬上这样的楼梯的方法有：【1，1，1】，【1，2】，【2，1】
所以答案为3
*/
class Solution
{
private:
    vector<int> memo;
    int clacWays(int n)
    {
        if (n == 1)
        {
            return 1;
        }

        if (n == 2)
        {
            return 2;
        }

        if (memo[n]==-1)
        {
            memo[n] = clacWays(n - 1) + clacWays(n - 2);
        }

        /* 跨n层台阶的方法 = 爬上n-1阶台阶的方法 + 爬上n-2阶台阶的方法 */
        return memo[n];
    }
public:
    int climbStairs(int n)
    {
        memo = vector<int>(n + 1, -1);
        return clacWays(n);
    }
    /* 动态规划的方法 */
    int climbStairs2(int n)
    {
        vector<int> memo2(n + 1, -1);
        memo2[0] = 1;
        memo2[1] = 1;

        for (int i = 2; i <= n;i++)
        {
            memo2[i] = memo2[i - 1] + memo2[i - 2];
        }
        return memo2[n];
    }
};



int _tmain(int argc, _TCHAR* argv[])
{
    Solution solution;
    num = 0;
    int n = 40;
    memo = vector<int>(n + 1, -1);
    //time_t startTime = clock();
    int res = fib(n);
    //time_t endTime = clock();

    cout << "fib(" << n << ")" << res << endl;

    int sumWays = solution.climbStairs(n);
    cout << "climb the "<< n << " stairs has ways num =" << sumWays << endl;

    int sumWays2 = solution.climbStairs2(n);
    cout << "climb the " << n << " stairs has ways num =" << sumWays2 << endl;

    //cout << "time :" << endTime - startTime << endl;
    system("pause");
	return 0;
}

