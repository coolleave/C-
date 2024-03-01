#include<stdio.h>
#include<stdlib.h>
int main()
{
	int p,i,n;
	scanf("%d",&n);
	p = 1;
	i = 1;
	while (i<n)
	{ 
		p=p*i;
		i=i+1;
	    
		printf("计算结果为：%d",p);

	}
	system("pause");
	return 0;


}