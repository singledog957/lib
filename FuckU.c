// 这个sb程序 我tm写了8个小时
// 我是sb 但是递归栈是真该死
// 我周六干什么不好 1h写完 7h都在debug
// 破防了 我真的f
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct func
{
    char self[21];
    struct func *sub[10];
    bool prCtl;
    int subs;
} func;
/*typedef struct rec
{
    char *self;
    bool prCtl;
} rec;
rec record[100];
int irec;*/
func *head;
func *result;
func *check(func *, func *);
void myFree(func *);
func *enter(func *now);
func *initalFunc();
void myprint(func *);
int preCheck(func *old, func *new);
int main()
{
    int n = 0;
    scanf("%d", &n);
    if (n)
    {
        head = initalFunc();
        enter(head);
    }
    myprint(head);
    // myFree(_main);
    return 0;
}
void myFree(func *now)
{
}
func *check(func *now, func *all)
{
    if (all == NULL || all->sub[0] == NULL)
        return now;
    result = NULL;
    for (int i = 0; all->sub[i] != NULL; i++)
    {
        if (strcmp(all->sub[i]->self, now->self) == 0)
            return result = all->sub[i];
        if (result == NULL)
            check(now, all->sub[i]);
    }
    return result == NULL ? now : result;
}
func *initalFunc()
{
    func *now = (func *)calloc(1, sizeof(func));
    scanf("%s", now->self);
    // record[irec++].self=now->self;
    // return check(now, head);
    return now;
}
func *enter(func *now)
{
    int op = 0;
    scanf("%d", &op);
    if (op == 0)
        return now;
    while (op)
    {
        func *new = initalFunc();
        func *old = check(new, now);
        func *Bold = check(new, head);
        if (preCheck(old, new))
        {
            scanf("%d", &op);
            continue;
        }
        if (old == new)
        {
            if (preCheck(Bold, new))
            {
                scanf("%d", &op);
                continue;
            }
        }
        now->sub[now->subs] = enter(new);
        now->subs++;
        scanf("%d", &op);
    }
    return now;
}
int preCheck(func *old, func *new)
{
    if (old != new)
    {
        old->sub[old->subs] = enter(old);
        old->subs++;
        if (old->sub[old->subs - 1] == old)
        {
            old->sub[old->subs - 1] = NULL;
            old->subs--;
        }
        return 1;
    }
    return 0;
}
void myprint(func *now)
{
    if (now->prCtl || now->sub[0] == NULL)
        return;
    printf("%s:", now->self);
    int i = 0;
    while (now->sub[i + 1] != NULL)
    {
        printf("%s,", now->sub[i++]->self);
    }
    printf("%s\n", now->sub[i]->self);
    now->prCtl = true;
    i = 0;
    while (now->sub[i] != NULL)
        myprint(now->sub[i++]);
}