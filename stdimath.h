#ifndef STDIMATH_H
#define STDIMATH_H
#define MATH_E 2.718281828459			//数值越精确，结果精度更高
#define MATH_1E 0.36787944117144			//数值越精确，结果精度更高
#define ACCURACY_LOG 1000			//数值越大，精确度更高
#define ACCURACY_POW 10				//数值越大，精确度更高
#define ACCURACY_SQRT 20			//数值越大，精度越高

/*
开方
sqrt(a)=x -> x^2=a -> x^2-a=0 -> f(x)=x^2-a,df/dx=2*x
*/
double isqrt(double x);

/*
ln(x)
ln(x)= {∫(1,x)}1/x*dx
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
    x^y最终形态
    条件  x>0
    因为  x=a^b -> log(a,x)=b -> lnx/lna-b=0
    所以  f(x)=lnx/lna-b  df/dx=1/(x*lna)
    公式  x[k+1]=f(x[k])/f'(x[k]) -> x[k+1]=1-ln(x[k])+b*lna
*/
double ipow(double x, double y);

/*
    阶乘近似值，Factorials(x)，x为全体大于0的实数，结果为e^x表示法
    例：4!=1*2*3*4=e^[ln(1*2*3*4)]=e^(ln1+ln2+ln3+ln4)
*/
double Factorials(double x);
#endif