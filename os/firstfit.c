#include <stdio.h>

#define MEMORY_SIZE 1000
#define MAX_PROCESSES 100

struct Process {
    int process_id;
    int memory_size;
    int allocated_block;
};

void firstFit(struct Process processes[], int num_processes, int blocks[], int num_blocks) {
    int allocation[num_processes];

    for (int i = 0; i < num_processes; i++) {
        allocation[i] = -1;
        for (int j = 0; j < num_blocks; j++) {
            if (blocks[j] >= processes[i].memory_size) {
                allocation[i] = j;
                blocks[j] -= processes[i].memory_size;
                break;
            }
        }
    }

    printf("\nProcess ID\tProcess Size\tBlock Number\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t", processes[i].process_id, processes[i].memory_size);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i]);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int num_processes, num_blocks;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[MAX_PROCESSES];
    printf("Enter the details of processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process ID: ");
        scanf("%d", &processes[i].process_id);
        printf("Memory Size: ");
        scanf("%d", &processes[i].memory_size);
        processes[i].allocated_block = -1;
    }

    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &num_blocks);

    int blocks[num_blocks];
    printf("Enter the details of memory blocks:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d Size: ", i);
        scanf("%d", &blocks[i]);
    }

    firstFit(processes, num_processes, blocks, num_blocks);

    return 0;
}
