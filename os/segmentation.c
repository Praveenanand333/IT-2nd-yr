#include <stdio.h>

#define MAX_SEGMENTS 10
#define MAX_PROCESSES 10

struct Segment {
    int segment_id;
    int base_address;
    int limit;
};

struct Process {
    int process_id;
    int num_segments;
    struct Segment segments[MAX_SEGMENTS];
};

void allocateSegments(struct Process processes[], int num_processes) {
    int memory_size;
    printf("Enter the total memory size: ");
    scanf("%d", &memory_size);

    int memory[memory_size];

    for (int i = 0; i < memory_size; i++) {
        memory[i] = -1; // -1 indicates unallocated memory
    }

    for (int i = 0; i < num_processes; i++) {
        printf("\nEnter details for Process %d:\n", processes[i].process_id);

        for (int j = 0; j < processes[i].num_segments; j++) {
            printf("Enter details for Segment %d:\n", processes[i].segments[j].segment_id);
            printf("Base Address: ");
            scanf("%d", &processes[i].segments[j].base_address);
            printf("Limit: ");
            scanf("%d", &processes[i].segments[j].limit);

            // Check if the segment can fit in the memory
            int allocated = 0;
            for (int k = processes[i].segments[j].base_address; k < processes[i].segments[j].base_address + processes[i].segments[j].limit; k++) {
                if (memory[k] != -1) {
                    allocated = 1;
                    break;
                }
            }

            if (allocated) {
                printf("Segment %d cannot be allocated for Process %d.\n", processes[i].segments[j].segment_id, processes[i].process_id);
            } else {
                // Allocate the segment in the memory
                for (int k = processes[i].segments[j].base_address; k < processes[i].segments[j].base_address + processes[i].segments[j].limit; k++) {
                    memory[k] = processes[i].process_id;
                }
                printf("Segment %d allocated for Process %d.\n", processes[i].segments[j].segment_id, processes[i].process_id);
            }
        }
    }

    printf("\nMemory Allocation:\n");
    printf("Memory Index\tProcess ID\n");
    for (int i = 0; i < memory_size; i++) {
        printf("%d\t\t%d\n", i, memory[i]);
    }
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the details for Process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &processes[i].process_id);
        printf("Number of Segments: ");
        scanf("%d", &processes[i].num_segments);

        for (int j = 0; j < processes[i].num_segments; j++) {
            printf("Enter details for Segment %d:\n", j + 1);
            printf("Segment ID: ");
            scanf("%d", &processes[i].segments[j].segment_id);
        }
    }

    allocateSegments(processes, num_processes);

    return 0;
}
