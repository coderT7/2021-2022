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
    //在开始“run”之前将数据先读取进程序
    readFile("./Images/information.txt");
    //加载背景图
    ::loadimage(&m_bk, "./Images/bk5.png", Window::width(), Window::height());
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
    
    m_table->setHeader(m_header);
    //将职工数据读入到表格中
    for (auto& val : vec_staff) {
        m_table->insertData(val.formateInfo());
        m_table->allSalary += val.salary6;
    }

    //居中表格
    m_table->move((Window::width() - m_table->width()) / 2, 250);

    //删除界面
    delBtnOfID = new PushButton("删除", 0, 0, 50, 30);
    delEditOfID = new EditLine("点击此输入职工id进行搜索");
    delBtnOfName = new PushButton("删除", 0, 0, 50, 30);
    delEditOfName = new EditLine("点击此输入职工姓名进行搜索");
    delTable = new Table;
    delTable->setRowCount(6);
    delTable->setHeader(m_header);
    delTable->move((Window::width() - delTable->width()) / 2, (Window::height() - delTable->height()) / 3 + 50);
    delEditOfID->move((Window::width() - delEditOfID->width()) / 2 , delTable->y() - 100);
    delBtnOfID->move(delEditOfID->x() + delEditOfID->width() + 5, delEditOfID->y());
    delEditOfName->move(delEditOfID->x(), delEditOfID->y() - delEditOfID->height() - 10);
    delBtnOfName->move(delEditOfName->x() + delEditOfName->width() + 5, delEditOfName->y());

    //查询界面
    searchBtn = new PushButton("查找", 0, 0, 50, 30);
    searchEdit = new EditLine("点击此输入职工id或者姓名进行搜索");
    searchTable = new Table;
    searchTable->setRowCount(6);
    searchTable->setHeader(m_header + "\t平均工资");
    searchTable->move((Window::width() - searchTable->width()) / 2, (Window::height() - searchTable->height()) / 3 + 50);
    searchEdit->move((Window::width() - searchEdit->width()) / 2, searchTable->y() - 100);
    searchBtn->move(searchEdit->x() + searchEdit->width() + 5, searchEdit->y());

    //修改界面
    option_btns.push_back(new PushButton("修改ID号"));
    option_btns.push_back(new PushButton("修改姓名"));
    option_btns.push_back(new PushButton("修改基本工资"));
    option_btns.push_back(new PushButton("修改职务工资"));
    option_btns.push_back(new PushButton("修改津贴"));
    option_btns.push_back(new PushButton("修改医疗保险"));
    option_btns.push_back(new PushButton("修改公积金"));

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
            //添加新的数据后更新表格并保存到文件
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
            //退出自动保存数据
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
        //将当前信息同步到菜单按钮
        menu_btns[i]->event_loop(m_msg);
        if(menu_btns[i]->is_clicked())
            return i;
    }
    return MENU;
}
//显示数据
void Mangerment::display()
{
    m_table->show();
}
//添加数据
void Mangerment::add()
{
    Empoyee tmp;
    int count = 0;
    char buf[1024] = { 0 };
    stringstream ss(buf);

    const char* str[] = { "请输入ID号","请输入姓名","请输入基本工资",
        "请输入职务工资","请输入津贴","请输入医疗保险","请输入公积金" };

    for (int i = 0; i < 7; i++) {
        memset(buf, 0, 1024);
        InputBox(buf, 1024, str[i], "添加新记录", NULL, 0, 0, true);
        if (i > 1) {
            count += atoi(buf);
        }
        ss << buf << " ";
    }
    ss << string(to_string(count)) << " ";
    //将数据分割传进临时对象
    ss >> tmp.id >> tmp.name >> tmp.salary1 >> tmp.salary2 >>
        tmp.salary3 >> tmp.salary4 >> tmp.salary5 >> tmp.salary6;
    vec_staff.push_back(tmp);
    updateTableData();
    saveFile("./Images/information.txt");
}
//更新表格
void Mangerment::updateTableData()
{
    m_table->clear();
    m_table->allSalary = 0;
    for (auto val : vec_staff){
        m_table->insertData(val.formateInfo());
        m_table->allSalary += val.salary6;
    }
}
//删除数据
void Mangerment::erase()
{
    delEditOfID->show();
    delBtnOfID->show();
    delTable->show();
    delBtnOfName->show();
    delEditOfName->show();
    std::string tmp;
    std::vector<Empoyee>::iterator it = vec_staff.end();

    //按ID删除
    
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
        cout <<  "当前迭代器id：" << it->id << endl;
        std::cout << "delete" << std::endl;
        vec_staff.erase(it);
        delTable->clear();
        it = vec_staff.end();
        updateTableData();
    }

    //按姓名删除
    
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

    //按两次Esc即可退出该模块
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if(m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_ESCAPE) {

                delTable->clear();
                delTable->set_status(false);
                delEditOfID->flag = false;
                delEditOfID->set_textContent("点击此输入职工id进行搜索");
                delEditOfName->flag = false;
                delEditOfName->set_textContent("点击此输入职工姓名进行搜索");
                Sleep(200);
            }    
    }
}
//修改数据
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
        //cout << "测试1" << endl;
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
            //cout << "测试2   " << vec_modifyStaff.size() << endl;
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {
                
                std::string tmp_1 = searchEdit->getModifyTextInput();
                Empoyee empoyee;
                stringstream ss;
                ss << tmp_1;
                ss >> empoyee.id;
                //cout << "测试5" << endl;
                for (auto& val : vec_staff) {
                    if (!tmp_1.compare(to_string(empoyee.id)))
                        val.id = empoyee.id;
                }
                //cout << "测试6" << endl;
                
                //cout << "测试3" << endl;
            }
        }
        //cout << "测试4" << endl;
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
        //将当前信息同步到菜单按钮
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

    //按ID进行搜索

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
                cout << "平均工资" << average << endl;
            }
        }
        searchTable->set_status(true);
    }
    //按两次Esc即可退出该模块
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_ESCAPE) {
                searchTable->allSalary = 0;
                searchTable->clear();
                searchTable->set_status(false);
                searchEdit->flag = false;
                vec_modifyStaff.clear();
                searchEdit->set_textContent("点击此输入职工id或者姓名进行搜索");
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
            continue;
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
