#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *p;    // Pointer to the array
    int size;  // Maximum capacity of the heap
    int count; // Current number of elements in the heap
} Heap;

// Initialize the heap
Heap* createHeap(int size) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->p = (int*)malloc(size * sizeof(int));
    heap->size = size;
    heap->count = 0;
    return heap;
}

// Insert an element into the Min-Heap
void push(Heap* heap, int x) {
    if (heap->count >= heap->size)
        return;
    heap->p[heap->count] = x; // Add the new element
    heap->count++;
    up_heapify(heap, heap->count - 1); // Restore heap property
}

// Remove and return the minimum element (root) from the Min-Heap
int pop(Heap* heap) {
    if (heap->count == 0)
        return -1; // Heap is empty
    int root = heap->p[0]; // The smallest element
    heap->p[0] = heap->p[heap->count - 1]; // Replace root with last element
    heap->count--;
    down_heapify(heap, 0); // Restore heap property
    return root;
}

// Up-Heapify
void up_heapify(Heap *heap, int idx) {
    while (idx > 0) {
        int parent_idx = (idx - 1) / 2;
        if (heap->p[idx] < heap->p[parent_idx]) {
            int temp = heap->p[idx];
            heap->p[idx] = heap->p[parent_idx];
            heap->p[parent_idx] = temp;

            idx = parent_idx;
        } else {
            break;
        }
    }
}

// Down-Heapify
void down_heapify(Heap *heap, int idx) {
    while (2 * idx + 1 < heap->count) {
        int left_child_idx = 2 * idx + 1;
        int right_child_idx = 2 * idx + 2;
        int smallest = idx;

        if (heap->p[left_child_idx] < heap->p[smallest])
            smallest = left_child_idx;

        if (right_child_idx < heap->count && heap->p[right_child_idx] < heap->p[smallest])
            smallest = right_child_idx;

        if (smallest != idx) {
            int temp = heap->p[idx];
            heap->p[idx] = heap->p[smallest];
            heap->p[smallest] = temp;

            idx = smallest;
        } else {
            break;
        }
    }
}

// Print the elements of the heap
void printHeap(Heap* heap) {
    for (int i = 0; i < heap->count; i++) {
        printf("%d ", heap->p[i]);
    }
    printf("\n");
}

int main() {
    Heap* heap = createHeap(10);

    push(heap, 5);
    push(heap, 3);
    push(heap, 8);
    push(heap, 1);
    push(heap, 2);

    printf("Heap elements: ");
    printHeap(heap);

    printf("Popped element: %d\n", pop(heap));

    printf("Heap elements after pop: ");
    printHeap(heap);

    return 0;
}
