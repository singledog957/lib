#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mergeStones(int *stones, int stonesSize, int k)
{
    if (stonesSize == 1)
        return 0;
    else if (stonesSize % (k - 1) != 1 && k != 2 || stonesSize < k)
        return -1;
    int ans = 0, cnt = 0;
    int sum = 0, min = 0;
    int left = 0, right = k;
    int index = 0, tmp = 0;
    int *dp = (int *)calloc(stonesSize + 1, sizeof(int));
    memset(dp, 0, sizeof(dp));
    int idp = 1;
    for (int i = left; i < right; i++)
    {
        sum += stones[i];
    }
    dp[0] = sum;
    while (cnt < (stonesSize - 1) / (k - 1))
    {
        while (right < stonesSize)
        {
            while (right < stonesSize && stones[right] == 0)
                right++;
            if (right == stonesSize)
                break;
            sum = sum - stones[left] + stones[right];
            dp[idp++] = sum;
            left++;
            while (stones[left] == 0)
                left++;
            right++;
        }
        min = dp[0], index = 0;
        for (int i = 0; i < idp; i++)
        {
            if (min > dp[i])
            {
                index = i;
                min = dp[i];
            }
        }
        while (stones[index] == 0)
            index++;
        stones[index] = min;
        memset(&stones[index] + 1, 0, sizeof(int) * (k - 1));
        ans += min;
        left = right = 0;
        while (tmp < k)
        {
            while (stones[right] == 0 && right < stonesSize)
                right++;
            if (right >= stonesSize)
                break;
            tmp++;
            right++;
        }
        if (tmp != k)
        {
            free(dp);
            return ans;
        }
        tmp = sum = 0;
        for (int i = left; i < right; i++)
        {
            sum += stones[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = sum;
        cnt++, idp = 1;
    }
    free(dp);
    return ans;
}
int main()
{
    int num[10] = {6, 4, 4, 6};
    printf("%d", mergeStones(num, 4, 2));
    return 0;
}