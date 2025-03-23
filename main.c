#include <stdio.h>
#include <stdlib.h>

// Step 1: Define Struct for Employees
typedef struct 
{
    char name[50];
    float salary;
    int experience;
} Employee;

int main() {
    // Step 2: Declare Necessary Variables
    int numEmployees = 0;
    float sumSalaries = 0;
    float averageSalary = 0;

    // Step 3: Get Input from the User
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    // Dynamically allocate memory
    Employee *employees = (Employee *)malloc(numEmployees * sizeof(Employee));

    // Check if memory allocation was successful
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit program with error
    }
    
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter name of employee %d: ", i + 1);
        scanf(" %[^\n]", employees[i].name);

        printf("Enter salary of %s: ", employees[i].name);
        scanf("%f", &employees[i].salary);

        printf("Enter years of experience of %s: ", employees[i].name);
        scanf("%d", &employees[i].experience);

        sumSalaries += employees[i].salary;
    }

    // Step 4: Calculate Average Salary
    averageSalary = sumSalaries / numEmployees; 

    // Step 5: Display Employee Information
    printf("\nEmployee Details:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s - Salary: $%.2f - Experience: %d years\n", employees[i].name, employees[i].salary, employees[i].experience);
    }    

    printf("\nTotal Salary: $%.2f\n", sumSalaries);
    printf("Average Salary: $%.2f\n", averageSalary);

    // Step 6: Identify High Earners
    printf("\nEmployees earning above the average:\n");
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].salary > averageSalary) {
            printf("- %s\n", employees[i].name);
        }
    }

    // Step 7: Free dynamically allocated memory
    free(employees);

    printf("Thank you for using the Employee Average System!");
    
    return 0;
}
