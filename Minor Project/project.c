#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Species {
    char name[50];
    char type[20];
    char habitat[30];
    char tolerance[20];
    struct Species *next;
};

struct Species *head = NULL;

void insertSpecies() {
    struct Species *newNode = (struct Species*)malloc(sizeof(struct Species));
    struct Species *temp;

    printf("Enter Species Name: ");
    scanf("%s", newNode->name);

    printf("Enter Type (Plant/Animal): ");
    scanf("%s", newNode->type);

    printf("Enter Habitat (Forest/Water/Urban): ");
    scanf("%s", newNode->habitat);

    printf("Enter Pollution Tolerance (High/Medium/Low): ");
    scanf("%s", newNode->tolerance);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("\n Species inserted successfully!\n");
}

void displayAll() {
    struct Species *temp = head;

    if (temp == NULL) {
        printf("\nNo species data available.\n");
        return;
    }

    printf("\n--- All Species Data ---\n");
    while (temp != NULL) {
        printf("Name: %s | Type: %s | Habitat: %s | Tolerance: %s\n",
               temp->name, temp->type, temp->habitat, temp->tolerance);
        temp = temp->next;
    }
}

void classifyByHabitat() {
    struct Species *temp = head;
    char searchHabitat[30];
    int found = 0;

    if (temp == NULL) {
        printf("No species data available.\n");
        return;
    }

    printf("Enter Habitat to classify (Forest/Water/Urban): ");
    scanf("%s", searchHabitat);

    printf("\nSpecies found in %s habitat:\n", searchHabitat);

    while (temp != NULL) {
        if (strcasecmp(temp->habitat, searchHabitat) == 0) {
            printf("%s (%s) - Tolerance: %s\n",
                   temp->name, temp->type, temp->tolerance);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("No species found for this habitat.\n");
}

void classifyByTolerance() {
    struct Species *temp = head;
    char searchTol[20];
    int found = 0;

    if (temp == NULL) {
        printf("No species data available.\n");
        return;
    }

    printf("Enter Pollution Tolerance (High/Medium/Low): ");
    scanf("%s", searchTol);

    printf("\nSpecies with %s pollution tolerance:\n", searchTol);

    while (temp != NULL) {
        if (strcasecmp(temp->tolerance, searchTol) == 0) {
            printf("%s (%s) - Habitat: %s\n",
                   temp->name, temp->type, temp->habitat);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("No species found with this tolerance level.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n====== Species Classification System ======\n");
        printf("1. Insert Species Data\n");
        printf("2. Display All Species\n");
        printf("3. Classify by Habitat\n");
        printf("4. Classify by Pollution Tolerance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertSpecies(); break;
            case 2: displayAll(); break;
            case 3: classifyByHabitat(); break;
            case 4: classifyByTolerance(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
