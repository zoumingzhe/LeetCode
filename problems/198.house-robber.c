#define max(a,b) (a) > (b) ? (a) : (b)

int rob(int* nums, int numsSize){
    int a = 0;
    int b = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (i % 2 == 0)
        {
            a += nums[i];
        }
        else
        {
            b += nums[i];
        }
    }
    
    return max(a,b);
}
