#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*prev;
    struct node*next;
}*head,*temp,*tail;

void create();
void delete_beg();
void delete_middle();
void delete_end();
void insert_end(int x);
void print();
void insert_mid(int x, int y);
void insert_beg(int x);
void main()
{
    create();
    int n;
    printf("how many nodes insert begining\n");
    scanf("%d",&n);
    int x;
    for(int i =0;i<n;i++)
    {
        printf("enter the data you want to insert");
        scanf("%d",&x);
        insert_beg(x);
    }
    print();
    int m;
    printf("how many nodes insert at last");
    scanf("%d",&m);
    int y;
    for(int i =0;i<m;i++)
    {
        printf("enter the data you want to insert at last");
        scanf("%d",&y);
        insert_end(y);
    }
    print();
    int k,l;
    printf("enter what data you want to insert at middle");
    scanf("%d",&k);
    printf("enter after what data u want to insert");
    scanf("%d",&l);
    insert_mid(k,l);   
    print();   
    delete_middle();
    delete_end();
    delete_beg();
    
}

void create()
{
  int i,x,n;
  printf("enter the number of nodes:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      temp=(struct node*)malloc(sizeof(struct node));
      printf("enter the data:");
      scanf("%d",&temp->data);
      if(head==NULL)
      {
          head=tail=temp;
      }
      else
      {
          tail->next=temp;
          tail=temp;
      }
  }
}
void delete_beg()
{
    printf("deleting from begining\n");
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
     printf("list empty");
        return;
    }
    else if(head->next==NULL)
    {
        printf("only one elemnt in list and that is deleted");
        free(head);
        head=NULL;
    }
    else
    {
       temp=head;
       head=head->next;
       head->prev=NULL;
       free(temp);
       temp=NULL;
    }
    print();
    printf("\n");
}
void delete_middle()
{
    int y;
    if(head==NULL)
    {
        printf("the list is empty:");
        return;
    }
    else
    {
      struct node*t=head;
    printf("enter the data  which you want to delete:");
    scanf("%d",&y);  
    if(head->data==y)
    {
        delete_beg();
    }
    while(t->next->data!=y)
    {
        t=t->next;
    }
    temp=t->next;
    t->next=temp->next;
    temp->next->prev=t;
    free(temp);
    }
    
    print();
    printf("\n");
}
void delete_end()
{
    printf("deleting from end\n");
    struct node*t=head;
    struct node*prev=head;
    if(head==NULL)
    {
        printf("list is empty:");
        return;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        
    }
    else
    {
      while(t->next!=NULL)
      {
        prev=t;
        t=t->next;
      }
      prev->next=NULL;
      t->prev=NULL;
      free(t);
      t=NULL;
    }
    print();
    printf("\n");
}
void print()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert_beg(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    head=temp;
    else
    {
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}
void insert_end(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
   temp->next=NULL;
    //remove above // to do doubly
    if(head==NULL)
    head=temp;
    else
    {
        struct node*ptr=head;
        while(ptr->next!=NULL)
        {
        ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
     //remove above // to do doubly
    }
    
}

void insert_mid(int x, int y)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    head=temp;
    else
  {
      struct node*ptr=head;
        while(ptr->data!=y)
        {
        ptr=ptr->next;
        }
        temp->next=ptr->next;
        temp->prev=ptr;
        ptr->next->prev=temp;
        ptr->next=temp;
  }
}

/*
OUTPUT :

enter the number of nodes:2
enter the data:4
enter the data:5
how many nodes insert begining
2
enter the data you want to insert2
enter the data you want to insert3
3       2       4       5
how many nodes insert at last2
enter the data you want to insert at last6
enter the data you want to insert at last7
3       2       4       5       6       7
enter what data you want to insert at middle9
enter after what data u want to insert2
3       2       9       4       5       6       7
enter the data  which you want to delete:2
3       9       4       5       6       7

deleting from end
3       9       4       5       6

deleting from begining
9       4       5       6



...Program finished with exit code 0
Press ENTER to exit console.
*/



















