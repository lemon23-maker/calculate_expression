#pragma once
typedef struct stack{
	double* base;
	double* top;
	double size;
}sqstack;

//����һ����ջ
void initstack(sqstack* s);

//����һ��ջ
void destroystack(sqstack* s);

//���һ��ջ
void clearstack(sqstack* s);

//��ջΪ��ջ���򷵻�TRUE�����򷵻�FALSE
double stackempty(sqstack* s);

//����s��Ԫ�ظ�������ջ�ĳ���
double stacklength(sqstack* s);

//��ȡջ��Ԫ��
double get_top(sqstack* s);

//����Ԫ��eΪ�µ�ջ��Ԫ��
void push(sqstack* s, double e);

//��ջ���գ�ɾ��s��ջ��Ԫ�أ���e������ֵ
double pop(sqstack* s);

//��ȡ���ȼ�
double Precede(double e1, double e2);

//����
double calculate(double opnd, double optr1, double optr2);

//��ȡ������λ��
int get_num_length(char* str);