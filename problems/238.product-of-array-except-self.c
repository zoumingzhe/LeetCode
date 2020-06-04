/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int)*numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        ret[i] = 1;
        for (int j = 0; j < numsSize; j++)
        {
            if (i != j)
            {
                ret[i] *= nums[j];
            }
        }
    }

    *returnSize = numsSize;
    return ret;
}
