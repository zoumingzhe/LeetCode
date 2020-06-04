/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int)*numsSize);
    int  product = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        product *= nums[i];
    }

    for (int i = 0; i < numsSize; i++)
    {
        ret[i] = product / nums[i];
    }
    
    *returnSize = numsSize;
    return ret;
}
