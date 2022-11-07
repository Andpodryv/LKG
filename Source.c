#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
unsigned long long X;
unsigned long long m = 4294967296;
unsigned long long a = 214013;
unsigned long long c = 2531011;
unsigned long long doublenumb_nod(unsigned long long x, unsigned long long y)
{
	if ((x == 1) || (y == 1))
		return 1;
	if (x == y)
		return x;
	if (x > y)
			return(doublenumb_nod(x - y, y));
	if (x < y)
		return(doublenumb_nod(y - x, x));
}
int doublenumb_simple(unsigned long long x, unsigned long long y)
{
	if (doublenumb_nod(x, y) == 1)
		return 1;
}
unsigned long long Lkg()
{
	X = (a * X + c) % m;
	return X;
}
int proverka_c()
{
	if (doublenumb_simple(m, c) == 1)
	{
		printf("the numbers c=%llu and m==%llu are mutually prime\n", c, m);
		return 1;
	}
	else
	{
		printf("the numbers ñ=%llu and m==%llu are not mutually prime\n", c, m);
		return 0;
	}
}
int proverka_a()
{
	if (a % 8 == 5)
	{
		printf("the remainder of dividing the number à=%llu by 8 ,  is the number 5\n", a);
		return 1;
	}
	else
	{
		printf("5 is not the remainder of dividing the number à=%llu by 8 \n", a);
		return 0;
	}
}

unsigned long long lenght()
{
	unsigned long long i = 0;
	unsigned long long mass[4] = { 0 };
	unsigned long long a;
	Lkg();
	a = X;
	Lkg(); i++;
	while (X != a)
	{
		Lkg();
		i++;

		if (i == 5000000000)
			break;
	}
	printf("period length %llu", i);
	return i;
}
int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int repeat()
{
	unsigned long long mass[6] = { 0 };
	unsigned long long a = 0;
	int num = 1;
	for (int i = 0; i < 2; i++)
	{
		Lkg();
		a = X % 1000;
		mass[i*3+2] = a % 10;
		a = a / 10;
		mass[i*3+1] = a % 10;
		a = a / 10;
		mass[i*3] = a % 10;
	}
	
	qsort(mass, 6, sizeof(unsigned long long), cmp);
	for (int i = 0; i < 5; i++)
	{
		if (mass[i] != mass[i + 1])
			num++;
	}
	return num;
}
float poker_test()
{
	int mass_rep[7] = { 0 };
	float hi_sqrt = 0;
	int num_rep = 0;
	int rep = 0;
	float P[7] = { 0,0.00006,0.011,0.16,0.464,0.321,0.042 };
	while (num_rep <6)
	{
		num_rep = num_rep + 1;
		rep = repeat();
		switch (rep)
		{
		case 1:
			mass_rep[1]++;
			break;
		case 2:
			mass_rep[2]++;
			break;
		case 3:
			mass_rep[3]++;
			break;
		case 4:
			mass_rep[4]++;
			break;
		case 5:
			mass_rep[5]++;
			break;
		case 6:
			mass_rep[6]++;
			break;
		}
	}
	for (int i = 1; i < 7; i++)
	{
		printf("%d different numbers were repeated %d times \n", i, mass_rep[i]);
		hi_sqrt = (hi_sqrt + ((mass_rep[i] - num_rep * P[i]) * (mass_rep[i] - num_rep * P[i]))/(num_rep*P[i]));

	}
	printf("hi-square: %f\n", hi_sqrt);
	return hi_sqrt;
}
long double Frequency()
{
	double P;
	double Sobs = 0;
	double S=0;
	unsigned long long a = 0;
	int r = 0;
	unsigned long long uno=0;
	unsigned long long zero=0;
	long double hi_sqr = 0;
	int i = 0;
	while (i < 100){
		if (a == 0)
		{
			Lkg();
			a = X;
		}
		r = a % 2;
		a = a / 2;
		if (r == 1)
			uno++;
		if (r==0)
			zero++;
		r = 0;
		i++;
		
	}
	hi_sqr = ((uno - zero) * (uno - zero)) / (uno + zero);
	return hi_sqr;

}
int low_bits()
{
	unsigned long long uno = 0;
	unsigned long long zero = 0;
	unsigned long long lenght = 0;
	unsigned long long i = 0;
	unsigned long long a;
	unsigned long long arr[50] = { 0 };
	Lkg();
	a = X;
	while (a)
	{
		arr[i] = a % 2;
		a = a / 2;
		i++;
	}
	lenght = i / 2;
	for (i=lenght; i > 0; i--)
	{
		printf("%llu", arr[i]);
	}
	printf("%llu \n",arr[0]);
	for (i = 0; i <= lenght; i++)
	{
		if (arr[i] == 1) uno++;
		if (arr[i] == 0) zero++;
	}
	if (abs(uno - zero) < 3)
		printf("units: %llu, zeros: %llu . Therefore, the number is random in the lower bits\n", uno,zero);
	else
		printf("units: %llu, zeros: %llu . The number is not random by the lower bits\n",uno,zero);
}

int main()
{
	int select = 0;
	srand(time(NULL));
	X = rand();
	printf("Select an action:\n 1) Check the parameters and display them on the screen \n 2) Display the length of the period \n 3) Check the lower bits \n 4) Test the series \n 5) conduct a poker test\n 6) Exit\n");
	scanf("%d", &select);
	while (select){
	switch (select)
	{
	case 1:
		if (proverka_a() && proverka_c())
			printf("according to the Theorem and its corollary a=%llu, m=%llu, c=%llu selected correctly\n", a, m, c);
		break;
	case 2:
		lenght();
		break;
	case 3:
		low_bits();
		break;
	case 4:
		printf("x^2= %Lf\n", Frequency());
		break;
	case 5:
		poker_test();
		break;
	case 6:
		return 0;
	}
	printf("\n\n\n---------------------------------------------------------------------\n");
	printf("Select an action:\n 1) Check the parameters and display them on the screen \n 2) Display the length of the period \n 3) Check the lower bits \n 4) Test the series \n 5) conduct a poker test\n 6) Exit\n");
	scanf("%d", &select);
	}

}