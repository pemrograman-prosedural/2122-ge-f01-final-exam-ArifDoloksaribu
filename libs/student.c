#include "student.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender){
    struct student_t students;
        strcpy(students.id, _id);
        strcpy(students.name, _name);
        strcpy(students.year, _year);
        students.gender = _gender;
        students.dorm = NULL; 

        return students;
}

void print_stu(struct student_t *_student, int size){
    for(int a=0; a<size; a++){
        if(_student[a].gender == GENDER_MALE){
            printf("%s|%s|%s|male\n", _student[a].id, _student[a].name, _student[a].year);
        }
        else if(_student[a].gender == GENDER_FEMALE){
            printf("%s|%s|%s|female\n", _student[a].id, _student[a].name, _student[a].year);
        }         
    }
}

void student_print_all_detail(struct student_t *_student, int size){
    int a = 0;
    for(a=0; a<size; a++){
       if(_student[a].dorm == NULL){
           if(_student[a].gender == GENDER_MALE){
             printf("%s|%s|%s|male|left\n", _student[a].id, _student[a].name, _student[a].year);
           }
           else if(_student[a].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|left\n", _student[a].id, _student[a].name, _student[a].year);
           }

        }
        else{
            if(_student[a].gender == GENDER_MALE){
                printf("%s|%s|%s|male|%s\n", _student[a].id, _student[a].name, _student[a].year, _student[a].dorm->name);
            }
            else if(_student[a].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|%s\n", _student[a].id, _student[a].name, _student[a].year, _student[a].dorm->name);
            }
            }
        }
}

void assign_student(struct student_t *_student, int size, struct dorm_t *_dorm, int size_dorm){
   if(_dorm->residents_num < _dorm->capacity){
    if(_student->gender == _dorm->gender){
     _student->dorm = _dorm;
        _dorm->residents_num++;   
    }
   }
}

void move_student(struct student_t *_student, int size, struct dorm_t *_dorm, int size_dorm)
{
    if (_student->dorm != NULL) {
        _student->dorm->residents_num--;
        _student->dorm = NULL;
    }

    if (_dorm->residents_num < _dorm->capacity) {
        if (_student->gender == _dorm->gender) {
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}

void student_leave(struct student_t *_student, struct dorm_t *dorm){
        _student->dorm = NULL;
        dorm->residents_num--;
}


