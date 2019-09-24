/*Lab 05 CIS 308
 * By: Cesar Zavala
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    union {
        struct {
            char school[20];
        } kid;

        struct {
            char college[20];
            double GPA;
        } student;

        struct {
            char company[20];
            double salary;
        } adult;
    } kind;
    enum {kidK,studentK,adultK} typeK;

} Person;

void Display(Person * person){
    if(person->typeK == kidK){
        printf("%s, %d, %s\n", person->name,person->age,person->kind.kid.school);
    }
    else if(person->typeK == studentK){
        printf("%s, %d, %s, %f\n", person->name,person->age,person->kind.student.college,person->kind.student.GPA);
    }
    else if(person->typeK == adultK){
        printf("%s, %d, %s, %f\n", person->name,person->age,person->kind.adult.company,person->kind.adult.salary);
    }
}


int main() {


    Person Willie;
    strcpy(Willie.name, "Willie");
    Willie.age=20;
    strcpy(Willie.kind.student.college,"K-State");
    Willie.kind.student.GPA = 3.5;
    Willie.typeK = studentK;
    // Pass address of Willie to display method.
    Display(&Willie);

    Person * Alison;
    Alison = malloc(sizeof(Person));
    strcpy(Alison->name,"Alison");
    Alison->age = 10;
    strcpy(Alison->kind.kid.school, "Amanda Arnold Elementary");
    Alison->typeK = kidK;
    Display(Alison);

    Person * Bob;
    Bob = malloc(sizeof(Person));
    strcpy(Bob->name,"Bob");
    Bob->age = 35;
    strcpy(Bob->kind.adult.company,"Best Buy");
    Bob->kind.adult.salary = 45000;
    Bob->typeK = adultK;
    Display(Bob);

free(Alison);
free(Bob);



    return 0;
}