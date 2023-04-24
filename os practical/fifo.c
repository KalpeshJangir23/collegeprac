// C program for FIFO page replacement algorithm
#include <stdio.h>
int main()
{
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int i, n, s, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");
    int temp[frames];
    for (i = 0; i < frames; i++)
    {
        temp[i] = -1;
    }

    for (i = 0; i < pages; i++)
    {
        s = 0;

        for (n = 0; n < frames; n++)
        {
            if (incomingStream[i] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;

        if ((pageFaults <= frames) && (s == 0))
        {
            temp[i] = incomingStream[i];
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[i];
        }

        printf("\n");
        printf("%d\t\t\t", incomingStream[i]);
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}