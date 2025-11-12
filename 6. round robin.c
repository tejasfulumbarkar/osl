#include <stdio.h>

int main() {
    int n, tq, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n], ct[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, complete = 0;
    float totalWT = 0, totalTAT = 0;

    while (complete != n) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                done = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    complete++;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    totalWT += wt[i];
                    totalTAT += tat[i];
                }
            }
        }
        if (done == 1)  // If no process is ready
            time++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    return 0;
}
