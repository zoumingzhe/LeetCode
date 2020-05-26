void quictsort(int* nums, int head, int tail) {
	int i = head;
	int j = tail;
	int tmp = nums[i];
	while (i < j)
	{
		for (; j > i; j--)
		{
			if (nums[j] < tmp)
			{
				nums[i] = nums[j];
				break;
			}
		}
		for (; i < j; i++)
		{
			if (nums[i] > tmp)
			{
				nums[j] = nums[i];
				break;
			}
		}
	}
	nums[i] = tmp;
	if (i - head > 1)
	{
		quictsort(nums, head, i - 1);
	}
	if (tail - j > 1)
	{
		quictsort(nums, j + 1, tail);
	}
}

int findDuplicate(int* nums, int numsSize){
    int *tmp = (int*)malloc(sizeof(int)*numsSize);
    memcpy(tmp, nums, sizeof(int)*numsSize);
    quictsort(tmp, 0, numsSize-1);
    for (int i = 0; i < numsSize-1; i++)
    {
        if (tmp[i] == tmp[i+1])
        {
            return tmp[i];
        }
    }
    return 0;
}
