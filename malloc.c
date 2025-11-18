#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i;
    float total = 0;

    struct employee *emp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    emp = (struct employee *)malloc(n * sizeof(struct employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter employee details:\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d ID: ", i + 1);
        scanf("%d", &emp[i].id);

        printf("Employee %d Name: ", i + 1);
        scanf("%s", emp[i].name);

        printf("Employee %d Monthly Salary: ", i + 1);
        scanf("%f", &emp[i].salary);
    }

    // Calculate total annual salary expenditure
    for (i = 0; i < n; i++) {
        total += emp[i].salary * 12;
    }

    printf("\nTotal Annual Salary Expenditure = ₹%.2f\n", total);

    // Free memory
    free(emp);

    return 0;
}
