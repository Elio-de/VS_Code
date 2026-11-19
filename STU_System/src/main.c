#include<stdio.h>
#include"data.h"
#include"Menu.h"



struct user_data undergrad[STUDENT_COUNT];

int main(void)
{
    int existing_student = 0 ,  *P_existing_student = &existing_student;

    Menu(P_existing_student);

    

    return 0;
}