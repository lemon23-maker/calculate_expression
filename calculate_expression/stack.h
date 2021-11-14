#pragma once
typedef struct stack{
	double* base;
	double* top;
	double size;
}sqstack;

//构造一个空栈
void initstack(sqstack* s);

//销毁一个栈
void destroystack(sqstack* s);

//清空一个栈
void clearstack(sqstack* s);

//若栈为空栈，则返回TRUE，否则返回FALSE
double stackempty(sqstack* s);

//返回s的元素个数，即栈的长度
double stacklength(sqstack* s);

//获取栈顶元素
double get_top(sqstack* s);

//插入元素e为新的栈顶元素
void push(sqstack* s, double e);

//若栈不空，删除s的栈顶元素，用e返回其值
double pop(sqstack* s);

//获取优先级
double Precede(double e1, double e2);

//计算
double calculate(double opnd, double optr1, double optr2);

//提取操作数位数
int get_num_length(char* str);