#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

//함수선언
void naiveMatching(string p1, const char* P, int textlen, int patlen);

void main() {
	
	int textlen, patlen;
	const char* P= "Further Reading about Standards";	//패턴문자열
	//const char* P = "17650    20000818";
	string A;	//텍스트문자열

	ifstream in("test1.txt"); 

	if (in.is_open()) {

		//위치 지정자를 파일의 끝으로 옮김
		in.seekg(0, ios::end);

		//파일의 끝 위치를 읽는다. (즉, 파일의 크기)
		int size = in.tellg();

		//파일 크기만큼의 문자열을 할당한다.
		A.resize(size);

		// 위치 지정자를 파일의 시작으로 옮김
		in.seekg(0, ios::beg);

		// 파일 전체 내용을 읽어서 문자열에 저장한다.
		in.read(&A[0], size);
		
		//cout << size << endl; size제대로 받음 확인완료

	}
	else {
		printf("파일을 찾을 수 없습니다!");
	}

	printf("<기본정보>\n\n\t패턴문자열 P ={");
	for (int i = 0; i < strlen(P); i++) {
		printf("%c", P[i]);
	}
	printf("}\n\n");

	textlen = A.length();
	patlen = strlen(P);
	printf("\t텍스트문자열의 길이는 %d, 패턴문자열의 길이는 %d \n\n", textlen, patlen);

	printf("<naiveMatching Algorithm 실행 결과>\n\n");
	naiveMatching(A, P, textlen, patlen);
}

void naiveMatching(string A, const char* P, int textlen, int patlen) {

	double naive_elapsed_time;
	clock_t before = clock(); //현재 시간 저장

	int i, j; int count = 0;

	for (i = 0; i < textlen - patlen +1; i++) {		//텍스트문자열 무조건 1칸씩 이동하며 비교한다.
		for (j = 0; j < patlen; j++) {

			if (A[i + j] != P[j])	//miss matching이 발생
				break;	//j를 더이상 증가시키지 않고 다음 텍스트문자열부터 비교한다.

		}
		if (j == patlen) {		//패턴문자열 전체와 matching.
			printf("\t찾으시는 패턴문자열이 텍스트문자열의 [%d]위치에서 매칭되었습니다! \n\n", i);
			count++;
		}
	}

	if (count == 0) printf("\n\n\t패턴문자열을 찾지 못했습니다.");

	naive_elapsed_time = (double)(clock() - before) / CLOCKS_PER_SEC;  // 초 단위로 경과 시간을 측정함
	fprintf(stdout, "\tnaiveMatching으로 패턴문자열을 찾는데 걸린 시간(초): %10.2f\n\n", naive_elapsed_time);

}

