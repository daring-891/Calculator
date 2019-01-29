
#ifndef calc_h
#define calc_h

#define TRUE 1;
#define FALSE 0;

struct student_rec {
  int sno;
  float grade;
};
/*
 * Week 5: Stories 1-7
 * Input and output
 */
char get_operator(void);
int execute_operator(char operator);
int get_int(char *msg);
/*
 * Week 6: Stories 8-11
 * Arithmetic
 */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
/*
 * Week 7: Stories 12-14
 *
 */
int factorial(int a);
int gcd ( int a, int b );
void print_binary(int num_to_convert);
/*
 * Week 8: Stories 15-18
 *
 */
// 15: Print an array.
void print_array(int array[], int length);
// 16: Read an array
void read_array(int array[], int length);
// 17: Sort an array
void swap(int *a, int *b);
void sort(int array[], int length);
// 18: Calculate median
int median(int array[], int length);
/*
 * Week 9: Stories 19-24
 *
 */
// 19: Print a single student record.
float get_float(char *msg);
void print_student(struct student_rec student);
// 20: add a student to db; returns new length of db
int add_student(struct student_rec db[], int db_length);
// 21: print all records
void print_db(struct student_rec db[], int db_length);
// 22: add several records; returns new length of db
int create_db(struct student_rec db[], int db_length);
// 23: find the student with sno; return index of record
int find_student(int sno, struct student_rec db[], int db_length);
// 24: delete student with serial number sno; return new size of db
int delete_student(int sno, struct student_rec db[], int db_length);
#endif
