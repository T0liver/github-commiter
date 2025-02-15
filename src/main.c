#include <stdio.h>
#include <stdlib.h>
#include "..\include\funcs.h"

int main() {
    int counter;

    // Opening file or creating if file is not found
    if (FileExists("commit.txt")) {
        printf("Commiting file exists\n");
        FILE *file = fopen("commit.txt", "r");
        char buffer[32];
        fgets(buffer, 32, file);
        printf("Current counter: %s", buffer);
        counter = atoi(buffer);
    } else {
        printf("Commiting file does not exist\nCreating new one...\n");
        FILE *file = fopen("commit.txt", "w");
        if (file) {
            fprintf(file, "1\n");
            fclose(file);
            counter = 1;
        } else {
            printf("Error creating file\nExiting...\n");
            return 5;
        }
    }

    // Incrementing counter
    counter++;
    FILE *file = fopen("commit.txt", "w");
    if (file) {
        fprintf(file, "%d\n", counter);
        fclose(file);
    } else {
        printf("Error creating file\nExiting...\n");
        return 5;
    }

    if (!GitInit()) {
        printf("Git init failed!\n");
        return 22;
    }

    if (!Fetch() || !Pull()) {
        printf("fetch & pull failed!\n");
        return 113;
    }

    if (!Commit(counter)) {
        printf("Commit failed!\n");
        return 5;
    }
    if (!Push()) {
        printf("Push failed!\n");
        return 112;
    }
    return 0;
}
