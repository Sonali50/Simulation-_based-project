#include<stdio.h>
int n;
struct prog    //making the structure
{

int p_no;

int ct,wait_t,burst_time,turnaround_time,p,arrival_time;    //declaring the required variables

int flag;       //declaring the flag
 }p_list[100];
 void Sorting_prid()      //sorting the processes on the basis of arrival time
 {
struct prog p;

int i, j;

for(i=0;i<n-1;i++)

{

for(j=i+1;j<n;j++)

{

if(p_list[i].arrival_time > p_list[j].arrival_time)

{

p = p_list[i];

p_list[i] = p_list[j];

p_list[j] = p;

}

}

}
 }
 int main()
 {

int i,t=0,b_t=0,largest_limit;

int a[10];

float wait_time = 0,turnaround_time = 0, avg_w_t=0, avg_taround_time=0;    //initializing the variables

printf("enter the no. of processes: ");     //taking input from the user for the no of processes

scanf("%d",&n);

for(i = 0; i < n; i++)

{

p_list[i].p_no = i+1;

printf("\nEnter Details For P%d process:-\n", p_list[i].p_no );  //enter the details of the processes
printf("Enter Arrival Time: ");
scanf("%d", &p_list[i].arrival_time );
printf("Enter Burst Time: ");
scanf("%d", &p_list[i].burst_time);
p_list[i].flag = 0;
b_t = b_t + p_list[i].burst_time;
}
Sorting_prid();          //calling the sorting function to sort the values
for(int i=0;i<n;i++)
{
a[i]=p_list[i].burst_time;
}
p_list[9].burst_time = 9999;
for(t = p_list[0].arrival_time; t <= b_t+1;)
{
largest_limit = 9;
for(i=0;i<n;i++)        //calculating the turn around values for each processes
{
if(p_list[i].arrival_time <= t && p_list[i].burst_time < p_list[largest_limit].burst_time && p_list[i].flag != 1)
{
largest_limit= i;
}
if(p_list[largest_limit].burst_time==0 && p_list[i].flag != 1)
{
p_list[i].flag = 1;
p_list[largest_limit].ct=t;
p_list[largest_limit].burst_time=9999;
printf("P%d completes in %d\n",p_list[i].p_no,p_list[largest_limit].ct);
}
}
t++;
(p_list[largest_limit].burst_time)--;
}
for(i=0;i<n;i++)    //calculating the average wating time for each processes
{
p_list[i].turnaround_time=(p_list[i].ct)-(p_list[i].arrival_time);
avg_taround_time=avg_taround_time+p_list[i].turnaround_time;
p_list[i].wait_t=((p_list[i].turnaround_time)-a[i]);
avg_w_t=avg_w_t+p_list[i].wait_t;
}
printf("P_no\tA_time\tB_time\tTA\tWTt\n");    //displaying the values
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",p_list[i].p_no,p_list[i].arrival_time,p_list[i].ct,p_list[i].turnaround_time
,p_list[i].wait_t);
 }
printf("Average Turn around Time: %f\t\n\n",avg_taround_time);     //displaying the turn around time
printf("Average Waiting Time :\t %f\t\n",avg_w_t);      //displaying the average wating time
}

