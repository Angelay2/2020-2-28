#include <stdio.h>
#include <Windows.h>

#pragma warning(disable:4996)


// ��һ������: δ�ж�����ɹ� 
// �����ж�û������ ָ������ָ���ϵ��ڴ�ռ�

void Test1(void){
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL){
		strcpy(str, "world");
		printf(str);
	}
}
// ������γ���ԭ������ͨ��һ���������һ�οռ�, Ȼ����ַ�����������ռ���, �����˻�û�ͷ�
// GetMemory()��û�������� û�еõ���һ���ڴ�ռ�
// p Ϊ��ʱ����, strռ4���ֽ�, str��ʼָ��NULL,
// ��GetMemoryʱ  ��һ��pҲָ��NULL,����malloc, ��οռ��ַ���ŵ�p�� ��ָ��NULL��
// ������ʼ���ն�����p�ﱣ��ĵ�ַ p����ʱ���� �������� p���ͷ�, 
// p Ϊջ֡�ṹ���һ������, p���ɵ� ָ��Ŀռ�Ҳ���ɵ��� str����ָ��NULL,
// �ѿռ仹�� ֻ���Ҳ�����, ��������������������ڴ�й© 
// ��һ�����: ô���п�
// �ڶ������: û���ͷ�
// ���������: �������ڴ�й©
// ���ĵ����: str�����õ��ռ� strΪNULL, ���ַ�������str��, 
// ��NULL���ռ� => �������
void GetMemory(char* p){// ����� p Ҫ�����β�ʵ���� 
	p = (char*)malloc(100);
}
void Test(void){
	char* str = NULL;
	GetMemory(str);// ֻҪ���� ��Ҫ�γ���ʱ���� �����p Ϊʵ��
	strcpy(str, "hello world");
	printf(str);
}
int main(){
	Test();
	system("pause");
	return 0;
}