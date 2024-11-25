#include <stdio.h>
#include <string.h>
union grade {
    int numgrade;
    float gpa;
    char comment[50];
};
struct StudentGrade {
    char name[50];
    char gradeType; 
    union grade gradevalue;
};

int main() {
    int n, i;
    printf("Enter the number of students ");
    scanf("%d", &n);
    struct StudentGrade students[n];
    struct StudentGrade *ptr=students;
    for (i=0;i<n;i++) {
        printf("Enter details for student %d\n",i+1);
       printf("Enter the name");
       getchar();
        fgets((ptr+i)->name, 50, stdin);
        printf("Enter grade type (N for Numeric, G for GPA, C for Comment");
        scanf("%c",&(ptr+i)->gradeType);
        switch ((ptr+i)->gradeType) {
            case 'N':
                printf("Enter numeric grade");
                scanf("%d",&(ptr+i)->gradevalue.numgrade);
                break;
            case 'G':
                printf("Enter GPA:");
                scanf("%f",(ptr+i)->gradevalue.gpa);
                break;
            case 'C':
                printf("Enter comment");
                getchar(); 
                fgets((ptr+i)->gradevalue.comment, 50, stdin);
                break;
            default:
                printf("Invalid grade type. Try again.\n");
                break;
        }
    }

    
    printf("Student Grades\n");
    for (i=0;i<n;i++) {
        printf("\nStudent %d\n",i+1);
        printf("Name: %s\n",(ptr+i)->name);
        printf("Grade Type: %c\n",(ptr+i)->gradeType);

        switch ((ptr + i)->gradeType) {
            case 'N':
                printf("Numeric Grade: %d\n",(ptr+i)->gradevalue.numgrade);
                break;
            case 'G':
                printf("GPA: %.2f\n", (ptr+i)->gradevalue.gpa);
                break;
            case 'C':
                printf("Comment: %s\n",(ptr+i)->gradevalue.comment);
                break;
        }
    }

    return 0;
}
