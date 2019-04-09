#include<stdio.h> 
#define N 10 
typedef struct 
{ 
	int process_id, arrival_time, burst_time, priority;
	int q, ready; 
}process_structure; 
int Queue(int t1) 
{ 
	if (t1 == 0 || t1 == 1 || t1 == 2 || t1 == 3) 
	{ 
		return 1; 
	} 
	else
	{
		return 2; 
	}
} 
void cal()
{

		int arrival_time[10], burst_time[10], temp[10];
	int i, smallest, count = 0, time, limit;
	double wait_time = 0, turnaround_time = 0, end;
	float average_waiting_time, average_turnaround_time;
	burst_time[9] = 9999;  
 	for(time = 0; count != limit; time++)
 	{
   		smallest = 9;
  		for(i = 0; i < limit; i++)
  		{
   			if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
			{
   				smallest = i;
			}
  		}
  		burst_time[smallest]--;
  		if(burst_time[smallest] == 0)
  		{
   			count++;
   			end = time + 1;
   			wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
   			turnaround_time = turnaround_time + end - arrival_time[smallest];
  		}
 	}
 	
}
void display()
{
float average_waiting_time, average_turnaround_time;
	/*int limit;
		double wait_time = 0, turnaround_time = 0, end;
average_waiting_time = wait_time / limit; 
	average_turnaround_time = turnaround_time / limit;*/
 	printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    	printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);	
}





int main() 
{ 
	int no_p, count, temp_process, time, j, y; 
	process_structure temp; 
	printf("Enter Total Number of Processes:\t"); 
	scanf("%d", &no_p);  
	process_structure process[no_p]; 
	for(count = 0; count < no_p; count++) 
	{ 
		printf("\nProcess ID:\t"); 
		scanf("%d", &process[count].process_id); 
		printf("Arrival Time:\t"); 
		scanf("%d", &process[count].arrival_time); 
		printf("Burst Time:\t"); 
		scanf("%d", &process[count].burst_time); 
		printf("Process Priority:\t"); 
		scanf("%d", &process[count].priority); 
		temp_process = process[count].priority; 
		process[count].q = Queue(temp_process);
		process[count].ready = 0; 
	}
    time = process[0].burst_time; 
	for(y = 0; y < no_p; y++) 
	{ 
		for(count = y; count < no_p; count++) 
		{ 
			if(process[count].arrival_time < time) 
			{
 				process[count].ready = 1; 
			} 
		} 
    for(count = y; count < no_p - 1; count++) 
		{
 			for(j = count + 1; j < no_p; j++) 
			{ 
                if(process[count].ready == 1 && process[j].ready == 1) 
				{ 
                    if(process[count].q == 2 && process[j].q == 1) 
					{ 
						temp = process[count]; 
						process[count] = process[j]; 
						process[j] = temp; 
					} }}}
					for(count = y; count < no_p - 1; count++) 
		{ 
			for(j = count + 1; j < no_p; j++) 
			{
				if(process[count].ready == 1 && process[j].ready == 1) 
				{ 
					if(process[count].q == 1 && process[j].q == 1) 
					{ 
						if(process[count].burst_time > process[j].burst_time) 
						{ 
							temp = process[count]; 
							process[count] = process[j]; 
							process[j] = temp; 
						} 
						else 
						{ 
							break; 
						} }}}}
    printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].process_id, time, time + process[y].burst_time); 
	time = time + process[y].burst_time; 
	for(count = y; count < no_p; count++) 
	{ 
		if(process[count].ready == 1) 
		{ 
			process[count].ready = 0; 
		} 
	} 
	} 
	cal();
	display();
	return 0; 
}

