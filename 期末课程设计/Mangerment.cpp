#include "Mangerment.h"

#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<sstream>
using namespace std;

Mangerment::Mangerment()
{
    //�ڿ�ʼ��run��֮ǰ�������ȶ�ȡ������
    readFile("./Images/information.txt");
    //���ر���ͼ
    ::loadimage(&m_bk, "./Images/bk6.png", Window::width(), Window::height());
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
    m_table->setColCount(16);
    m_table->setHeader(m_header);
    //��ְ�����ݶ��뵽�����
    for (auto& val : vec_staff) {
        m_table->insertData(val.formateInfo());
    }

    //���б��
    m_table->move((Window::width() - m_table->width()) / 2, 250);
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
            add();
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
            saveFile("./Images/text.txt");
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
        menu_btns[i]->event_loop(m_msg);
        if(menu_btns[i]->is_clicked())
            return i;
    }
    return MENU;
}

void Mangerment::display()
{
    m_table->show();
}

void Mangerment::add()
{
    ::outtextxy(0, 0, "Add");
    cout << "ADD" << endl;
}

void Mangerment::erase()
{
    ::outtextxy(0, 0, "Erase");
    cout << "ERASE" << endl;
}

void Mangerment::modify()
{
    ::outtextxy(0, 0, "Modify");
    cout << "MODIFY" << endl;
}

void Mangerment::search()
{
    ::outtextxy(0, 0, "Search");
    cout << "SEARCH" << endl;
}

void Mangerment::drawBackground()
{
    ::putimage(0, 0, &m_bk);
}

void Mangerment::event_loop()
{
    m_table->event_loop(m_msg);
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
            break;
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
