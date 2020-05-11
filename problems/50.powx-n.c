double myPow(double x, int n){
    unsigned int z = n;
    unsigned int i = 0;
    bool negative = 0;
    double  ret = 1.0;
    double *tmp = (double*)malloc(sizeof(double)*65536);
    unsigned int *idx = (int*)malloc(sizeof(int)*65536);

    if (n < 0) {
        z = -(long int)n;
        negative = 1;
    }
    else if (n == 0) {
        return 1.0;
    }

    i = 1;
    idx[0] = 1;
    tmp[0] = x;
    while ((long unsigned int)idx[i-1]*2 <= z)
    {
        tmp[i] = tmp[i-1] * tmp[i-1];
        idx[i] = idx[i-1] * 2;
        i++;
    }

    while (i > 0 && z > 0)
    {
        i--;
        if (z >= idx[i])
        {
            ret *= tmp[i];
            z -= idx[i];
        }
    }
    
    if (!negative) return ret;
    else return (1.0/ret);
}
