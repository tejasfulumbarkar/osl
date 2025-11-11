#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

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

    pid = fork(); // create child

    if(pid == 0) { // Child process
        sleep(4); // allow parent to exit first
        
        printf("\nChild Process:\n");
        printf("Child PID = %d\n", getpid());
        printf("New Parent PID = %d (should be 1 i.e. init)\n", getppid());

        bubbleSort(arr, n);
        printf("Sorted by Child: ");
        for(i=0;i<n;i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else { // Parent process
        printf("\nParent Process:\n");
        printf("Parent PID = %d\n", getpid());
        printf("Parent sorting and exiting early (will orphan child)\n");

        bubbleSort(arr, n);
        printf("Sorted by Parent: ");
        for(i=0;i<n;i++)
            printf("%d ", arr[i]);
        printf("\n");

        printf("Parent exiting now...\n");
        // Parent exits before child completes ⇒ CHILD BECOMES ORPHAN
    }

    return 0;
}
