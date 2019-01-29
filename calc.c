#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#include <string.h>
struct student_rec db[80];
int db_length = 0;

int test_array[80] = {1, 2, 3};

/*****************************************
 * Execute
 ****************************************/

int execute_operator(char operator) {
  int operand1 = 0, operand2 = 0;
  struct student_rec student;

  switch (operator) {
/*
 * Story 3: As a user, I want to be able to exit the program, so I can
 * tell it I am finished.
 */
  case 'x': // Story 3
    /* Add code here */
	exit(0);
  case 'i': // Story 6 and 7
    operand1 = get_int("Enter int> ");
    printf("You entered %d\n",
           operand1);
    return TRUE;
	break;
  case '+': // Story 8
    operand1 = get_int("add> ");
    operand2 = get_int("to> ");
    printf("%d + %d = %d\n",
           operand1,
           operand2,
           add(operand1, operand2));
    return TRUE;
	break;
  case '-': // Story 9
    operand1 = get_int("subtract> ");
    operand2 = get_int("from> ");
    printf("%d - %d = %d\n",
           operand1,
           operand2,
           subtract(operand1, operand2));
    return TRUE;
	break;
  case '*': // Story 10
    operand1 = get_int("multiply> ");
    operand2 = get_int("by> ");
    printf("%d * %d = %d\n",
           operand1,
           operand2,
           multiply(operand1, operand2));
    return TRUE;
	break;
  case '/': // Story 11
    operand1 = get_int("divide> ");
    operand2 = get_int("by> ");
    printf("%d / %d = %f\n",
           operand1,
           operand2,
           divide(operand1, operand2));
    return TRUE;
	break;
  case '!': // Story 12
    operand1 = get_int("Enter int for factorial> ");
    printf("%d! = %d\n",
           operand1,
           factorial(operand1));
    return TRUE;
	break;
  case 'g': // Story 13
    operand1 = get_int("Enter first int for gcd> ");
    operand2 = get_int("Enter second int for gcd> ");
    printf("Greatest Common Divisor of %d and %d is %d\n",
           operand1,
           operand2,
           gcd(operand1, operand2));
    return TRUE;
	break;
  case 'b': // Story 14
    operand1 = get_int("Enter int to convert to binary> ");
    printf("%d in binary is ", operand1);
    print_binary(operand1);
    printf("\n");
    return TRUE;
	break;
   case 'r': // Story 16
    operand1 = get_int("Enter the length of the array> ");
    read_array(test_array, operand1);
    printf("You entered: ");
    print_array(test_array, operand1);
    return TRUE;
	break;
  case 's': // Story 17
    operand1 = get_int("Enter the length of the array> ");
    read_array(test_array, operand1);
    printf("You entered: ");
    print_array(test_array, operand1);
    sort(test_array, operand1);
    printf("sorted it is: ");
    print_array(test_array, operand1);
    return TRUE;
	break;
  case 'm': // Story 18
    operand1 = get_int("Enter the length of the array> ");
    read_array(test_array, operand1);
    printf("You entered: ");
    print_array(test_array, operand1);
    sort(test_array, operand1);
    printf("sorted it is: ");
    print_array(test_array, operand1);
    printf("It's median is %d\n", median(test_array, operand1));
    return TRUE;
	break;
  case 'S': // Story 19
    printf("Enter a student's record:\n");
    student.sno = get_int("Enter serial #> ");
    student.grade = get_float("Enter GPA> ");
    print_student(student);
    return TRUE;
	break;
  case 'A': // Story 20
    db_length = add_student(db, db_length);
    print_student(db[db_length - 1]);
    return TRUE;
	break;
  case 'P': // Story 21
    print_db(db, db_length);
    return TRUE;
	break;
  case 'C': // Story 22
    db_length = create_db(db, db_length);
    print_db(db, db_length);
    return TRUE;
	break;
  case 'F': // Story 23
    operand1 = get_int("Find Serial #> ");
    operand2 = find_student(operand1, db, db_length);
    if (-1 == operand2) {
      printf("Student not found\n");
    } else {
      print_student(db[operand2]);
    }
    return TRUE;
	break;
  case 'D': // Story 24
    printf("Student number to delete: ");
    operand1 = get_int("Enter Serial #> ");
    db_length = delete_student(operand1, db, db_length);
    print_db(db, db_length);
    return TRUE;
	break;
/*
 * Story 4
 * As a user, I the calculator to notify me when I have entered an
 * incorrect command, so I know when I have make a typo.
 */

  /* Put code here */
	default : printf("invalid Command");
  }
  return TRUE;
}

