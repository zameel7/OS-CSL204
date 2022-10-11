#include <stdio.h>

typedef struct PROCESS {
    int id, bt, at, rt;
} process;

process p[10];

int main() {
    int n, time, count, TQ, flag=0;
    int wt=0, tt=0;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    int remain = n;
    printf("Enter the process details: \n");
    for(int i = 0; i < n; i++) {
        p[i].id = i;
        printf("P[%d] => BT, AT: ", i+1);
        scanf("%d%d", &p[i].bt, &p[i].at);
        p[i].rt = p[i].bt;
    }
    printf("\nEnter TQ: ");
    scanf("%d", &TQ);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(p[j].at > p[j+1].at) {
                int temp = p[j].id;
                int temp1 = p[j].bt;
                int temp2 = p[j].at;
                p[j].id = p[j+1].id;
                p[j].at = p[j+1].at;
                p[j].bt = p[j+1].bt;
                p[j+1].id = temp;
                p[j+1].bt = temp1;
                p[j+1].at = temp2;
                p[j].rt = p[j].bt;
                p[j+1].rt = p[j+1].bt;
            }
        }
    }
    printf("\nid  tt wt\n");
    for(time=0, count=0; remain!=0;) {
        if(p[count].rt<=TQ && p[count].rt>0) {
            time += p[count].rt;
            p[count].rt = 0;
            flag = 1;
        }
        else if (p[count].rt>0)
        {
            p[count].rt -= TQ;
            time += TQ;
        }
        if (p[count].rt == 0 && flag == 1) 
        {
            printf("%d %d %d\n", count+1, time-p[count].at, time-p[count].at-p[count].bt);
            remain--;
            wt += time-p[count].at-p[count].bt;
            tt += time-p[count].at;
            flag = 0;
        }
        if (count == n-1)
        {
            count = 0;
        }
        else if (p[count+1].at <= time)
        {
            count += 1;
        }
        else {
            count = 0;
        }
    }
    printf("\nAvg WT: %f\nAvg TT: %f\n", (float)wt/n, (float)tt/n);
    return 0;
}