#include <stdio.h>
#include <Windows.h>

#pragma warning(disable:4996)


// ��һ������: δ�ж�����ɹ� 
// �ڶ�������: �����ж�û������ ָ������ָ���ϵ��ڴ�ռ�
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
//void GetMemory(char* p){// ����� p Ҫ�����β�ʵ���� 
//	p = (char*)malloc(100);
//}
//void Test(void){
//	char* str = NULL;
//	GetMemory(str);// ֻҪ���� ��Ҫ�γ���ʱ���� �����strΪʵ��
//	strcpy(str, "hello world");
//	printf(str);
//}

// ��������Ѷѿռ��õ� ��Ϊ�������
// ���� s�γ�tr���� GetMemory����ȥ����str�ĵ�ַ, p����ʱ����,����Ҫ���ٿռ� 
// strָ��NULL, pҲָ��NULL, �Զ���ָ��p ������, *p����str, 
// str����ֵ��, ����malloc����Ŀռ�ĵ�ַ�ͷ���str��, GetMemory����� p���ͷ���
// ����str�õ���malloc����Ŀռ�, ����Ҫ�õ��ѿռ�ĵ�ַ �ô�����ָ��,
//void GetMemory(char** p){// ����� p Ҫ�����β�ʵ���� 
//	*p = (char*)malloc(100);
//}
//void Test(void){
//	char* str = NULL;
//	GetMemory(&str);// ֻҪ���� ��Ҫ�γ���ʱ���� �����str Ϊʵ��
//	strcpy(str, "hello world");
//	printf(str);
//}

// ����ֵ���p �ĵ�ַ�ŵ�str����, ��Ȼp���ͷ���, ��str����ָ���Ӧ�Ķѿռ�
char* GetMemory(){// ����� p Ҫ�����β�ʵ���� 
	char* p = (char*)malloc(100);
	return p;// ����Ҫ��p����
}
void Test(void){
	char* str = GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
}
int main(){
	Test();
	system("pause");
	return 0;
}