#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTime(struct Process processes[], int n) {
    int i, time = 0, min_priority, min_priority_index;
    int completed_processes = 0;
    while (completed_processes < n) {
        min_priority = 9999;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time && processes[i].priority < min_priority) {
                min_priority = processes[i].priority;
                min_priority_index = i;
            }
        }
        processes[min_priority_index].remaining_time--;
        time++;
        if (processes[min_priority_index].remaining_time == 0) {
            completed_processes++;
            processes[min_priority_index].waiting_time = time - processes[min_priority_index].burst_time - processes[min_priority_index].arrival_time;
            if (processes[min_priority_index].waiting_time < 0) {
                processes[min_priority_index].waiting_time = 0;
            }
            processes[min_priority_index].turnaround_time = processes[min_priority_index].waiting_time + processes[min_priority_index].burst_time;
        }
    }
}

void printTable(struct Process processes[], int n) {
    int i;
    printf("Process ID\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (i = 0; i < n; i++) {
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter priority of process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
    calculateWaitingTime(processes, n);
    printTable(processes, n);
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    return 0;
}
