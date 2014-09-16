
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  JiDan                                                                */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/16                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by JiDan, 2014/09/16
 *
 */



#include<stdio.h>
#include<stdlib.h>

int Help();

#define DESC_LEN 1024
#define CMD_NUM 10
#define CMD_MAX_LEN 128

typedef struct DataNode
{
    char*     cmd;
    char*     desc; 
    int       (*handler)();
    struct    DataNode *next;
} tDataNode;

static tDataNode head[] = 
{
    {"help", "this is help cmd", Help, &head[1]},
    {"version", "meunu program v1", NULL, &head[2]},
    {"jidan", "this is JiDan's software test", NULL, &head[3]}
    {"end", "over", NULL, NULL}
};

main()
{                                                                                   
    /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd > ");
        scanf("%s", cmd);
        tDataNode *p = head;
        while(p != NULL) 
        {
            if(!strcmp(p->cmd, cmd))
            {
                printf("%s - %s\n", p->cmd, p->desc);
                if(p->handler !=NULL)
                {
                    p->handler();
                }
                break;
            }
            p = p->next;
        }
        if(p == NULL)
        {
            printf("This is a wrong cmd!\n ");
        }
    }
} 

int Help()
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p != NULL) 
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}
