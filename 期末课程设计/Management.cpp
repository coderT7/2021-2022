#include "Management.h"

#include<iostream>
#include<conio.h>
#include<thread>
#include<future>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<unordered_map>
#include<algorithm> 
using namespace std;

//�����ṩ����ȽϷ�ʽ�����㲻ͬ����������
inline static int cmp_salary(const void* arg1, const void* arg2) {
    return (*(Empoyee*)arg1).salary6 - (*(Empoyee*)arg2).salary6;
}
inline static int cmp_id(const void* arg1, const void* arg2) {
    return (*(Empoyee*)arg1).id - (*(Empoyee*)arg2).id;
}
inline static int cmp_name(const void* arg1, const void* arg2) {
    return (*(Empoyee*)arg1).name.compare((*(Empoyee*)arg2).name);
}
Management::Management()
{
    //�ڿ�ʼ��run��֮ǰ�������ȶ�ȡ������
    readFile("./Images/information.txt");
    //Ԥ�豳��ͼ�Ĵ�С�����������г�ʼ��������ֱ��ʹ������б���ͼ�ĳ�ʼ����
    m_bks.resize(25);
    //���ر���ͼ
    for (int i = 1; i <= 22; i++) {
        char tmp[100] = { 0 };
        sprintf_s(tmp, "./Images/bk%d.png", i);
        ::loadimage(&m_bks[i], tmp, Window::width(), Window::height());
    }
    
    //��������������ֺ�
    ::settextstyle(25, 0, "΢���ź�", 0,0,550,0,0,0);
    
    //�����˵��Ĺ��ܰ�ť
    menu_btns.push_back(new PushButton("�鿴������Ϣ"));
    menu_btns.push_back(new PushButton("��ӹ�����Ϣ"));
    menu_btns.push_back(new PushButton("ɾ��������Ϣ"));
    menu_btns.push_back(new PushButton("�޸Ĺ�����Ϣ"));
    menu_btns.push_back(new PushButton("���ҹ�����Ϣ"));
    menu_btns.push_back(new PushButton("ͳ�ƹ�����Ϣ"));
    menu_btns.push_back(new PushButton("�˳�ϵͳ"));
    cPushButton = new CirclePushButton("SAVE", 0, 0, 40);
    //����ÿ����ť��λ��
    for (int i = 0; i < menu_btns.size(); i++) {
        menu_btns[i]->setFixedSize(250, 50);
        int x = (Window::width() - menu_btns[i]->width()) / 2;
        int vspace = (Window::height() - (int)menu_btns.size() * menu_btns[i]->height()) / 2 ;
        int y = vspace + i * menu_btns[i]->height();

        menu_btns[i]->move(x, y);
    }
    cPushButton->move(menu_btns[1]->x() + menu_btns[1]->width() + cPushButton->width() - 20, menu_btns[0]->y() + 20);
    cPushButton->setBackgroundColor(COLORREF(RGB(253, 241, 255)));
    cPushButton->setHoverColor(COLORREF(RGB(237, 236, 255)));
    //�����������չʾ����
    m_table = new Table;
    m_salaryTable = new SalaryTable;
    //���������Լ���ͷ
    m_table->setRowCount(16);
    m_table->setHeader(m_header);

    m_salaryTable->setRowCount(16);
    m_salaryTable->setHeader(m_header);
    //��ְ�����ݶ��뵽�����
    for (auto& val : vec_staff) {
        m_table->insertData(val.formateInfo());
        m_salaryTable->insertData(val.formateInfo());
        m_salaryTable->allSalary += val.salary6;
        m_salaryTable->allSalary1 += val.salary1;
        m_salaryTable->allSalary2 += val.salary2;
        m_salaryTable->allSalary3 += val.salary3;
        m_salaryTable->allSalary4 += val.salary4;
        m_salaryTable->allSalary5 += val.salary5;
        //�����ͬʱ������ص�����ͳ��
        if (val.salary6 > 3000) m_salaryTable->moreThan3000Humans++;
        if (val.salary6 < 2000) m_salaryTable->lessThan2000Humans++;
        if (val.salary6 >= 2000 && val.salary6 <= 3000) m_salaryTable->between2000To3000Humans++;
    }
    
    //���б��
    m_table->move((Window::width() - m_table->width()) / 2, (Window::height()-m_table->height()) / 2);
    m_salaryTable->move((Window::width() - m_table->width()) / 2, (Window::height() - m_table->height()) / 3);

    //��ӽ���
    addBtn = new PushButton("���", 0, 0, 50, 30);
    addEdit = new EditLine("����˽������ݵ����");
    addTable = new Table;
    addTable->setRowCount(6);
    addTable->setHeader(m_header);
    addTable->move((Window::width() - addTable->width()) / 2, (Window::height() - addTable->height()) / 2);
    addEdit->move((Window::width() - addEdit->width()) / 2, addTable->y() - 100);
    addBtn->move(addEdit->x() + addEdit->width() + 5, addEdit->y());
    //ɾ������
    delBtnOfID = new PushButton("ɾ��", 0, 0, 50, 30);
    delEditOfID = new EditLine("���������ְ��id��������");
    delBtnOfName = new PushButton("ɾ��", 0, 0, 50, 30);
    delEditOfName = new EditLine("���������ְ��������������");
#if 0
    //confirmBtn = new PushButton("ȷ��", 0, 0, 50, 30);
    //cancelBtn = new PushButton("ȡ��", 0, 0, 50, 30);
#endif
    delTable = new Table;
    delTable->setRowCount(6);
    delTable->setHeader(m_header);
#if 0
    //confirmBtn->move(Window::width() / 2 - 2 * confirmBtn->width(), (Window::height() - confirmBtn->height()) / 8);
    //cancelBtn->move(Window::width() / 2 + cancelBtn->width(), confirmBtn->y());
#endif
    delTable->move((Window::width() - delTable->width()) / 2, (Window::height() - delTable->height()) / 3 + 50);
    delEditOfID->move((Window::width() - delEditOfID->width()) / 2 , delTable->y() - 100);
    delBtnOfID->move(delEditOfID->x() + delEditOfID->width() + 5, delEditOfID->y());
    delEditOfName->move(delEditOfID->x(), delEditOfID->y() - delEditOfID->height() - 10);
    delBtnOfName->move(delEditOfName->x() + delEditOfName->width() + 5, delEditOfName->y());

    //��ѯ����
    searchBtn = new PushButton("����", 0, 0, 50, 30);
    searchEdit = new EditLine("���������ְ��id����������������");
    searchTable = new Table;
    searchTable->setRowCount(6);
    searchTable->setHeader(m_header + "\tƽ������");
    searchTable->move((Window::width() - searchTable->width()) / 2, (Window::height() - searchTable->height()) / 3 + 50);
    searchEdit->move((Window::width() - searchEdit->width()) / 2, searchTable->y() - 100);
    searchBtn->move(searchEdit->x() + searchEdit->width() + 5, searchEdit->y());

    //�޸Ľ���
    option_btns.push_back(new PushButton("�޸�ID��"));
    option_btns.push_back(new PushButton("�޸�����"));
    option_btns.push_back(new PushButton("�޸Ļ�������"));
    option_btns.push_back(new PushButton("�޸�ְ����"));
    option_btns.push_back(new PushButton("�޸Ľ���"));
    option_btns.push_back(new PushButton("�޸�ҽ�Ʊ���"));
    option_btns.push_back(new PushButton("�޸Ĺ�����"));
    //����ÿ����ť�Ķ�Ӧλ��
    for (int i = 0; i < option_btns.size(); i++) {
        option_btns[i]->setFixedSize(200, 30);
        if (i < 4) {
            int y = (((Window::height() - searchTable->m_h) / 2) + searchTable->m_h) + 
                ((Window::height() - searchTable->m_h) / 4) - 100;
            int x = searchTable->x() - 90 + i * (option_btns[i]->width() + 10);
            option_btns[i]->move(x, y);
        }
        else {
            int y = (((Window::height() - searchTable->m_h) / 2) + searchTable->m_h) + 
                ((Window::height() - searchTable->m_h) / 4) - 50;
            int j = i - 4;
            int x = searchTable->x() - 90 + j * (option_btns[i]->width() + 10);
            option_btns[i]->move(x, y);
        }
    }

    //�������
    sort_btns.push_back(new PushButton("����ID����"));
    sort_btns.push_back(new PushButton("������������"));
    sort_btns.push_back(new PushButton("�����ܹ�������"));
    for (int i = 0; i < sort_btns.size(); i++) {
        sort_btns[i]->setFixedSize(140, 30);
        int y = m_table->y() + 2 * i * sort_btns[i]->height() - m_table->m_gridH;
        int x = m_table->x()+ m_table->m_gridW * m_table->m_cols + 20;

        sort_btns[i]->move(x, y);
    }

}

