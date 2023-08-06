/****************************************************/
/*   AUTHOR      : Ahmed Osama Metwally Azzap       */
/*   Description : School Managemnet System         */
/*   DATE        : 1/8/2023                         */
/*   FILE        : School.c                         */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "School.h"
static u8 Exit_Program =0;

void initializeSchool(School_t* school) 
{
    school->head = NULL;
}
/**
  * @brief  Function to display the main menu and handle user input
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
 void MAIN_MENU(School_t* school)
{
    int feature=1,mode;
        while(Exit_Program == 0)
    {
        printf(" *********************************************\n");
        printf(" *********************************************\n");
        printf("      Welcome to School Management System     \n");
        printf(" *********************************************\n");
        printf(" *********************************************\n");
        printf(" ---------------------------------------------\n");
        printf(" Manager Mode Press -------> [1]\n");
        printf(" Student Mode Press -------> [2]\n");
        printf(" Exit Program Press -------> [0]\n");
        printf(" ---------------------------------------------\n");
        printf(" Enter the mode you need : ");
        scanf("%d",&mode);
        printf(" ---------------------------------------------\n");
        switch (mode)
        {
            case 0 :
                    printf(" *******************************\n");
                    printf(" *******************************\n");
                    printf(" <<<<<<<<<<  GoodBye  >>>>>>>>>>\n");
                    printf(" *******************************\n");
                    printf(" *******************************\n");
                    freeStudentList(school);
                    Exit_Program++;
                    break;
            case 1 :
                    printf(" Please Enter Manager Password : ");
                    for ( int i=0 ; i < 3 ; i++ )
                    {
                        int pass;
                        scanf("%d",&pass);
                        
                        if ( pass == 1234 )
                        {
                            printf(" *********************************\n");
                            printf(" <<<<<<<< Welcome Manager >>>>>>>>\n");
                            printf(" *********************************\n");
                        while(feature !=0)
                            { 
                            printf(" (Create) Student account         Press ------> [1]\n");
                            printf(" (Delete) Student account         Press ------> [2]\n");
                            printf(" (Edit)   Student account         Press ------> [3]\n");
                            printf(" (Enter)  Students scores         Press ------> [4]\n");
                            printf(" (View)   Students list           Press ------> [5]\n");
                            printf(" Back to Main Window              Press ------> [0]\n");
                            printf(" Select Your choice :------> ");
                            scanf("%d",&feature);
                            switch (feature)
                                {
                                    case 0 :
                                        feature = 0;
                                        break;
                                    case 1:
                                        NEW_STUDENT(school);
                                        break;
                                    case 2:
                                        DELETE_STUDENT(school);
                                        break;
                                    case 3:
                                        STUDENT_EDIT(school);
                                        break;
                                    case 4:
                                        STUDENT_SCORE(school);
                                        break;
                                    case 5:
                                        STUDENT_LIST(school);
                                    default :
                                        printf("\n<<<<<<<<<<<<<<<<<<<<< Invalid choice >>>>>>>>>>>>>>>>>\n\n");
                                        break;
                                }
                            }
                            break;
                        }else
                        {
                           if (i==2)
                            {
                                printf(" **********************************************\n");
                                printf(" Incorrect Password for 3 times, No more tries \n");
                                printf(" **********************************************\n");
                                Exit_Program++ ;
                                break;							
                            }
                            else 
                            {
                                printf("xxxxxxxxxxxxx\n");
                                printf(" Try again : ");
                            } 
                        }
                    }
                break;
            case 2:
                    printf("**********************************\n");
                    printf(" <<<<<<<< Welcome Student >>>>>>> \n");
                    printf("**********************************\n");
                    while ( feature != 3 )
                    {
                        printf(" --------------------------------------------------\n");
                        printf(" (Count)  Students in School      Press ------> [1]\n");
                        printf(" (Rank)   Students by CS score    Press ------> [2]\n");
                        printf(" Back to Main Window              Press ------> [3]\n");
                        printf(" --------------------------------------------------\n");
                        printf(" Select Your choice :------> ");
                        scanf("%d",&feature);
                        switch (feature)
                                {
                                    case 1:
                                        SIZE_SCHOOL(school);    
                                        break;
                                    case 2:
                                        RANK_STUDENT(school);
                                        break;
                                    case 3:
                                        break;
                                    default:
                                        printf("\n<<<<<<<<<<<<<<<<<<<<< Invalid choice >>>>>>>>>>>>>>>>>\n\n");
                                        break;
                                }
                     }
                break;
            default:
            printf("\n<<<<<<<<<<<<<<<<<<<<<Invalid Mode>>>>>>>>>>>>>>>>>\n\n");
                break;
        } 
    }
}
/**
  * @brief  Function to create a new student account
  * @param  school which is a pointer to a School_t struct
  * @retval Return a pointer to struct that been created
  */