/* Story 5
 * As a user,I want the calculator to take a single character off the
 * line, so it doesn't print out an “invalid command” message every
 * time I enter a command
 */

int is_whitespace(char c) {
  return (' ' == c || '\t' == c || '\n' == c);
}

char get_first_non_white(char *s) {
  for (int i = 0; '\0' != s[i] && i < 80; i++) {
    if (!is_whitespace(s[i])) {
      return(s[i]);
    }
  }
  return('\0');
}

/*
 * Story 2: The programs prints “Enter command> “ and then accepts a
 * command and terminates. It does not do anything else.
 *
 * Story 2 needs to be moved below story 5 because it uses functions from
 * story 5
 *
 * Stories 1 and 3 are in main.c
 *
 * Story 4 is in execute_command
 */

char get_operator(void) {
  /* Put code here */
	char command[80];
	printf("\nenter command>");
	scanf("%s",command);
if(get_first_non_white(command)=='\0')
	{
		return get_operator();
	}


  return *command;
}

/*
 * Story 7: As a user, I want the calculator to notify me when I have
 * entered incorrect integer operand , so I know when I have made a
 * typo.
 */

int consume_digits(char *s) {
  int i = 0;
  while (i < 80 && ('0' == s[i] ||
                    '1' == s[i] ||
                    '2' == s[i] ||
                    '3' == s[i] ||
                    '4' == s[i] ||
                    '5' == s[i] ||
                    '6' == s[i] ||
                    '7' == s[i] ||
                    '8' == s[i] ||
                    '9' == s[i] )
         ) {
    i++;
  }
  return i;
}

int can_be_int(char *s) {
  /* Put code here */
	int digits,strlength,operand;
	strlength=strlen(s);
	digits=consume_digits(s);
	if(strlength==digits)
	{
		sscanf(s,"%d",&operand);
		return operand;
	}
	else
	{
		printf("%s",s);
		printf("  is not an integer,");	
		return get_int(" try again>");
  	}

}
/*
 * Story 6: As a user, I want to be able to enter a int operand, so my
 * calculator can do integer arithmetic.
 *
 * Function needs to be augmented for Story 7
 */

int get_int(char *msg) {
  /* Put code here */
	int operand;
	char input[80];
	printf("%s",msg);
	scanf("%s",input);
	operand=can_be_int(input);
  	return operand;
}

/*
 * Story 8: As a user, I want to be able to add two numbers using the
 * program, so I can use it for addition.
 */

int add(int a, int b) {
  /* Put code here */
  return a+b;
}

/*
 * Story 9: As a user, I want to be able to subtract two numbers using the
 * program, so I can use it for addition.
 */

int subtract(int a, int b) {
  /* Put code here */
  return a-b;
}

/*
 * Story 10: As a user, I want to be able to multiply two numbers
 * using the program, so I can use it for addition.
 */

int multiply(int a, int b) {
  /* Put code here */
  return a*b;
}

/*
 * Story 11: As a user, I want to be able to divide two numbers using the
 * program, so I can use it for addition.
 */

float divide(int a, int b)
{
  /* Put code here */
  return a/b;
}

/*
 * Story 12: As a user, I want to be able to use the program to
 * calculate a factorial, so I can use the calculator for factorials.
 */

int factorial(int a)
{
	int fact=1;
	for(int i=1;i<=a;i++)
	fact=fact*i;
  return fact;
}

/*
 * Story 13: As a user, I want to be able to use the program to
 * calculate the greatest common divisor (GCD) of two numbers, so I
 * can use the calculator for GCD.
 */

int gcd ( int a, int b )
{
	if(a==0)
	return b;
	else
	return gcd(b%a,a);
}

/*
 * Story 14: As a user, I want to be able to use the program to
 * print decimal number in binary representation, so I can use the
 * calculator for binary conversion.
 */

void print_binary(int num_to_convert)
{
  /* Put code here */
	if(num_to_convert>1)
		print_binary(num_to_convert/2);
	printf("%d",num_to_convert%2);
}

/*****************************************
 * Arrays
 ****************************************/

/*
 * Story 15: As a user, I want to be able to print out an array so I
 * can see the results of my array algorithms.
 */

void print_array(int array[], int length)
{
  /* Put code here */
	int i;
	for(i=0;i<length-1;i++)
	{
		printf("%d ,",array[i]);
	}
	printf("   %d\n",array[length-1]);

}

/*
 * Story 16: As a user, I want to enter an array of numbers so I can
 * do calculations on them.
 */

