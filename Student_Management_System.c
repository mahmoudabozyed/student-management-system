/*
 ============================================================================
 Name        : Student_Management_System.c
 Author      : Mahmoud Abouzeid
 Version     :
 Copyright   : Your copyright notice
 Description : The Student Management System is a C program designed to manage student
 	 	 	 	 information efficiently. It allows the user to perform various operations such as
 	 	 	 	 adding new students, displaying all students, searching for a student by ID,
 	 	 	 	 updating student details, calculating the average GPA, and finding the student
 	 	 	 	 with the highest GPA.
 	 	 	 	 This system utilizes fundamental programming concepts including conditions,
 	 	 	 	 loops, strings, structs, and pointers, besides the ability to use data structures
 	 	 	 	 efficiently like the linked list.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct {
	int id;
	char name[50];
	int age;
	float GPA;
} student;

typedef struct node {
	student data;
	struct node *next;
} node;

node *head = NULL;

/***********************************************************************************************************************
* Function Name: void addStudent(const struct student *const ptr)
* Description  :
*   - Adds a new student to the linked list.
*   - Checks if the student's ID already exists.
*   - If it exists, prints an error and returns.
*   - If it doesn't, allocates memory and adds the student to the end of the list.
*   - If memory allocation fails, prints an error and returns.
* Arguments    : ptr - pointer to the student struct to be added.
* Return Value : None
***********************************************************************************************************************/
void addStudent(const student *const ptr) {
	if (ptr == NULL) {
		printf("Error student pointer!\n");
		return;
	}
	node *current = head;
	while (current != NULL) {
		if (current->data.id == ptr->id) {
			printf("Student with ID %d already exists. Cannot add duplicate.\n",
					ptr->id);
			return;
		}
		current = current->next;
	}
	node *link = malloc(sizeof(node));
	assert(link != NULL);
	link->data = *ptr;
	link->next = head;
	head = link;
}

/***********************************************************************************************************************
* Function Name: void displayStudents(void)
* Description  :
*   - Displays all students in the linked list.
*   - If the list is empty, prints a message indicating that.
*   - Otherwise, traverses the list and prints details of each student.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void displayStudents(void) {
	if (head == NULL) {
		printf("No students in the list.\n");
		return;
	}
	node *current = head;
	while (current != NULL) {
		printf("ID   : %d\n", current->data.id);
		printf("Name : %s\n", current->data.name);
		printf("Age  : %d\n", current->data.age);
		printf("GPA  : %.2f\n", current->data.GPA);
		current = current->next;
	}
}

/***********************************************************************************************************************
* Function Name: void searchStudentByID(int id)
* Description  :
*   - Searches for a student by their ID in the linked list.
*   - If found, prints their details.
*   - If not found, prints a message indicating that.
* Arguments    : id - the ID of the student to search for.
* Return Value : None
***********************************************************************************************************************/

void searchStudentByID(int id) {
	if (head == NULL) {
		printf("No students in the list.\n");
		return;
	}
	node *current = head;
	while (current != NULL) {
		if (current->data.id == id) {
			printf("Found id (%d) \n", current->data.id);
			printf("ID   : %d\n", current->data.id);
			printf("Name : %s\n", current->data.name);
			printf("Age  : %d\n", current->data.age);
			printf("GPA  : %.2f\n", current->data.GPA);
			return;
		}
		current = current->next;
	}
	printf("Error, ID not found or list is empty.");
}
/***********************************************************************************************************************
* Function Name: void updateStudent(int id)
* Description  :
*   - Updates the details of a student with the given ID.
*   - If found, updates the student's name, age, and GPA.
*   - If not found, prints a message indicating that.
* Arguments    : id - the ID of the student to update.
* Return Value : None
***********************************************************************************************************************/

void updateStudent(int id) {
	if (head == NULL) {
		printf("No students in the list.\n");
		return;
	}
	node *current = head;
	while (current != NULL) {
		if (current->data.id == id) {
			printf("Enter new student name : ");
			gets(current->data.name);
			printf("Enter new student age : ");
			scanf("%d", &current->data.age);
			printf("Enter new student GPA : ");
			scanf("%f", &current->data.GPA);
			return;
		}
		current = current->next;
	}
	printf("Error, ID not found or list is empty.");
}
/***********************************************************************************************************************
* Function Name: float calculateAverageGPA(void)
* Description  :
*   - Calculates and returns the average GPA of all students.
*   - If the list is empty, returns 0.0.
*   - Otherwise, traverses the list, sums the GPAs, and divides by the number of students.
* Arguments    : None
* Return Value : The average GPA as a float.
***********************************************************************************************************************/

