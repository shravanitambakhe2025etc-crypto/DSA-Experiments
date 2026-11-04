#include<stdio.h>
#include<conio.h>

int length(char[]);
void compare(char[],char[]);
void palindrom(char[]);
void substring(char[], char[]);
void copy(char[],char[]);     //Copy second into first
void reverse(char[]);

int i,j;
int main(){
int choice;
char str[50];
char str2[50];
int exit = 0;
void displayMenu();
do{
printf("ENTER CHOICE (7 for Display Menu) :\n");
scanf("%d", &choice);

if(!(choice==7 || choice==8)){
printf("Enter String:");
scanf("%s", &str);
}
switch(choice){
case 1:
printf("Length of the String is %d\n\n",length(str));
break;

case 2:
printf("Enter second String: ");
scanf("%s", &str2);
copy(str,str2);
break;
case 3:
reverse(str);
break;

case 4:
palindrom(str);
break;

case 5:
printf("Enter substring String:");
scanf("%s", &str2);
substring(str,str2);
break;

case 6:
printf("Enter second String:");
scanf("%s", &str2);
compare(str, str2);
break;
case 7:
displayMenu();
break;
case 8:
exit = 1;
}
}while(exit==0);
return 0;
}

void displayMenu(){
printf("<<-----------Menu------------->>\n");
printf("1. Length\n");
printf("2. Copy String in another String\n");
printf("3. Reverse String\n");
printf("4. Check for Palindrom\n");
printf("5. Check for substring\n");
printf("6. compare Any String with another\n");
printf("7. Display menu\n");
printf("8. Exit\n");
}

int length(char a[])
{
    int len = 0;
    int i = 0;

    if(a[0] == '\0')
        return 0;

    do
    {
        len++;
        i++;
    } while(a[i] != '\0');

    return len;
}
 void compare(char str[50], char str2[50]){
    int flag = 0;
    int i = 0;

    do {
        if(str[i] != str2[i]){
            flag = 1;
            break;
        }
        i++;
    } while(str[i] != '\0' || str2[i] != '\0');

    if(flag == 0){
        printf("Both Strings are equal\n\n");
    }
    else{
        printf("Both Strings are not equal\n\n");
    }
}

void palindrom(char a[]){
    int l = length(a);
    int i = 0;

    do
    {
        if(a[i] != a[l-i-1])
        {
            printf("Not Palindrome\n\n");
            return;
        }
        i++;

    } while(i < l/2);

    printf("Palindrome\n\n");
}

void substring(char a[50], char b[50]){ // b is substring of a
    int al = length(a);
    int bl = length(b);
    int flag = 0;
    int count = 0;
    int i = 0;
    int j;

    do
    {
        j = 0;

        do
        {
            if(a[i + j] != b[j])
            {
                break;
            }

            j++;

        } while(j < bl);

        if(j == bl)
        {
            count++;
        }

        i++;

    } while(i <= al - bl);

    flag = count;

    if(flag == 0)
    {
        printf("The String B is not substring of A\n\n");
    }
    else
    {
        printf("The String B is substring of A and it occur %d times\n\n", flag);
    }
}

void copy(char a[], char b[]){
    int al = length(a);
    int bl = length(b);
    char str3[50];
    int i = 0;

    do
    {
        str3[i] = b[i];
        i++;

    } while(i < bl);

    str3[i] = '\0';

    i = 0;

    do
    {
        a[i] = str3[i];
        i++;

    } while(i <= bl);

    printf("Copied String is: %s\n\n", a);
}
void reverse(char a[]){
    int al = length(a);
    int i;
    char temp;

    for(i = 0; i < al / 2; i++){
        temp = a[i];
        a[i] = a[al - i - 1];
        a[al - i - 1] = temp;
    }

    printf("Reverse String is: %s\n\n", a);
}
