#include"stdimath.h"

/*开方最终形态*/
double isqrt(double x)
{
	double next;
	int k = 0, i;
	if (x > 4)
	{
		x *= 0.25;
		k++;
	}
	next = x / 2;
	for (i = 0; i < ACCURACY_SQRT; i++)	next = next * 0.5 + x / (2 * next);
	while (k--)	next *= 2;
	return next;
}

/*ln(x)最终形态*/
double iln(double x)
{
	double h, result, result1 = 0, result2 = 0;
	int i = 1, k = 0;
	if (x <= 0 || x == 1) return 0;
	if (x < MATH_E)
		while (x < MATH_E)
		{
			x *= MATH_E;
			k--;
		}
	else if (x == MATH_E) return 1;
	else
	{
		while (x > MATH_E)
		{
			x *= MATH_1E;
			k++;
		}
	}
	h = (x - 1) / ACCURACY_LOG;
	result = 1 + 1.0 / x;
	while (i < ACCURACY_LOG)
	{
		if (i % 2)	result1 += 1.0 / (1 + h * i);
		else	result2 += 1.0 / (1 + h * i);
		i++;
	}
	result += result1 * 4;
	result += result2 * 2;
	result *= h / 3;
	result += k;
	return result;
}

/*log(a,x)*/
double ilog(double a, double x)
{
	return iln(x) / iln(a);
}

/* e^x -> x为全体实数 */
double iexp(double x)
{
	double result;
	int k = 0, i;
	if (x < 0)  return 1.0 / iexp(-x);
	if (x == 0) return 1;
	while (x > 2)
	{
		x *= 0.5;
		k++;
	}
	result = x++;
	for (i = 0; i < ACCURACY_POW; i++) result *= x - iln(result);
	while (k-- > 0)	result *= result;
	return result;
}

/* x^y -> x>=0,y为全体实数*/
double ipow(double x, double y)
{
	double result, blna;
	int k = 0, i;
	if (x <= 0)	return 0;
	if (y < 0) return 1.0 / ipow(x, -y);
	if (y == 0) return 1;
	while (y > 2)
	{
		y *= 0.5;
		k++;
	}
	result = iln(x) * y;
	blna = result + 1;
	for (i = 0; i < ACCURACY_POW; i++)	result *= blna - iln(result);
	while (k--)	result *= result;
	return result;
}

/* 阶乘近似值，Factorials(x)，x为全体大于0的实数，结果为e^x表示法 */
double Factorials(double x)
{
	double result = 0, i = 1;
	if (x <= 1) return 1;
	while (++i < x)
		result += iln(i);
	result += iln(x);
	return result;
}