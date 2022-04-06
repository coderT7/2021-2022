#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//为了防止重名 这里给个id进行标识
int id = 1;

static void check_capacity(Contanct& contanct) {
	if (contanct.size == contanct.capacity) {
		PeoInfo* tmp = (PeoInfo*)realloc(contanct.info, sizeof(PeoInfo) * contanct.capacity * 2);
		assert(tmp);
		contanct.info = tmp;
		contanct.capacity *= 2;
	}
}

static void load_contanct(Contanct& contanct) {
	FILE* pFile = fopen("peoInfo.dat", "rb");
	assert(pFile);
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pFile)) {
		check_capacity(contanct);
		contanct.info[contanct.size++] = tmp;
		id++;
	}
	fclose(pFile);
	pFile = nullptr;
}

//初始化通讯录
void init_contanct(Contanct& contanct) {
	contanct.info = (PeoInfo*)malloc(sizeof(PeoInfo) * DEEAULT_MAX);
	contanct.size = 0;
	contanct.capacity = 4;
	load_contanct(contanct);
}

//打印通讯录
void print_contanct(Contanct& contanct) {
	
	if (contanct.size == 0) {
		cout << "通讯录目前无联系人！" << endl;
		return;
	}
	else {
		printf("%-8s%-8s%-8s%-8s%-20s%-16s\n", "序号", "姓名", "年龄", "性别", "住址", "手机号码");
		PeoInfo tmp;
		int index = 0;
		while (index < contanct.size) {
			tmp = contanct.info[index];
			printf("%-8d%-8s%-8d%-8s%-20s%-16s\n", tmp.num, tmp.name, tmp.age, tmp.sex, tmp.address, tmp.phone);
			index++;
		}
	}
}

//增加联系人
void add_peoInfo(Contanct& contanct) {
	check_capacity(contanct);
	int n = 0;
	cout << "请输入要添加几位联系人：";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入要添加的第" << i + 1 << "位联系人的姓名" << endl;
		cin >> contanct.info[contanct.size].name;
		cout << "请输入要添加的第" << i + 1 << "位联系人的年龄" << endl;
		cin >> contanct.info[contanct.size].age;
		cout << "请输入要添加的第" << i + 1 << "位联系人的性别" << endl;
		cin >> contanct.info[contanct.size].sex;
		cout << "请输入要添加的第" << i + 1 << "位联系人的住址" << endl;
		cin >> contanct.info[contanct.size].address;
		cout << "请输入要添加的第" << i + 1 << "位联系人的手机号码" << endl;
		cin >> contanct.info[contanct.size].phone;
		cout << "添加成功" << endl;
		contanct.info[contanct.size].num = id++;
		contanct.size++;
		int ans = 0;
		if (i + 1 < n) {
			cout << "是否要继续进行添加？" << endl << "输入0退出当前模块，输入其它数字默认继续添加" << endl;
			cout << "请输入：";
			cin >> ans;
			if (!ans) break;
		}
		check_capacity(contanct);
	}
}
//查找联系人
bool search_peoInfo(Contanct& contanct, string name) {
	bool flag = 1;
	for (int i = 0; i < contanct.size; i++) {
		if (strcmp(contanct.info[i].name, name.c_str()) == 0) {
			if (flag) {
				printf("%-8s%-8s%-8s%-8s%-20s%-16s\n", "序号", "姓名", "年龄", "性别", "住址", "手机号码");
			}
			PeoInfo tmp;
			tmp = contanct.info[i];
			printf("%-8d%-8s%-8d%-8s%-20s%-16s\n", tmp.num, tmp.name, tmp.age, tmp.sex, tmp.address, tmp.phone);
			flag = 0;
		}
	}
	if (flag) {
		cout << "该联系人不存在" << endl;
		return false;
	}
	return true;
}
//删除联系人
void del_peoInfo(Contanct& contanct) {
	if (contanct.size == 0) {
		cout << "当前通讯录无联系人！" << endl;
		return;
	}
	string name;
	cout << "请输入要删除的联系人的姓名：";
	cin >> name;
	bool ret = search_peoInfo(contanct, name);
	if(ret) {
		cout << "请输入要删除的联系人的序号：";
		int index = 0;
		cin >> index;
		index -= 1;
		while (index < contanct.size - 1) {
			contanct.info[index] = contanct.info[index + 1];
			contanct.info[index].num -= 1;
			index++;
		}
		contanct.size--;
		cout << "删除成功！" << endl;
		return;
	}
	else {
		cout << "该联系人不存在！" << endl;
		return;
	}

}

//修改联系人
void modify_peoInfo(Contanct& contanct) {
	if (contanct.size == 0) {
		cout << "当前通讯录无联系人！" << endl;
		return;
	}
	string name;
	cout << "请输入要修改的联系人的姓名：" << endl;
	cin >> name;
	bool ret = search_peoInfo(contanct, name);
	if (ret) {
		int index = 0;
		cout << "请输入要修改的联系人的序号：";
		cin >> index;
		index -= 1;
		char tmp[20] = { 0 };
		int age = 0;
		cout << "请输入该联系人新的姓名：" << endl;
		cin >> tmp;
		strcpy(contanct.info[index].name, tmp);
		cout << "请输入该联系人新的年龄：" << endl;
		cin >> age;
		contanct.info[index].age = age;
		cout << "请输入该联系人新的性别：" << endl;
		cin >> tmp;
		strcpy(contanct.info[index].sex, tmp);
		cout << "请输入该联系人新的住址：" << endl;
		cin >> tmp;
		strcpy(contanct.info[index].address, tmp);
		cout << "请输入该联系人新的手机号码：" << endl;
		cin >> tmp;
		strcpy(contanct.info[index].phone, tmp);
		cout << "修改完毕！" << endl;
		return;
	}
	else {
		cout << "该联系人不存在！" << endl;
		return;
	}
}

static void m_swap(char* a, char* b, int count) {
	while (count--) {
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

static int cmp_struct(const void* a, const void *b) {
	return strcmp((*(PeoInfo*)a).name, (*(PeoInfo*)b).name);
}

static void bullet_sort(void* base, size_t num, size_t size, int (*cmp)(const void*, const void*)) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0) {
				m_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}

//排序联系人
void sort_peoInfo(Contanct& contanct) {
	qsort(contanct.info, contanct.size, sizeof(PeoInfo), cmp_struct);
	cout << "排序完成" << endl;
}
//销毁通讯录
void destroy_contanct(Contanct& contanct) {
	cout << "你确定要销毁通讯录吗，该操作不可逆！" << endl;
	cout << "请输入“确定”以开始销毁：";
	string tmp;
	cin >> tmp;
	if (tmp.compare("确定")) {
		free(contanct.info);
		contanct.size = 0;
		contanct.capacity = 0;
	}
	else {
		return;
	}
}

void save_stu(Contanct& contanct) {
	
	if (contanct.size == 0) {
		cout << "当前通讯录无信息！" << endl;
		return;
	}
	FILE* pFile = fopen("peoInfo.dat", "w");
	for (int i = 0; i < contanct.size; i++) {
		fwrite(contanct.info + i, sizeof(PeoInfo), 1, pFile);
	}
	cout << "保存成功" << endl;
	fclose(pFile);
	pFile = nullptr;
}