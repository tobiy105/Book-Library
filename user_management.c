#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_management.h"


int user_register(char *username, char *password, unsigned int type) {

  FILE * file;
  char str[50];
  char * token;
  token = (char * ) malloc(20 * sizeof(char));
  file = fopen("users.txt", "a+");
  if (file == NULL) {
    printf("Unable to create file.\n");
    fclose(file);
    return -1;
  }
  while (fgets(str, sizeof(str), file) != NULL) {
    token = strtok(str, " ");
    if (strcmp(username, token) == 0) {
      printf("This username is registered already. Try a different username.\n");
      fclose(file);
      return -1;
    }

  }
  file = fopen("users.txt", "a+");

  fprintf(file, "%s %s %d\n", username, password, type);
  fclose(file);

  return 0;
}



int login(char *username, char *password) {

  FILE * file;
  char str[50];
  char * savedusername;
  char * savedpassword;
  char * token;
  token = (char * ) malloc(20 * sizeof(char));
  savedusername = (char * ) malloc(20 * sizeof(char));
  savedpassword = (char * ) malloc(20 * sizeof(char));

  file = fopen("users.txt", "r");
  if (file == NULL) {
    printf("Unable to create file.\n");
    fclose(file);
    return -2;
  }
  while (fgets(str, sizeof(str), file) != NULL) {
    token = strtok(str, " ");
    if (strcmp(username, token) == 0) {
      token = strtok(NULL, " ");
      if (strcmp(password, token) == 0) {
        token = strtok(NULL, " ");
        printf(token);
        
        if (strcmp("1\n", token) == 0){
            printf("Librarian login succesful!\n");
            fclose(file);
            return 1; 
        }  
        if (strcmp("0\n", token) == 0){
            printf("Login succesful!\n");
            fclose(file);
            return 0; 
        }  
      }
    }
  }
  fclose(file);
  printf("Error, please user a correct username and password!\n");
  return -1;
}


