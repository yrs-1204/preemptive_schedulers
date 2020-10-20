#include<stdio.h>
#include<stdlib.h>
struct process
{
  int pid, at, bt, ct, wt, tat, pr;
  int completed;
}proc[10];
int n;
void sort_at()
{
  struct process temp;
  int i, j;
  for(i=0; i<n-1; i++)
  {
    for(j=i+1; j<n; j++)
    {
      if(proc[i].at>proc[j].at)
      {
        temp = proc[i];
        proc[i] = proc[j];
        proc[j] = temp;
      }
    }
  }
}
int main()
{
  printf("-----PREORITY CPU SHEDUALING-----");
  int i, time=0 , burst_time=0, largest;
  float avg_wt=0, avg_tat=0;
  printf("\nEnter number of processes to shedual:-  ");
  scanf("%d", &n);
  for(i=0; i<n; i++)
  {
    proc[i].pid = i+1;
    printf("\nEnter arrival time of P[%d]:-   ", i+1);
    scanf("%d", &proc[i].at);
    printf("Enter preority of P[%d]:-    ", i+1);
    scanf("%d", &proc[i].pr);
    printf("Enter bust time of P[%d]:-   ", i+1);
    scanf("%d", &proc[i].bt);
    proc[i].completed=0;
    burst_time+=proc[i].bt;
  }
  printf("\nINPUT:-   \n");
  printf("\nP_ID\t AT\t PR\t BT\t\n");
  for(int i=0; i<n; i++)
  {
    printf("P%d\t %d\t %d\t %d\t\n", proc[i].pid, proc[i].at, proc[i].pr, proc[i].bt);
  }
  sort_at();
  printf("\nOUTPUT:-   \n");
  printf("\nP_ID\t AT\t PR\t BT\t CT\t TAT\t WT\n");
  proc[9].pr = -9999;
  for(time=proc[0].at; time<burst_time;)
  {
    largest = 9;
    for(i=0; i<n; i++)
    {
      if(proc[i].at<=time && proc[i].completed!=1 && proc[i].pr>proc[largest].pr)
      {
        largest = i;
      }
    }
    time = time + proc[largest].bt;
    proc[largest].ct = time;
    proc[largest].tat = proc[largest].ct - proc[largest].at;
    proc[largest].wt = proc[largest].tat - proc[largest].bt;
    proc[largest].completed = 1;
    avg_tat = avg_tat + proc[largest].tat;
    avg_wt = avg_wt + proc[largest].wt;
    printf("P%d\t %d\t %d\t %d\t %d\t %d\t %d\n", proc[largest].pid, proc[largest].at, proc[largest].pr, proc[largest].bt, proc[largest].ct, proc[largest].tat, proc[largest].wt);
  }
  printf("\nAverage Turnaround Time = %f\n", avg_tat/n);
  printf("\nAverage Waiting Time = %f\n", avg_wt/n);
  return 0;
}
