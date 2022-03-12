#pragma once
#include<cstdio>
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<cassert>
#include<Windows.h>
using namespace std;

enum CHOICE
{
	Exit,
	readTxt,
	delHyink,
	getWord,
	delDup,
	delFile
};

void menu();

void hyperlink_delete(const char* fileName);

void read_text(const char* fileName);

int get_word_num(const char* fileName);

void remove_duplicates(const char* fileName);

void delete_file(const char* fileName);