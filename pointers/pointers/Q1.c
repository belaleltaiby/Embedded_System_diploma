/*
 * pointers.c
 *
 *  Created on: Jul 3, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

////////  Q 1 ///////////////////////////////////

/*
int main()
{
	int m = 29;

	printf(" Address of m : %x \n",&m);
	printf(" value of m : %d \n",m);
	int *ab = (void*)0;
	printf(" Address of pointer ab : %x \n",ab);
	printf(" content of pointer ab : %d \n",*ab);
	m=34;
	printf(" Address of pointer ab : %x \n",ab);
	printf(" content of pointer ab : %d \n",*ab);
	*ab=7;
	printf(" Address of m : %x \n",&m);
	printf(" value of m : %d \n",m);

}
*/


/////  Q 2////////////////////////////////////////////////////
/*
int main()
{
	char alpha[27];
	char *pt =alpha;
	for(int i=0;i<26;i++)
	{
		*pt = i+'A';
		pt++;
	}

	pt=alpha;

	for(int i=0;i<26;i++)
	{
		printf(" %c \n",*pt);
		pt++;
	}

	return 0;
}
*/

///Q 3///////////////////////////////
/*
int main()
{
	printf("Enter a string \n");
	fflush(stdin);fflush(stdout);
	char str[11];
	scanf("%s",str);
	char *pt =str;
	int last;
	for(int i=0;i<10;i++)
	{
		if(str[i]==0)
		{
			pt =&str[i-1];
			last=i;
			break;
		}
	}

	for(int rev=0;rev<last;rev++)
	{
		printf("%c",*pt);
		pt--;
	}
}
*/
/////Q 4 ///////////////////////////////////

int main()
{
	int arr[15];
	printf("input 5 number of elements in the array:\n");
	fflush(stdin);fflush(stdout);

	for(int i=0,j=1; i<5; i++,j++)
	{
		printf("element-%d: ",j);
		fflush(stdin);fflush(stdout);
		scanf("%d",&arr[i]);
		fflush(stdin);fflush(stdout);
	}
	printf("The elements of array in reverse order are : \n");
	fflush(stdin);fflush(stdout);
	int *pt = &arr[4];
	for(int rev=5; rev>0;rev--)
	{
		printf("element - %d : %d \n",rev,*pt);
		fflush(stdin);fflush(stdout);

		pt--;
	}

	return 0;
}


////Q 5////////////////////////////
/*
struct employee
{
	char empName;
	int empId;
};

int main()
{
	int *hello(){
		printf("hello");
		int a=4;
		return &a;
	}
	int *ptr =hello();
	clrscr();
	printf("%d",*ptr);
	//static struct employee emp1={"cairo",1},emp2={"Alex",1002};
	//struct employee *arr[2]={&emp1,&emp2};
	//struct employee (*(*pt)[2])=&arr;

	//printf("")

	return 0;
}
*/
