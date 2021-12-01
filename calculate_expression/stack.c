#pragma once
#include "stack.h"
#include <ctype.h>
#include <stdlib.h>
//����һ����ջ
void initstack(sqstack* s) {

	s->base = (double*)malloc(100 * sizeof(double));
	s->size = 100;
	s->top = s->base;
}


//����һ��ջ
void destroystack(sqstack* s) {
	if (!s)
	{
		return;
	}
	free(s->base);
}

//���һ��ջ
void clearstack(sqstack* s) {
	if(!stackempty(s))
	s->top = s->base;
}

//��ջΪ��ջ���򷵻�TRUE�����򷵻�FALsE
double stackempty(sqstack* s) {
	
	return s->base == s->top ? 1 : 0;

}

//����s��Ԫ�ظ�������ջ�ĳ���
double stacklength(sqstack* s) {

	return s->top - s->base;

}

//��ȡջ��Ԫ��
double get_top(sqstack* s) {

	return *(s->top - 1);

}

//����Ԫ��eΪ�µ�ջ��Ԫ��
void push(sqstack* s, double e) {
	
	*s->top++ = e;

}

//��ջ���գ�ɾ��s��ջ��Ԫ�أ���e������ֵ
double pop(sqstack* s) {

	s->top--;
	
	return *s->top;
}
//��ȡ���ȼ�
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
//����
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
//��ȡ������λ��
int get_num_length(char* str) {

	int num = 0;
	while (isdigit(str[num])||str[num]=='.')
	{
		num++;
	}

	return num;
}