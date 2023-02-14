#include <stdio.h>
#include <stdlib.h>

typedef struct PROCESS
{
    int id, at, bt, wt, tt, ct;
} process;


int main() {
    process P[10], temp[1];
    int n;
    float awt=0, att=0;

    printf("FCFS:\n");

    printf("Enter the no. of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of P[%d]: ", i);
        scanf("%d%d", &P[i].at,&P[i].bt);
        P[i].id = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (P[i].at > P[i+1].at)
            {
                temp[0] = P[i];
                P[i] = P[i+1];
                P[i+1] = temp[0];
            }   
        }
    }
    printf("ID\tBT\tAT\tWT\tCT\tTT\n");
    P[0].wt = 0;
    P[0].tt = P[0].bt;
    P[0].ct = P[0].tt - P[0].at;
    att += P[0].tt;
    printf("%d\t%d\t%d\tW%d\t%d\t%d\n", P[0].id, P[0].bt, P[0].at, P[0].wt, P[0].ct, P[0].tt);
    for (int i = 1; i < n; i++)
    {
        P[i].ct = P[i-1].ct + P[i].bt;
        P[i].tt = P[i].ct - P[i].at;
        P[i].wt = P[i].tt - P[i].bt; 
        awt += P[i].wt;
        att += P[i].tt;
        printf("%d\t%d\t%d\tW%d\t%d\t%d\n", P[i].id, P[i].bt, P[i].at, P[i].wt, P[i].ct, P[i].tt);
    }
    for (int i = 0; i < n; i++)
    {
        printf("|\t%d\t", P[i].id);
    }
    printf("|\n0");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t%d", P[i].tt);
    }

    printf("Average Waiting time: %f\nAverage Turnaround time: %f", awt/(float)n, att/(float)n);
}