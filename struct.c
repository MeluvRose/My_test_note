#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
struct Person
{
	// 구조체 멤버
	char name[20];
	int age;
	char address[100];
};
//} p1; // 정의와 동시에 변수 선언 가능(전역 변수)
*/

typedef struct _Person
{
	char name[20];
	int age;
	char address[100];
} Person; // typedef를 사용하여 구조체 별칭을 Person으로 정의

/*
<typedef는 자료형의 별칭을 만드는 기능이다.>

typedef int MYINT;      // int를 별칭 MYINT로 정의
typedef int* PMYINT;    // int 포인터를 별칭 PMYINT로 정의

MYINT num1;        // MYINT로 변수 선언
PMYINT numPtr1;    // PMYINT로 포인터 변수 선언

numPtr1 = &num1;   // 포인터에 변수의 주소 저장
                   // 사용 방법은 일반 변수, 포인터와 같음
*/

int main(void)
{
	//struct Person p1; // 구조체 변수 선언
	//Person p1 = {.name = "홍길동", .age = 30, .address = "서울시 용산구 한남동"};
	//Person p1; // 별칭 Person으로 변수 선언
	//struct Person *p1 = malloc(sizeof(struct Person)); // 구조체 포인터 선언(동적 할당)
	//Person *p1 = malloc(sizeof(Person)); // 구조체 포인터 선언(동적 할당) with 구조체 별칭
	Person *ptr;
	Person p1;

	/*
	//'.'으로 구조체 멤버에 접근하여 값 할당
	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");
	*/

	/*
	//구조체 포인터에선 '->'으로 구조체 멤버에 접근하여 값 할당
	strcpy(p1->name, "홍길동");
	p1->age = 30;
	strcpy(p1->address, "서울시 용산구 한남동");
	*/

	ptr = &p1;
	ptr->age = 30;

	/*
	printf("이름: %s\n", p1->name);
	printf("나이: %d\n", p1->age);
	printf("주소: %s\n", p1->address);
	*/

	printf("p1.age = %d\n", p1.age);
	printf("ptr->age = %d\n", ptr->age);

	//free(p1); // 동적 메모리 해제

	return;
}
