#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==key)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low=0, high=n-1, mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

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

int main() {
    int arr[50], n, i, key, pos, choice;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    while(1) {
        printf("\n1.Linear Search\n2.Binary Search\n3.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1) {
            printf("Enter element to search: ");
            scanf("%d",&key);
            pos=linearSearch(arr,n,key);
            if(pos!=-1)
                printf("Element found at position %d\n",pos+1);
            else
                printf("Element not found\n");
        } 
        else if(choice==2) {
            bubbleSort(arr,n);
            printf("Enter element to search: ");
            scanf("%d",&key);
            pos=binarySearch(arr,n,key);
            if(pos!=-1)
                printf("Element found at position %d\n",pos+1);
            else
                printf("Element not found\n");
        } 
        else if(choice==3) {
            break;
        } 
        else {
            printf("Invalid choice\n");
        }
    }

    printf("\nTime Complexity Comparison:\n");
    printf("Linear Search: O(n)\n");
    printf("Binary Search: O(log n) (only on sorted list)\n");
    return 0;
}
