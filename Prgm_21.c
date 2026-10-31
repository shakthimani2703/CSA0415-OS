#include <stdio.h>

int main()
{
    int n, i, j;
    int at[10], bt[10], ct[10], tat[10], wt[10], p[10], t;
    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        p[i] = i + 1;
    }

    /* Sort processes by arrival time */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                t = at[j];
                at[j] = at[j + 1];
                at[j + 1] = t;

                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    t = 0;

    printf("\nGantt Chart: ");

    for (i = 0; i < n; i++)
    {
        if (t < at[i])
            t = at[i];

        printf("| P%d (%d-%d) ", p[i], t, t + bt[i]);

        t += bt[i];

        ct[i] = t;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        twt += wt[i];
        ttat += tat[i];
    }

    printf("|\n\n");

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", twt / n);
    printf("Average Turnaround Time = %.2f\n", ttat / n);

    return 0;
}
