/* [평가 항목1] : 과제 설명

  컴퓨터프로그래밍 평가과제 (배점 25점)
  학과 : 컴퓨터공학부
  학번 : 202200240
  이름 : 강지민

  과제 주제 : 코로나 지역별 확진자 수 및 현황 (6월 9일 기준)

*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define REGIONS 8 
#define SIZE 8               //[평가 항목5] : 구조체 사용
#define SIZE2 4

void Output(void);

struct covid {
    char area[20];
    int people;
};

struct covid19 {                             //[평가 항목7] : 파일 입출력 사용
    int number; //거리두기 단계
    char stage; // 단계 별 방안
};

void print_stars() //[평가 항목 2] : 배열 사용
{
    for (int i = 0; i < 30; i++)
        printf("*");
}

void menu()
{
    Output();
    printf("출력이 끝났습니다.\n");
    exit;
}

int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int mul(int x, int y)
{
    return x * y;
}
/*
int div(int x, int y) {
    return x / y;
}
*/


int main(void)
{
    int peoples[REGIONS]; //[평가 항목 3] : 배열 사용
    int sum = 0;
    int i, average;
              //[평가 항목4] : 포인터 사용
    int* p = NULL;
    int choice, result, x, y;
    struct covid19 s;
    FILE* fp = NULL;
    int k;
    int seoul = 4948774, gyeonggi, incheon;

    print_stars();
    printf("\n코로나 확진자 현황 및 확진자수\n");
    print_stars();
    printf("\n");
    //return 0;

    for (i = 0; i < REGIONS; i++)
    {
        printf("지역별 확진자 수를 입력하시오(2022년 6월 10일 기준):");
        scanf_s("%d", &peoples[i]);
    }

    for (i = 0; i < REGIONS; i++)
        sum += peoples[i];
    average = sum / REGIONS;
    printf("평균 확진자 수 = %d\n", average);

    //return 0;
    p = &seoul;
    printf("seoul = %d\n", *p);


    printf("서울의 확진자 수 = %d\n", seoul);

    //return 0;

    struct covid list[SIZE];
    
    char imsi[10];
    for (int j = 0; j < SIZE; j++)
    {
        printf("확진자 현황을 알고 싶은 지역을 입력하시오:");
        scanf("%s", &imsi);
        strcpy(list[j].area, imsi);
        printf("확진자 수를 입력 하시오:");
        scanf("%d", &list[j].people);
    }
    for (int j = 0; j < SIZE; j++)
        printf("지역: %s, 확진자: %d\n", list[j].area, list[j].people);

    //return 0;

    printf("====================\n");
    printf("0. 덧셈\n");
    printf("1. 뺄셈\n");
    printf("2. 곱셈\n");
    printf("3. 나눗셈\n");
    printf("4. 종료\n");
    printf("====================\n");

    int (*pf[3])(int, int) = { add, sub, mul};

    while (1)
    {
        printf("메뉴를 선택하십시오:");
        scanf_s("%d", &choice);

        if (choice < 0 || choice >= 4)
            break;

        printf("두 지역의 확진자 수를 입력하시오:");
        scanf_s("%d %d", &x, &y);

        result = pf[choice](x, y);

        printf("연산 결과 = %d\n", result);
    }

    struct covid19 table[SIZE2] = {
       {1,"집합금지 없음, 운영시간 제한 없음, 1차이상 접종자는 실외 다중이용시설 인원 제한에서 제외, 방역수칙을 준수하면서 사적모임 가능,사전예약제 운영을 권고하며, 관람석 내 음식물 섭취 금지 및 지정장소 섭취 허용, 함성‧응원 금지"},
       {2,"집합금지 없음,명까지 사적모임 가능 ,참여인원이 100명 이상인 행사 및 집회 금지,사전예약제 운영을 권고하며, 관람석 내 음식물 섭취 금지 및 지정장소 섭취 허용, 함성‧응원 금지,정규 종교활동 시 수용인원의 30%,직장근무) 300인 이상 사업장(제조업 제외) 시차 출퇴근제, 점심시간 시차제, 재택근무 10% 권고"},
       {3,"집합금지 없음, 시설면적 8㎡당 1명(기본)으로 인원 제한,4명까지 사적모임 가능 (5인 이상 사적모임 금지),상견례의 경우 8인까지 예외적 허용,참여인원이 50명 이상인 행사 및 집회 금지,정규 종교활동 시 수용인원의 20%(좌석 세 칸 띄우기),PCR 검사는 예방접종완료 또는 1차 접종 증명으로 대체 가능"},
       {4,"1그룹 시설 집합금지,시설면적 8㎡당 1명(기본)으로 인원 제한,다중이용시설 2~3그룹 시설 22시 이후 운영 제한,18시 이후 2명까지 사적모임 가능 (3인 이상 사적모임 금지),18시 이전에는 3단계 조치와 동일하게 4인까지 사적모임 가능,행사 금지 및 1인 시위 외 집회 금지, 전체 수용인원의 10% 범위 내, 최대 99명 가능, 모임/행사‧식사‧숙박 금지"}
    };

    //return 0;
    /*
    if ((fp = fopen_s(&fp, "covid19.dat", "wb")) == NULL)
    {
        fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }
    fwrite(table, sizeof(struct covid19), SIZE2, fp);
    fclose(fp);

    if ((fp = fopen_s(&fp, "covid19.dat", "rb")) == NULL)
    {
        fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }

    for (k = 0; k < SIZE2; k++)
    {
        fread(&s, sizeof(struct covid19), 1, fp);
        printf("거리두기단계 = %d, 단계별방안 = %s\n", s.number, s.stage);
    }
    fclose(fp);
    */

    //return 0;4
    printf("seoul의 확진자 수를 입력하시오:");
    scanf_s("%d", &seoul);
    printf("gyeonggi의 확진자 수를 입력하시오:");
    scanf_s("%d", &gyeonggi);
    printf("incheon의 확진자 수를 입력하시오:");
    scanf_s("%d", &incheon);
    printf("%d와 %d 그리고 %d 를 더한 수도권 확진자 수는 %d\n", seoul, gyeonggi, incheon, pow(seoul, gyeonggi, incheon));

    //return 0;
    menu();
    
}



		