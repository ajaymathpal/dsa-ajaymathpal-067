#include <stdio.h>

int main() {
    int arr[100], n, i, pos, val, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    while(1) {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1) {
            printf("Enter position and value: ");
            scanf("%d%d",&pos,&val);
            for(i=n;i>=pos;i--)
                arr[i]=arr[i-1];
            arr[pos-1]=val;
            n++;
        } 
        else if(choice==2) {
            printf("Enter position to delete: ");
            scanf("%d",&pos);
            for(i=pos-1;i<n-1;i++)
                arr[i]=arr[i+1];
            n--;
        } 
        else if(choice==3) {
            printf("List: ");
            for(i=0;i<n;i++)
                printf("%d ",arr[i]);
            printf("\n");
        } 
        else if(choice==4) {
            break;
        } 
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
