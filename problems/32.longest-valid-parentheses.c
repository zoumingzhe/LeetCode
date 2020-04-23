typedef struct StackLink{
    int len;
    struct StackLink *prev;
}StackLink;

StackLink *push(StackLink *s, int len)
{
    StackLink *ret;
    ret = (StackLink*)malloc(sizeof(StackLink));
    ret->len = len;
    ret->prev = s;
    return ret;
}

StackLink *pop(StackLink *s)
{
	StackLink *ret = NULL;
	if (s)
	{
		ret = s->prev;
		free(s);
	}
	return ret;
}

int top(StackLink *s, int n)
{
	StackLink *ret = s;
    while (--n)
    {
        if (ret)
        {
            ret = ret->prev;
        }
        else
        {
            break;
        }
        
    }

    if (ret)
    {
        return ret->len;
    }
    else
    {
        return 0;
    }
}

int longestValidParentheses(char * s){
    int i = 0;
    int tmp = 0;
    int max = 0;
    int top1, top2;
    StackLink *stack = NULL;

    while(s[i] != '\0')
    {
        if (s[i] == ')')
        {
            top1 = top(stack, 1);
            top2 = top(stack, 2);
            if (top1 == 1)
            {
                stack->len = 2;
            }
            else if (top1 > 1 && top2 == 1)
            {
                tmp = stack->len + 2;
                stack = pop(stack);
                stack->len = tmp;
            }
            else
            {
                stack = push(stack, 0);
            }

            while (top(stack, 2) > 1 && stack->len > 1)
            {
                tmp = stack->len;
                stack = pop(stack);
                stack->len += tmp;
            }
        }
        else if (s[i] == '(')
        {
            stack = push(stack, 1);
        }
        i++;
    }

    while(stack)
    {
        max = stack->len > max ? stack->len : max;
        stack = pop(stack);
    }
    return (max > 1 ? max : 0);
}
