#include <stdio.h>
#include <stdlib.h>

struct array
{
    int a[10];
    int size;
    int len;
};
void displaythearray(struct array arr)
{
    int i;
    for(i=0;i<arr.len;i++)
    {
        printf("%d ",arr.a[i]);
    }
    printf("\n");
}
int get(struct array arr,int index)
{
    if(index>=0 && index<arr.len)
    {
        return arr.a[index];

    return -1; //for invalid index
    }
}
void set(struct array *arr,int index,int x)
{
    if(index>=0 && index<arr->len)
    {
        arr->a[index]=x;
    }
}
int max(struct array arr)
{
    int max=arr.a[0];
    for(int i=1;i<arr.len;i++)
    {
        if(arr.a[i]>max)
        {
            max=arr.a[i];
        }
    }
    return max;
}
int sum(struct array arr)
{
    int sum=0;
    for(int i=0;i<arr.len;i++)
    {
        sum=sum+arr.a[i];
    }
    return sum;
}

float avg(struct array arr)
{
    return (float)sum(arr)/arr.len;
}
void reverse (struct array *arr)
{
    int *b;
    b=(int *)malloc(arr->len * sizeof(int));
    for(int i=arr->len-1,j=0;i>=0;i--,j++)
    {
        b[j]=arr->a[i];
    }
    for(int i=0;i<arr->len;i++)
    {
        arr->a[i]=b[i];
    }
}
void rev(struct array *arr)
{
    for(int i=0,j=arr->len-1;i<j;i++,j--)
    {
        int temp=arr->a[i];
        arr->a[i]=arr->a[j];
        arr->a[j]=temp;
    }
}
void lshift(struct array *arr)
{
    int b;
    for(int i=0;i<arr->len;i++)
    {
       if(i==0)
       {
           b=arr->a[0];
       }
        arr->a[i]=arr->a[i+1];
    }
   arr->a[arr->len-1]=b;
}
void rshift(struct array *arr)
{
    int b;
    for(int i=arr->len-1;i>=0;i--)
    {
      if(i==arr->len-1)
       {
           b=arr->a[arr->len-1];
       }
      arr->a[i+1]=arr->a[i];
    }
   arr->a[0]=b;
}
int main()
{
   struct array arr={{2,4,6,8,10},10,5};
   displaythearray(arr);
   printf("%d\n",get(arr,3));
   set(&arr,1,7);
   displaythearray(arr);
   printf("%d\n",max(arr));
   printf("%d\n",sum(arr));
   //printf("%d\n",tot(arr.a,arr.len));
   printf("%.2f\n",avg(arr));
   //reverse(&arr);
  // displaythearray(arr);
   //rev(&arr);
   lshift(&arr);
   displaythearray(arr);

   rshift(&arr);
   displaythearray(arr);



}
