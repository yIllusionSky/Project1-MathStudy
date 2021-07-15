#ifndef STDIMATH_H
#define STDIMATH_H
#define MATH_E 2.718281828459			//��ֵԽ��ȷ��������ȸ���
#define MATH_1E 0.36787944117144			//��ֵԽ��ȷ��������ȸ���
#define ACCURACY_LOG 1000			//��ֵԽ�󣬾�ȷ�ȸ���
#define ACCURACY_POW 10				//��ֵԽ�󣬾�ȷ�ȸ���
#define ACCURACY_SQRT 20			//��ֵԽ�󣬾���Խ��

/*
����
sqrt(a)=x -> x^2=a -> x^2-a=0 -> f(x)=x^2-a,df/dx=2*x
*/
double isqrt(double x);

/*
ln(x)
ln(x)= {��(1,x)}1/x*dx
*/
double iln(double x);

/*
log(a,x)
log(a,x)=ln(x)/ln(a)
*/
double ilog(double a, double x);

/*
    e^x 
*/
double iexp(double x);

/*
    x^y������̬
    ����  x>0
    ��Ϊ  x=a^b -> log(a,x)=b -> lnx/lna-b=0
    ����  f(x)=lnx/lna-b  df/dx=1/(x*lna)
    ��ʽ  x[k+1]=f(x[k])/f'(x[k]) -> x[k+1]=1-ln(x[k])+b*lna
*/
double ipow(double x, double y);

/*
    �׳˽���ֵ��Factorials(x)��xΪȫ�����0��ʵ�������Ϊe^x��ʾ��
    ����4!=1*2*3*4=e^[ln(1*2*3*4)]=e^(ln1+ln2+ln3+ln4)
*/
double Factorials(double x);
#endif