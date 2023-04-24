#include <stdio.h>

void calculate_times(int n, int bt[], int quantum)
{
    // initialize waiting time and turn around time to 0
    int wt[n], tat[n];
    for (int i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
    }

    // create a copy of burst time array
    int remaining_bt[n];
    for (int i = 0; i < n; i++)
    {
        remaining_bt[i] = bt[i];
    }

    int t = 0; // current time
    while (1)
    {
        int done = 1;
        // traverse all processes
        for (int i = 0; i < n; i++)
        {
            if (remaining_bt[i] > 0)
            {
                done = 0;
                if (remaining_bt[i] > quantum)
                {
                    t += quantum;
                    remaining_bt[i] -= quantum;
                }
                else
                {
                    t += remaining_bt[i];
                    wt[i] = t - bt[i];
                    remaining_bt[i] = 0;
                }
            }
        }
        // if all processes are done
        if (done == 1)
        {
            break;
        }
    }

    // calculate turn around time
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }

    // print the waiting time and turn around time for each process
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
}

int main()
{
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n];
    printf("Enter the burst time of each process: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    calculate_times(n, bt, quantum);
    return 0;
}