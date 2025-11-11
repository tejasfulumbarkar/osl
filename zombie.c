#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[20], n, i;
    pid_t pid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    pid = fork();   // create child

    if(pid == 0) {  // Child process
        printf("\nChild Process (PID = %d)\n", getpid());

        // Child sorts array
        bubbleSort(arr, n);

        printf("Sorted by Child: ");
        for(i=0;i<n;i++)
            printf("%d ", arr[i]);
        printf("\n");

        // Child finishes but parent hasn't waited → child becomes ZOMBIE for few seconds
        printf("Child completed. (Now Zombie until parent waits)\n");
        sleep(5); // delay to show zombie state
    }
    else {  // Parent Process
        printf("\nParent Process (PID = %d)\n", getpid());

        // Parent waits to show zombie state
        sleep(2);
        printf("Check Zombie state now (use: ps -l)\n");

        wait(NULL); // Parent waits, zombie cleared

        printf("Child finished, zombie cleared.\n");

        // Parent sorts
        bubbleSort(arr, n);

        printf("Sorted by Parent: ");
        for(i=0;i<n;i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
