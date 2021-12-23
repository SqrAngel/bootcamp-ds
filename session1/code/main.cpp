#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//array: banyak elemen -> array of int, array of char, array of float, dkk.
//array of struct : elemen yang memeiliki beberapa tipe data

//CRUD: Create, Read, Update, Delete

struct Course
{
    /* data */
    char ID[10];
    char namaDosen[255];
};


struct Student
{
    /* data */
    char name[255];
    double GPA;
    Course c; //course yang diikuti oleh student
};

// 255 bytes + 8 bytes + 10 bytes + 255 bytes = size dari Student object

//malloc allocation
//malloc(sizeof(Student) atau 255 bytes + 8 bytes + 10 bytes + 255 bytes)


// Create
// Student create(char name[], double GPA, char id[], char namaDosen[]){

// }
Student* create(const char *name, double GPA, const char *ID, const char *namaDosen){
    // 6 baris
    Student *newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->GPA = GPA;
    strcpy(newStudent->c.ID, ID);
    strcpy(newStudent->c.namaDosen, namaDosen);
 
    return newStudent; ///return variable pointer yg menunjuk ke address newStudent
}

// Read
void read(Student *s) { //yang kita pass adalah pointer yangmenunjuk ke alamat student
    printf("Name: %s\n", s->name); //(*s).name
    printf("GPA: %lf\n", s->GPA); //(*s).GPA
    printf("Course ID: %s\n", s->c.ID); //(*s).c.ID
    printf("Nama Dosen: %s\n", s->c.namaDosen); //(*s).c.namaDosen
}

void update(Student *s){
    strcpy(s->name, "Tanto");
}

void remove(Student *s) {
    free(s); // freee alocated memory from malloc 
    s = NULL; //protect against dangling pointer
}

int main(){
    // Student s = {"Joshua", 3.90, {"COMP6047", "Pak Indra"}};
    // printf("%s ", s.name);
    // printf("%s\n", s.c.namaDosen);

    //create("Joshua", 3.90, "COMP6047", "Pak Indra"); // --> ini coding tidak akan jalan karena bukan passing variable
    //caranya kita buat seperti ini 
    // char name[] = "Joshua";
    // char ID[] = "6047";
    // char namaDosen[] = "Pak Indra";
    // tapi cara ini tidak efisien karena struct memiliki banyak variable dan data pasti banyak yang akan dimasukan
    // create(name, 3.90, ID, namaDosen);
    Student *s = create("Joshua", 3.9, "COMP6047", "Pak Indra");
    read(s);
    update(s);
    // remove(s);
    read(s);
    




    return 0;
}