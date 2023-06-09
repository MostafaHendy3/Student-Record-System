#ifndef Data_h
#define Data_h
#define PassWord "1234"
typedef struct student
{
    char *name;
    int Grade;
    int id;
    int age;
    char *password;
    int gender;
}Student;
extern struct admin
{
    char *name;
    char *password;
} Admin1;

#endif

