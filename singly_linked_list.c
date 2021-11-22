#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
} *temp,*head,*newnode,*temp_prev;

void create();
void insertion_at_begining();
void insertion_at_middle();
void insertion_at_end();
void deletion_at_begining();
void deletion_at_middle();
void deletion_at_end();

int main()
{
int CHOICE;
printf("\n1.create list");
printf("\n2.insertion at begining");
printf("\n3.insertion at middle");
printf("\n4.insertion at end");
printf("\n5.deletion at begining");
printf("\n6.deletion at middle");
printf("\n7.deletion at end");
do
{
printf("\n enter the operation to be performed");
scanf("%d",&CHOICE);
switch(CHOICE)
{
case 1: 
create();
break;
case 2:
insertion_at_begining();
break;
case 3: 
insertion_at_middle();
break;
case 4: 
insertion_at_end();
break;      
case 5: 
deletion_at_begining();
break;        
case 6: 
deletion_at_middle();
break;       
case 7: 
deletion_at_end();
break;       
default:
printf("enter the valid value");
exit(0);
}
}while(1);
return 0;
}
void create()
{
int data;
head=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
printf("Error in memory allocation");
}
else
{
printf("enter the data to the linked list:");
scanf("%d",&data);
head->data=data;
head->next=NULL;
}
printf("list is:\n");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}


void insertion_at_begining()
{
int data;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\nError in memory allocation");
exit(0);
}
else
{
printf("\nEnter the data inserted at begining of linked list:");
scanf("%d",&data);
newnode->data=data;
newnode->next=head;
head=newnode;
}
printf("the new edited linked list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}

void insertion_at_middle()
{
int x;
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Memory Not Allocated !");
        exit(1);
    }
    printf("After which value you want to insert = ");
    scanf("%d",&x);
    printf("Enter the Number to be Added  :\n");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    temp=head;
    while (temp->data!=x){
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Number not found !");
            exit(1);
        }
    }    
    ptr->next=temp->next;
    temp->next=ptr;
    

printf("\nthe list is\n:");
temp=head;
while(temp!=NULL)
{
printf("\n Data :%d",temp->data);
temp=temp->next;
}
}

void insertion_at_end()
{
int data;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("error in memory allocation");
exit(0);
}
else
{
printf("\nenter the data to be entered in end:");
scanf("%d",&data);
newnode->data=data;
newnode->next=NULL;
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
printf("\nThe list is:\n");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}

void deletion_at_begining()
{
printf("Enter the data to be deleted");
temp=head;
head=head->next;
free(temp);
printf("\n the new edited linked list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}

void deletion_at_middle()
{
    
    int x;
	printf("\nEnter the data you want to delete: ");
    scanf("%d", &x);
    int i;
    struct node *current =head;
    struct node *previous =NULL;
    if(head == NULL)
    {
        printf("List is already empty.");
    }
while(current->data!=x)
{
    if(current->next==NULL)
    {
        return NULL;
    }
    else
    {
        previous=current;
        current=current->next;
    }
}
    if(current==head)
    {
        head=head->next;
    }
    else
    {
        previous->next=current->next;
    }
printf("\nthe list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}

void deletion_at_end()
{
   
temp=head;
temp_prev=head;
temp=temp->next;
while(temp->next!=NULL)
{
temp_prev=temp;
temp=temp->next;
}
temp_prev->next=NULL;
free(temp);
printf("\nthe list is:");
temp=head;
printf("\nData in the list are:%d\n");
while(temp!=NULL)
{
printf("\n %d",temp->data);
temp=temp->next;
}
}

/*OUTPUT :

1.create list
2.insertion at begining
3.insertion at middle
4.insertion at end
5.deletion at begining
6.deletion at middle
7.deletion at end
 enter the operation to be performed1
enter the data to the linked list:5
list is:

Data:5
 enter the operation to be performed2

Enter the data inserted at begining of linked list:4
the new edited linked list is:
Data:4
Data:5
 enter the operation to be performed4

enter the data to be entered in end:6

The list is:

Data:4
Data:5
Data:6
 enter the operation to be performed4

enter the data to be entered in end:7

The list is:

Data:4
Data:5
Data:6
Data:7
 enter the operation to be performed4

enter the data to be entered in end:8

The list is:

Data:4
Data:5
Data:6
Data:7
Data:8
 enter the operation to be performed5
Enter the data to be deleted
 the new edited linked list is:
Data:5
Data:6
Data:7
Data:8
 enter the operation to be performed7

the list is:
Data in the list are:-923540671

 5
 6
 7
 enter the operation to be performed6

Enter the data you want to delete: 6

the list is:
Data:5
Data:7
 enter the operation to be performed0
enter the valid value

...Program finished with exit code 0
Press ENTER to exit console.*/