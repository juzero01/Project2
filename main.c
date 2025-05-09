#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}
//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    if (stat("text1", &stat1) == -1) {
        perror("파일 'text1'을 찾을 수 없습니다"); // 에러 메시지 출력
        return;
    }
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    if (stat("text2", &stat2) == -1) {
        perror("파일 'text2'을 찾을 수 없습니다"); // 에러 메시지 출력
        return;
    }
}
//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){      
    struct tm* temp = localtime(&stat1.st_mtime);// 마지막 수정 시간 → 로컬 시간(time1) 저장  
    if (temp == NULL) {
        perror("localtime() 변환 실패");
        return;
    }
    time1 = temp;

}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    struct tm* temp = localtime(&stat2.st_mtime);// 마지막 수정 시간 → 로컬 시간(time2) 저장
    if (temp == NULL) {
        perror("localtime() 변환 실패");
        return;
    }
    time2 = temp;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp() {
    if (stat1.st_size > stat2.st_size)
        printf("size compare\ntext1 is bigger\n\n");
    else if (stat1.st_size < stat2.st_size)
        printf("size compare\ntext2 is bigger\n\n");
    else
        printf("size compare\nsizes are equal\n\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    printf("date compare\n");
    char *file1 = "text1";
    char *file2 = "text2";
    
    if (time1->tm_year != time2->tm_year)
        printf("%s is newer\n", time1->tm_year > time2->tm_year ? file1 : file2);
    else if (time1->tm_mon != time2->tm_mon)
        printf("%s is newer\n", time1->tm_mon > time2->tm_mon ? file1 : file2);
    else if (time1->tm_mday != time2->tm_mday)
        printf("%s is newer\n", time1->tm_mday > time2->tm_mday ? file1 : file2);
    else
        printf("dates are equal\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    printf("time compare\n");
    char *file1 = "text1";
    char *file2 = "text2";
    
    if (time1->tm_hour != time2->tm_hour)
        printf("%s is newer\n", time1->tm_hour > time2->tm_hour ? file1 : file2);
    else if (time1->tm_min != time2->tm_min)
        printf("%s is newer\n", time1->tm_min > time2->tm_min ? file1 : file2);
    else if (time1->tm_sec != time2->tm_sec)
        printf("%s is newer\n", time1->tm_sec > time2->tm_sec ? file1 : file2);
    else
        printf("times are equal\n");
}
