
#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char expression[100];
	char substr[10];
	sqstack optr;
	sqstack opnd;
	initstack(&optr);
	initstack(&opnd);
	char is_continue = 'y';
	while (is_continue=='y'||is_continue=='Y')
	{
		printf("请输入表达式:");
		gets(expression);
		int i = 0;
		while (expression[i] != '=')
		{
			if (expression[i] == '\0')
				break;
			if (isdigit(expression[i])) {
				
				int length = get_num_length(&expression[i]);
				strncpy(substr, &expression[i], length);
				double num = atof(&expression[i]);
				push(&optr, num);
				i += length;
			}
			else
			{
				switch (expression[i])
				{
				
				case '+':while (!stackempty(&opnd)&&get_top(&opnd)!='(' && Precede(get_top(&opnd), expression[i]))
							{
								int opnd1 = pop(&opnd);
								
								double optr1 = pop(&optr);
								double optr2 = pop(&optr);
								//运算
								double res = calculate(opnd1, optr2, optr1);
								push(&optr, res);
							}
						push(&opnd, expression[i]);
						break;
				case '-':while (!stackempty(&opnd)&&get_top(&opnd) != '(' && Precede(get_top(&opnd), expression[i]))
							{
								int opnd1 = pop(&opnd);
								
								double optr1 = pop(&optr);
								double optr2 = pop(&optr);
								//运算
								double res = calculate(opnd1, optr2, optr1);
								push(&optr, res);
							}
						push(&opnd, expression[i]);
						break;
				case '*':while (!stackempty(&opnd)&&get_top(&opnd) != '(' && Precede(get_top(&opnd), expression[i]))
							{
								int opnd1 = pop(&opnd);
								
								double optr1 = pop(&optr);
								double optr2 = pop(&optr);
								//运算
								double res = calculate(opnd1, optr2, optr1);
								push(&optr, res);
							}
						push(&opnd, expression[i]);
						break;
				case '/':while (!stackempty(&opnd)&&get_top(&opnd) != '(' && Precede(get_top(&opnd), expression[i]))
							{
								int opnd1 = pop(&opnd);
								
								double optr1 = pop(&optr);
								double optr2 = pop(&optr);
								//运算
								double res = calculate(opnd1, optr2, optr1);
								push(&optr, res);
							}
						push(&opnd, expression[i]);
						break;
 				case '(':push(&opnd, expression[i]); break;
				case ')':while (!stackempty(&opnd) && Precede(get_top(&opnd), expression[i]))
							{
								int opnd1 = pop(&opnd);
								if (opnd1 == '(')
									break;
								double optr1 = pop(&optr);
								double optr2 = pop(&optr);
								//运算
								double res = calculate(opnd1, optr2, optr1);
								push(&optr, res);
							}
						
						break;
				
				
				}
				i++;
			}
			
		}
		while (!stackempty(&opnd))
		{
			int opnd1 = pop(&opnd); 
			double optr1 = pop(&optr);
			double optr2 = pop(&optr);
			//运算
			double res = calculate(opnd1, optr2, optr1);
			push(&optr, res);
		}
		printf("运算结果为:%f\n", pop(&optr));
		printf("是否继续运算?Y/N\n");
		scanf("%c", &is_continue);
		getchar();
	}
}

