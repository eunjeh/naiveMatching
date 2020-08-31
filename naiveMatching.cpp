#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

//�Լ�����
void naiveMatching(string p1, const char* P, int textlen, int patlen);

void main() {
	
	int textlen, patlen;
	const char* P= "Further Reading about Standards";	//���Ϲ��ڿ�
	//const char* P = "17650    20000818";
	string A;	//�ؽ�Ʈ���ڿ�

	ifstream in("test1.txt"); 

	if (in.is_open()) {

		//��ġ �����ڸ� ������ ������ �ű�
		in.seekg(0, ios::end);

		//������ �� ��ġ�� �д´�. (��, ������ ũ��)
		int size = in.tellg();

		//���� ũ�⸸ŭ�� ���ڿ��� �Ҵ��Ѵ�.
		A.resize(size);

		// ��ġ �����ڸ� ������ �������� �ű�
		in.seekg(0, ios::beg);

		// ���� ��ü ������ �о ���ڿ��� �����Ѵ�.
		in.read(&A[0], size);
		
		//cout << size << endl; size����� ���� Ȯ�οϷ�

	}
	else {
		printf("������ ã�� �� �����ϴ�!");
	}

	printf("<�⺻����>\n\n\t���Ϲ��ڿ� P ={");
	for (int i = 0; i < strlen(P); i++) {
		printf("%c", P[i]);
	}
	printf("}\n\n");

	textlen = A.length();
	patlen = strlen(P);
	printf("\t�ؽ�Ʈ���ڿ��� ���̴� %d, ���Ϲ��ڿ��� ���̴� %d \n\n", textlen, patlen);

	printf("<naiveMatching Algorithm ���� ���>\n\n");
	naiveMatching(A, P, textlen, patlen);
}

void naiveMatching(string A, const char* P, int textlen, int patlen) {

	double naive_elapsed_time;
	clock_t before = clock(); //���� �ð� ����

	int i, j; int count = 0;

	for (i = 0; i < textlen - patlen +1; i++) {		//�ؽ�Ʈ���ڿ� ������ 1ĭ�� �̵��ϸ� ���Ѵ�.
		for (j = 0; j < patlen; j++) {

			if (A[i + j] != P[j])	//miss matching�� �߻�
				break;	//j�� ���̻� ������Ű�� �ʰ� ���� �ؽ�Ʈ���ڿ����� ���Ѵ�.

		}
		if (j == patlen) {		//���Ϲ��ڿ� ��ü�� matching.
			printf("\tã���ô� ���Ϲ��ڿ��� �ؽ�Ʈ���ڿ��� [%d]��ġ���� ��Ī�Ǿ����ϴ�! \n\n", i);
			count++;
		}
	}

	if (count == 0) printf("\n\n\t���Ϲ��ڿ��� ã�� ���߽��ϴ�.");

	naive_elapsed_time = (double)(clock() - before) / CLOCKS_PER_SEC;  // �� ������ ��� �ð��� ������
	fprintf(stdout, "\tnaiveMatching���� ���Ϲ��ڿ��� ã�µ� �ɸ� �ð�(��): %10.2f\n\n", naive_elapsed_time);

}

