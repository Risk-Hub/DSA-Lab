#include <stdio.h>
struct student
{
    int roll, marks;
    char name[50], gender;
};
int main()
{
    int n, i;
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    struct student s[n];
    printf("\nEnter the details of the student:-\n");
    for (i = 0; i < n; i++)
    {
        printf("\nFor student-%d", i + 1);
        printf("\n Enter Name: ");
        scanf(" %[^\n]", s[i].name);
        printf(" Enter Roll No.: ");
        scanf("%d", &s[i].roll);
        printf(" Enter Gender: ");
        scanf(" %c", &s[i].gender);
        printf(" Enter Total Marks: ");
        scanf(" %d", &s[i].marks);
    }
    printf("\nStudent details enetred are as follows:-\n");
    for (i = 0; i < n; i++)
    {
        printf("\nFor student-%d", i + 1);
        printf("\n Name: %s", s[i].name);
        printf("\n Roll No.: %d", s[i].roll);
        printf("\n Gender: %c", s[i].gender);
        printf("\n Total Marks: %d", s[i].marks);
    }
}