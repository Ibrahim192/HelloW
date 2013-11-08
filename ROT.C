#include<stdio.h>
#include<stdlib.h>
typedef struct node
{

    int data;
    node *rlink,*llink;
}node;
node *first=NULL,*last=NULL;
void display()
{
    node *n=first;
     if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(n!=NULL)
    {

        printf("%d\t",n->data);
        n=n->rlink;
    }
}
void insert(int x){



    if(last==NULL)
    {

        first=last=(node*)malloc(sizeof(node));

           first->data=x;
        first->llink=NULL;
        first->rlink=NULL;

    }
    else
    {
        first->llink=(node*)malloc(sizeof(node));


        first->llink->rlink=first;

        first=first->llink;
        first->data=x;
         first->llink=NULL;





    }
}
void del(int x)
{

    node *n,*p;
    n=first;
    if(n->data==x)
    {
        if(n->rlink==n->llink)
        {

            first=last=NULL;
            free(n);
            return;

        }


        first=n->rlink;
        first->llink=NULL;
        free(n);
        return;
    }
    else
    {
        while(n->rlink!=NULL)
    {
        if(n->rlink->data==x)
        {
            p=n->rlink;

            if(n->rlink->rlink==NULL)
            {

                last=n;
                n->rlink=NULL;

                free(p);
                return;
            }


            n->rlink->rlink->llink=n;
            n->rlink=n->rlink->rlink;
            free(p);
            return;
        }
        n=n->rlink;
    }
     }
    printf("Element not found\n");


}
void insbef(int e,int key)
{
    node *t=first;


    if(t->data==key)
    {

        first->llink=(node*)malloc(sizeof(node));
        first=first->llink;
        first->llink=NULL;
        first->rlink=t;
        first->data=e;
        return;

    }
    else
    {


    while(t->rlink!=NULL)

{

    if(t->rlink->data==key)
    {
        t->rlink->llink=(node*)malloc(sizeof(node));
        t->rlink->llink->rlink=t->rlink;
        t->rlink=t->rlink->llink;
        t->rlink->llink=t;
        t->rlink->data=e;
        return;

    }
    t=t->rlink;
    }

}
printf("\nKey Not found");

}
    int main()
{

    int ele,ch,key;
    while(1)
    {

        printf("\n1.Insert\n2.Delete\n3.InsertBefore\n4.Display\n5.exit\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1: printf("enter element to be inerted: ");
            scanf("%d",&ele);
            insert(ele);
            display();
            break;
            case 2:
            if(first==NULL)
            {
                printf("List is empty\n");
                break;
                }
                printf("Enter element to be deleted: ");
            scanf("%d",&ele);
            del(ele);
            break;
            case 3:if(first==NULL)
    {
        printf("List is empty\n");
        break;
    }

            printf("Enter the element to be inserted: ");
            scanf("%d",&ele);
            printf("enter the key before which element needs to be added: ");
            scanf("%d",&key);
            insbef(ele,key);
            break;

            case 4:
            display();
            break;
            default:return 0;
        }
    }
}