float calculateAverageGPA(void) {
	node *current = head;
	int count = 0;
	float sum = 0.0;

	if (head == NULL) {
		return 0.0;
	}
	while (current != NULL) {
		sum += current->data.GPA;
		count++;
		current = current->next;
	}

	if (count == 0) {
		return 0.0;
	}
	return sum / count;
}
/***********************************************************************************************************************
* Function Name: void searchHighestGPA(void)
* Description  :
*   - Searches for the student with the highest GPA in the linked list.
*   - If the list is empty, prints a message.
*   - Otherwise, finds and prints the details of the student with the highest GPA.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void searchHighestGPA(void) {
	if (head == NULL) {
		printf("No students in the list.\n");
		return;
	}
	node *current = head;
	node *topStudent = head;
	while (current != NULL) {
		if (current->data.GPA > topStudent->data.GPA) {
			topStudent = current;
		}
		current = current->next;
	}
	printf("Student with the Highest GPA: \n");
	printf("ID   : %d\n", topStudent->data.id);
	printf("Name : %s\n", topStudent->data.name);
	printf("Age  : %d\n", topStudent->data.age);
	printf("GPA  : %.2f\n", topStudent->data.GPA);
}
/***********************************************************************************************************************
* Function Name: void deleteStudent(int id)
* Description  :
*   - Deletes a student from the linked list by their ID.
*   - Iterates through the list to find the student.
*   - If found, adjusts pointers, frees memory, and prints a success message.
*   - If not found, prints an error message.
* Arguments    : id - the ID of the student to delete.
* Return Value : None
***********************************************************************************************************************/

void deleteStudent(int id) {
	node *current = NULL;
	node *prev = NULL;
	node *delete_node = NULL;

	if (head == NULL) {
		printf("Linked List is empty");
		return;
	}

	if (head->data.id == id) {
		delete_node = head;
		head = head->next;
		printf("%d found and deleted \n", id);
		free(delete_node);
		return;
	}
	current = head->next;
	prev = head;
	while (current != NULL) {
		if (current->data.id == id) {
			delete_node = current;
			prev->next = current->next;
			printf("%d found and deleted \n", id);
			free(delete_node);
			return;
		}
		prev = current;
		current = current->next;
	}
	if (delete_node == NULL) {
		printf("%d not found in the List.", id);
	}
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int choice, id;
	student s;

	while (1) {
		printf("\n====== Student Management System ======\n");
		printf("1. Add Student\n");
		printf("2. Display All Students\n");
		printf("3. Search Student by ID\n");
		printf("4. Update Student\n");
		printf("5. Delete Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Search for Student with Highest GPA\n");
		printf("8. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);


		switch (choice) {
		case 1:
			printf("Enter ID: ");
			scanf("%d", &s.id);
			printf("Enter Name: ");
			scanf(" %[^\n]", s.name);
			printf("Enter Age: ");
			scanf("%d", &s.age);
			printf("Enter GPA: ");
			scanf("%f", &s.GPA);
			addStudent(&s);
			break;

		case 2:
			displayStudents();
			break;

		case 3:
			printf("Enter ID to search: ");
			scanf("%d", &id);
			searchStudentByID(id);
			break;

		case 4:
			printf("Enter ID to update: ");
			scanf("%d", &id);
			getchar();
			updateStudent(id);
			break;

		case 5:
			printf("Enter ID to delete: ");
			scanf("%d", &id);
			deleteStudent(id);
			break;

		case 6: {
			float avg = calculateAverageGPA();
			if (avg > 0.0)
				printf("Average GPA is: %.2f\n", avg);
			else
				printf("No students to calculate GPA.\n");
			break;
		}

		case 7:
			searchHighestGPA();
			break;

		case 8:
			printf("Exiting program. Goodbye!\n");
			return 0;

		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}
