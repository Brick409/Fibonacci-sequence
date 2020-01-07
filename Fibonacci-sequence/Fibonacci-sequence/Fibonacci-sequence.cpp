// Fibonacci-sequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <malloc.h>

using namespace std;

vector<int> memo; //��¼֮ǰ�������f(n)

int num = 0;

/* ����쳲��������е�ֵ */
/* ���仯�����ķ������Զ����µĽ�����⣩��֮ǰ���ֹ��ľ�ֱ�Ӵ���memo������ */
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
��̬�滮����ԭ����������ɸ������⣬ͬʱ����������Ĵ𰸣�
ʹ��ÿ��������ֻ���һ�Σ����ջ��ԭ����Ĵ𰸡�
*/
/* �Ե����ϵĽ�����⣬֮ǰ���ֹ��ľ�ֱ�Ӵ���memo������ */
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

/* ��һ��¥�ݣ��ܹ���n��̨�ס�ÿһ�Σ�������һ��̨�ף�Ҳ����������̨�ס�
�ʣ�����������һ��¥�ݣ�һ���ж��ٲ�ͬ�ķ�����
���磺n=3ʱ����������������¥�ݵķ����У���1��1��1������1��2������2��1��
���Դ�Ϊ3
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

        /* ��n��̨�׵ķ��� = ����n-1��̨�׵ķ��� + ����n-2��̨�׵ķ��� */
        return memo[n];
    }
public:
    int climbStairs(int n)
    {
        memo = vector<int>(n + 1, -1);
        return clacWays(n);
    }
    /* ��̬�滮�ķ��� */
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

