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

    // sort by arrival
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].arrival > p[j].arrival) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;

    for(int i = 0; i < n; i++) {
        if(current_time < p[i].arrival)
            current_time = p[i].arrival;

        p[i].waiting = current_time - p[i].arrival;
        current_time += p[i].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    for(int i = 0; i < n; i++) {
        printf("%s %d %d", p[i].pid, p[i].waiting, p[i].turnaround);
        if(i != n-1) printf("\n");
    }

    return 0;
}
