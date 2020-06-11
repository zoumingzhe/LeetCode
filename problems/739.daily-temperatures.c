/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int)*TSize);
    int  min_day = 0;

    for (int i = 0; i < TSize; i++)
    {
        ret[i] = 0;
        for (int j = min_day; j < i; j++)
        {
            if (ret[j] == 0 && T[i] > T[j])
            {
                ret[j] = i - j;
            }
        }
        for (int j = min_day; j < i; j++)
        {
            if (ret[j] == 0)
            {
                min_day = j;
                break;
            }
        }
    }

    *returnSize = TSize;
    return ret;
}
