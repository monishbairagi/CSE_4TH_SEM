#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,p[20],d[20],r,t,j[20],i,l,k,c;
int main()
    {
        int profit;
        printf("Enter the no of the jobs :");
        scanf("%d",&n);
        for(i=0;i<n;i++)
           {
               printf("\nEnter the profit of job #%d      :",i+1);
               scanf("%d",&p[i]);                  
               printf("\nEnter the deadline of job #%d    :",i+1);
               scanf("%d",&d[i]); 
           }
           for(i=0;i<n;i++)
           {
            for(l=i+1;l<n;l++)
            {
             if(p[i]<p[l])
                {
                  t=p[i];
                  p[i]=p[l];
                  p[l]=t;
                  t=d[i];
                  d[i]=d[l];
                  d[l]=t;              
                }
             }
            }
            printf("\n    INDEX      PROFIT     DEADLINE    \n");
            for(i=0;i<n;i++)
            {
                  printf("\n       %d       %d       %d",i+1,p[i],d[i]);
            }
            
    profit=0; 
    d[-1]=0;j[-1]=0; 
    k=1; 
    j[0]=1; 
    profit+=p[0]; 
    for(int i=1;i<=n;i++) 
    { 
       r=k; 
       while((d[j[r]]>d[i]) && (d[j[r]]!=r)) 
       r--; 
       if((d[j[r]] <=d[i]) && (d[i]>r)) 
       { 
       j[c]=i;
       for(t=k;t>=r+1;t--) 
                  j[t+1]=j[t]; 
       profit+=p[i]; 
       j[r+1]=i; 
       k++; 
       }
       
    }
    int s=k;
     
     printf("\n\nFeasible solution: \n\n%d  ",k);
   for(c=1;c<=s;c++)
    {
                     if(j[c]>0)
                     printf("\n%d",j[c]);
    }
    printf("\n\nThe optimal profit is:  %d\n",profit);
     getch();
  }
