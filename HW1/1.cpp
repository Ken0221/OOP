//#include<iostream>
#include<stdio.h>
#include<string.h>

struct strecord{
    char name[20];
    char id[7];
    int chinese;
    int english;
    int math;
    int total;
} typedef Student;

void input(strecord &st){
    printf("input name: ");
    scanf("%s", st.name);
    printf("input id:   ");
    scanf("%s", st.id);
    printf("chinese:    ");
    scanf("%d", &st.chinese);
    printf("english:    ");
    scanf("%d", &st.english);
    printf("math:       ");
    scanf("%d", &st.math);
    st.total = st.chinese + st.english + st.math;
    return;
}

void sort(strecord list[], int size){ 
    // total -> chinese -> english -> math -> id
    for(int i_t = 0; i_t < size; i_t++){
        for(int j_t = i_t + 1; j_t < size; j_t++){
            if(list[i_t].total > list[j_t].total){
                Student temp = list[i_t];
                list[i_t] = list[j_t];
                list[j_t] = temp;
            }
            else if(list[i_t].total == list[j_t].total){
                for(int i_c = i_t; i_c < size; i_c++){
                    for(int j_c = i_c + 1; j_c < size; j_c++){
                        if(list[i_c].chinese > list[j_c].chinese){
                            Student temp = list[i_c];
                            list[i_c] = list[j_c];
                            list[j_c] = temp;
                        }
                        else if(list[i_c].chinese == list[j_c].chinese){
                            for(int i_e = i_c; i_e < size; i_e++){
                                for(int j_e = i_e + 1; j_e < size; j_e++){
                                    if(list[i_e].english > list[j_e].english){
                                        Student temp = list[i_e];
                                        list[i_e] = list[j_e];
                                        list[j_e] = temp;
                                    }
                                    else if(list[i_e].english == list[j_e].english){
                                        for(int i_m = i_e; i_m < size; i_m++){
                                            for(int j_m = i_m + 1; j_m < size; j_m++){
                                                if(list[i_m].math > list[j_m].math){
                                                    Student temp = list[i_m];
                                                    list[i_m] = list[j_m];
                                                    list[j_m] = temp;
                                                }
                                                else if(list[i_m].math == list[j_m].math){
                                                    for(int i_id = i_m; i_id < size; i_id++){
                                                        for(int j_id = i_id + 1; j_id < size; j_id++){
                                                            if(strcmp(list[i_id].id, list[j_id].id) > 0){
                                                                Student temp = list[i_id];
                                                                list[i_id] = list[j_id];
                                                                list[j_id] = temp;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    const int MAX_NUM_STUDENT = 100;
    int num;
    //std::cin >> num;
    printf("numbers of data: ");
    scanf("%d", &num);
    if(num <= MAX_NUM_STUDENT){
        Student student[num];
        for(int i = 0; i < num; i++){
            printf("\n");
            input(student[i]);
        }
        sort(student, num);
        printf("               name    id   chinese   english      math     total\n");
        for(int i = 0; i < num; i++){
            printf("               %4s    %2s       %3d       %3d       %3d       %3d\n", student[i].name, student[i].id, student[i].chinese, student[i].english, student[i].math, student[i].total);
        }
    }
    
    return 0;
}
