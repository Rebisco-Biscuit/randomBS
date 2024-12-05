#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the heap

typedef struct {
    int size;         // Number of elements in the heap
    int arr[MAX];     // Array to store the heap elements
} MaxHeap;

// Function to initialize the heap
void initHeap(MaxHeap *heap) {
    heap->size = 0;
}

// Function to get the parent index
int parent(int i) {
    return (i - 1) / 2;
}

// Function to get the left child index
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get the right child index
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to insert a new element into the heap
void insert(MaxHeap *heap, int value) {
    if (heap->size == MAX) {
        printf("Heap is full!\n");
        return;
    }

    // Insert the new value at the end of the array
    heap->arr[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // Bubble up to maintain the heap property
    while (i != 0 && heap->arr[parent(i)] < heap->arr[i]) {
        // Swap the current node with its parent
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[parent(i)];
        heap->arr[parent(i)] = temp;

        i = parent(i);
    }
}

// Function to heapify a subtree rooted at index i
void heapify(MaxHeap *heap, int i) {
    int largest = i; // Initialize the largest as root
    int left = leftChild(i);
    int right = rightChild(i);

    // Check if the left child is larger than the root
    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;

    // Check if the right child is larger than the current largest
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        // Swap the root with the largest
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[largest];
        heap->arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(heap, largest);
    }
}

// Function to extract the maximum element from the heap
int extractMax(MaxHeap *heap) {
    if (heap->size <= 0)
        return -1; // Return -1 if the heap is empty

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0]; // Return the only element in the heap
    }

    // Store the maximum value and remove it
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify the new root to maintain the heap property
    heapify(heap, 0);

    return root;
}

// Function to display the heap
void display(MaxHeap *heap) {
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

// Main function to test the Max-Heap
int main() {
    MaxHeap heap;
    initHeap(&heap);

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    insert(&heap, 40);

    printf("Heap elements: ");
    display(&heap);

    printf("Extracted max: %d\n", extractMax(&heap));
    printf("Heap elements after extraction: ");
    display(&heap);

    return 0;
}
