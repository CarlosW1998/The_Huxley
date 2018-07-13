#include<stdio.h>
#include<stdlib.h>

int dp[2][200000];

int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

int maxsale(int* values, int size, int price, int i, int flag, int hight)
{
      if(i >= size) return hight;
      if(dp[flag][i] != -1) return dp[flag][i];
      if(flag)
      {
        dp[flag][i] = max(maxsale(values, size, price, i+1, 0, -(values[i]+price)), maxsale(values, size, price, i+1, 1, hight));
        return dp[flag][i];
      }
      dp[flag][i] = max(values[i] + hight + maxsale(values, size, price, i+1, 1, 0), maxsale(values, size, price, i+1, 0, hight));
      return dp[flag][i];
}

int main()
{
    int size, price, a, b, c;

    scanf("%d%d", &size, &price);

    int value[size];

    for(a = 0; a < size; a++)
    {
        dp[0][a] = -1;
        dp[1][a] = -1;
        scanf("%d", &value[a]);
    }

    printf("%d\n", maxsale(value, size, price, 0, 1, 0));

    return 0;
}
