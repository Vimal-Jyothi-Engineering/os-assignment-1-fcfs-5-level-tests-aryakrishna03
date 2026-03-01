#include <stdio.h>

typedef struct {
    char pid[10];
    int arrival;
    int burst;
    int waiting;
    int turnaround;
} Process;

int main() {
    int n;
    scanf("%d", &n);

    Process p[100];

    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].arrival, &p[i].burst);
    }

    int time = 0;

    for(int i = 0; i < n; i++) {
        if(time < p[i].arrival)
            time = p[i].arrival;

        p[i].waiting = time - p[i].arrival;
        time += p[i].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    for(int i = 0; i < n; i++) {
        printf("%s %d %d", p[i].pid, p[i].waiting, p[i].turnaround);
        if(i != n-1) printf("\n");
    }

    return 0;
}
