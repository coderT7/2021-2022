#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//Ϊ�˷�ֹ���� �������id���б�ʶ
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

//��ʼ��ͨѶ¼
void init_contanct(Contanct& contanct) {
	contanct.info = (PeoInfo*)malloc(sizeof(PeoInfo) * DEEAULT_MAX);
	contanct.size = 0;
	contanct.capacity = 4;
	load_contanct(contanct);
}

//��ӡͨѶ¼
void print_contanct(Contanct& contanct) {
	
	if (contanct.size == 0) {
		cout << "ͨѶ¼Ŀǰ����ϵ�ˣ�" << endl;
		return;
	}
	else {
		printf("%-8s%-8s%-8s%-8s%-20s%-16s\n", "���", "����", "����", "�Ա�", "סַ", "�ֻ�����");
		PeoInfo tmp;
		int index = 0;
		while (index < contanct.size) {
			tmp = contanct.info[index];
			printf("%-8d%-8s%-8d%-8s%-20s%-16s\n", tmp.num, tmp.name, tmp.age, tmp.sex, tmp.address, tmp.phone);
			index++;
		}
	}
}

//������ϵ��
void add_peoInfo(Contanct& contanct) {
	check_capacity(contanct);
	int n = 0;
	cout << "������Ҫ��Ӽ�λ��ϵ�ˣ�";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "������Ҫ��ӵĵ�" << i + 1 << "λ��ϵ�˵�����" << endl;
		cin >> contanct.info[contanct.size].name;
		cout << "������Ҫ��ӵĵ�" << i + 1 << "λ��ϵ�˵�����" << endl;
		cin >> contanct.info[contanct.size].age;
		cout << "������Ҫ��ӵĵ�" << i + 1 << "λ��ϵ�˵��Ա�" << endl;
		cin >> contanct.info[contanct.size].sex;
		cout << "������Ҫ��ӵĵ�" << i + 1 << "λ��ϵ�˵�סַ" << endl;
		cin >> contanct.info[contanct.size].address;
		cout << "������Ҫ��ӵĵ�" << i + 1 << "λ��ϵ�˵��ֻ�����" << endl;
		cin >> contanct.info[contanct.size].phone;
		cout << "��ӳɹ�" << endl;
		contanct.info[contanct.size].num = id++;
		contanct.size++;
		int ans = 0;
		if (i + 1 < n) {
			cout << "�Ƿ�Ҫ����������ӣ�" << endl << "����0�˳���ǰģ�飬������������Ĭ�ϼ������" << endl;
			cout << "�����룺";
			cin >> ans;
			if (!ans) break;
		}
		check_capacity(contanct);
	}
}
//������ϵ��
bool search_peoInfo(Contanct& contanct, string name) {
	bool flag = 1;
	for (int i = 0; i < contanct.size; i++) {
		if (strcmp(contanct.info[i].name, name.c_str()) == 0) {
			if (flag) {
				printf("%-8s%-8s%-8s%-8s%-20s%-16s\n", "���", "����", "����", "�Ա�", "סַ", "�ֻ�����");
			}
			PeoInfo tmp;
			tmp = contanct.info[i];
			printf("%-8d%-8s%-8d%-8s%-20s%-16s\n", tmp.num, tmp.name, tmp.age, tmp.sex, tmp.address, tmp.phone);
			flag = 0;
		}
	}
	if (flag) {
		cout << "����ϵ�˲�����" << endl;
		return false;
	}
	return true;
}
//ɾ����ϵ��
void del_peoInfo(Contanct& contanct) {
	if (contanct.size == 0) {
		cout << "��ǰͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	string name;
	cout << "������Ҫɾ������ϵ�˵�������";
	cin >> name;
	bool ret = search_peoInfo(contanct, name);
	if(ret) {
		cout << "������Ҫɾ������ϵ�˵���ţ�";
		int index = 0;
		cin >> index;
		index -= 1;
		while (index < contanct.size - 1) {
			contanct.info[index] = contanct.info[index + 1];
			contanct.info[index].num -= 1;
			index++;
		}
		contanct.size--;
		cout << "ɾ���ɹ���" << endl;
		return;
	}
	else {
		cout << "����ϵ�˲����ڣ�" << endl;
		return;
	}

}

//�޸���ϵ��
void modify_peoInfo(Contanct& contanct) {
	if (contanct.size == 0) {
		cout << "��ǰͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	string name;
	cout << "������Ҫ�޸ĵ���ϵ�˵�������" << endl;
	cin >> name;
	bool ret = search_peoInfo(contanct, name);
	if (ret) {
		int index = 0;
		cout << "������Ҫ�޸ĵ���ϵ�˵���ţ�";
		cin >> index;
		index -= 1;
		char tmp[20] = { 0 };
		int age = 0;
		cout << "���������ϵ���µ�������" << endl;
		cin >> tmp;
		strcpy(contanct.info[index].name, tmp);
		cout << "���������ϵ���µ����䣺" << endl;
		cin >> age;
		contanct.info[index].age = age;
		cout << "���������ϵ���µ��Ա�" << endl;
		cin >> tmp;
		strcpy(contanct.info[index].sex, tmp);
		cout << "���������ϵ���µ�סַ��" << endl;
		cin >> tmp;
		strcpy(contanct.info[index].address, tmp);
		cout << "���������ϵ���µ��ֻ����룺" << endl;
		cin >> tmp;
		strcpy(contanct.info[index].phone, tmp);
		cout << "�޸���ϣ�" << endl;
		return;
	}
	else {
		cout << "����ϵ�˲����ڣ�" << endl;
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

//������ϵ��
void sort_peoInfo(Contanct& contanct) {
	qsort(contanct.info, contanct.size, sizeof(PeoInfo), cmp_struct);
	cout << "�������" << endl;
}
//����ͨѶ¼
void destroy_contanct(Contanct& contanct) {
	cout << "��ȷ��Ҫ����ͨѶ¼�𣬸ò��������棡" << endl;
	cout << "�����롰ȷ�����Կ�ʼ���٣�";
	string tmp;
	cin >> tmp;
	if (tmp.compare("ȷ��")) {
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
		cout << "��ǰͨѶ¼����Ϣ��" << endl;
		return;
	}
	FILE* pFile = fopen("peoInfo.dat", "w");
	for (int i = 0; i < contanct.size; i++) {
		fwrite(contanct.info + i, sizeof(PeoInfo), 1, pFile);
	}
	cout << "����ɹ�" << endl;
	fclose(pFile);
	pFile = nullptr;
}