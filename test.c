#include <stdio.h>
#include <Windows.h>
//#include <malloc.h>

// 栈帧
/*栈往下增长, 每次调一个函数 这个函数里面会有局部变量 会提前计算好函数所需的空间
提前给函数分配好空间 => 栈针 定义的变量是在栈里的栈帧结构开辟的空间
所以此时 就给char* str 在Test()的栈帧上开辟了空间 
只要是函数调用 必定先形成栈帧 给GetMemory开辟栈帧 栈帧一直在栈空间上往下增长
但不会一直增长 直到栈溢出(递归) GetMemory里面的数组调完后 返回的是数组的起始地址
在函数内部定义变量是在自己的函数内部的栈帧结构 返回函数时 空间无效了 
函数调完了 栈帧就没了 但内容还在
但是printf也是函数 也要先形成栈帧 内部也有临时变量 所以之前GetMemory的空间被覆盖了
第三个栈帧*/

// GetMemory 返回值是 char*, 返回的是数组 
// 这个数组在栈上开辟空间 字符串也在栈上 字符依次被放入数组
// 这个数组是局部数组 当这个数组被调完之后呢, 就会被释放掉 
// 所以就算拿到这个空间的地址 可是空间已经被释放掉了 所以结果乱码
// 计算机释放空间时 不会清空内容, 
char* GetMemory(void){
	char p[] = "hello world";
	return p;// 返回值是里面数组的起始地址(首元素的地址)
}
void Test(void){
	char* str = NULL;
// str拿到那个空间的地址 str指向栈上'h' 
// 虽然指针所指向的那块空间里内容已经无效了 但是那块内容还是"hello world"
	
	str = GetMemory();
	printf(str);// 打印起始地址 printf第一个参数是char*呢 就是打印字符串
}
int main(){
	Test();// 结果乱码
	system("pause");
	return 0;
}