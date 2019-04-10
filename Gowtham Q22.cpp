#include<conio.h>
#include<stdio.h>
int main()
{   
 int n,r,i,j,k,cnt,cntt,s=0;
 int inst[20],avail[20],pid[20],safe[20];
 int need[20][20],alloc[20][20],max[20][20];

 printf("\nENTER NUMBER OF PROCESSES :\n");
 scanf("%d",&n);
 printf("\nENTER NUMBER OF RESOURCES AVAILABLE:\n");
 scanf("%d",&r);
 printf("\nENTER INSTANCES FOR EACH RESOURSE:\n");
 for(i=0;i<r;i++)
 {  
 printf("R%d ",i);
 scanf("%d",&inst[i]);
 }
 printf("\nENTER ALLOCATION VALUES\n\n\t");
 for(i=0;i<r;i++)
 {
 	printf("R%d ",i+1);
 }
 printf("\n");
 for(i=0;i<n;i++)
 {
 printf("P%d\t",i);
 pid[i]=0;
 for(j=0;j<r;j++)
 {
  scanf("%d",&alloc[i][j]);
 }
}
  printf("\nENTER MAXIMUM VALUES  \n\n\t");
for(i=0;i<r;i++)
 {
 	printf("R%d ",i+1);
 }
 printf("\n");
 for(i=0;i<n;i++)
 {
 printf("P%d\t",i);
 for(j=0;j<r;j++)
 {
  scanf("%d",&max[i][j]);
 }
 }
 for(i=0;i<r;i++)
 {
 	int sum=0;
 	for(j=0;j<n;j++)
 	{
 		sum=sum+alloc[j][i];
	 }
 	avail[i]=inst[i]-sum;
 	//printf("%d",avail[i]);
 }
 printf("\nVALUES OF NEED FOR EACH RESOURCE\n\n\t");
 for(i=0;i<r;i++)
 {
 	printf("R%d ",i+1);
 }
 //printf("\n");
 for(i=0;i<n;i++)
 {
 printf("\nP%d\t",i) ;
 for(j=0;j<r;j++)
 {
  need[i][j]=max[i][j]-alloc[i][j];
  printf("%d ",need[i][j]);
  }
 }
 k=0;
 cntt=1;
 while(k<15)
 {
 for(i=0;i<n;i++)
 {  cnt=0;
 if(pid[i]!=1)
 {
 	for(j=0;j<r;j++)
 {
  if(need[i][j]<=avail[j])
  {
    cnt++;
  }
  if(cnt==r)
  {
   for(j=0;j<r;j++)
   {
   	 avail[j]-=need[i][j];
     avail[j]+=max[i][j];
   }
  //printf("\np%d\t",i+1);
  safe[s]=i;
  s++;
  pid[i]=1;
  cntt++;
  }
 }
 }
}
k++;
}
 if(cntt<n)
 {
 printf("\n XXXX---Deadlock Occured---XXX");
 }
 else
 {
 	printf("\n\n-----In Safe state-----\n\n");
 	printf("P%d",safe[0]);
 	for(i=1;i<n;i++)
 	{
 		printf("---->P%d",safe[i]);
	}
	printf("\n\n\n");
 }
 getch();
}

