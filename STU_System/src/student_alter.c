#include<stdio.h>
#include"student_alter.h"
#include"data.h"
//#include<string.h>

int student_alter(int *P_existing_student)
{
    int temp = 0;
    printf("请输入对应学生的学号：");
    while (scanf("%d", &temp) != 1) {
        printf("不能输入字母！\n请重新输入：");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');          // 清掉学号行残留

    int found = 0;
    for (int i = 0; i < *P_existing_student; i++) {
        if (temp == undergrad[i].ID) {
            found = 1;
            printf("请输入正确成绩：");
            while (scanf("%d", &undergrad[i].exam_scores) != 1
                   || undergrad[i].exam_scores < 0
                   || undergrad[i].exam_scores > 100) {
                printf("输入错误（字母或超出 0~100）！\n请重新输入：");
                while (getchar() != '\n');
            }
            break;
        }
    }

    if (found) printf("修改成功！\n");
    else       printf("未找到该学号！\n");

    return 1;
}

// int student_alter(int *P_existing_student)
// {
//     int temp = 0;
//     printf("请输入对应学生的学号：");

//     while (scanf("%d",&temp) != 1)
//     {
//         printf("不能输入字母！\n请输重新入：");
//         while (getchar() != '\n');
//     }
    
//     for (int i = 0; i < *P_existing_student; i++)
//     {
//         if(temp == undergrad[i].ID)
//         {
//             printf("请输入正确成绩：");
//             while (scanf("%d",&undergrad[i].exam_scores) != 1 || undergrad[i].exam_scores <= 100 || undergrad[i].exam_scores >= 0)
//             {
//                 printf("不能输入字母或者输入不能超过范围！\n请输重新入：");
//                 while (getchar() != '\n');
//             }
//         }
//     }
//     printf("修改成功！\n");
    
//     return 1;
// }