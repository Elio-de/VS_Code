#include<stdio.h>
#include"Menu.h"
#include"student_io.h"
#include"student_alter.h"

int Menu(int *P_existing_student)
{
    while (1)
    {
        printf
        (
        "======================\n"
        "      学生管理系统\n"
        "======================\n"
        "1.输入学生信息\n"
        "2.显示统计信息\n"
        "3.修改学生信息\n"
        "0.退出管理系统\n"
        "======================\n"
        "请输入你想选择操作的对应代码："
        //"\n"
        );
        
        int code = 0;
        scanf("%d",&code);

        switch (code)
        {
        case 1:
            student_input(P_existing_student);
            break;
        
        case 2:
            student_print(P_existing_student);
            break;

        case 3:
            student_alter(P_existing_student);
            break;

        case 0:
            printf("程序即将结束……\n");
            return 0;
            
        default:
            printf("输入无效!\n");
            break;
        } 
    }
}