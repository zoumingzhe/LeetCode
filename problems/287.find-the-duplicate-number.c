int findDuplicate(int* nums, int numsSize){
    int *tmp = (int*)malloc(sizeof(int)*numsSize);
    memset(tmp, 0x0, sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        if (tmp[nums[i]])
        {
            return nums[i];
        }
        else
        {
            tmp[nums[i]] = nums[i];
        }
    }
    return 0;
}
