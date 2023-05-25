#include <stdio.h>

#define FRAME_SIZE 3
#define PAGE_SEQUENCE_SIZE 20

int main() {
    int page_sequence[PAGE_SEQUENCE_SIZE] = {1, 2, 3, 4, 1, 5, 6, 3, 7, 8, 1, 2, 7, 3, 4, 5, 6, 8, 1, 2};
    int frame[FRAME_SIZE];
    int page_faults = 0;
    int next_frame_index = 0;

    for (int i = 0; i < FRAME_SIZE; i++) {
        frame[i] = -1; // -1 indicates an empty frame
    }

    for (int i = 0; i < PAGE_SEQUENCE_SIZE; i++) {
        int page_number = page_sequence[i];
        int is_page_fault = 1;

        // Check if the page is already in a frame
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frame[j] == page_number) {
                is_page_fault = 0;
                break;
            }
        }

        if (is_page_fault) {
            page_faults++;
            frame[next_frame_index] = page_number;
            next_frame_index = (next_frame_index + 1) % FRAME_SIZE;
        }

        printf("Page %d -> [", page_number);
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frame[j] == -1) {
                printf("_ ");
            } else {
                printf("%d ", frame[j]);
            }
        }
        printf("]\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
