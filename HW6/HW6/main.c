//
//  main.c
//  HW6
//
//  Created by Thomas on 4/3/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int crawlDirectory(char *contains_string, char *current_path, int counter);


int main(int argc, const char * argv[])
{
    
    char *curr_path = argv[1];
    char *user_string = argv[2];
    int counter = 0;
    counter = crawlDirectory(user_string, curr_path, counter);
    printf("%d matching files in all \n", counter);
    return 0;
}


int crawlDirectory(char *contains_string, char *current_path, int counter){
    
    DIR *current_directory = opendir(current_path);
    if (current_directory == NULL) return 0;
    
    int sub_counter = 0;
    struct stat fst;
    struct dirent *dentry = readdir(current_directory);
    char path[1024];
    strcat(path, current_path);
    strcat(path, "/");
    stat(dentry->d_name, &fst);
    
    while (dentry) {
        
        char *string_inside_directory = strstr(dentry->d_name, contains_string);
        if(string_inside_directory){
            printf("%s%s \n",path, dentry->d_name);
            counter++;
        }
        
        if(dentry != NULL){
            if (S_ISDIR(fst.st_mode) != 0 && (dentry->d_name[0] != '.')) {
                strcat(path, dentry->d_name);
                counter += crawlDirectory(contains_string, path, sub_counter);
                strcpy(path, current_path);
                strcat(path, "/");
            }
        }
        dentry = readdir(current_directory);

    }
    
    return counter;
    
}
