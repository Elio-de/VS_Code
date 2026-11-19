#include<stdio.h>
#include"student_io.h"
#include"data.h"

#define BENCHMARK 60
//输入学生信息
int student_input(int *P_existing_student)
{
    // int temp = *P_existing_student;
    // while (1)
    // {
    //     printf("当前要输入的人数：");

    //     if (scanf("%d",&temp) == 1)
    //     {
    //         if (temp + *P_existing_student > STUDENT_COUNT)
    //             {
    //                 printf("当前输入人数超过上限！");
    //                 printf("最多还可输入%d个人",STUDENT_COUNT - temp - *P_existing_student);
    //             }break;
    //     }else printf("不能输入字母！"); 
    // }

/*==================================================================================*/
 
    int temp;
    
    // 1. 前置检查：获取要输入的人数
    while (1)//本循环由AI生成
    {
        printf("请输入当前要录入的人数: ");
        
        // 正确写法：scanf 加 &，且判断返回值是否为 1
        if (scanf("%d", &temp) == 1) 
        {
            // 检查是否超过上限，或者输入了负数
            if (temp + *P_existing_student > STUDENT_COUNT)
            {
                // 你的计算逻辑稍微有点问题，剩余名额应该是 STUDENT_COUNT - 已有人数
                printf("超过上限！当前最多还可输入 %d 个人。\n", STUDENT_COUNT - *P_existing_student);
                continue; // 重新循环，让用户再输一次
            }
            else if (temp <= 0) 
            {
                printf("输入无效，人数必须大于 0！\n");
                continue;
            }
            else 
            {
                break; // 输入合法，且没超限，跳出 while 循环
            }
        }
        else 
        {
            printf("不能输入字母或符号！请重新输入。\n");
            // 【关键】清空输入缓冲区里的脏数据，防止死循环
            while (getchar() != '\n'); 
        }
    }

    // 2. 开始 for 循环，录入具体信息
    for (int i = 0; i < temp; i++)
    {
        // 计算当前应该存入数组的哪个位置
        // 比如：已经存了2个人，这次要存3个，那新录入的第一个应该放在 undergrad[2]
        int current_index = *P_existing_student + i; 

        printf("\n--- 正在录入第 %d 个学生 (总进度 %d/%d) ---\n", i + 1, current_index + 1, STUDENT_COUNT);

        // (1) 录入姓名（字符串）
        printf("请输入姓名: ");
        // 限制长度为 12，给 '\0' 留位置，防止输入太长撑爆数组
        scanf("%12s", undergrad[current_index].name); 

        // (2) 录入学号（防错）
        printf("请输入学号: ");
        while (scanf("%d", &undergrad[current_index].ID) != 1) 
        {
            printf("学号必须是数字，请重新输入: ");
            while (getchar() != '\n'); // 清理错误输入
        }

        // (3) 录入成绩（防错）
        printf("请输入成绩: ");
        while (scanf("%d", &undergrad[current_index].exam_scores) != 1) 
        {
            printf("成绩必须是数字，请重新输入: ");
            while (getchar() != '\n'); // 清理错误输入
        }
    }

    // 3. 更新总人数（非常重要！）
    // 录入完成后，把指针指向的值加上这次录入的人数
    *P_existing_student += temp; 
    
    printf("\n成功录入 %d 名学生！\n", temp);
    return 1; // 返回 1 表示录入成功
    

}

int student_print(int *P_existing_student)
{
    printf("当前总共%d个人。\n",*P_existing_student);
    
    int i = 0;
    float num = 0;
    
    for ( i = 0; i < *P_existing_student; i++)
    {
        num += (float)undergrad[i].exam_scores;
    }
    printf("平均成绩为：%.2f分\n",num / (float)*P_existing_student);

    int student_benchmark = 0;
    for ( i = 0; i < *P_existing_student; i++)
    {
        if (undergrad[i].exam_scores >= BENCHMARK)
        {
            student_benchmark++;
        } 
    }
    printf("共%d个人及格。\n",student_benchmark);
    

    return 2;
}