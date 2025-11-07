#include <stdio.h>
#include <stdlib.h>

#define P 5 // Processes
#define R 3 // Resources

int main()
{
    int i, j;

    // Allocation, Max, and Available matrices
    int allocation[P][R] = {
        { 0, 1, 0 },  //  rows P columns R
         { 2, 0, 0 }, 
         { 3, 0, 2 }, 
         { 2, 1, 1 }, 
         { 0, 0, 2 }
    };
    int max[P][R] = {
        { 7, 5, 3 },
         { 3, 2, 2 }, 
         { 9, 0, 2 },
          { 2, 2, 2 }, 
          { 4, 3, 3 }
    };
    int available[R] = { 3, 3, 2 };

    int finish[P] = {0};
    int safe_sequence[P];
    int ind = 0;
    int need[P][R];

    // Calculate Need matrix
    for (i = 0; i < P; i++)
        for (j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    int process_found_in_pass;

    // Safety Algorithm Core
    do {
        process_found_in_pass = 0;
        for (i = 0; i < P; i++) {
            if (!finish[i]) {
                int can_execute = 1;
                for (j = 0; j < R; j++) {
                    if (need[i][j] > available[j]) {
                        can_execute = 0;
                        break;
                    }
                }

                if (can_execute) {
                    safe_sequence[ind++] = i;
                    process_found_in_pass = 1;
                    for (j = 0; j < R; j++)
                        available[j] += allocation[i][j];
                    finish[i] = 1;
                }
            }
        }
    } while (ind < P && process_found_in_pass);

    // Output
    if (ind == P) {
        printf("System is in a SAFE state. Sequence: ");
        for (i = 0; i < P; i++) {
            printf("P%d%s", safe_sequence[i], (i == P - 1) ? "" : " ->");
        }
        printf("\n");
    } else {
        printf("System is in an UNSAFE state.\n");
    }

    return 0;
}
