#include <stdio.h>
#include <Windows.h>

#pragma warning(disable:4996)


// 第一个错误: 未判定申请成功 
// 条件判定没有意义 指针依旧指向老的内存空间

void Test1(void){
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL){
		strcpy(str, "world");
		printf(str);
	}
}
// 下面这段程序原本他想通过一个函数获得一段空间, 然后把字符串拷进这个空间里, 用完了还没释放
// GetMemory()并没有起到作用 没有得到那一段内存空间
// p 为临时变量, str占4个字节, str开始指向NULL,
// 调GetMemory时  第一个p也指向NULL,进行malloc, 这段空间地址被放到p里 不指向NULL了
// 但是自始至终都是在p里保存的地址 p是临时变量 函数调完 p被释放, 
// p 为栈帧结构里的一个变量, p被干掉 指向的空间也被干掉了 str依旧指向NULL,
// 堆空间还在 只是找不见了, 所以这道题最大的问题是内存泄漏 
// 第一点错误: 么有判空
// 第二点错误: 没有释放
// 第三点错误: 本身有内存泄漏
// 第四点错误: str不能拿到空间 str为NULL, 把字符串拷到str里, 
// 往NULL里拷空间 => 程序崩溃
void GetMemory(char* p){// 这里的 p 要进行形参实例化 
	p = (char*)malloc(100);
}
void Test(void){
	char* str = NULL;
	GetMemory(str);// 只要传参 就要形成临时拷贝 这里的p 为实参
	strcpy(str, "hello world");
	printf(str);
}
int main(){
	Test();
	system("pause");
	return 0;
}