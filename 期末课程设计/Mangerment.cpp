#include "Mangerment.h"

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
Mangerment::Mangerment()
{
    //�ڿ�ʼ��run��֮ǰ�������ȶ�ȡ������
    readFile("./Images/information.txt");
    m_bks.resize(25);
    //���ر���ͼ
    for (int i = 1; i <= 22; i++) {
        char tmp[100] = { 0 };
        sprintf_s(tmp, "./Images/bk%d.png", i);
        ::loadimage(&m_bks[i], tmp, Window::width(), Window::height());
    }
    
    //��������������ֺ�
    ::settextstyle(25, 0, "΢���ź�", 0,0,550,0,0,0);
    
    //�������ܵİ�ť
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
    addTable->move((Window::width() - addTable->width()) / 2, (Window::height() - addTable->height()) / 3 + 50);
    addEdit->move((Window::width() - addEdit->width()) / 2, addTable->y() - 100);
    addBtn->move(addEdit->x() + addEdit->width() + 5, addEdit->y());
    //ɾ������
    delBtnOfID = new PushButton("ɾ��", 0, 0, 50, 30);
    delEditOfID = new EditLine("���������ְ��id��������");
    delBtnOfName = new PushButton("ɾ��", 0, 0, 50, 30);
    delEditOfName = new EditLine("���������ְ��������������");
    //confirmBtn = new PushButton("ȷ��", 0, 0, 50, 30);
    //cancelBtn = new PushButton("ȡ��", 0, 0, 50, 30);
    delTable = new Table;
    delTable->setRowCount(6);
    delTable->setHeader(m_header);
    //confirmBtn->move(Window::width() / 2 - 2 * confirmBtn->width(), (Window::height() - confirmBtn->height()) / 8);
    //cancelBtn->move(Window::width() / 2 + cancelBtn->width(), confirmBtn->y());
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

    for (int i = 0; i < option_btns.size(); i++) {
        option_btns[i]->setFixedSize(125, 30);
        int y = searchTable->y() + 300;
        int x = searchTable->x() + i * option_btns[i]->width() - 35;
        
        option_btns[i]->move(x, y);
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

void Mangerment::run()
{
    int op = MENU;
    //���ڻ���ϸ���ʱ���������˸
    //ʹ��BeginBatchDraw();FlushBatchDraw();EndBatchDraw();������������������ͼģʽ���ɽ��
    Window::beginDraw();
    while (true) {
        updateTableData();
        updataSalaryTableData();
        Window::clear();
        drawBackground();
        
        if (Window::hasMsg())
        {
            m_msg = Window::getMsg();
            switch (m_msg.message)
            {
            case WM_KEYDOWN:		//������Ϣ
                switch (m_msg.vkcode)
                {
                case VK_ESCAPE:		//ESC
                    op = MENU;
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
        switch (op)
        {
        case Mangerment::DISPLAY:
            display();
            background = 0;
            break;
        case Mangerment::ADD:
            background = 1;
            //����µ����ݺ���±�񲢱��浽�ļ�
            add();
            break;
        case Mangerment::ERASE: 
            background = 2;
            erase();
            break;
        case Mangerment::MODIFY:
            background = 5;
            modify();
            break;
        case Mangerment::SEARCH:
            background = 6;
            search();
            break;
        case Mangerment::STATISTICS:
            background = 4;
            statistics();
            break;
        case Mangerment::EXIT:
            //�˳��Զ���������
            saveFile("./Images/information.txt");
            exit(0);
            break;
        case Mangerment::MENU:
            background = 3;
            op = menu();
            //Window::flushDraw();
            break;
        default: 
            break;
        } 
        Window::flushDraw();
    }
    Window::endDraw();
}
//�˵�
int Mangerment::menu()
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
        if(menu_btns[i]->is_clicked())
            return i;
    }
    return MENU;
}
//��ʾ����
void Mangerment::display()
{
    sort(vec_staff.begin(), vec_staff.end());
    m_table->show();
}
//�������
void Mangerment::add()
{
    addBtn->show();
    addEdit->show();
    addTable->show();

    static Empoyee tmp;
    int count = 0;
    char buf[1024] = { 0 };
    string text;
    memset(buf, 0, 1024);
    stringstream ss(buf);

    const char* str[] = { "������ID��","����������","�������������",
        "������ְ����","���������","������ҽ�Ʊ���","�����빫����" };
    
    if (addEdit->is_clicked() && !addEdit->flag) {
        for (int i = 0; i < 7; i++) {
            memset(buf, 0, 1024);
            if (!InputBox(buf, 1024, str[i], "����¼�¼", NULL, 0, 0, false))
                return;
            text += (buf + (string)" ");
            if (i > 1) {
                count += atoi(buf);
            }
            ss << buf << " ";
        }
        addEdit->set_textContent(text);
        addEdit->flag = true;
        ss << string(to_string(count)) << " ";
        //�����ݷָ����ʱ����
        ss >> tmp.id >> tmp.name >> tmp.salary1 >> tmp.salary2 >>
            tmp.salary3 >> tmp.salary4 >> tmp.salary5 >> tmp.salary6;
        addTable->insertData(tmp.formateInfo());
        addTable->set_status(true);
    }
    if (addBtn->is_clicked() && addTable->get_status()) {
        vec_staff.push_back(tmp);
        updateTableData();
        updataSalaryTableData();
        addTable->set_status(false);
        addTable->clear();
        saveFile("./Images/information.txt");
    }

    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_SPACE) {
                addTable->clear();
                addTable->set_status(false);
                addEdit->flag = false;
                addEdit->set_textContent("����˽������ݵ����");
                Sleep(200);
            }
    }
}
//���±��
void Mangerment::updateTableData()
{
    m_table->clear();
    for (auto val : vec_staff){
        m_table->insertData(val.formateInfo());  
    }
}
void Mangerment::updataSalaryTableData()
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
void Mangerment::statistics()
{
    m_salaryTable->show();

    int op = -1;
    for (int i = 0; i < sort_btns.size(); i++) {
        sort_btns[i]->show();
        //����ǰ��Ϣͬ�����˵���ť
        sort_btns[i]->event_loop(m_msg);
        if (sort_btns[i]->is_clicked())
            op = i;
    }
    switch (op)
    {
    case 0: {
        Sleep(200);
        qsort(&vec_staff[0], vec_staff.size(), sizeof(vec_staff[0]), cmp_id);
        updataSalaryTableData();
        updateTableData();
        Sleep(100);
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


//inline  bool Mangerment::getChoice()
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

//ɾ������
void Mangerment::erase()
{
    delEditOfID->show();
    delBtnOfID->show();
    delTable->show();
    delBtnOfName->show();
    delEditOfName->show();
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
    
    std::string tmp;
    std::vector<Empoyee>::iterator it = vec_staff.end();

    //��IDɾ��
    
    if (delEditOfID->is_clicked() && delEditOfID->flag == false) {
        tmp = delEditOfID->getDelIDInput();
        delEditOfID->set_textContent(tmp);
        Sleep(1000);
        if (tmp.empty())
            return;
        delEditOfID->flag = true;
        delEditOfName->flag = true;
        cout << delEditOfID->get_text() << endl;
    }
    if (delEditOfID->textChange()) {
        Empoyee empoyee;
        std::stringstream stream;
        tmp = delEditOfID->get_text();
        stream << tmp;
        stream >> empoyee.id;
        it = find(vec_staff.begin(), vec_staff.end(), empoyee);
        if (it != vec_staff.end() && !delTable->get_status()){
            delTable->insertData(it->formateInfo());
            delTable->set_status(true);
        }
    }
    if (delBtnOfID->is_clicked() && it != vec_staff.end())
    {
        cout <<  "��ǰ������id��" << it->id << endl;
        std::cout << "delete" << std::endl;
        vec_staff.erase(it);
        delTable->clear();
        it = vec_staff.end();
        updateTableData();
        updataSalaryTableData();
    }

    //������ɾ��
    
    if (delEditOfName->is_clicked() && delEditOfName->flag == false) {
        tmp = delEditOfName->getDelNameInput();
        delEditOfName->set_textContent(tmp);
        Sleep(1000);
        if (tmp.empty())
            return;
        delEditOfName->flag = true;
        delEditOfID->flag = true;
        cout << delEditOfName->get_text() << endl;
    }
    if (delEditOfName->textOfNameChange()) {
        Empoyee empoyee;
        std::stringstream stream;
        tmp = delEditOfName->get_text();
        stream << tmp;
        stream >> empoyee.name;
        if (!delTable->get_status()) {
            for (auto& val : vec_staff) {
                if (!val.name.compare(empoyee.name))
                    delTable->insertData(val.formateInfo());

            }
            delTable->set_status(true);
        }
    }
    
    if (delBtnOfName->is_clicked()){
        cout << "���̲߳��Խ��룡" << endl;
        /*future<bool> ret = async(launch::async, Mangerment::getChoice);
        cout << "���Ƕ��̲߳��ԣ�" << ret.get() << endl;*/

        Empoyee empoyee;
        std::stringstream stream;
        tmp = delEditOfID->getDelIDInput();
        stream << tmp;
        stream >> empoyee.id;
        it = find(vec_staff.begin(), vec_staff.end(), empoyee);
        //settextstyle(50, 0, "���ķ���", 0, 0, 500, 0, 0, 0);
        //outtextxy(confirmBtn->x(), confirmBtn->y() - 100, "����ȷ�ϰ���");
        //if (confirmBtn->is_clicked()) confirmFlag = true;
        //::settextstyle(20, 0, "����");
        if (it != vec_staff.end() ) {
            Sleep(200);
            vec_staff.erase(it);
            delTable->clear();
            updateTableData();
            updataSalaryTableData();
        }
    }
    //���ո���յ�ǰ�༭��
    
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_SPACE) {
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
void Mangerment::modify()
{
    Mangerment::search();
    int option = getModifyOption();
    std::string tmp;
    vector<Empoyee>::iterator it;
    //if(searchEdit->flag)
    switch (option)
    {
    case Mangerment::ID: {
        tmp = searchEdit->getChooseModifyTextInput();
        //cout << "����1" << endl;
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            //cout << "����2   " << vec_modifyStaff.size() << endl;
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                
                std::string tmp_1 = searchEdit->getModifyTextInput();
                Empoyee empoyee;
                stringstream ss;
                ss << tmp_1;
                ss >> empoyee.id;
                //cout << "����5" << endl;
                for (auto& val : vec_staff) {
                    if (!tmp_1.compare(to_string(empoyee.id)))
                        val.id = empoyee.id;
                }
                //cout << "����6" << endl;
                
                //cout << "����3" << endl;
            }
        }
        //cout << "����4" << endl;
        updateTableData();
        updataSalaryTableData();
    }
        break;
    case Mangerment::NAME: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                Empoyee empoyee;
                stringstream ss;
                ss << tmp_1;
                ss >> empoyee.name;
                for (auto& val : vec_staff) {
                    if (!tmp_1.compare(empoyee.name))
                        val.name = empoyee.name;
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }
        break;
    case Mangerment::SALARY1: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                Empoyee empoyee;
                stringstream ss;
                ss << tmp_1;
                ss >> empoyee.salary1;
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary1 = empoyee.salary1;
                        val.salary6 = getAllSalary(val);
                    }
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }    
        break;
    case Mangerment::SALARY2: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                Empoyee empoyee;
                stringstream ss;
                ss << tmp_1;
                ss >> empoyee.salary2;
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary2 = empoyee.salary2;
                        val.salary6 = getAllSalary(val);
                    }
                        
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }     
        break;
    case Mangerment::SALARY3: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                Empoyee empoyee;
                stringstream ss;
                ss << tmp_1;
                ss >> empoyee.salary3;
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary3 = empoyee.salary3;
                        val.salary6 = getAllSalary(val);
                    }       
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }
        break;
    case Mangerment::SALARY4: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                Empoyee empoyee;
                stringstream ss;
                ss << tmp_1;
                ss >> empoyee.salary4;
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary4 = empoyee.salary4;
                        val.salary6 = getAllSalary(val);
                    }      
                }
            }
        }
        updateTableData();
        updataSalaryTableData();
    }  
        break;
    case Mangerment::SALARY5: {
        tmp = searchEdit->getChooseModifyTextInput();
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                std::string tmp_1 = searchEdit->getModifyTextInput();
                Empoyee empoyee;
                stringstream ss;
                ss << tmp_1;
                ss >> empoyee.salary5;
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.salary5 = empoyee.salary5;
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
int Mangerment::getAllSalary(Empoyee& empoyee)
{
    return empoyee.salary1 + empoyee.salary2 + empoyee.salary3 + empoyee.salary4 + empoyee.salary5;
}
//��ȡ�޸�ѡ��
int Mangerment::getModifyOption()
{
    for (int i = 0; i < option_btns.size(); i++) {
        option_btns[i]->show();
        //����ǰ��Ϣͬ�����˵���ť
        option_btns[i]->event_loop(m_msg);
        if (option_btns[i]->is_clicked())
            return i;
    }
    return -1;
}
//��������
void Mangerment::search()
{
    searchBtn->show();
    searchTable->show();
    searchEdit->show();

    //��ID��������

    std::string tmp;
    std::stringstream stream;
    
    if (searchEdit->is_clicked() && !searchEdit->flag) {
        tmp = searchEdit->getSearchTextInput();
        searchEdit->set_textContent(tmp);
        searchEdit->flag = true;
    }
    /*std::unordered_map<Empoyee, int> salaryMap;*/
    if (searchEdit->textOfSearchChange() && !searchTable->get_status()) {
        for (int i = 0; i < vec_staff.size(); i++) {
            tmp = searchEdit->get_text();
            if (!tmp.compare(to_string(vec_staff[i].id)) || !tmp.compare(vec_staff[i].name)) {
                double average = 0;
                average += vec_staff[i].salary6 / 5.0;
                Empoyee empoyee(vec_staff[i]);
                empoyee.averageSalary = average;
                searchTable->insertData(empoyee.formateInfoOfAverage());
                vec_modifyStaff.emplace_back(vec_staff[i]);
                cout << "ƽ������" << average << endl;
            }
        }
        searchTable->set_status(true);
    }
    //������Esc�����˳���ģ��
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
void Mangerment::drawBackground()
{
    int i[] = { 7,12,13,14,15,17,18 };
    //for (int k = 0; k < menu_btns.size(); k++) {
    //    if (menu_btns[k]->is_clicked() && !menu_btns[k]->was_clicked()) {
    //        background = rand() % 7;
    //        menu_btns[k]->flag = true;
    //        break;
    //    }
    //}
    ::putimage(0, 0, &m_bks[i[background]]);
}
//�����¼�ͬ��
void Mangerment::event_loop()
{
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
    //confirmBtn->event_loop(m_msg);
    //cancelBtn->event_loop(m_msg);
    cPushButton->event_loop(m_msg);

    searchBtn->event_loop(m_msg);
    searchEdit->event_loop(m_msg);
    searchTable->event_loop(m_msg);
}
//���ļ�
void Mangerment::readFile(const std::string& fileName)
{
    fstream fRead(fileName, ios::in);
    if (!fRead.is_open()) {
        return;
    }
    //��ȡ��ͷ
    char buf[1024] = { 0 };
    fRead.getline(buf, 1024);
    m_header = buf;
    cout << buf << endl;
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
        vec_staff.push_back(tmp);
        
    }
    fRead.close();
}
//д�ļ��������ļ���
void Mangerment::saveFile(const std::string& fileName)
{
    fstream fWrite(fileName, ios::out | ios::trunc);
    if (!fWrite.is_open()) {
        cerr << fileName << "file open failed" << endl;
        return;
    }
    //д��ͷ
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
