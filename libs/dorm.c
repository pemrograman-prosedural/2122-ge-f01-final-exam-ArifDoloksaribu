#include "dorm.h"
#include "student.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender){
    struct dorm_t dorm;
    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.gender = _gender;
    dorm.residents_num = 0;
    return dorm;
    }

void print_dorms(struct dorm_t *_dorm, int size){
      for(int a=0; a<size; a++){
        if(_dorm[a].gender == GENDER_MALE){
            printf("%s|%d|male\n", _dorm[a].name, _dorm[a].capacity);
        }
        else if(_dorm[a].gender == GENDER_FEMALE){
            printf("%s|%d|female\n", _dorm[a].name, _dorm[a].capacity);
        }         
    }
}

void dorm_print_all_detail(struct dorm_t *_dorm, int size){
    for(int a=0; a<size; a++){
        if(_dorm[a].gender == GENDER_MALE){
        printf("%s|%d|male|%d\n", _dorm[a].name, _dorm[a].capacity, _dorm[a].residents_num);
        }
        else{
            printf("%s|%d|female|%d\n", _dorm[a].name, _dorm[a].capacity, _dorm[a].residents_num);
            }
    }
}