void Management::run()
{
    //ѡ��Ĭ���ǲ˵�
    int op = MENU;
    //���ڻ���ϸ���ʱ���������˸
    //ʹ��BeginBatchDraw();FlushBatchDraw();EndBatchDraw();������������������ͼģʽ���ɽ��
    Window::beginDraw();
    while (true) {
        //ÿ�ν��붼����һ����ȷ�����������ͬ��չʾ
        updateTableData();
        updataSalaryTableData();
        Window::clear();
        //���Ʊ���
        drawBackground();
        //ʱ�̼���������Ϣ
        if (Window::hasMsg())
        {
            m_msg = Window::getMsg();
            switch (m_msg.message)
            {
            case WM_KEYDOWN:		//������Ϣ
                switch (m_msg.vkcode)
                {
                case VK_ESCAPE:		//ESC�������ֵ
                    op = MENU;//����ESC���򷵻ز˵�����
                    break;
                }
                break;
            default:				//�����Ϣ
                event_loop();
                break;
            }
        }
#if 0
        if (_kbhit()) {
            if (_getch() == VK_ESCAPE) {
                op = MENU;
            }
        }
#endif
        //����ѡ��
        switch (op)
        {
        case Management::DISPLAY:
            display();
            background = 0;
            break;
        case Management::ADD:
            background = 1;
            //����µ����ݺ���±�񲢱��浽�ļ�
            add();
            break;
        case Management::ERASE: 
            background = 2;
            erase();
            break;
        case Management::MODIFY:
            background = 5;
            modify();
            break;
        case Management::SEARCH:
            background = 6;
            search();
            break;
        case Management::STATISTICS:
            background = 4;
            statistics();
            break;
        case Management::EXIT:
            //�˳��Զ���������
            saveFile("./Images/information.txt");
            exit(0);
            break;
        case Management::MENU:
            background = 3;
            op = menu();
            break;
        default: 
            break;
        } 
        Window::flushDraw();
    }
    Window::endDraw();
}
//�˵�
int Management::menu()
{
    cPushButton->show();
    
    if (cPushButton->is_clicked()) {
        saveFile("./Images/information.txt");
        cout << "����ɹ�" << endl;
    }
    for (int i = 0; i < menu_btns.size(); i++) {
        menu_btns[i]->show();
        //����ǰ��Ϣͬ�����˵���ť
        menu_btns[i]->event_loop(m_msg);
        //��������Ϣ�����ж�
        if(menu_btns[i]->is_clicked())
            return i;
    }
    return MENU;
}
//��ʾ����
void Management::display()
{
    //ÿ����ʾ����ǰĬ����ID��������
    sort(vec_staff.begin(), vec_staff.end());
    m_table->show();
}
//�������
void Management::add()
{
    addBtn->show();
    addEdit->show();
    addTable->show();
    //����û�в��ö��̵߳���ƣ����ж���ͬ������
    //��ֹÿ�ν���ú���tmp������ʼ������ʹ��static����
    static Empoyee tmp;
    int count = 0;
    char buf[1024] = { 0 };
    string text;
    memset(buf, 0, 1024);
    stringstream ss(buf);

    const char* str[] = { "������ID��","����������","�������������",
        "������ְ����","���������","������ҽ�Ʊ���","�����빫����" };
    //������򱻵�����������û����ʱ�ſɽ�������
    if (addEdit->is_clicked() && !addEdit->flag) {
    flag:
        //ѭ��¼���߸�������
        for (int i = 0; i < 7; i++) {
            //ÿ�ζ��ȳ�ʼ���������ʱ���飨��ֹ����Ī����bug��
            memset(buf, 0, 1024);
            //��������ȡ����ֱ��ȡ����������
            if (!InputBox(buf, 1024, str[i], "����¼�¼", NULL, 0, 0, false))
                return;
            //���Է��ֿ��ܻ��в��ɲ��bug���������߼�������ϸ�����ƣ���ȷ��¼���ID��Ψһ��
            if (!strcmp(str[i], "������ID��")) {
                tmp.id = atoi(buf);
                if (find(vec_staff.begin(), vec_staff.end(), tmp) != vec_staff.end()) {
                    while (strcmp(buf, "�������")) {
                        if (!InputBox(buf, 1024, "��ID�Ѵ��ڣ������롰������ˡ������½�������", "Error", 0, 0, 0, false)) {
                            return;
                        }
                        Sleep(200);
                    }
                    Sleep(1000);
                    //ֻ��������ȷ�˲��ܼ���¼�����ȡ��
                    goto flag;
                }
            }
            //�Կո�ָ�ÿ������
            text += (buf + (string)" ");
            //�����ܹ���
            if (i > 1) {
                count += atoi(buf);
            }
            ss << buf << " ";
        }
        //���������Ϣ��ʾ���ı�����
        addEdit->set_textContent(text);
        //�ı����ڴ�ʱ�������ݣ����ı����״̬��Ϊtrue
        addEdit->flag = true;
        //���ܹ���Ҳд������
        ss << string(to_string(count)) << " ";
        //�����ݷָ����ʱ�����ÿ����������
        ss >> tmp.id >> tmp.name >> tmp.salary1 >> tmp.salary2 >>
            tmp.salary3 >> tmp.salary4 >> tmp.salary5 >> tmp.salary6;
        //��¼�����ʱ�����������
        addTable->insertData(tmp.formateInfo());
        //����״̬����Ϊtrue�������ݣ�
        addTable->set_status(true);
    }
    //����ȷ�ϡ���ť��������ұ���������ݣ�����ȷ�ϰ�ť�Ǹ���������ӵĵ�һ�ε��
    if (addBtn->is_clicked() && addTable->get_status() && addBtn->flag == false) {
        //�����ݲ��������ݱ��У���Դ������ص�������
        vec_staff.push_back(tmp);
        //������ɺ���ť״̬����Ϊ�ѱ����
        addBtn->flag = true;
        //�����ܱ����ͳ�Ʊ�������
        updateTableData();
        updataSalaryTableData();
        //���ڡ���ӡ�����е������ѱ�������ܱ��ʸñ������ݿ������
        addTable->clear();
        //�������״̬�ÿ�
        addTable->set_status(false);
        InputBox((char*)string().c_str(), 1, "��ӳɹ�������ȷ�ϼ�������");
        //�������ļ�
        saveFile("./Images/information.txt");
    }
    //���ո��������ó�ʼ���Խ�����һ��¼��
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_SPACE) {
                addBtn->flag = false;
                addTable->clear();
                addTable->set_status(false);
                addEdit->flag = false;
                addEdit->set_textContent("����˽������ݵ����");
                Sleep(200);
            }
    }
}
//���±��
void Management::updateTableData()
{
    //����񡰸�ʽ����
    m_table->clear();
    //���´�Դ���в�������
    for (auto val : vec_staff){
        m_table->insertData(val.formateInfo());  
    }
}
//����ͳ�Ʊ��
void Management::updataSalaryTableData()
{
    m_salaryTable->clear();
    m_salaryTable->allSalary = 0;
    m_salaryTable->allSalary1 = 0;
    m_salaryTable->allSalary2 = 0;
    m_salaryTable->allSalary3 = 0;
    m_salaryTable->allSalary4 = 0;
    m_salaryTable->allSalary5 = 0;
    for (auto val : vec_staff) {
        m_salaryTable->insertData(val.formateInfo());
        m_salaryTable->allSalary += val.salary6;
        m_salaryTable->allSalary1 += val.salary1;
        m_salaryTable->allSalary2 += val.salary2;
        m_salaryTable->allSalary3 += val.salary3;
        m_salaryTable->allSalary4 += val.salary4;
        m_salaryTable->allSalary5 += val.salary5;
        if (val.salary6 > 3000) m_salaryTable->moreThan3000Humans++;
        if (val.salary6 < 2000) m_salaryTable->lessThan2000Humans++;
        if (val.salary6 >= 2000 && val.salary6 <= 3000) m_salaryTable->between2000To3000Humans++;
    }
}
//ͳ�Ʊ����Ϣ
void Management::statistics()
{
    m_salaryTable->show();

    int op = -1;
    for (int i = 0; i < sort_btns.size(); i++) {
        sort_btns[i]->show();
        //����ǰ��Ϣͬ�����˵���ť
        sort_btns[i]->event_loop(m_msg);
        //���ݰ�ť�ĵ����ȡ��Ӧ����ѡ��
        if (sort_btns[i]->is_clicked())
            op = i;
    }
    switch (op)
    {
    case 0: {
        //���ǰ�����߳���һС�������ֹ����������ܻ����bug
        Sleep(200);
        //���ÿ⺯�����ײ���ڿ��ţ��󲿷�����¶����Լ�д������죬��Ҫ�Ƿ����
        qsort(&vec_staff[0], vec_staff.size(), sizeof(vec_staff[0]), cmp_id);
        //�������Ա�����ݽ��и�����ͬ����ʾ
        updataSalaryTableData();
        updateTableData();
        Sleep(100);
        //�������ѡ����Ϊ-1����switchѡ��Ա����ظ�����
        op = -1;
    }
        break;
    case 1: {
        Sleep(200);
        qsort(&vec_staff[0], vec_staff.size(), sizeof(vec_staff[0]), cmp_name);
        updataSalaryTableData();
        updateTableData();
        Sleep(100);
        op = -1;
    }
        break;
    case 2: {
        Sleep(200);
        qsort(&vec_staff[0], vec_staff.size(), sizeof(vec_staff[0]), cmp_salary);
        updataSalaryTableData();
        updateTableData();
        Sleep(100);
        op = -1;
    }
        break;
    default:
        break;
    }
}

