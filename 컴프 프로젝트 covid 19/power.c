//power.c
#include <stdio.h>
#include "power2.h"

int num1 = 2061;
int num2 = 1380;

void Output()
{
	printf("오늘 하루 경기도 확진자 증가량%d와 서울시 오늘 하루 확진자 증가량%d의 합은 %d입니다\n", num1, num2, num1 + num2);
}
