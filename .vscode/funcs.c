#include "funcs.h"

int FileExists(const char *path) {
    FILE *file = fopen(path, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

int ReadConfigs(const char *path, char *uname, char *email) {
    // Read the first line
    if (fgets(uname, 40, path) == NULL) {
        printf("Error reading username\n");
        fclose(path);
        exit(IO_ERROR);
    }

    // Read the second line
    if (fgets(email, 255, path) == NULL) {
        perror("Error reading email\n");
        fclose(path);
        exit(IO_ERROR);
    }

    fclose(path);
    return 1;
}

int ExecuteCommand(const char *cmd, const char *output) {
    FILE *fp;
    char buffer[512];

    // Open the command for reading
    fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }

    // Read the output a line at a time - output it
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcat(output, buffer);
    }

    // Close the pipe
    if (pclose(fp) == -1) {
        perror("Failed to close command stream");
        exit(EXIT_FAILURE);
    }
}

int CompareStrings(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            // Strings are not equal
            return 0;
        }
        str1++;
        str2++;
    }

    // Check if both strings have reached the end
    return (*str1 == '\0' && *str2 == '\0');
}

int GitInit() {
    if (FileExists("user.txt")) {
        FILE *file = fopen("user.txt", "r");

        // Max length of a GitHub username is 39 chars
        char uname[40];
        char cuname[40];

        // Max length of an email address is 254 chars
        char email[255];
        char cemail[255];

        ReadConfigs(file, uname, email);

        ExecuteCommand("git config user.name", cuname);
        ExecuteCommand("git config user.email", cemail);

        if (CompareStrings(uname, cuname) && CompareStrings(email, cemail)) {
            printf("User configs are all set\n");
        } else {
            printf("User configs are not set\nSetting them up...\n");
            system("git config user.name \"%s\"", uname);
            system("git config user.email \"%s\"", email);
        }

        return 1;
    } else {
        printf("user.txt file does not exist\nPlease fill it out first!...\n");
        return 0;
    }
}

int Commit(int cnt) {
    system("git add .");
    system("git commit -m \"Update nr. %d\"", cnt);
}

int Push() {
    system("git push");
}

int Pull() {
    system("git pull");
}

int Fetch() {
    system("git fetch");
}
