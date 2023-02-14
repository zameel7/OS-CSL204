#include <stdio.h>

typedef struct PROCESS
{
    int id, bt, wt, tt, ct, pr;
}process;


int main() {
    int n;
    float awt=0, att=0;
    process p[10], t[1];
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    printf("Process details: \n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: Burst time, Priority => ", i+1);
        scanf("%d%d", &p[i].bt, &p[i].pr);
        p[i].id = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (p[j].pr > p[j+1].pr)
            {
                t[1] = p[j];
                p[j] = p[j+1];
                p[j+1] = t[1];
            }
        }
    }
    p[0].wt = 0;
    p[0].tt = p[0].bt;
    awt += p[0].wt;
    att += p[0].tt;
    for (int i = 1; i < n; i++)
    {
        p[i].tt = p[i-1].tt + p[i].bt;
        p[i].wt = p[i].tt - p[i].bt;
        awt += p[i].wt;
        att += p[i].tt;
    }
    printf("\nPID\tPRI\tBT\tWT\tTT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].id+1, p[i].pr, p[i].bt, p[i].wt, p[i].tt);
    }
    for (int i = 0; i < n; i++)
    {
        printf("|\t%d\t", p[i].id);
    }
    printf("|\n0");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t%d", p[i].tt);
    }
    printf("\nAverage waiting time: %f\n", (float)awt/n);
    printf("Average turnaround tme: %f\n", (float)att/n);
}