#if 0
//inline  bool Management::getChoice()
//{
//    int n = 10;
//    while (n) {
//        Sleep(200);
//        cout << "�ѽ����߳�" << endl;
//        confirmBtn->show();
//        confirmBtn->event_loop(Window::getMsg());
//        if (confirmBtn->is_clicked())
//            return true;
//        else if (cancelBtn->is_clicked())
//            return false;
//        n--;
//    }
//}
#endif

//ɾ������
void Management::erase()
{
    delEditOfID->show();
    delBtnOfID->show();
    delTable->show();
    delBtnOfName->show();
    delEditOfName->show();
#if 0
    //confirmBtn->show();
    //cancelBtn->show(); 
    //bool confirmFlag = false;
    //if (!confirmBtn->is_clicked() && !confirmBtn->getBtnClicked()) {
    //    
    //    cout << "��δȷ��" << endl;
    //    cout << confirmBtn->getBtnClicked() << endl;
    //}
    //else if(confirmBtn->is_clicked() && !confirmBtn->getBtnClicked()) {
    //    confirmBtn->setBtnClicked(true);
    //    Sleep(200);
    //    cout << "��ȷ��" << endl;
    //    cout << confirmBtn->getBtnClicked() << endl;
    //}
#endif
    //��ȡ�ı�����ı�
    std::string tmp;
    //����ɾ�������ڵĶ�Ӧ���ݣ���׼���������鷳��ɾ��ֻ�����õ�������
    std::vector<Empoyee>::iterator it = vec_staff.end();

    //��IDɾ��
    //���ı��򱻵�������ı�����û�����ݲſ��Խ����������ݵ�¼��
    if (delEditOfID->is_clicked() && delEditOfID->flag == false) {
        //��ȡ��������
        tmp = delEditOfID->getDelIDInput();
        if (tmp.empty())
            return;
        //����������չʾ���ı�����
        delEditOfID->set_textContent(tmp);
        //�Ӹ�����һ��ʼ��֪�����ɶ�������ˣ�ɾ��Ҳû�£��������ϸ���һ�֡��������ĸо�
        Sleep(1000);
        //ɶ��û�����򷵻���һ��
        if (tmp.empty())
            return;
        //���ı���״̬������Ϊ��
        delEditOfID->flag = true;
        //�о�����Ҫ���Ͱ�������Ҫ���Ͱ�ID���ֱ���У���ͬ����Ҫ���ǵĿ��ܸ���һЩ�����ܻ��漰�ظ�ɾ�����³��������
        delEditOfName->flag = true;
#if 0
        cout << delEditOfID->get_text() << endl;
#endif
    }
    //�������ɹ����������������ı������ݻ�ı䣬��ʱ�Ž�������
    if (delEditOfID->textChange()) {
        //��������ʱ����
        Empoyee empoyee;
        //���������
        std::stringstream stream;
        //��ȡ�ı����ڵ��ı�����
        tmp = delEditOfID->get_text();
        //����������ʱ������
        stream << tmp;
        stream >> empoyee.id;
        //��Դ����������Ӧid��ְ��
        it = find(vec_staff.begin(), vec_staff.end(), empoyee);
        //����ҵ�������뵽ɾ������н���չʾ
        if (it != vec_staff.end() && !delTable->get_status()){
            delTable->insertData(it->formateInfo());
            delTable->set_status(true);
        }
    }
    //ɾ����ť������˲��ҵ������Ѿ��������˶�Ӧ��ְ������ɾ����ťû�б�������Ž���ɾ��
    if (delBtnOfID->is_clicked() && it != vec_staff.end() && delBtnOfID->flag == false)
    {
#if 0
        cout <<  "��ǰ������id��" << it->id << endl;
        std::cout << "delete" << std::endl;
#endif
        int delID = it->id;
        //ֱ��ɾ����Ӧ��������Ӧ��Ԫ��
        vec_staff.erase(it);
        //���ɾ�����
        delTable->clear();
        //���������á��ա�
        it = vec_staff.end();
        //��ť״̬����Ϊ���ѵ����
        delBtnOfID->flag = true;
        //���±������
        updateTableData();
        updataSalaryTableData();
        char tmp[50];
        sprintf_s(tmp, "IDΪ %d ��������ɾ�����밴ȷ�ϼ�������", delID);
        InputBox((char*)string().c_str(), 1, tmp);
    }

    //������ɾ���������밴IDɾ����ͬ��ֻ�ǿ��ܴ���ͬ���������
    if (delEditOfName->is_clicked() && delEditOfName->flag == false) {
        tmp = delEditOfName->getDelNameInput();
        Sleep(1000);
        if (tmp.empty())
            return;
        delEditOfName->set_textContent(tmp);
        delEditOfName->flag = true;
        delEditOfID->flag = true;
#if 0
        cout << delEditOfName->get_text() << endl;
#endif
    }
    if (delEditOfName->textOfNameChange()) {
        Empoyee empoyee;
        std::stringstream stream;
        tmp = delEditOfName->get_text();
        stream << tmp;
        stream >> empoyee.name;
        //��������������Ӧ��������
        if (!delTable->get_status()) {
            for (auto& val : vec_staff) {
                if (!val.name.compare(empoyee.name))
                    delTable->insertData(val.formateInfo());

            }
            delTable->set_status(true);
        }
    }
    if (delBtnOfName->is_clicked() && delBtnOfName->flag == false && delTable->get_status()){
#if 0
        cout << "���̲߳��Խ��룡" << endl;

        /*future<bool> ret = async(launch::async, Management::getChoice);
        cout << "���Ƕ��̲߳��ԣ�" << ret.get() << endl;*/
#endif
        //ID����Ψһ����Ψһ��Ĭ��ɾ����ID��һ�α�����������������
        Empoyee empoyee;
        std::stringstream stream;
        //�Ȼ�ȡҪɾ����ID
        tmp = delEditOfID->getDelIDInput();
        stream << tmp;
        stream >> empoyee.id;
        //Ѱ�Ҹ�ID�Ƿ����
        it = find(vec_staff.begin(), vec_staff.end(), empoyee);
#if 0
        //settextstyle(50, 0, "���ķ���", 0, 0, 500, 0, 0, 0);
        //outtextxy(confirmBtn->x(), confirmBtn->y() - 100, "����ȷ�ϰ���");
        //if (confirmBtn->is_clicked()) confirmFlag = true;
        //::settextstyle(20, 0, "����");
#endif
        //������������ɾ��
        if (it != vec_staff.end() ) {
            Sleep(200);
            string delName = it->name;
            vec_staff.erase(it);
            delBtnOfName->flag = true;
            delTable->clear();
            updateTableData();
            updataSalaryTableData();
            char tmp[50];
            sprintf_s(tmp, "����Ϊ %s ��������ɾ�����밴ȷ�ϼ�������", delName.c_str());
            InputBox((char*)string().c_str(), 1, tmp);
        }
    }
    //���ո���յ�ǰ�༭��
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_SPACE) {
                delBtnOfID->flag = false;
                delBtnOfName->flag = false;
                delTable->clear();
                delTable->set_status(false);
                delEditOfID->flag = false;
                delEditOfID->set_textContent("���������ְ��id��������");
                delEditOfName->flag = false;
                delEditOfName->set_textContent("���������ְ��������������");
                Sleep(200);
            }    
    }
}
//�޸�����
void Management::modify()
{
    //���������Ĵ��루�޸�ǰ����������
    Management::search();
    //��ȡ�޸ĵ�ѡ��
    int option = getModifyOption();
    std::string tmp;
    vector<Empoyee>::iterator it;
    //if(searchEdit->flag)
    //���ݲ�ͬ�ĵ��ѡ�񣬽��벻ͬ��������޸�
    switch (option)
    {
    case Management::ID: {
        //��ȡҪ�޸ĵ�ID����ֹͬ����
        tmp = searchEdit->getChooseModifyTextInput();
#if 0
        cout << "����1   " << tmp << endl;
#endif
        //�ټ������������ڶԸ�ID���м���
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
#if 0
            cout << "����2   " << vec_modifyStaff.size() << endl;
#endif
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {  
                flag:
                //����������ˣ����ȡҪ��Ӧ�޸ĵ�����
                std::string tmp_1 = searchEdit->getModifyTextInput();
#if 0
                cout << "����5    " << tmp << "   " <<  tmp_1 << endl;
#endif
                for (auto& val : vec_staff) {
                    if (val.id == atoi(tmp_1.c_str())) {
                        InputBox((char*)string().c_str(), 1, "��ID�Ѵ��ڣ�������ȷ��Ҫ�޸ĵ�ID������ȷ�ϡ�������", "Error", 0, 0, 0, false);
                        goto flag;
                    }
                }
                //��Դ���ݱ����ҵ���ID��Ӧ��ְ������������Ӧ����Ϣ������Ӧ�޸�
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.id = atoi(tmp_1.c_str());
#if 0
                        cout << "����3  " << val.id <<  endl;
#endif
                        break;
                    }
                }
                break;
#if 0
                cout << "����6" << endl;
#endif            
            }
        }
