#define _CRT_SECURE_NO_WARNINGS 1

#include"menu.h"
#include"All.h"
void all_menu::show_menu()
{
	cout << "������������Ӧѡ�" << endl;
	cout << "1��ʵ��һ��س������" << endl;
	cout << "2��ʵ�����س������" << endl;
	cout << "3��ʵ������س������" << endl;
	cout << "4��ʵ������س������" << endl;
	cout << "5��ʵ������س������" << endl;
	cout << "6��ʵ������س������" << endl;
	cout << "0���˳�����" << endl;
}
static void do_wrok(menu*& m)
{
	int n = 0;
	m->show_menu();
	cin >> n;
	m->get_enter(n);
	delete m;
}
void all_menu::get_enter(int enter)
{
	int n = 0;
	switch (enter)
	{
	case 0:
		break;
	case 1:
	{
		menu* m = new menu1;
		do_wrok(m);
		break;
	}
	//case 2:
	//{
	//	menu* m = new menu2;
	//	do_wrok(m);
	//	break;
	//}
	//case 3:
	//{
	//	menu* m = new menu3;
	//	do_wrok(m);
	//	break;
	//}
	//case 4:
	//{
	//	menu* m = new menu4;
	//	do_wrok(m);
	//	break;
	//}
	//case 5:
	//{
	//	menu* m = new menu5;
	//	do_wrok(m);
	//	break;
	//}
	//case 6:
	//{
	//	menu* m = new menu6;
	//	do_wrok(m);
	//	break;
	//}
	default:
		break;
	}
}

void menu1::show_menu()
{
	cout << "��ѡ����Ҫ���Ե���Ŀ��" << endl;
	cout << "1.��3�������ĺ�" << endl;
	cout << "2.��2�����ĺ͡��������" << endl;
	cout << "3.��2�����нϴ��ߣ���3�������ֵ" << endl;
	cout << "4.����Բ�İ뾶����Բ��������ܳ�" << endl;
	cout << "5.����Ļ���������hello world!��" << endl;
	cout << "6.������úÿ��ķ�ʽ������Լ���ѧ�š��������Ա����ա��༶���Լ��������֡�" << endl;
	cout << "0.������һ��" << endl;
}
void menu1::get_enter(int enter)
{
	int a, b, c;
	int tmp = enter;
	while (tmp)
	{
		switch (tmp)
		{
		case 0:
			break;
		case 1:
			cout << "������Ҫ������͵���������:";
			cin >> a >> b >> c;
			sum_three(a, b, c);
			break;
		case 2:
			cout << "������Ҫ���������������������";
			cin >> a >> b;
			four_arithmetic(a, b);
			break;
		case 3:
			cout << "������Ҫ���бȽϵ���λ����";
			cin >> a >> b >> c;
			max_num(a, b, c);
			break;
		case 4:
			cout << "������Բ���ܳ���";
			cin >> a;
			cal_circle(a);
			break;
		case 5:
			m_print();
			break;
		case 6:
			m_print(2);
			break;
		default:
			cout << "��������������ѡ��";
			break;
		}
		system("pause");
		system("cls");
		menu1().show_menu();
		cin >> tmp;
	}
}
void menu2::show_menu()
{
	cout << "1.ʵ����Ϣ��ʽ�����" << endl;
	cout << "2.Сд��ĸת��д" << endl;
	cout << "3.����������ͬ�������ݺ󣬾����ʵ������㣨�ӡ������ˡ����������" << endl;
	cout << "4.ʵ�ּ�������������������������ͱ����" << endl;
	cout << "5.��֤int��char��float��double��long int��short int���������͵ĳ���" << endl;
	cout << "0.������һ��";
}
//void menu3::show_menu()
//{
//	cout << "1�������Լ������գ�����ƴ��������ĸ�����䣬Ȼ�����" << endl;
//	cout << "2�������Լ��߿����пγ̵ĳɼ�, ����ƽ���ɼ��ͱ�׼��������" << endl;
//	cout << "3�������ѧ������ϵͳ���Ĳ˵�" << endl;
//	cout << "4������ƿ�����֤��������ʱ������ʾ�������ģ���֮�ԡ�#��"<< endl;
//	cout << "5������3�ſεĳɼ�����������гɼ�������һ�ſ�" << endl;
//	cout << "6������������ѧ�������������գ�������ߵ����������ն�����ͬ�ģ������yes,�������no" << endl;
//	cout << "7��ʲô�Ƕ�·���򣿱�д������֤��·����" << endl;
//	cout << "8���Լ������ǰ׺�ͺ�׺��ʲô���𣿱�д������֤֮" << endl;
//	cout << "7. ��д�������һԪ���η���" << endl;
//	cout << "0.������һ��";
//}
//void menu4::show_menu()
//{
//	cout << "1.һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ���" << endl;
//	cout << "2.Ϊʹ���ı��ܣ�������һ�����ɽ���ת�������룬�ձ����ٰ�Լ���Ĺ��ɽ������ԭ��" << endl;
//	cout << "3.�ж�101 - 200֮���ж��ٸ��������������������" << endl;
//	cout << "4.��ӡ����" << endl;
//	cout << "5.��1 + 2!+ 3!+ ... + 20!�ĺ͡�Ҫ�󣺽׳��ú���ʵ��" << endl;
//	cout << "6.���һ������ģ����Ӳ�ҵĲ���" << endl;
//	cout << "0.������һ��" << endl;
//}
//void menu5::show_menu()
//{
//	cout << "1.��д������ƺ�����ʵ�ְ�����������ַ�������ϲ����ϲ�ʱ����Сд��ĸ�ĳɴ�д��" << endl;
//	cout << "2.����һ���ɵ�����ɵ��ַ��������ַ���������Ӧ����"<< endl;
//	cout << "3.���֤���봦��" << endl;
//	cout << "4.��Ʒ�������֤C�����У�������������ʱ��������ջ��˳�򡣣��������������������ӣ�" << endl;
//	cout << "5.��Ʒ�������֤C�����У���ָ������Ĵ洢�ռ��������޹أ�ָ������㿴���͡��Ľ��ۡ�" << endl;
//	cout << "0.������һ��";
//}
//void menu6::show_menu()
//{
//	cout << "1.��һ���������ĸ�λ�����" << endl;
//	cout << "2.��һ������������" << endl;
//	cout << "3.��������Լ�����������øú������������󹫱����ĺ���" << endl;
//	cout << "4.��һ����������Ϊ������" << endl;
//	cout << "5.ʹ���ṩ0 - 9���ֵ�����ģ����д��ʾ��ģ����" << endl;
//	cout << "6.��д������ƺ�����ʵ�ְ�����������ַ�������ϲ����ϲ�ʱ����Сд��ĸ�ĳɴ�д��" << endl;
//	cout << "7.���ı��ļ�����һ�����㷨���м���" << endl;
//	cout << "8.��������רҵ��ѧ����ѧ��ҵ��ķ���" << endl;
//	cout << "0.������һ��";
//}



