#include<conio.h>
#include<stdio.h>
int main()
{   
 int f,n=3,r=3,i,j,k,cnt,cntt,s=0;
 int inst[3]={3,2,2},avail[3],pid[3],safe[3],req[3];
 int need[3][3],alloc[3][3]={0,0,1,3,2,0,2,1,1},max[3][3]={8,4,3,6,2,0,3,3,3};

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
  printf("%d  ",need[i][j]);
  }
 }
 k=0;
 cntt=1;
 printf("\nEnter Process number for requesting\n");
 scanf("%d",&f);
 for(i=0;i<3;i++)
 {
 	if(i==0)
 	{
 		printf("No. of instance of A\n");
	 }
	 else if(i==1)
	 {
	 	printf("No. of instance of B\n");
	 }
	 else if(i==2)
	 {
	 	printf("No. of instance of c\n");
	 }
 	scanf("%d",&req[i]);	
 }
 for(i=0;i<n;i++)
 {  cnt=0;
 	for(j=0;j<r;j++)
 {
  if(req[j]<=avail[j])
  {
    cnt++;
  }
  if(cnt==r)
  {
  	
   for(j=0;j<r;j++)
   {
   	 avail[j]-=req[j];
   	 alloc[f][j]+=req[j];
     need[f][j]-=req[j];
   }
  //printf("\np%d\t",i+1);
  }
 }
}
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
 printf("\n----Request Rejected as Not in Safe state----");
 }
 else
 {
 	printf("\n\n----Request Granted as In Safe state-----\n\n");
 	printf("P%d",safe[0]);
 	for(i=1;i<n;i++)
 	{
 		printf("---->P%d",safe[i]);
	}
	printf("\n\n\n");
 }
 getch();
}

