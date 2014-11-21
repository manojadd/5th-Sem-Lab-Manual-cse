#include<stdio.h>
#include<stdlib.h>
void round_robin(int,int,int[],int[]);
void srtf(int);
main()
{
 int n,tq,choice;
 int bt[10],st[10],i,j,k;
 printf("enter the choice.\n");
 printf("1.Round robin\n2.SRT\n3.exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:printf("round robin scheduling algorithm\n");  
 	 printf("enter the no of process:\n");
         scanf("%d",&n);
   	 printf("enter the burst time for sequences:");
   	 for(i=0;i<n;i++)
         {
	  scanf("%d",&bt[i]);
    	  st[i]=bt[i];
    	 }
   	 printf("enter time quantum:");
    	 scanf("%d",&tq);
    	 round_robin(n,tq,st,bt);
	 break;
  case 2:printf("shortest remaining time next..\n");
	 printf("enter the no of process:\n");
     	 scanf("%d",&n);
	 srtf(n);
	 break;
  case 3:exit(0);
  
 }
}

void round_robin(int n,int tq,int st[ ],int bt[ ])
{
 int time=0;
 int tat[10],wt[10],i,count=0,stat=0,temp1,sq=0,j,k;
 float atat=0.0;
 while(1)
 {
  for(i=0,count=0;i<n;i++)
  {
   temp1=tq;
   if(st[i]==0)
   {
    count++;
    continue;
   }
   if(st[i]>tq)
    st[i]=st[i]-tq;
   else if(st[i]>=0)
   {
    temp1=st[i];
    st[i]=0;
   }
   sq=sq+temp1;
   tat[i]=sq;
  }
  if(n==count)
  break;
 }
 for(i=0;i<n;i++)
 {
  wt[i]=tat[i]-bt[i];
  stat=stat+tat[i];
 }
 atat=(float)stat/n;
 printf("process no |  burst time  |  wait time |      turnaround time\n");
 for(i=0;i<n;i++)
 printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
 printf("avg turn around time is %f\n",atat);
}

void srtf(int n)
{
 int at[15],bt[15],rt[15],fintime,i,shortest;
 int complete=0,time,sumturn=0;
 for(i=0;i<n;i++)
 {
  printf("Enter arrival time P%d : ",i+1);
  scanf("%d",&at[i]);
  printf("Enter burst time P%d : ",i+1);
  scanf("%d",&bt[i]);
  rt[i]=bt[i];
 }
 printf("\n\nProcess\t  |  Turnaround Time  | Waiting Time\n\n");
 rt[14]=8888;
 for(time=0;complete!=n;time++)
 {
  shortest=14;
  for(i=0;i<n;i++)
  {
   if(at[i]<=time && rt[i]<rt[shortest] && rt[i]>0)
   {
    shortest=i;
   }
  }
  rt[shortest]--;
  if(rt[shortest]==0)
  {
   complete++;
   fintime=time+1;
   printf("\nP[%d]\t|\t%d\t|\t%d",shortest+1,fintime-at[shortest],fintime-bt[shortest]-at[shortest]);
   sumturn+=fintime-at[shortest];
  }
 }
 printf("\nAverage Turnaround time = %f",sumturn*1.0/n);
}
