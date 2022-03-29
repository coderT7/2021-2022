#pragma once

#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct Student {
	string id;
	string name;
	int mark;
	Student(string _id, string _name, int _mark) : id(_id), name(_name), mark(_mark) {}
}student;

typedef struct List {
	struct List* prev;
	struct List* next;
	student stu;
	List(struct List* pr, struct List* ne, student st) : prev(pr), next(ne), stu(st) {}
}list;

list* init_list();

void add_stu(list* head, student stu);

void print_list(list* head);

void del_stu(list* head, string id);