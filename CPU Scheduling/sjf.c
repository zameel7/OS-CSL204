#include <stdio.h>

typedef struct PROCESS
{
    int id, bt, wt, tt, ct;
}process;


int main() {
    int n;
    float awt, att;
    process p[10];
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    printf("Process details: \n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: Burst time => ", i+1);
        scanf("%d", &p[i].bt);
        p[i].id = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (p[j].bt > p[j+1].bt)
            {
                int temp1 = p[j].bt;
                int temp2 = p[j].id;
                p[j].bt = p[j+1].bt;
                p[j].id = p[j+1].id;
                p[j+1].bt = temp1;
                p[j+1].id = temp2;
            }
        }
    }
    p[0].wt = 0;
    p[0].tt = p[0].bt+p[0].wt;
    p[0].ct = p[0].tt;
    for (int i = 1; i < n; i++)
    {
        p[i].ct = p[i-1].ct + p[i].bt;
        p[i].tt = p[i].ct;
        p[i].wt = p[i].tt - p[i].bt;
        awt += p[i].wt;
        att += p[i].tt;
    }
    printf("\nPID\tBT\tWT\tTT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].id+1, p[i].bt, p[i].wt, p[i].tt);
    }
    printf("Average waiting time: %f\n", (float)awt/n);
    printf("Average turnaround tme: %f\n", (float)att/n);
}