#if 0
        //cout << "����4" << endl;
#endif
        //�������ݱ��
        updateTableData();
        updataSalaryTableData();
    }
        break;
        //������޸�ѡ���ͬС��
    case Management::NAME: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();

                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.name = tmp_1;
                        break;
                    }
                }
                break;
            }
        }
        updateTableData();
        updataSalaryTableData();
    }
        break;
        //�޸�ĳ������ѡ��ʱ�ǵý��ܹ���Ҳ���¼���һ��
    case Management::SALARY1: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary1 = atoi(tmp_1.c_str());
                        val.salary6 = getAllSalary(val);
                    }
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }    
        break;
    case Management::SALARY2: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary2 = atoi(tmp_1.c_str());
                        val.salary6 = getAllSalary(val);
                    }
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }     
        break;
    case Management::SALARY3: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary3 = atoi(tmp_1.c_str());
                        val.salary6 = getAllSalary(val);
                    }
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }
        break;
    case Management::SALARY4: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary4 = atoi(tmp_1.c_str());
                        val.salary6 = getAllSalary(val);
                    }
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }  
        break;
    case Management::SALARY5: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary5 = atoi(tmp_1.c_str());
                        val.salary6 = getAllSalary(val);
                    }
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }
        break;
    default:
        break;
    }
}
//��ȡ�ܹ���
int Management::getAllSalary(Empoyee& empoyee)
{
    return empoyee.salary1 + empoyee.salary2 + empoyee.salary3 + empoyee.salary4 + empoyee.salary5;
}
//��ȡ�޸�ѡ��
int Management::getModifyOption()
{
    for (int i = 0; i < option_btns.size(); i++) {
        option_btns[i]->show();
        //����ǰ��Ϣͬ�����˵���ť
        option_btns[i]->event_loop(m_msg);
        //���ݵ�����ض�Ӧ���޸�ѡ��
        if (option_btns[i]->is_clicked())
            return i;
    }
    return -1;
}
//��������
void Management::search()
{
    searchBtn->show();
    searchTable->show();
    searchEdit->show();

    //��ID��������

    std::string tmp;
    std::stringstream stream;
    //��������򱻵��������������������������Խ�������
    if (searchEdit->is_clicked() && !searchEdit->flag) {
        //��ȡ�ı�����
        tmp = searchEdit->getSearchTextInput();
        //���ı�����ͬ�����ı�������ʾ
        searchEdit->set_textContent(tmp);
        //��ǰ�ı����������ݼ���״̬����Ϊtrue
        searchEdit->flag = true;
    }
    //std::unordered_map<Empoyee, int> salaryMap;���������ù�ϣ����������ģ����淢�ֺ���������ô�鷳��
    if (searchEdit->textOfSearchChange() && !searchTable->get_status()) {
        for (int i = 0; i < vec_staff.size(); i++) {
            //��ȡ�ı��������
            tmp = searchEdit->get_text();
            //������������Դ�����н��м���
            if (!tmp.compare(to_string(vec_staff[i].id)) || !tmp.compare(vec_staff[i].name)) {
                //��Ϊ֮ǰ�������������������죬�ڴ˼�����ÿ��Ա��ƽ��ÿ���������ƽ��ֵ
                //�������˴��ţ���û��ɾ��
                double average = 0;
                average += vec_staff[i].salary6 / 5.0;
                Empoyee empoyee(vec_staff[i]);
                empoyee.averageSalary = average;
                //�����ݲ�������չʾ�����
                searchTable->insertData(empoyee.formateInfoOfAverage());
                vec_modifyStaff.emplace_back(vec_staff[i]);
#if 0
                cout << "ƽ������" << average << endl;
#endif
            }
        }
        //����������ݣ�����Ϊtrue
        searchTable->set_status(true);
    }
    //���ո���ɽ���ǰ�����������Ϣ���г�ʼ��
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_SPACE) {
                searchTable->clear();
                searchTable->set_status(false);
                searchEdit->flag = false;
                vec_modifyStaff.clear();
                searchEdit->set_textContent("���������ְ��id����������������");
                Sleep(200);
            }
    }
}
//���Ʊ���
void Management::drawBackground()
{
    int i[] = { 7,12,13,14,15,17,18 };
#if 0
    //for (int k = 0; k < menu_btns.size(); k++) {
    //    if (menu_btns[k]->is_clicked() && !menu_btns[k]->was_clicked()) {
    //        background = rand() % 7;
    //        menu_btns[k]->flag = true;
    //        break;
    //    }
    //}
#endif
    ::putimage(0, 0, &m_bks[i[background]]);
}
//�����¼�ͬ��
void Management::event_loop()
{
    //����ǰ�����¼�ͬ����������Ҫ�����¼��Ŀؼ���
    m_table->event_loop(m_msg);
    m_salaryTable->event_loop(m_msg);
    delTable->event_loop(m_msg);

    addBtn->event_loop(m_msg);
    addTable->event_loop(m_msg);
    addEdit->event_loop(m_msg);

    delEditOfID->event_loop(m_msg);
    delBtnOfID->event_loop(m_msg);
    delEditOfName->event_loop(m_msg);
    delBtnOfName->event_loop(m_msg);
#if 0
    //confirmBtn->event_loop(m_msg);
    //cancelBtn->event_loop(m_msg);
#endif
    cPushButton->event_loop(m_msg);

    searchBtn->event_loop(m_msg);
    searchEdit->event_loop(m_msg);
    searchTable->event_loop(m_msg);
}
//���ļ�
void Management::readFile(const std::string& fileName)
{
    fstream fRead(fileName, ios::in);
    if (!fRead.is_open()) {
        return;
    }
    //��ȡ��ͷ
    char buf[1024] = { 0 };
    fRead.getline(buf, 1024);
    m_header = buf;
#if 0
    cout << buf << endl;
#endif
    //��ȡ����
    while (!fRead.eof()) {
        memset(buf, 0, 1024);
        fRead.getline(buf, 1024);
        //��������
        if (strlen(buf) == 0)
            continue;
        Empoyee tmp;
        stringstream ss(buf);
        //�����ݷָ����ʱ����
        ss >> tmp.id >> tmp.name >> tmp.salary1 >> tmp.salary2 >> 
            tmp.salary3 >> tmp.salary4 >> tmp.salary5 >> tmp.salary6;
        //����Դ���ݱ���
        vec_staff.push_back(tmp);
        
    }
    fRead.close();
}
//д�ļ��������ļ���
void Management::saveFile(const std::string& fileName)
{
    //Ϊд�ļ����򿪣�����ļ��Ѵ��ڣ�����ɾ���ٴ������Խ������ݵ�ͬ����
    fstream fWrite(fileName, ios::out | ios::trunc);
    if (!fWrite.is_open()) {
        cerr << fileName << "file open failed" << endl;
        return;
    }
    //д��ͷ
    //��ͷ���Զ������У������ݸ�ʽͳһ
    if(m_header[m_header.size()-1] != '\n')//���Ᵽ��ʱ��Ӷ�λ��з�
        m_header += '\n';
    fWrite.write(m_header.c_str(), m_header.size());

    //д����
    for (auto& val : vec_staff) {
        //�����ݽ��и�ʽ��������ٱ������ļ�
        std::string info = val.formateInfo();
        fWrite.write(info.c_str(), info.size());
    }

    fWrite.close();
}
