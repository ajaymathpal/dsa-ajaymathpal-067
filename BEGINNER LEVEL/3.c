#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i=1;i<n;i++) {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=low-1, temp, j;
    for(j=low;j<high;j++) {
        if(arr[j]<pivot) {
            i++;
            temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;
        }
    }
    temp=arr[i+1]; arr[i+1]=arr[high]; arr[high]=temp;
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low<high) {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1=m-l+1, n2=r-m, i, j, k;
    int L[50], R[50];
    for(i=0;i<n1;i++) L[i]=arr[l+i];
    for(j=0;j<n2;j++) R[j]=arr[m+1+j];
    i=0; j=0; k=l;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void heapify(int arr[], int n, int i) {
    int largest=i, l=2*i+1, r=2*i+2, temp;
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    if(largest!=i) {
        temp=arr[i]; arr[i]=arr[largest]; arr[largest]=temp;
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n) {
    int i, temp;
    for(i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(i=n-1;i>0;i--) {
        temp=arr[0]; arr[0]=arr[i]; arr[i]=temp;
        heapify(arr,i,0);
    }
}

void display(int arr[], int n) {
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    int arr[50], n, i, choice, temp[50];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    while(1) {
        for(i=0;i<n;i++) temp[i]=arr[i];
        printf("\n1.Bubble Sort\n2.Quick Sort\n3.Insertion Sort\n4.Merge Sort\n5.Heap Sort\n6.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1) { bubbleSort(temp,n); printf("Sorted: "); display(temp,n); }
        else if(choice==2) { quickSort(temp,0,n-1); printf("Sorted: "); display(temp,n); }
        else if(choice==3) { insertionSort(temp,n); printf("Sorted: "); display(temp,n); }
        else if(choice==4) { mergeSort(temp,0,n-1); printf("Sorted: "); display(temp,n); }
        else if(choice==5) { heapSort(temp,n); printf("Sorted: "); display(temp,n); }
        else if(choice==6) break;
        else printf("Invalid choice\n");
    }

    printf("\nTime Complexity Comparison:\n");
    printf("Bubble Sort:     O(n^2)\n");
    printf("Insertion Sort:  O(n^2)\n");
    printf("Quick Sort:      O(n log n) average, O(n^2) worst\n");
    printf("Merge Sort:      O(n log n)\n");
    printf("Heap Sort:       O(n log n)\n");
    return 0;
}
