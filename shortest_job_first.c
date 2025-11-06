#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n], ct[n];
    
    for(int i = 0; i < n; i++){
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; 
    }

    int complete = 0, time = 0, shortest = 0, min = 9999;
    int finish_time;
    int check = 0;

    while(complete != n) {
        for(int i = 0; i < n; i++) {
            if((at[i] <= time) && (rt[i] < min) && rt[i] > 0){
                min = rt[i];
                shortest = i;
                check = 1;
            }
        }

        if(check == 0) {
            time++;
            continue;
        }

        rt[shortest]--;
        min = rt[shortest];
        if(min == 0)
            min = 9999;

        if(rt[shortest] == 0){
            complete++;
            check = 0;
            finish_time = time + 1;
            ct[shortest] = finish_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
        time++;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
