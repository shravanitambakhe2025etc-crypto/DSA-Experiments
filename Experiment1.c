#include <stdio.h>

int length(char a[]);
void compare(char str[], char str2[]);
void palindrom(char a[]);
void substring(char a[], char b[]);
void copy(char a[], char b[]); // Copy second into first
void reverse(char a[]);
void displayMenu();

int main() {
    int choice;
    char str[50];
    char str2[50];
    int exit = 0;

    displayMenu();

    do {
        printf("ENTER CHOICE (7 for Display Menu):\n");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            printf("Enter String: ");
            scanf("%49s", str);
        }

        switch (choice) {
            case 1:
                printf("Length of the String is %d\n\n", length(str));
                break;
            case 2:
                printf("Enter second String: ");
                scanf("%49s", str2);
                copy(str, str2);
                break;
            case 3:
                reverse(str);
                break;
            case 4:
                palindrom(str);
                break;
            case 5:
                printf("Enter substring String: ");
                scanf("%49s", str2);
                substring(str, str2);
                break;
            case 6:
                printf("Enter second String: ");
                scanf("%49s", str2);
                compare(str, str2);
                break;
            case 7:
                displayMenu();
                break;
            case 8:
                exit = 1;
                break;
            default:
                printf("Invalid choice! Please enter 1-8.\n\n");
        }
    } while (exit == 0);

    return 0;
}

void displayMenu() {
    printf("<<-----------Menu------------->>\n");
    printf("1. Length\n");
    printf("2. Copy String in another String\n");
    printf("3. Reverse String\n");
    printf("4. Check for Palindrome\n");
    printf("5. Check for Substring\n");
    printf("6. Compare Any String with another\n");
    printf("7. Display menu\n");
    printf("8. Exit\n\n");
}

int length(char a[]) {
    int len = 0;
    while (a[len] != '\0') {
        len++;
    }
    return len;
}

void compare(char str[], char str2[]) {
    int i = 0;
    while (str[i] != '\0' || str2[i] != '\0') {
        if (str[i] != str2[i]) {
            printf("Both Strings are not equal\n\n");
            return;
        }
        i++;
    }
    printf("Both Strings are equal\n\n");
}

void palindrom(char a[]) {
    int l = length(a);
    for (int i = 0; i < l / 2; i++) {
        if (a[i] != a[l - i - 1]) {
            printf("Not Palindrome\n\n");
            return;
        }
    }
    printf("Palindrome\n\n");
}

void substring(char a[], char b[]) {
    int al = length(a);
    int bl = length(b);
    int count = 0;

    if (bl == 0 || bl > al) {
        printf("The String B is not substring of A\n\n");
        return;
    }

    for (int i = 0; i <= al - bl; i++) {
        int j = 0;
        while (j < bl && a[i + j] == b[j]) {
            j++;
        }
        if (j == bl) {
            count++;
        }
    }

    if (count == 0) {
        printf("The String B is not substring of A\n\n");
    } else {
        printf("The String B is substring of A and it occurs %d times\n\n", count);
    }
}

void copy(char a[], char b[]) {
    int i = 0;
    while (b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
    printf("Copied String is: %s\n\n", a);
}

void reverse(char a[]) {
    int al = length(a);
    for (int i = 0; i < al / 2; i++) {
        char temp = a[i];
        a[i] = a[al - i - 1];
        a[al - i - 1] = temp;
    }
    printf("Reverse String is: %s\n\n", a);
}