Student_t* NEW_STUDENT(School_t* school) 
{
    Student_t* newStudent = (Student_t*)malloc(sizeof(Student_t));
    if (newStudent == NULL) 
    {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    printf("\n===============================================\n");
    printf("Enter student details:\n");
    printf("===============================================\n");
    printf("Name: ");
    getchar(); // Clear the input buffer
    fgets(newStudent->name, sizeof(newStudent->name), stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = '\0'; // Remove trailing newline
/*************************************************************************************************/
    printf("Date of Birth: ");
    fgets(newStudent->Birth, sizeof(newStudent->Birth), stdin);
    newStudent->Birth[strcspn(newStudent->Birth, "\n")] = '\0';// Remove trailing newline
/*************************************************************************************************/
    printf("ID: ");
    fgets(newStudent->ID, sizeof(newStudent->ID), stdin);
    newStudent->ID[strcspn(newStudent->ID, "\n")] = '\0';// Remove trailing newline
/*************************************************************************************************/
    printf("Address: ");
    fgets(newStudent->address, sizeof(newStudent->address), stdin);
    newStudent->address[strcspn(newStudent->address, "\n")] = '\0';// Remove trailing newline
/*************************************************************************************************/
    printf("Phone number: ");
    fgets(newStudent->phone, sizeof(newStudent->phone), stdin);
    newStudent->phone[strcspn(newStudent->phone, "\n")] = '\0';// Remove trailing newline
/*************************************************************************************************/
    newStudent->cs_score = 0; // Initialize computer science score to 0
    newStudent->next = NULL;
    // Add the new student to the linked list
    if (school->head == NULL) 
    {
        school->head = newStudent;
    } else 
    {
       Student_t* current_Node = school->head;
        while (current_Node->next != NULL) 
        {
            current_Node = current_Node->next;
        }
        current_Node->next = newStudent;
    }
    printf("New student account created successfully.\n");
    printf("===============================================\n");
    return newStudent;
}
/**
  * @brief  Function to view the list of students
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void STUDENT_LIST(School_t* school) 
{
    if (school->head == NULL)
    {
        printf("No Students Accounts Created Yet.\n");
        return;
    }
    printf("\n===============================================\n");
    printf("Students List:\n");
    printf("===============================================\n");
    printf("===============================================\n");
    Student_t* current_Node = school->head;
    while (current_Node != NULL) 
    {
    printf("Name : %s\n", current_Node->name);
    printf("ID : %s\n", current_Node->ID);   
    printf("Date of Birth : %s\n", current_Node->Birth);
    printf("Address : %s\n", current_Node->address);
    printf("Phone number : %s\n", current_Node->phone);
    printf("===============================================\n");
        current_Node = current_Node->next;
    }
}
/**
  * @brief  Function to delete a student account
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void DELETE_STUDENT(School_t* school)
{
    if (school->head == NULL) 
    {
        printf("No students found. Cannot delete.\n");
        return;
    }
    char Local_ID[15];
    printf("\n===============================================\n");
    printf("Enter the ID of the student you want to delete: ");
    getchar(); // Clear the input buffer
    fgets(Local_ID, sizeof(Local_ID), stdin);
    Local_ID[strcspn(Local_ID, "\n")] = '\0';

    Student_t* current_Node = school->head;
    Student_t* prev = NULL;
    while (current_Node != NULL) 
    {
        if (strcmp(current_Node->ID, Local_ID) == 0) 
        {
            if (prev == NULL) 
            {
                school->head = current_Node->next;
            } else 
            {
                prev->next = current_Node->next;
            }
            free(current_Node);
            printf("Student account with ID '%s' deleted successfully.\n", Local_ID);
            printf("===============================================\n");
            return;
        }
        prev = current_Node;
        current_Node = current_Node->next;
    }
    printf("No student account found with ID '%s'. Deletion failed.\n", Local_ID);
    printf("===============================================\n");
}
/**
  * @brief Function to update a particular student account
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void STUDENT_EDIT(School_t* school) 
{
    if (school->head == NULL)
    {
        printf("No students found. Cannot update.\n");
        return;
    }

    u8 Local_ID[15];
    printf("\nEnter the ID of the student you want to update: ");
    getchar(); // Clear the input buffer
    fgets(Local_ID, sizeof(Local_ID), stdin);
    Local_ID[strcspn(Local_ID, "\n")] = '\0';

    Student_t* current_Node = school->head;
    while (current_Node != NULL) 
    {
        if (strcmp(current_Node->ID, Local_ID) == 0) 
        {
            printf("\n============================================\n");
            printf("Enter updated student details:\n");
            printf("Name: ");
            getchar(); // Clear the input buffer
            fgets(current_Node->name, sizeof(current_Node->name), stdin);
            current_Node->name[strcspn(current_Node->name, "\n")] = '\0';// Remove trailing newline
/*************************************************************************************************/
            printf("Date of Birth: ");
            fgets(current_Node->Birth, sizeof(current_Node->Birth), stdin);
            current_Node->Birth[strcspn(current_Node->Birth, "\n")] = '\0';// Remove trailing newline
/*************************************************************************************************/
            printf("Address: ");
            fgets(current_Node->address, sizeof(current_Node->address), stdin);
            current_Node->address[strcspn(current_Node->address, "\n")] = '\0';// Remove trailing newline
/*************************************************************************************************/
            printf("Phone number: ");
            fgets(current_Node->phone, sizeof(current_Node->phone), stdin);
            current_Node->phone[strcspn(current_Node->phone, "\n")] = '\0';// Remove trailing newline
/*************************************************************************************************/
            printf("Student account with ID '%s' updated successfully.\n", Local_ID);
            return;
        }
        current_Node = current_Node->next;
    }
    printf("No student account found with ID '%s'. Update failed.\n", Local_ID);
}
/**
  * @brief Function to rank students by computer science score
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void RANK_STUDENT(School_t* school) 
{
    if (school->head == NULL)
    {
        printf("No students found. Cannot rank.\n");
        return;
    }
    u8 num_students = 0;
    u8 Iterator = 0;
    u8 Iterator_1=0;
    u8 Iterator_2 = 0;
    u8 Print_Iterator = 0; 
    // Convert the linked list to an array for sorting
   Student_t* current_Node = school->head;
    while (current_Node != NULL) 
    {
        num_students++;
        current_Node = current_Node->next;
    }
    // Create an array of pointers to Student_t structure
    Student_t** studentsArr = (Student_t**)malloc(num_students * sizeof(Student_t*));
    if (studentsArr == NULL) 
    {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    // Populate the array with pointers to each student
    current_Node = school->head;
    for (Iterator = 0; Iterator < num_students; Iterator++) 
    {
        studentsArr[Iterator] = current_Node;
        current_Node = current_Node->next;
    }
    // Perform Bubble Sort on the array based on cs_score
    for (Iterator_1 = 0; Iterator_1 < num_students - 1; Iterator_1++) 
    {
        for (Iterator_2 = 0; Iterator_2 < num_students - Iterator_1 - 1; Iterator_2++) 
        {
            if (studentsArr[Iterator_2]->cs_score < studentsArr[Iterator_2 + 1]->cs_score) 
            {
                // Swap the pointers if the current element's cs_score is less than the next element's cs_score
                Student_t* temp = studentsArr[Iterator_2];
                studentsArr[Iterator_2] = studentsArr[Iterator_2 + 1];
                studentsArr[Iterator_2 + 1] = temp;
            }
        }
    }
    printf("\nRanked Students (by CS score):\n");
    printf("------------------------------------------------------\n");
    printf("Rank | Name                   | ID          | CS Score\n");
    printf("------------------------------------------------------\n");
    for (Print_Iterator = 0; Print_Iterator < num_students; Print_Iterator++) 
    {
     printf("%-4d | %-22s | %-11s | %-8d\n", Print_Iterator + 1, studentsArr[Print_Iterator]->name, studentsArr[Print_Iterator]->ID, studentsArr[Print_Iterator]->cs_score);
    }
    free(studentsArr);
}
/**
  * @brief Function to update computer science scores for all students
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void STUDENT_SCORE(School_t* school) 
{
    if (school->head == NULL) {
        printf("No students found. Cannot update scores.\n");
        return;
    }

    printf("\nEnter computer science scores for all students:\n");

    Student_t* current_Node = school->head;
    while (current_Node != NULL) 
    {
        printf("Enter CS score for Student ID ( %s ) : ",current_Node->ID);
        scanf("%d", &current_Node->cs_score);
        current_Node = current_Node->next;
    }

    printf("Computer science scores updated successfully.\n");
}
/**
  * @brief Function to Count a Number of Students in School
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void SIZE_SCHOOL(School_t* school)
{
    u8 count = 0;
    Student_t* current_Node = school->head;
    while (current_Node != NULL) 
    {
        count++;
        current_Node = current_Node->next;
    }
   printf("\n===================================================\n");
   printf("Number of students in the school is : %d\n", count);
   printf("===================================================\n");
}
/**
  * @brief Function to free the memory used by the linked list
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void freeStudentList(School_t* school) 
{
    Student_t* current_Node = school->head;
    Student_t* next;
    while (current_Node != NULL) 
    {
        next = current_Node->next;
        free(current_Node);
        current_Node = next;
    }
}