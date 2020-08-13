typedef struct Stack{
    char val;
    struct Stack *prev;
}Stack;

Stack *push(Stack *s, char val)
{
    Stack *ret;
    ret = (Stack*)malloc(sizeof(Stack));
    ret->val = val;
    ret->prev = s;
    return ret;
}

Stack *pop(Stack *s)
{
    Stack *ret = NULL;
    if (s)
    {
        ret = s->prev;
        free(s);
    }
    return ret;
}

char * multiply(char * num1, char * num2){
    char ret[12345];
    Stack sp[10] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    int  carry = 0;
    int  off1 = 0;
    int  off2 = 0;
    int  len1 = 0;
    int  len2 = 0;

    while (num1[off1++] != '\0');
    while (num2[off2++] != '\0');
    off1 = len1;
    off2 = len2;
    off1 = 0;
    off2 = 0;
}
