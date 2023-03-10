#include <stdio.h>

#define MAX_PROCESSES 100

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, quantum, time = 0;

    // Read input values
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Execute processes in round-robin order
    printf("\nRound-robin scheduling:\n\n");
    while (1) {
        int all_finished = 1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                all_finished = 0;
                if (processes[i].remaining_time <= quantum) {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    printf("Process %d finished at time %d\n", processes[i].pid, time);
                } else {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                    printf("Process %d executed for %d units and suspended at time %d\n", processes[i].pid, quantum, time);
                }
            }
        }
        if (all_finished) break;
    }

    return 0;
}

