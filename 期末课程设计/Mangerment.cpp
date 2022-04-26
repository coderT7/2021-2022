#include "Mangerment.h"

#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<sstream>
using namespace std;

Mangerment::Mangerment()
{
    //在开始“run”之前将数据先读取进程序
    readFile("./Images/information.txt");
    //加载背景图
    ::loadimage(&m_bk, "./Images/bk6.png", Window::width(), Window::height());
    //设置整体的字体字号
    ::settextstyle(20, 0, "宋体");
    //创建功能的按钮
    menu_btns.push_back(new PushButton("查看工资信息"));
    menu_btns.push_back(new PushButton("添加工资信息"));
    menu_btns.push_back(new PushButton("删除工资信息"));
    menu_btns.push_back(new PushButton("修改工资信息"));
    menu_btns.push_back(new PushButton("查找工资信息"));
    menu_btns.push_back(new PushButton("退出系统"));

    //设置每个按钮的位置
    for (int i = 0; i < menu_btns.size(); i++) {
        menu_btns[i]->setFixedSize(250, 50);
        int x = (Window::width() - menu_btns[i]->width()) / 2;
        int vspace = (Window::height() - (int)menu_btns.size() * menu_btns[i]->height()) / 2;
        int y = vspace + i * menu_btns[i]->height();

        menu_btns[i]->move(x, y);
    }
    //创建表格，用于展示数据
    m_table = new Table;
    //设置行列以及表头
    m_table->setRowCount(16);
    m_table->setColCount(16);
    m_table->setHeader(m_header);
    //将职工数据读入到表格中
    for (auto& val : vec_staff) {
        m_table->insertData(val.formateInfo());
    }

    //居中表格
    m_table->move((Window::width() - m_table->width()) / 2, 250);
}

void Mangerment::run()
{
    int op = MENU;
    //由于画面较复杂时，画面会闪烁
    //使用BeginBatchDraw();FlushBatchDraw();EndBatchDraw();这三个函数的批量绘图模式即可解决
    Window::beginDraw();
    while (true) {
        Window::clear();
        drawBackground();
        
        if (Window::hasMsg())
        {
            m_msg = Window::getMsg();
            switch (m_msg.message)
            {
            case WM_KEYDOWN:		//按键消息
                switch (m_msg.vkcode)
                {
                case VK_ESCAPE:		//ESC
                    op = MENU;
                    break;
                }
                break;
            default:				//其他的都是鼠标消息了
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
            //退出自动保存数据
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
    //读取表头
    char buf[1024] = { 0 };
    fRead.getline(buf, 1024);
    m_header = buf;
    cout << buf << endl;
    //读取数据
    while (!fRead.eof()) {
        memset(buf, 0, 1024);
        fRead.getline(buf, 1024);
        //跳过空行
        if (strlen(buf) == 0)
            break;
        Empoyee tmp;
        stringstream ss(buf);
        //将数据分割传进临时对象
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

    //写表头
    m_header += '\n';
    fWrite.write(m_header.c_str(), m_header.size());

    //写数据
    for (auto& val : vec_staff) {
        //将数据进行格式化处理后再保存至文件
        std::string info = val.formateInfo();
        fWrite.write(info.c_str(), info.size());
    }

    fWrite.close();
}
