/****************************************************/
/*   AUTHOR      : Ahmed Osama Metwally Azzap       */
/*   Description : School Managemnet System         */
/*   DATE        : 31/8/2023                        */
/*   FILE        : School.h                         */
/****************************************************/
#ifndef _SCHOOL_H
#define _SCHOOL_H
#include "Std_Types.h"
// Define the structure for a student record
typedef struct Student 
{
    u8 name   [50];
    u8 Birth  [20];
    u8 ID     [15];
    u8 address[100];
    u8 phone  [15];
    u8 cs_score;
   struct Student* next;
}Student_t;

typedef struct School 
{
    Student_t* head;
} School_t;

void initializeSchool (School_t* school) ;
/**
  * @brief  Function to display the main menu and handle user input
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void MAIN_MENU        (School_t* school);
/**
  * @brief  Function to create a new student account
  * @param  school which is a pointer to a School_t struct
  * @retval Return a pointer to struct that been created
  */
Student_t* NEW_STUDENT(School_t* school);
/**
  * @brief  Function to delete a student account
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void DELETE_STUDENT   (School_t* school);
/**
  * @brief  Function to view the list of students
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void STUDENT_LIST     (School_t* school);
/**
  * @brief Function to update a particular student account
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void STUDENT_EDIT     (School_t* school);
/**
  * @brief Function to rank students by computer science score
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void RANK_STUDENT     (School_t* school);
/**
  * @brief Function to update computer science scores for all students
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void STUDENT_SCORE    (School_t* school);
/**
  * @brief Function to Count a Number of Students in School
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void SIZE_SCHOOL(School_t* school);
/**
  * @brief Function to free the memory used by the linked list
  * @param  school which is a pointer to a School_t struct
  * @retval void Doesn't Return any arrguments
  */
void freeStudentList  (School_t* school);

#endif//_SCHOOL_H