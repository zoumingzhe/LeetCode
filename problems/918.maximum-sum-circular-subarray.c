#define max(a,b) (a>b?a:b)

int max_sub(int *arr, int num, int off)
{
    int sum = arr[off];
    int max = arr[off];
    for (int i = off + 1; i < off + num; i++)
    {
        sum += arr[i % num];
        max = max(max, sum);
    }
    return max;
}

int maxSubarraySumCircular(int* A, int ASize){
    int val = A[0];
    int max = A[0];
    for (int i = 0; i < ASize; i++)
    {
        val = max_sub(A, ASize, i);
        max = max(max, val);
    }
    return max;
}
