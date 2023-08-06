/****************************************************/
/*   AUTHOR      : Ahmed Osama Metwally Azzap       */
/*   Description : School Managemnet System         */
/*   DATE        : 30/7/2023                        */
/*   FILE        : main.c                           */
/****************************************************/
#include "School.h"
int main()
{
    School_t school;
    initializeSchool(&school);
    MAIN_MENU(&school);
    return 0;
}
