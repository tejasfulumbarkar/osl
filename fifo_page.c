#include<stdio.h>

int main()
{
    int frames_number, pages_number;
    printf("Enter number of frames: ");
    scanf("%d", &frames_number);
    printf("Enter number of pages: ");
    scanf("%d", &pages_number);

    int pages[50], frames[50];
    int faults = 0;
    int i, j, k, pointer = 0;

    printf("Enter page reference string: ");
    for(i = 0; i < pages_number; i++)
        scanf("%d", &pages[i]);

    // Initialize frames
    for(i = 0; i < frames_number; i++)
        frames[i] = -1;

    for(i = 0; i < pages_number; i++)
    {
        int found = 0;

        // Check HIT
        for(j = 0; j < frames_number; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1; // Hit, no page fault
                break;
            }
        }

        // MISS → Replace page using FIFO
        if(found == 0)
        {
            faults++;                       // Count page fault
            frames[pointer] = pages[i];     // Replace at pointer
            pointer = (pointer + 1) % frames_number; // Move pointer in circular manner
        }

        // Print frame state
        for(j = 0; j < frames_number; j++)
        {
            if(frames[j] == -1)
                printf("-\t");
            else
                printf("%d\t", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
