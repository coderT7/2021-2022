#pragma once
#include<cstdio>
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<cassert>
#include<Windows.h>
#include<direct.h>
#include<io.h>
#include <fstream>
#include<atlstr.h>
#include<regex>
#include<filesystem>
using namespace std;

enum CHOICE
{
	Exit,
	readTxt,
	delHyink,
	getWord,
	delDup,
	delFile,
	readFolder,
	removeFile
};

void delete_all(const char* fileName);

void delete_non_visualization(const char* fileName);

void del_funtion(const char* fileName);

void del_semicolon(const char* fileName);

void blank_line(const char* fileName);

void menu();
void _menu();

void hyperlink_delete(const char* fileName);

void read_text(const char* fileName);

int get_word_num(const char* fileName);

void remove_duplicates(const char* fileName);

void delete_file(const char* fileName);

void inside_floder();

void create_floder();

void remove_file(const char* fileName);

void get_all_file_name(const string& strPath);