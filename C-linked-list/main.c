#include <stdio.h>
#include <stdlib.h>
struct node
{
    int n;
    struct node* next;
} *head;

struct compnode
{
    struct node* head;
    int size;
};
void input()
{
    int i,f=0;
    struct node *tmp;
    while (scanf("%d", &i), i != -1)
    {
        if(!(f++)) {
            tmp = malloc(sizeof(struct node));
            head=tmp;
        }
        else
        {
            tmp->next=malloc(sizeof(struct node));
            tmp=tmp->next;
        }
        tmp->n = i;
    }
    if(!f)
    {
        head=NULL;
        return;
    }
    tmp->next=NULL;
    return;
}

void output(struct node *n)
{
    struct node *tmp = n;
    while (tmp != NULL)
    {
        printf("%d ", tmp->n);
        tmp = tmp->next;
    }
    printf("\n");
    return;
}

int searchlist(struct node *head, int val)
//单＊传入head的值 call by value 会创建一个local head var
{
    int index=0;
    while(head->n!=val)
    {
        head=head->next;
        index++;
    }
    return index;
}

void cleanlist(struct node *head)
{
    struct node *tmp=head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
        free(head);
        head=tmp;
    }
    return;
}

int removenode(struct node **ptrhead, int index)
{
    struct node *tmp,*tmp1;
    if(index==0)
    {
        if((*ptrhead)->next==NULL)
            return -1;
        tmp=*ptrhead;
        *ptrhead=(*ptrhead)->next;
        free(tmp);
    }
    else
    {
        tmp=*ptrhead;
        while(index-- > 1)
        {
            if(tmp->next == NULL) return -1;
            tmp=tmp->next;
        }
        tmp1=tmp->next;
        if(tmp->next->next!=NULL)
            tmp->next=tmp->next->next;
        else
            tmp->next=NULL;
        free(tmp1);
    }
    return 0;
}

int removenode2(struct compnode *ll, int index)
{
    struct node *tmp,*tmp1;
    if(index==0)
    {
        if (ll->size == 0)
            return -1;
        tmp = ll->head;
        ll->head = ll->head->next;
        free(tmp);
    }
    else
    {
        tmp=ll->head;
        while(index-- > 1)
        {
            if(tmp->next==NULL) return -1;
            tmp=tmp->next;
        }
        tmp1=tmp->next;
        if(tmp->next->next!=NULL)
            tmp->next=tmp->next->next;
        else
            tmp->next=NULL;
        free(tmp1);
    }
    return 0;
}

void split(struct node *head, struct node **ptrEvenList, struct node **ptrOddList)
{
    struct node *even,*odd;
    (*ptrEvenList)=head;
    if(head!=NULL)
        (*ptrOddList)=head->next;
    else
    {
        //链表为空
        (*ptrOddList)=NULL;
        return;
    }
    head=head->next;
    even=(*ptrEvenList);
    odd=(*ptrOddList);
    if(head!=NULL)  //长度为1
        while(head->next!=NULL)
        {
            even->next=head->next;
            even=even->next;
            head=head->next;
            if(head->next==NULL) break;
            odd->next=head->next;
            odd=odd->next;
            head=head->next;
        }
    else return;
    even->next=odd->next=NULL;
    return;

}

int duplicateReverse(struct node *head, struct node **ptrNewHead)
{
    struct node *origin[1000], *tmp;
    int cnt=0,i;
    if(head==NULL) return -1;
    while(head != NULL)
    {
        origin[cnt++]=head;
        head=head->next;
    }
    if(!cnt) return -1;
    if(cnt==1) return 0;
    tmp=(*ptrNewHead)=origin[cnt-1];
    for(i=cnt-2;i>=0;i--)
    {
        tmp->next=origin[i];
        tmp=tmp->next;
    }
    tmp->next=NULL;
    return 0;
}

int main()
{
    int i, j, k;
    struct node *even, *old;
    input();
    even=malloc(sizeof(struct node));
    old=malloc(sizeof(struct node));
    duplicateReverse(head,&old);
    output(old);
    return 0;
}
