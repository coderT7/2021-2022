#include "Mangerment.h"

#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<unordered_map>
using namespace std;

Mangerment::Mangerment()
{
    //�ڿ�ʼ��run��֮ǰ�������ȶ�ȡ������
    readFile("./Images/information.txt");
    //���ر���ͼ
    ::loadimage(&m_bk, "./Images/bk5.png", Window::width(), Window::height());
    //��������������ֺ�
    ::settextstyle(20, 0, "����");
    //�������ܵİ�ť
    menu_btns.push_back(new PushButton("�鿴������Ϣ"));
    menu_btns.push_back(new PushButton("��ӹ�����Ϣ"));
    menu_btns.push_back(new PushButton("ɾ��������Ϣ"));
    menu_btns.push_back(new PushButton("�޸Ĺ�����Ϣ"));
    menu_btns.push_back(new PushButton("���ҹ�����Ϣ"));
    menu_btns.push_back(new PushButton("�˳�ϵͳ"));

    //����ÿ����ť��λ��
    for (int i = 0; i < menu_btns.size(); i++) {
        menu_btns[i]->setFixedSize(250, 50);
        int x = (Window::width() - menu_btns[i]->width()) / 2;
        int vspace = (Window::height() - (int)menu_btns.size() * menu_btns[i]->height()) / 2;
        int y = vspace + i * menu_btns[i]->height();

        menu_btns[i]->move(x, y);
    }
    //�����������չʾ����
    m_table = new Table;
    //���������Լ���ͷ
    m_table->setRowCount(16);
    
    m_table->setHeader(m_header);
    //��ְ�����ݶ��뵽�����
    for (auto& val : vec_staff) {
        m_table->insertData(val.formateInfo());
        m_table->allSalary += val.salary6;
    }

    //���б��
    m_table->move((Window::width() - m_table->width()) / 2, 250);

    //ɾ������
    delBtnOfID = new PushButton("ɾ��", 0, 0, 50, 30);
    delEditOfID = new EditLine("���������ְ��id��������");
    delBtnOfName = new PushButton("ɾ��", 0, 0, 50, 30);
    delEditOfName = new EditLine("���������ְ��������������");
    delTable = new Table;
    delTable->setRowCount(6);
    delTable->setHeader(m_header);
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
}

void Mangerment::run()
{
    int op = MENU;
    //���ڻ���ϸ���ʱ���������˸
    //ʹ��BeginBatchDraw();FlushBatchDraw();EndBatchDraw();������������������ͼģʽ���ɽ��
    Window::beginDraw();
    while (true) {
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
            default:				//�����Ķ��������Ϣ��
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
            break;
        case Mangerment::ADD:
            //����µ����ݺ���±�񲢱��浽�ļ�
            add();
            op = MENU;
            break;
        case Mangerment::ERASE: 
            erase();
            break;
        case Mangerment::MODIFY:
            modify();
            break;
        case Mangerment::SEARCH:
            search();
            break;
        case Mangerment::MENU:
            op = menu();
            break;
        default:
            //�˳��Զ���������
            saveFile("./Images/information.txt");
            exit(0);
            break;
        } 
        Window::flushDraw();
    }
    Window::endDraw();
}

