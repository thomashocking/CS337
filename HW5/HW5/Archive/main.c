//
//  main.c
//  HW5
//
//  Created by Thomas on 3/25/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *title;
    char *year;
    char *length;
}dvd;

void record_info(dvd*[], FILE *);
void write_info(dvd*[], FILE *);
void free_dvds(dvd*[]);
void print_dvds_from_file(dvd*[], FILE *);

int main(int argc, const char * argv[])
{
    const int SIZE = 1024;
    dvd *listOfDvds[SIZE];
    FILE *dvdFile = fopen(argv[1], "r");
    if(!dvdFile){
        printf("Cannot read file!\n");
    }else{
        FILE *dvdWriteFile = fopen(argv[2], "w");
        if (!dvdWriteFile) {
            printf("Cannot read output file!\n");
        }else{
            int i;
            for (i = 0; i < SIZE; i++) {
                listOfDvds[i] = NULL;
            }
    
            record_info(listOfDvds, dvdFile);
            fclose(dvdFile);
            write_info(listOfDvds, dvdWriteFile);
            fclose(dvdWriteFile);
            free_dvds(listOfDvds);
        
            dvdWriteFile = fopen(argv[2], "r");
            print_dvds_from_file(listOfDvds, dvdWriteFile);
        }
    }
    return 0;
}

void record_info(dvd *list[], FILE *dvdFile){
        int listCounter = 0;
        char line[100];
        while (!feof(dvdFile)) {
            list[listCounter] = (dvd*)malloc(sizeof(dvd));
            int i;
            for (i = 0; i < 3; i++) {
                fgets(line, 100, dvdFile);
                if(i==0) list[listCounter]->title = strdup(line);
                else if(i==1) list[listCounter]->year = strdup(line);
                else list[listCounter]->length = strdup(line);
            }
            fgets(line, 100, dvdFile);
            listCounter++;
        }
}

void write_info(dvd *list[], FILE *dvdWriteFile){
    dvd *curr = list[0];
    int counter = 0;
    while (curr != NULL) {
        int i;
        for (i = 0; i < 3; i++) {
            if(i==0){
                char label[100] = "Movie Title: ";
                strcat(label, curr->title);
                fwrite(label, sizeof(char), strlen(label+1), dvdWriteFile);
                fwrite("\n", sizeof(char), 1, dvdWriteFile);
            }
            else if(i == 1) {
                char label[100] = "Year of Movie: ";
                strcat(label, curr->year);
                fwrite(label, sizeof(char), strlen(label + 1), dvdWriteFile);
                fwrite("\n", sizeof(char), 1, dvdWriteFile);
            }
            else{
                char label[100] = "Length of Movie: ";
                strcat(label, curr->length);
                fwrite(label, sizeof(char), strlen(label + 1), dvdWriteFile);
                fwrite("\n", sizeof(char), 1, dvdWriteFile);
            }
        }
        fwrite("\n", sizeof(char), 1, dvdWriteFile);
        curr = list[++counter];
    }
    fwrite("\0", sizeof(char), 1, dvdWriteFile);
}

void free_dvds(dvd *list[]){
    dvd *curr = list[0];
    int counter = 0;
    while (curr != NULL) {
        free(curr->title);
        free(curr->year);
        free(curr->length);
        curr = list[++counter];
    }
    
    int dvd_counter = 0;
    while (list[dvd_counter] != NULL) {
        list[dvd_counter] = NULL;
        counter++;
    }
}

void print_dvds_from_file(dvd*list[], FILE *dvdWriteFile){
    char file[1024];
    fread(file,sizeof(char),1024,dvdWriteFile);
    
    //clean up output.
    int i;
    for (i = 0; i<1024; i++) {
        if (file[i] == '\0') break;
    }
  
    int j;
    for (j = i; j < 1024; j++) {
        file[j] = '\0';
    }
    
    printf("%s", file);
  
}