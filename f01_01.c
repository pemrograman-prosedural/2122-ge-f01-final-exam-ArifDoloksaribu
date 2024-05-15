// 12S23026 - Arif M. Doloksaribu
// 12S23051 - Theresia Silaban


#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include <stdlib.h>
#include <string.h>

int main(int _argc, char **_argv)
{
    struct dorm_t *dorm = malloc(1000 * sizeof(struct dorm_t));
    struct student_t *student = malloc(1000 * sizeof(struct student_t));
    int i = 0;

    char masukan[100], *argument, *token;
    int h = 0;
    int idn;
    int hdn;

    while (1) {
        fgets(masukan, 100, stdin);
        masukan[strcspn(masukan, "\n")] = 0;
        if (strcmp(masukan, "---") == 0) {
            break;
        } else if (strcmp(masukan, "dorm-print-all") == 0) {
            print_dorms(dorm, h);
            continue;
        }
        else if(strcmp(masukan, "dorm-print-all-detail")==0){
            dorm_print_all_detail(dorm, h);
        }
        else if (strcmp(masukan, "student-print-all") == 0) {
            print_stu(student, i);
            continue;
        }
        else if(strcmp(masukan, "student-print-all-detail")==0){
            student_print_all_detail(student, i);
            continue;
        }    
        argument = strtok(masukan, "#");
        if (strcmp(argument, "dorm-add") == 0) {
            token = strtok(NULL, "#");
            strcpy(dorm[h].name, token);
            token = strtok(NULL, "#");
            dorm[h].capacity = atoi(token);
            token = strtok(NULL, "#");
            if (strcmp(token, "male") == 0) {
                dorm[h].gender = GENDER_MALE;
            } else {
                dorm[h].gender = GENDER_FEMALE;
            }
            
            dorm[h] = create_dorm(dorm[h].name, dorm[h].capacity, dorm[h].gender);

            h++;
        }
        else if (strcmp(argument, "student-add") == 0){
            token = strtok(NULL, "#");
            strcpy(student[i].id, token);
            token = strtok(NULL, "#");
            strcpy(student[i].name, token);
            token = strtok(NULL, "#");
            strcpy(student[i].year, token);
            token = strtok(NULL, "#");
            if (strcmp(token, "male") == 0) {
                 student[i].gender = GENDER_MALE;
            } else {
                student[i].gender = GENDER_FEMALE;
            }
             student[i] = create_student(student[i].id, student[i].name, student[i].year, student[i].gender);

            i++;
        }   
        else if(strcmp(argument,"assign-student")==0){
            int x, y; 
            int z; 
            token = strtok(NULL, "#");
            char student_id[20];
            strcpy(student_id, token);

            for(x = 0; x < i; x++){
                if(strcmp(student[x].id, student_id) == 0){
                    y = x;
                    break;
                }
            }

            if(x == i){
                continue;
            }

            token = strtok(NULL, "#");
            char dorm_name[20];
            strcpy(dorm_name, token);

            for(x = 0; x < h; x++){
                if(strcmp(dorm[x].name, dorm_name) == 0){
                    z = x;
                    break;
                }
            }

            if(x == h){
                continue;
            }

            assign_student(&student[y], y, &dorm[z], z);
        }
                
        else if(strcmp(argument,"move-student")==0){
            int x, y, w;
            token = strtok(NULL, "#");
            char student_id[20];
            strcpy(student_id, token);

            for(x = 0; x < i; x++){
                if(strcmp(student[x].id, student_id) == 0){
                    y = x;
                    break;
                }
            }

            if(x == i){
                continue;
            }

            token = strtok(NULL, "#");
            char dorm_name[20];
            strcpy(dorm_name, token);

            for(x = 0; x < h; x++){
                if(strcmp(dorm[x].name, dorm_name) == 0){
                    w = x;
                    break;
                }
            }

            if(w == h){ 
                continue;
            }
            
            if(student[y].dorm == NULL){
                assign_student(&student[y], y, &dorm[w], w); 
            }
            else{
                if(strcmp(student[y].dorm->name, dorm[w].name) != 0){
                    move_student(&student[y], y, &dorm[w], w); 
                }
            }
        }
            else if(strcmp(argument, "student-leave")==0){
                char id[20];
                token = strtok(NULL,"#");
                strcpy(id,token);
                for(int k=0; k<i; k++){
                    if(strcmp(student[k].id, id)==0){
                        idn = k;
                        break;
                    }
                }
                if (idn == i){
                    continue;
                }

                for(int u=0; u<h; u++){
                    if(strcmp(dorm[u].name, dorm[h].name)==0){
                        hdn = u;
                        break;
                    }
                }
                if(hdn == h){
                    continue;
                }
                student_leave(&student[idn], &dorm[hdn]);
            }
    }
    free(student);
    free(dorm);
    return 0;
}