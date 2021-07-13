#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

// bin file로부터 숫자 읽어 반환
uint32_t read_binFile(const char* filename){
    FILE* fp = fopen(filename, "r");    // 파일 열기
    if(fp == NULL){
        printf("Can't read file\n");
        exit(1);
    }

    uint32_t num;
    fread(&num, sizeof(num), 1, fp);    //파일로부터 숫자 읽기
    num = ntohl(num);   //32bit 숫자 NBO -> HBO

    fclose(fp); //파일 닫기

    return num;
}

// 10진수, 16진수 출력
void print_dec_hex(uint32_t n){
    printf("%d(0x%x)", n, n);
}

int main(int argc, char* argv[]){
    if(argc != 3)
    {
        printf("No inputs or Too many inputs");
        exit(1);
    }

    uint32_t n1 = read_binFile(argv[1]);
    uint32_t n2 = read_binFile(argv[2]);

    // 포멧에 맞춰 출력
    print_dec_hex(n1);
    printf(" + ");
    print_dec_hex(n2);
    printf(" = ");
    print_dec_hex(n1+n2);
    printf("\n");
}
