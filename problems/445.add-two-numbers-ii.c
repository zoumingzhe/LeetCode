/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* item1;
    struct ListNode* item2;
    struct ListNode* item3;
    struct ListNode* newl1;
    struct ListNode* newl2;
    struct ListNode* tmp;
    struct ListNode* ret = NULL;
    int       add = 0;

    // 反转列表1
    item1 = l1;
    item2 = l1->next;
    l1->next = NULL;
    while (item2 != NULL)
    {
        item3 = item2->next;
        item2->next = item1;
        item1 = item2;
        item2 = item3;
    }
    newl1 = item1;

    // 反转列表2
    item1 = l2;
    item2 = l2->next;
    l2->next = NULL;
    while (item2 != NULL)
    {
        item3 = item2->next;
        item2->next = item1;
        item1 = item2;
        item2 = item3;
    }
    newl2 = item1;

    // 相加
    while (newl1 != NULL || newl2 != NULL)
    {
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (newl1 != NULL && newl2 != NULL)
        {
            add += (newl1->val + newl2->val);
            newl1 = newl1->next;
            newl2 = newl2->next;
        }
        else if (newl1 != NULL)
        {
            add += (newl1->val);
            newl1 = newl1->next;
        }
        else if (newl2 != NULL)
        {
            add += (newl2->val);
            newl2 = newl2->next;
        }
        tmp->val = add % 10;
        tmp->next = ret;
        ret = tmp;
        add /= 10;
    }
    if (add > 0)
    {
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = add;
        tmp->next = ret;
        ret = tmp;
    }
    return ret;
}
