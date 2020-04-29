#define max(a,b) (a>b?a:b)
#define is_merge(a,b) ((a>=0&&b>=0)?1:0)

int max_val(int *arr, int num, int off)
{
    int sum = arr[off];
    int max = arr[off];
    if (max < 0)
    {
        return max;
    }
    
    for (int i = off + 1; i < off + num; i++)
    {
        sum += arr[i % num];
        max = max(max, sum);
    }
    return max;
}

int max_sub(int *arr, int num)
{
    int val = arr[0];
    int max = arr[0];
    for (int i = 0; i < num; i++)
    {
        val = max_val(arr, num, i);
        max = max(max, val);
    }
    return max;
}

int maxSubarraySumCircular(int* A, int ASize){
    int *B = (int*)malloc(sizeof(int)*ASize);
    int BSize;
    BSize = 1;
    B[0] = A[0];
    for (int off = 1; off < ASize; off++)
    {
        if (is_merge(A[off], B[BSize-1]))
        {
            B[BSize-1] += A[off];
        }
        else
        {
            B[BSize++] = A[off];
        }
    }
    return max_sub(B, BSize);
}
