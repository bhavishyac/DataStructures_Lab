#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
int a[1000],i,n,j;  
  printf("Enter size of array 1 : ");
    scanf("%d",&n);
 
     printf("Enter %d elements in the array for insertion sort : ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    printArray(a, n);
    
 int ar[1000],i1,n1,j1;  
  printf("Enter size of array 2: ");
    scanf("%d",&n1);
 
     printf("Enter %d elements in the array for bubble sort : ", n);
    for(i1=0;i1<n1;i1++)
    {
        scanf("%d", &ar[i1]);
    }
    
    for(j1 = 0; j1<n1; j1++)
    {
        int swapped1 = 0;
        i1 = 0;
        while(i1<n1-1)
        {

            if (ar[i1] > ar[i1+1])
            {

                int temp1 = ar[i1];
                ar[i1] = ar[i1+1];
                ar[i1+1] = temp1;

                swapped1 = 1;
            }
            i1++;
        }
        if (!swapped1)
            break;
    }
printf("\n\n");
    for(i1=0;i1<n1;i1++)
        printf("%d\t",ar[i1]);

    return 0;
}

/*
OUTPUT :

Enter size of array 1 : 4
Enter 4 elements in the array for insertion sort : 4
1
3
9
1 3 4 9 
Enter size of array 2: 4
Enter 4 elements in the array for bubble sort : 9
1
4
3


1       3       4       9

...Program finished with exit code 0
Press ENTER to exit console.
*/