void read_array(int array[], int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("enter integer>");
		scanf("%d",&array[i]);
	}

  /* Put code here */
}

/*
 * Story 17: As a user, I want to be able to sort an array of numbers
 * so I can calculate the median.
 */

void swap (int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
  /* Put code here */
}

void sort(int array[], int length)
{
  /* Put code here */
	int i,j;
	for(i=0;i<length-1;i++)
	{
		for(j=0;j<length-i-1;j++)
		{	
			if(array[j]>array[j+1])
			{	
				swap(&array[j],&array[j+1]);
			}
		}
	}
}

/*
 * Story 18: As a user, I want to be able to find the median of an
 * array of numbers, so I can use it for calculate the median.
 */

int median(int array[], int length) {
  /* Put code here */
	int median;
	sort(array,length);
	if(length%2==0)
	{	
		median=(array[(length/2)-1]+array[((length/2))])/2;
	}
	else
	{
		median=array[length/2];	
	}
  return median;
}

/*****************************************
 * Student DB
 ****************************************/

/*
 * Story 19: As a user, I want to print a students record, so I can
 * see the students grade and serial number.
 */

void print_student(struct student_rec s)
{
  /* Put code here */
	printf( "\nstudent : sno\t=  %d,grade = %f ",s.sno,s.grade);
}

/*
 * Story 20: As a user, I want to be able to add a student to the list
 * of students, so I can add student grades to my class.
 */

float can_be_float(char *s)
{
  /* Put code here */
	int b_point=0,a_point=0,strlength; /*b_point = digit before the floating point....
					     a_point= digits after the floating point.....*/
	int i,j;
	float operand;
	char si[79],sj[80];
	strlength=strlen(s);
		for(i=0;s[i]!='\0'&&i<80;i++)		/* si is the string before the folating point in the string*/
		{
			if(s[i]=='.')
			{
				strlength--;			/*if string contain float point remove it size so it can be compare with no of digit easily*/
				break;
			}
		}
		i++;
		strcpy(sj,s);
		b_point=consume_digits(s);
		for(j=0;i!='\0'&&i<79;i++)			/*sj is the string after the floating point in the string*/ 
		{
			si[j]=sj[i];
			j++;
		}
		a_point=consume_digits(si);
		if(strlength==a_point+b_point)
		{
			sscanf(s,"%f",&operand);
			return operand;
		}

	{
	printf("%s is not a float ",s);	
	return get_float("try again>");
	}
}


float get_float(char *msg) {
  /* Put code here */
	float grade;
	char input[80];
	printf("%s",msg);
	scanf("%s",input);
	grade=can_be_float(input);
	return grade;
}

int add_student(struct student_rec db[], int db_length)
{
  /* Put code here */
	printf("Enter a student's record :\n");
	db[db_length].sno=get_int("Enter Serial #> ");
	db[db_length].grade=get_float("Enter GPA> ");
	db_length++;

  	return db_length;
}

/*
 * Story 21: As a user, I want to print all of the students records,
 * so I can see the grades of the entire class.
 */

void print_db(struct student_rec db[], int db_length)
{
  /* Put code here */
	int i=0;
	for(i=0;i<db_length;i++)
	{

		print_student(db[i]);
        }

}
/*
 * Story 22: As a user I want to save a class of students' records so
 * I can track a set of grades.
 */

int create_db(struct student_rec db[], int db_length)
{
  /* Put code here */
	int n;
	printf("how many student");
	scanf("%d",&n);
	n=n+db_length;
	for(int i=db_length;i<n;i++)
	{
		db_length=add_student(db,db_length);
	}
  return db_length;
}

/*
 * Story 23: As a user, I want to find a student grade by serial
 * number, so I can track grades in a class.
 */

int find_student(int student_no, struct student_rec db[], int db_length)
{
	
  /* Put code here */
  
	int z=-1;
	for(int i=0;i<db_length;i++)
	{
		if(student_no==db[i].sno)
		{
			z=i;
			break;
		}
	}
	return z;
}

/*
 * Story 24: As a user I want to be able to remove a student from the
 * class, so I can delete students who drop.
 */

int delete_student(int student_no, struct student_rec db[], int db_length)
{
  /* Put code here */
	int i;
	i=find_student(student_no,db,db_length);
	if(i==-1)
	{
		printf("student not found");
	}
	else
	{
		printf("Student found and after deletion ");	
		for(int j=i;j<db_length-1;j++)
		{
			db[j]=db[j+1];

		}
		db_length--;

	}
  return db_length;
}
