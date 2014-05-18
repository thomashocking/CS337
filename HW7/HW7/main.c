//
//  main.c
//  HW7
//
//  Created by Thomas on 4/11/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


void run(char * command);

int main(int argc, const char * argv[])
{
    char input[256];
    
    printf("?: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

    while (strcmp(input, "exit") != 0) {
        fseek(stdin,0,SEEK_END);
        printf("?: ");


        if (strcmp(input, "exit") != 0){
            run(input);
        }
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

    }
    
    return 0;
}


void run(char *command){
    //parse command.
    
    char *sub_commands[16];
    int i = 0;
    while (i < 16) {
        sub_commands[i] = NULL;
        i++;
    }
    
    char *token = strtok(command, " ");
    int index = 0;
    while (token != NULL) {
        sub_commands[index] = token;
        index++;
        token = strtok(NULL, " ");
    }
    
    i = 0;
    int has_output = 0;
    int command_number_for_path = 0;
    int index_of_command;
    int save_fd = dup(0);
    
    if (strcmp(sub_commands[0], "multi") == 0) {
        //check if output differs.
        while (sub_commands[i] != NULL) {
            if (strcmp(sub_commands[i], "output") == 0) {
                    //check for output.
                    //flag
                    has_output = 1;
                    command_number_for_path = i + 1;
                    index_of_command = i;
                    sub_commands[i] = NULL;
                 }
                 i++;
            }
        
        if (has_output==1) {
            close(1);
            open(sub_commands[command_number_for_path], O_WRONLY|O_TRUNC|O_CREAT, 0644);
        }
        
        FILE *input = fopen(sub_commands[1], "r");
        if (!input) {
            printf("Error opening file...\n");
        }else{
            char command_multi[128];
            while (fgets(command_multi, 128, input) != NULL) {
                
                int i = 0;
                while (i < 16) {
                    sub_commands[i] = NULL;
                    i++;
                }
                
                command_multi[strlen(command_multi) - 1] = '\0';
                char *token = strtok(command_multi, " ");
                int index = 0;
                while (token != NULL) {
                    sub_commands[index] = token;
                    index++;
                    token = strtok(NULL, " ");
                }
           
                pid_t pid = fork();
                if (pid == 0) {
                    execvp(sub_commands[0], sub_commands);
                }else{
                    wait(&pid);
                }
            }
            close(1);
            dup(save_fd);
        }
    }else{
        while (sub_commands[i] != NULL) {
            if (strcmp(sub_commands[i], "output") == 0) {
                //check for output.
                //flag
                has_output = 1;
                command_number_for_path = i + 1;
                index_of_command = i;
                sub_commands[i] = NULL;
            }
            i++;
        }
        
        if (has_output==1) {
            save_fd = dup(0);
            close(1);
            open(sub_commands[command_number_for_path], O_WRONLY|O_TRUNC|O_CREAT, 0644);
        }
        
        
        if (fork() == 0) {
            execvp(sub_commands[0], sub_commands);
        }else{
            wait(0);
            fseek(stdin,0,SEEK_END);
            if (has_output) {
                close(1);
                dup(save_fd);
            }
        }
    }

}
