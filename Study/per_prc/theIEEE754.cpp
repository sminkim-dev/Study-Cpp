#include <stdio.h>
#include <iostream>

int main() {
    float f = 0.3f;
    double d = 0.3;

    // 1. 포인터를 이용해 비트 패턴을 강제로 정수형으로 읽기
    unsigned int *f_bit = (unsigned int *)&f;
    unsigned long long *d_bit = (unsigned long long *)&d;

    printf("float 0.3f hex: 0x%08X\n", *f_bit);
    printf("double 0.3 hex: 0x%016llX\n", *d_bit);

    // 2. 실제 값 출력 (오차 확인)
    printf("float precision:  %.25f\n", f);
    printf("double precision: %.25f\n", d);

    system("pause");
    return 0;
}