int Mangerment::menu()
{
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
    m_table->show();
}
//�������
void Mangerment::add()
{
    Empoyee tmp;
    int count = 0;
    char buf[1024] = { 0 };
    stringstream ss(buf);

    const char* str[] = { "������ID��","����������","�������������",
        "������ְ����","���������","������ҽ�Ʊ���","�����빫����" };

    for (int i = 0; i < 7; i++) {
        memset(buf, 0, 1024);
        InputBox(buf, 1024, str[i], "����¼�¼", NULL, 0, 0, true);
        if (i > 1) {
            count += atoi(buf);
        }
        ss << buf << " ";
    }
    ss << string(to_string(count)) << " ";
    //�����ݷָ����ʱ����
    ss >> tmp.id >> tmp.name >> tmp.salary1 >> tmp.salary2 >>
        tmp.salary3 >> tmp.salary4 >> tmp.salary5 >> tmp.salary6;
    vec_staff.push_back(tmp);
    updateTableData();
    saveFile("./Images/information.txt");
}
//���±��
void Mangerment::updateTableData()
{
    m_table->clear();
    m_table->allSalary = 0;
    for (auto val : vec_staff){
        m_table->insertData(val.formateInfo());
        m_table->allSalary += val.salary6;
    }
}
//ɾ������
void Mangerment::erase()
{
    delEditOfID->show();
    delBtnOfID->show();
    delTable->show();
    delBtnOfName->show();
    delEditOfName->show();
    std::string tmp;
    std::vector<Empoyee>::iterator it = vec_staff.end();

    //��IDɾ��
    
    if (delEditOfID->is_clicked() && delEditOfID->flag == false) {
        tmp = delEditOfID->getDelTextInput();
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
    }

    //������ɾ��
    
    if (delEditOfName->is_clicked() && delEditOfName->flag == false) {
        tmp = delEditOfName->getDelTextInput();
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
    if (delBtnOfName->is_clicked()) {
        Empoyee empoyee;
        std::stringstream stream;
        tmp = delEditOfID->getDelTextInput();
        stream << tmp;
        stream >> empoyee.id;
        it = find(vec_staff.begin(), vec_staff.end(), empoyee);
        if (it != vec_staff.end()) {
            vec_staff.erase(it);
            delTable->clear();
            updateTableData();
        }
        
    }

    //������Esc�����˳���ģ��
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if(m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_ESCAPE) {

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
                    if (!tmp_1.compare(to_string(empoyee.salary1))) {
                        val.salary1 = empoyee.salary1;
                        val.salary6 = getAllSalary(val);
                    }
                }
            }
        }
        updateTableData();
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
                    if (!tmp_1.compare(to_string(empoyee.salary2))) {
                        val.salary2 = empoyee.salary2;
                        val.salary6 = getAllSalary(val);
                    }
                        
                }
            }
        }
        updateTableData();
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
                    if (!tmp_1.compare(to_string(empoyee.salary3))) {
                        val.salary3 = empoyee.salary3;
                        val.salary6 = getAllSalary(val);
                    }       
                }
            }
        }
        updateTableData();
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
                    if (!tmp_1.compare(to_string(empoyee.salary4))) {
                        val.salary4 = empoyee.salary4;
                        val.salary6 = getAllSalary(val);
                    }      
                }
            }
        }
        updateTableData();
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
                    if (!tmp_1.compare(to_string(empoyee.salary5))) {
                        val.salary5 = empoyee.salary5;
                        val.salary6 = getAllSalary(val);
                    }
                }
            }
        }
        updateTableData();
    }
        break;
    default:
        break;
    }
}

int Mangerment::getAllSalary(Empoyee& empoyee)
{
    return empoyee.salary1 + empoyee.salary2 + empoyee.salary3 + empoyee.salary4 + empoyee.salary5;
}

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
                searchTable->allSalary += vec_staff[i].salary6;
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
            if (m_msg.vkcode == VK_ESCAPE) {
                searchTable->allSalary = 0;
                searchTable->clear();
                searchTable->set_status(false);
                searchEdit->flag = false;
                vec_modifyStaff.clear();
                searchEdit->set_textContent("���������ְ��id����������������");
                Sleep(200);
            }
    }
}

void Mangerment::drawBackground()
{
    ::putimage(0, 0, &m_bk);
}

void Mangerment::event_loop()
{
    m_table->event_loop(m_msg);
    delTable->event_loop(m_msg);

    delEditOfID->event_loop(m_msg);
    delBtnOfID->event_loop(m_msg);
    delEditOfName->event_loop(m_msg);
    delBtnOfName->event_loop(m_msg);

    searchBtn->event_loop(m_msg);
    searchEdit->event_loop(m_msg);
    searchTable->event_loop(m_msg);
}

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
