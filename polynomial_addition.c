#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int coeff;
    int power;
    struct poly *next;
};
struct poly *create_node(int co,int po)
{
    struct poly *t1=(struct poly*) malloc(sizeof(struct poly));
    t1->coeff=co;
    t1->power=po;
    t1->next=NULL;
    return t1;
}
struct poly *poly_add(struct poly *poly1 ,struct poly *poly2);
struct poly *create_poly(int count ,int coeff[],int power[])
{
    struct poly *t1,*last=NULL,*polylink=NULL;
     int i;
     for(i=0;i<count;i++)
     {
         t1=create_node(coeff[i],power[i]);
         if(polylink==NULL)
         {
             polylink=last=t1;
         }
         else
         {
             last->next=t1;
             last=last->next;
         }
     }
     return polylink;
}
void display (struct poly *first)
{
    struct poly *t1;
    t1=first;
    printf("polynomial");
    while(t1!=NULL)
    {
        printf("coeff= %d  power=%d \n",t1->coeff,t1->power);
        t1=t1->next;
    }
}
int main()
{
    int c1=5;
    int a_ce1[]={5,4,6,7,8};
    int a_po1[]={6,3,2,1,0};
    int c2=3;
    int a_ce2[]={13,14,16};
    int a_po2[]={4,3,2};
    struct poly *poly1,*poly2,*poly3;
    poly1=create_poly(c1,a_ce1,a_po1);
    poly2=create_poly(c2,a_ce2,a_po2);
    display(poly1);
    display(poly2);
    poly3=poly_add(poly1,poly2);
    display(poly3);
    return 0;
}

struct poly*poly_add(struct poly*poly1,struct poly*poly2)
{
    struct poly *p,*q,*t1,*res=NULL,*relast=NULL;
    p=poly1;
    q=poly2;
    while(1)
    {
        if(p==NULL||q==NULL)
        break;
    if(p->power>q->power)
    {
        t1=create_node(p->coeff,p->power);
        p=p->next;
    }
    else if(p->power<q->power)
    {
        t1=create_node(q->coeff,q->power);
        q=q->next;
    }
    else
    {
        t1=create_node(p->coeff+q->coeff,q->power);
        p=p->next;
        q=q->next;
    }
    if(res==NULL)
    res=relast=t1;
    else
    {
        relast->next=t1;
        relast=relast->next;
    }
    }
    while(p!=NULL)
    {
        t1=create_node(p->coeff,p->power);
        p=p->next;
        if(res==NULL)
        res=relast=t1;
        else
        {
            relast->next=t1;
            relast=relast->next;
        }
    }
        while(q!=NULL)
        {
            t1=create_node(q->coeff,q->power);
            q=q->next;
            if(res==NULL)
            res=relast=t1;
            else
            {
                relast->next=t1;
                relast=relast->next;
            }
        }
        return res;
    }

}
/*
OUTPUT : 
polynomialcoeff= 5  power=6 
coeff= 4  power=3 
coeff= 6  power=2 
coeff= 7  power=1 
coeff= 8  power=0 
polynomialcoeff= 13  power=4 
coeff= 14  power=3 
coeff= 16  power=2 
polynomialcoeff= 5  power=6 
coeff= 13  power=4 
coeff= 18  power=3 
coeff= 22  power=2 
coeff= 7  power=1 
coeff= 8  power=0 

...Program finished with exit code 0
Press ENTER to exit console.
*/