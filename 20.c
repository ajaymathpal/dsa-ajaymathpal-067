#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Species {
    char name[50];
    char type[20];       // Plant or Animal
    char habitat[30];    // e.g., Freshwater, Forest, Urban
    char tolerance[20];  // e.g., High, Medium, Low
    struct Species *next;
};

struct Species *head = NULL;

void insertSpecies() {
    struct Species *newNode, *temp;
    newNode = (struct Species*)malloc(sizeof(struct Species));

    printf("Enter Species Name: ");
    scanf("%s", newNode->name);
    printf("Enter Type (Plant/Animal): ");
    scanf("%s", newNode->type);
    printf("Enter Habitat (Forest/Water/Urban): ");
    scanf("%s", newNode->habitat);
    printf("Enter Pollution Tolerance (High/Medium/Low): ");
    scanf("%s", newNode->tolerance);

    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayAll() {
    struct Species *temp = head;
    if(temp == NULL) {
        printf("No species data available.\n");
        return;
    }
    printf("\n--- All Species Data ---\n");
    while(temp != NULL) {
        printf("Name: %s | Type: %s | Habitat: %s | Tolerance: %s\n",
               temp->name, temp->type, temp->habitat, temp->tolerance);
        temp = temp->next;
    }
}

void classifyByHabitat() {
    struct Species *temp = head;
    char searchHabitat[30];
    if(temp == NULL) {
        printf("No species data available.\n");
        return;
    }
    printf("Enter habitat to classify (Forest/Water/Urban): ");
    scanf("%s", searchHabitat);

    printf("\nSpecies found in %s habitat:\n", searchHabitat);
    int found = 0;
    while(temp != NULL) {
        if(strcasecmp(temp->habitat, searchHabitat) == 0) {
            printf("%s (%s) - Tolerance: %s\n", temp->name, temp->type, temp->tolerance);
            found = 1;
        }
        temp = temp->next;
    }
    if(!found)
        printf("No species found in this habitat.\n");
}

void classifyByTolerance() {
    struct Species *temp = head;
    char searchTol[20];
    if(temp == NULL) {
        printf("No species data available.\n");
        return;
    }
    printf("Enter Pollution Tolerance (High/Medium/Low): ");
    scanf("%s", searchTol);

    printf("\nSpecies with %s pollution tolerance:\n", searchTol);
    int found = 0;
    while(temp != NULL) {
        if(strcasecmp(temp->tolerance, searchTol) == 0) {
            printf("%s (%s) - Habitat: %s\n", temp->name, temp->type, temp->habitat);
            found = 1;
        }
        temp = temp->next;
    }
    if(!found)
        printf("No species found with this tolerance level.\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Insert Species Data\n2. Display All Species\n3. Classify by Habitat\n4. Classify by Pollution Tolerance\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1)
            insertSpecies();
        else if(choice == 2)
            displayAll();
        else if(choice == 3)
            classifyByHabitat();
        else if(choice == 4)
            classifyByTolerance();
        else if(choice == 5)
            break;
        else
            printf("Invalid choice.\n");
    }
    return 0;
}
