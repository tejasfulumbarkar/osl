#include<stdio.h>

int main()
{
    int frames_number, pages_number;
    printf("Enter number of frames: ");
    scanf("%d", &frames_number);
    printf("Enter number of pages: ");
    scanf("%d", &pages_number);

    int pages[50], frames[50], recent[50];
    int faults = 0;
    int i, j, k, pos, min;

    printf("Enter page reference string: ");
    for(i = 0; i < pages_number; i++)
        scanf("%d", &pages[i]);

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
                found = 1; // hit
                break;
            }
        }

        if(found == 0) // MISS
        {
            faults++;

            // Check for empty frame
            for(j = 0; j < frames_number; j++)
            {
                if(frames[j] == -1)
                {
                    frames[j] = pages[i];
                    found = 1;
                    break;
                }
            }

            // No empty frame → Apply LRU Replacement
            if(found == 0)
            {
                for(j = 0; j < frames_number; j++)
                {
                    recent[j] = -1;
                    for(k = i - 1; k >= 0; k--)
                    {
                        if(frames[j] == pages[k])
                        {
                            recent[j] = k; // last used position
                            break;
                        }
                    }
                }

                // Find least recently used (minimum recent[])
                pos = 0;
                min = recent[0];

                for(j = 1; j < frames_number; j++)
                {
                    if(recent[j] < min)
                    {
                        min = recent[j];
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
            }
        }

        // Print frames
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
