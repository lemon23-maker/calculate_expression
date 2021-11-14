#pragma once
#include "stack.h"
#include <ctype.h>
#include <stdlib.h>
//构造一个空栈
void initstack(sqstack* s) {

	s->base = (double*)malloc(100 * sizeof(double));
	s->size = 100;
	s->top = s->base;
}


//销毁一个栈
void destroystack(sqstack* s) {
	if (!s)
	{
		return;
	}
	free(s->base);
}

//清空一个栈
void clearstack(sqstack* s) {
	if(!stackempty(s))
	s->top = s->base;
}

//若栈为空栈，则返回TRUE，否则返回FALsE
double stackempty(sqstack* s) {
	
	return s->base == s->top ? 1 : 0;

}

//返回s的元素个数，即栈的长度
double stacklength(sqstack* s) {

	return s->top - s->base;

}

//获取栈顶元素
double get_top(sqstack* s) {

	return *(s->top - 1);

}

//插入元素e为新的栈顶元素
void push(sqstack* s, double e) {
	
	*s->top++ = e;

}

//若栈不空，删除s的栈顶元素，用e返回其值
double pop(sqstack* s) {

	s->top--;
	
	return *s->top;
}
//获取优先级
double Precede(double e1, double e2) {
	double res;
	switch ((int)e1)
	{
	case '+':res = (e2 == '-' || e2 == '+'||e2==')') ? 1 : 0;
		break;
	case '-':res = (e2 == '-' || e2 == '+'||e2==')') ? 1 : 0;
		break;
	case '*':res = 1;
		break;
	case '/':res = 1;
		break;
	case '(':res = 1;
		break;
	}
	return (int)res;
}
//计算
double calculate(double opnd, double optr1, double optr2) {
	double res = 0;
	switch ((int)opnd)
	{
		case '+':res = optr1 + optr2; break;
		case '-':res = optr1 - optr2; break;
		case '*':res = optr1 * optr2; break;
		case '/':res = optr1 / optr2; break;
	}

	return res;
}
//提取操作数位数
int get_num_length(char* str) {

	int num = 0;
	while (isdigit(str[num])||str[num]=='.')
	{
		num++;
	}

	return num;
}