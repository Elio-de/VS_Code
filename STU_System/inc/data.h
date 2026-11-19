#ifndef DATA_H
#define DATA_H

#define STUDENT_COUNT 50

struct user_data
{
    char name[13];
    int ID;
    int exam_scores;
};

// 注意：这里改成了 extern（声明），不再实际分配内存
extern struct user_data undergrad[STUDENT_COUNT];

#endif