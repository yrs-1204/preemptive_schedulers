#include<stdio.h>
int main()
{
  printf("-----LONGEST REMAINING TIME FIRST CPU SHEDUALING-----");
  //initializing the shedualer 
  int n;
  printf("\nEnter number of processes to shedual:-  ");
  scanf("%d", &n);
  int at[10]={0}, bt[10]={0}, x[10], ct[10]={0}, tat[10]={0}, wt[10]={0}, rt[10]={0};
  int i, j, largest, count=0, time;
  float avg_wt=0, avg_tat=0,avg_rt=0, end;
  for(i=0; i<n; i++)
  {
    printf("\nenter arrival time of P%d:-  ", i+1);
    scanf("%d", &at[i]);
    printf("enter burst time of P%d:- ", i+1);
    scanf("%d", &bt[i]);
    x[i] = bt[i];
    printf("\n");
  }
  //display input
  printf("\nINPUT:-   \n");
  printf("\nP_ID\t AT\t BT\t\n");
  //opretion to find longert remainig time process
  for(int i=0; i<n; i++)
  {
    printf("P%d\t %d\t %d\t\n", i+1, at[i], bt[i]);
  }
  bt[9]=-9999;
  for(time=0; count!=n; time++)
  {
    largest=9;
    for(i=0; i<n; i++)
    {
      if(at[i]<=time && bt[i]>bt[largest] && bt[i]>0)
      {
        largest = i;
      }
    }
    if(bt[largest]==x[largest])
    {
      rt[largest] = time - at[largest];
    }
    bt[largest]--;
    if(bt[largest]==0)
    {
      count++;
      end = time+1;
      wt[largest] = end-at[largest]-x[largest];
      tat[largest] = end - at[largest];
      avg_wt = avg_wt + wt[largest];
      avg_tat = avg_tat + tat[largest];
      avg_rt = avg_rt + rt[largest];
      ct[largest] = tat[largest]+at[largest];

    }
  }
  //display output
  printf("\nOUTPUT:-   \n");
  printf("\nP_ID\t AT\t BT\t CT\t TAT\t WT\t RT\t\n");
  for(int i=0; i<n; i++)
  {
    printf("P%d\t %d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], x[i], ct[i], tat[i], wt[i], rt[i]);
  }
  //average output
  printf("\nAverage Turnaround Time = %f\n", avg_tat/n);
  printf("\nAverage Waiting Time = %f\n", avg_wt/n);
  printf("\nAverage Response Time = %f\n", avg_rt/n);
  return 0;
}
