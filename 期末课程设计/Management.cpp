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

//排序提供多个比较方式来满足不同的排序需求
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
    //在开始“run”之前将数据先读取进程序
    readFile("./Images/information.txt");
    //预设背景图的大小（对容器进行初始化，才能直接使用其进行背景图的初始化）
    m_bks.resize(25);
    //加载背景图
    for (int i = 1; i <= 22; i++) {
        char tmp[100] = { 0 };
        sprintf_s(tmp, "./Images/bk%d.png", i);
        ::loadimage(&m_bks[i], tmp, Window::width(), Window::height());
    }
    
    //设置整体的字体字号
    ::settextstyle(25, 0, "微软雅黑", 0,0,550,0,0,0);
    
    //创建菜单的功能按钮
    menu_btns.push_back(new PushButton("查看工资信息"));
    menu_btns.push_back(new PushButton("添加工资信息"));
    menu_btns.push_back(new PushButton("删除工资信息"));
    menu_btns.push_back(new PushButton("修改工资信息"));
    menu_btns.push_back(new PushButton("查找工资信息"));
    menu_btns.push_back(new PushButton("统计工资信息"));
    menu_btns.push_back(new PushButton("退出系统"));
    cPushButton = new CirclePushButton("SAVE", 0, 0, 40);
    //设置每个按钮的位置
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
    //创建表格，用于展示数据
    m_table = new Table;
    m_salaryTable = new SalaryTable;
    //设置行列以及表头
    m_table->setRowCount(16);
    m_table->setHeader(m_header);

    m_salaryTable->setRowCount(16);
    m_salaryTable->setHeader(m_header);
    //将职工数据读入到表格中
    for (auto& val : vec_staff) {
        m_table->insertData(val.formateInfo());
        m_salaryTable->insertData(val.formateInfo());
        m_salaryTable->allSalary += val.salary6;
        m_salaryTable->allSalary1 += val.salary1;
        m_salaryTable->allSalary2 += val.salary2;
        m_salaryTable->allSalary3 += val.salary3;
        m_salaryTable->allSalary4 += val.salary4;
        m_salaryTable->allSalary5 += val.salary5;
        //读入的同时进行相关的数据统计
        if (val.salary6 > 3000) m_salaryTable->moreThan3000Humans++;
        if (val.salary6 < 2000) m_salaryTable->lessThan2000Humans++;
        if (val.salary6 >= 2000 && val.salary6 <= 3000) m_salaryTable->between2000To3000Humans++;
    }
    
    //居中表格
    m_table->move((Window::width() - m_table->width()) / 2, (Window::height()-m_table->height()) / 2);
    m_salaryTable->move((Window::width() - m_table->width()) / 2, (Window::height() - m_table->height()) / 3);

    //添加界面
    addBtn = new PushButton("添加", 0, 0, 50, 30);
    addEdit = new EditLine("点击此进行数据的添加");
    addTable = new Table;
    addTable->setRowCount(6);
    addTable->setHeader(m_header);
    addTable->move((Window::width() - addTable->width()) / 2, (Window::height() - addTable->height()) / 2);
    addEdit->move((Window::width() - addEdit->width()) / 2, addTable->y() - 100);
    addBtn->move(addEdit->x() + addEdit->width() + 5, addEdit->y());
    //删除界面
    delBtnOfID = new PushButton("删除", 0, 0, 50, 30);
    delEditOfID = new EditLine("点击此输入职工id进行搜索");
    delBtnOfName = new PushButton("删除", 0, 0, 50, 30);
    delEditOfName = new EditLine("点击此输入职工姓名进行搜索");
#if 0
    //confirmBtn = new PushButton("确认", 0, 0, 50, 30);
    //cancelBtn = new PushButton("取消", 0, 0, 50, 30);
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
    //设置每个按钮的对应位置
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

    //排序界面
    sort_btns.push_back(new PushButton("根据ID排序"));
    sort_btns.push_back(new PushButton("根据姓名排序"));
    sort_btns.push_back(new PushButton("根据总工资排序"));
    for (int i = 0; i < sort_btns.size(); i++) {
        sort_btns[i]->setFixedSize(140, 30);
        int y = m_table->y() + 2 * i * sort_btns[i]->height() - m_table->m_gridH;
        int x = m_table->x()+ m_table->m_gridW * m_table->m_cols + 20;

        sort_btns[i]->move(x, y);
    }

}

void Management::run()
{
    //选项默认是菜单
    int op = MENU;
    //由于画面较复杂时，画面会闪烁
    //使用BeginBatchDraw();FlushBatchDraw();EndBatchDraw();这三个函数的批量绘图模式即可解决
    Window::beginDraw();
    while (true) {
        //每次进入都更新一遍表格确保数据与界面同步展示
        updateTableData();
        updataSalaryTableData();
        Window::clear();
        //绘制背景
        drawBackground();
        //时刻监听窗口消息
        if (Window::hasMsg())
        {
            m_msg = Window::getMsg();
            switch (m_msg.message)
            {
            case WM_KEYDOWN:		//按键消息
                switch (m_msg.vkcode)
                {
                case VK_ESCAPE:		//ESC的虚拟键值
                    op = MENU;//按下ESC后则返回菜单界面
                    break;
                }
                break;
            default:				//鼠标消息
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
        //功能选项
        switch (op)
        {
        case Management::DISPLAY:
            display();
            background = 0;
            break;
        case Management::ADD:
            background = 1;
            //添加新的数据后更新表格并保存到文件
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
            //退出自动保存数据
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
//菜单
int Management::menu()
{
    cPushButton->show();
    
    if (cPushButton->is_clicked()) {
        saveFile("./Images/information.txt");
        cout << "保存成功" << endl;
    }
    for (int i = 0; i < menu_btns.size(); i++) {
        menu_btns[i]->show();
        //将当前信息同步到菜单按钮
        menu_btns[i]->event_loop(m_msg);
        //并利用信息进行判断
        if(menu_btns[i]->is_clicked())
            return i;
    }
    return MENU;
}
//显示数据
void Management::display()
{
    //每次显示数据前默认以ID进行排序
    sort(vec_staff.begin(), vec_staff.end());
    m_table->show();
}
//添加数据
void Management::add()
{
    addBtn->show();
    addEdit->show();
    addTable->show();
    //由于没有采用多线程的设计，所有都是同步进行
    //防止每次进入该函数tmp都被初始化，故使用static修饰
    static Empoyee tmp;
    int count = 0;
    char buf[1024] = { 0 };
    string text;
    memset(buf, 0, 1024);
    stringstream ss(buf);

    const char* str[] = { "请输入ID号","请输入姓名","请输入基本工资",
        "请输入职务工资","请输入津贴","请输入医疗保险","请输入公积金" };
    //当输入框被点击并且输入框没内容时才可进行输入
    if (addEdit->is_clicked() && !addEdit->flag) {
    flag:
        //循环录入七个数据项
        for (int i = 0; i < 7; i++) {
            //每次都先初始化输入的临时数组（防止出现莫名的bug）
            memset(buf, 0, 1024);
            //如果点击了取消则直接取消本次输入
            if (!InputBox(buf, 1024, str[i], "添加新记录", NULL, 0, 0, false))
                return;
            //测试发现可能会有不可测的bug，这里在逻辑上增加细分限制，以确保录入的ID是唯一的
            if (!strcmp(str[i], "请输入ID号")) {
                tmp.id = atoi(buf);
                if (find(vec_staff.begin(), vec_staff.end(), tmp) != vec_staff.end()) {
                    while (strcmp(buf, "我输错了")) {
                        if (!InputBox(buf, 1024, "该ID已存在，请输入“我输错了”后重新进行输入", "Error", 0, 0, 0, false)) {
                            return;
                        }
                        Sleep(200);
                    }
                    Sleep(1000);
                    //只有输入正确了才能继续录入或者取消
                    goto flag;
                }
            }
            //以空格分隔每个数据
            text += (buf + (string)" ");
            //计算总工资
            if (i > 1) {
                count += atoi(buf);
            }
            ss << buf << " ";
        }
        //将输入的信息显示在文本框中
        addEdit->set_textContent(text);
        //文本框内此时存在数据，将文本框的状态设为true
        addEdit->flag = true;
        //将总工资也写入流中
        ss << string(to_string(count)) << " ";
        //将数据分割传进临时对象的每个数据项中
        ss >> tmp.id >> tmp.name >> tmp.salary1 >> tmp.salary2 >>
            tmp.salary3 >> tmp.salary4 >> tmp.salary5 >> tmp.salary6;
        //将录入的临时对象插入表格中
        addTable->insertData(tmp.formateInfo());
        //表格的状态设置为true（有数据）
        addTable->set_status(true);
    }
    //当“确认”按钮被点击并且表格内有数据，并且确认按钮是该数据项添加的第一次点击
    if (addBtn->is_clicked() && addTable->get_status() && addBtn->flag == false) {
        //将数据插入总数据表中（与源数据相关的容器）
        vec_staff.push_back(tmp);
        //插入完成后，则按钮状态设置为已被点击
        addBtn->flag = true;
        //更新总表格与统计表格的内容
        updateTableData();
        updataSalaryTableData();
        //由于“添加”表格中的数据已被添加至总表，故该表格的数据可以清除
        addTable->clear();
        //并将表格状态置空
        addTable->set_status(false);
        InputBox((char*)string().c_str(), 1, "添加成功！请点击确认键继续！");
        //保存至文件
        saveFile("./Images/information.txt");
    }
    //按空格将所有设置初始化以进行下一次录入
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_SPACE) {
                addBtn->flag = false;
                addTable->clear();
                addTable->set_status(false);
                addEdit->flag = false;
                addEdit->set_textContent("点击此进行数据的添加");
                Sleep(200);
            }
    }
}
//更新表格
void Management::updateTableData()
{
    //将表格“格式化”
    m_table->clear();
    //重新从源表中插入数据
    for (auto val : vec_staff){
        m_table->insertData(val.formateInfo());  
    }
}
//更新统计表格
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
//统计表格信息
void Management::statistics()
{
    m_salaryTable->show();

    int op = -1;
    for (int i = 0; i < sort_btns.size(); i++) {
        sort_btns[i]->show();
        //将当前信息同步到菜单按钮
        sort_btns[i]->event_loop(m_msg);
        //根据按钮的点击获取对应排序选项
        if (sort_btns[i]->is_clicked())
            op = i;
    }
    switch (op)
    {
    case 0: {
        //点击前后都休眠程序一小会儿，防止连续点击可能会产生bug
        Sleep(200);
        //利用库函数（底层基于快排，大部分情况下都比自己写的排序快，主要是方便嘛）
        qsort(&vec_staff[0], vec_staff.size(), sizeof(vec_staff[0]), cmp_id);
        //排序完后对表格数据进行更新以同步显示
        updataSalaryTableData();
        updateTableData();
        Sleep(100);
        //排序完后将选项置为-1（非switch选项）以避免重复排序
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
//        cout << "已进入线程" << endl;
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

//删除数据
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
    //    cout << "还未确认" << endl;
    //    cout << confirmBtn->getBtnClicked() << endl;
    //}
    //else if(confirmBtn->is_clicked() && !confirmBtn->getBtnClicked()) {
    //    confirmBtn->setBtnClicked(true);
    //    Sleep(200);
    //    cout << "已确认" << endl;
    //    cout << confirmBtn->getBtnClicked() << endl;
    //}
#endif
    //获取文本框的文本
    std::string tmp;
    //用于删除容器内的对应数据（标准库就是这点麻烦，删除只能利用迭代器）
    std::vector<Empoyee>::iterator it = vec_staff.end();

    //按ID删除
    //当文本框被点击并且文本框内没有内容才可以进行搜索内容的录入
    if (delEditOfID->is_clicked() && delEditOfID->flag == false) {
        //获取搜索内容
        tmp = delEditOfID->getDelIDInput();
        if (tmp.empty())
            return;
        //将搜索内容展示到文本框上
        delEditOfID->set_textContent(tmp);
        //加个休眠一开始不知道想干啥，忘记了，删掉也没事，不过加上更有一种“搜索”的感觉
        Sleep(1000);
        //啥都没输入则返回上一层
        if (tmp.empty())
            return;
        //将文本框状态都设置为空
        delEditOfID->flag = true;
        //感觉搜索要不就按姓名，要不就按ID，分别进行，共同进行要考虑的可能更多一些（可能会涉及重复删除导致程序崩溃）
        delEditOfName->flag = true;
#if 0
        cout << delEditOfID->get_text() << endl;
#endif
    }
    //如果上面成功搜索到了数据则文本框内容会改变，此时才进行搜索
    if (delEditOfID->textChange()) {
        //创建个临时对象
        Empoyee empoyee;
        //万能输出流
        std::stringstream stream;
        //获取文本框内的文本内容
        tmp = delEditOfID->get_text();
        //将其填入临时对象中
        stream << tmp;
        stream >> empoyee.id;
        //在源表中搜索对应id的职工
        it = find(vec_staff.begin(), vec_staff.end(), empoyee);
        //如果找到了则插入到删除表格中进行展示
        if (it != vec_staff.end() && !delTable->get_status()){
            delTable->insertData(it->formateInfo());
            delTable->set_status(true);
        }
    }
    //删除按钮被点击了并且迭代器已经搜索到了对应的职工并且删除按钮没有被点击过才进行删除
    if (delBtnOfID->is_clicked() && it != vec_staff.end() && delBtnOfID->flag == false)
    {
#if 0
        cout <<  "当前迭代器id：" << it->id << endl;
        std::cout << "delete" << std::endl;
#endif
        int delID = it->id;
        //直接删除对应迭代器对应的元素
        vec_staff.erase(it);
        //情空删除表格
        delTable->clear();
        //将迭代器置“空”
        it = vec_staff.end();
        //按钮状态设置为“已点击”
        delBtnOfID->flag = true;
        //更新表格数据
        updateTableData();
        updataSalaryTableData();
        char tmp[50];
        sprintf_s(tmp, "ID为 %d 的数据已删除，请按确认键继续！", delID);
        InputBox((char*)string().c_str(), 1, tmp);
    }

    //按姓名删除（大体与按ID删除相同，只是可能存在同名的情况）
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
        //根据姓名搜索对应的数据项
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
        cout << "多线程测试进入！" << endl;

        /*future<bool> ret = async(launch::async, Management::getChoice);
        cout << "这是多线程测试：" << ret.get() << endl;*/
#endif
        //ID必须唯一，不唯一则默认删除该ID第一次被检索到的那条数据
        Empoyee empoyee;
        std::stringstream stream;
        //先获取要删除的ID
        tmp = delEditOfID->getDelIDInput();
        stream << tmp;
        stream >> empoyee.id;
        //寻找该ID是否存在
        it = find(vec_staff.begin(), vec_staff.end(), empoyee);
#if 0
        //settextstyle(50, 0, "华文仿宋", 0, 0, 500, 0, 0, 0);
        //outtextxy(confirmBtn->x(), confirmBtn->y() - 100, "请点击确认按键");
        //if (confirmBtn->is_clicked()) confirmFlag = true;
        //::settextstyle(20, 0, "宋体");
#endif
        //如果存在则进行删除
        if (it != vec_staff.end() ) {
            Sleep(200);
            string delName = it->name;
            vec_staff.erase(it);
            delBtnOfName->flag = true;
            delTable->clear();
            updateTableData();
            updataSalaryTableData();
            char tmp[50];
            sprintf_s(tmp, "姓名为 %s 的数据已删除，请按确认键继续！", delName.c_str());
            InputBox((char*)string().c_str(), 1, tmp);
        }
    }
    //按空格即清空当前编辑栏
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_SPACE) {
                delBtnOfID->flag = false;
                delBtnOfName->flag = false;
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
void Management::modify()
{
    //复用搜索的代码（修改前都得搜索）
    Management::search();
    //获取修改的选项
    int option = getModifyOption();
    std::string tmp;
    vector<Empoyee>::iterator it;
    //if(searchEdit->flag)
    //根据不同的点击选择，进入不同数据项的修改
    switch (option)
    {
    case Management::ID: {
        //获取要修改的ID（防止同名）
        tmp = searchEdit->getChooseModifyTextInput();
#if 0
        cout << "测试1   " << tmp << endl;
#endif
        //再检索到的数据内对该ID进行检索
        for (int i = 0; i < vec_modifyStaff.size(); i++) {
#if 0
            cout << "测试2   " << vec_modifyStaff.size() << endl;
#endif
            if (!tmp.compare(to_string(vec_modifyStaff[i].id))) {  
                flag:
                //如果检索到了，则获取要对应修改的数据
                std::string tmp_1 = searchEdit->getModifyTextInput();
#if 0
                cout << "测试5    " << tmp << "   " <<  tmp_1 << endl;
#endif
                for (auto& val : vec_staff) {
                    if (val.id == atoi(tmp_1.c_str())) {
                        InputBox((char*)string().c_str(), 1, "该ID已存在，请重新确认要修改的ID后点击“确认”键继续", "Error", 0, 0, 0, false);
                        goto flag;
                    }
                }
                //在源数据表中找到该ID对应的职工，并对其相应的信息进行相应修改
                for (auto& val : vec_staff) {
                    if (!tmp.compare(to_string(val.id))) {
                        val.id = atoi(tmp_1.c_str());
#if 0
                        cout << "测试3  " << val.id <<  endl;
#endif
                        break;
                    }
                }
                break;
#if 0
                cout << "测试6" << endl;
#endif            
            }
        }
#if 0
        //cout << "测试4" << endl;
#endif
        //更新数据表格
        updateTableData();
        updataSalaryTableData();
    }
        break;
        //其余的修改选项大同小异
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
        //修改某个工资选项时记得将总工资也重新计算一遍
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
//获取总工资
int Management::getAllSalary(Empoyee& empoyee)
{
    return empoyee.salary1 + empoyee.salary2 + empoyee.salary3 + empoyee.salary4 + empoyee.salary5;
}
//获取修改选项
int Management::getModifyOption()
{
    for (int i = 0; i < option_btns.size(); i++) {
        option_btns[i]->show();
        //将当前信息同步到菜单按钮
        option_btns[i]->event_loop(m_msg);
        //根据点击返回对应的修改选项
        if (option_btns[i]->is_clicked())
            return i;
    }
    return -1;
}
//搜索数据
void Management::search()
{
    searchBtn->show();
    searchTable->show();
    searchEdit->show();

    //按ID进行搜索

    std::string tmp;
    std::stringstream stream;
    //如果搜索框被点击，并且搜索框内无数据则可以进行输入
    if (searchEdit->is_clicked() && !searchEdit->flag) {
        //获取文本内容
        tmp = searchEdit->getSearchTextInput();
        //将文本内容同步到文本框中显示
        searchEdit->set_textContent(tmp);
        //当前文本框内有数据即将状态设置为true
        searchEdit->flag = true;
    }
    //std::unordered_map<Empoyee, int> salaryMap;（本来想用哈希表进行搜索的，后面发现好像不至于这么麻烦）
    if (searchEdit->textOfSearchChange() && !searchTable->get_status()) {
        for (int i = 0; i < vec_staff.size(); i++) {
            //获取文本框的内容
            tmp = searchEdit->get_text();
            //将搜索内容在源数据中进行检索
            if (!tmp.compare(to_string(vec_staff[i].id)) || !tmp.compare(vec_staff[i].name)) {
                //因为之前理解的搜索功能有所差异，在此计算了每个员工平均每个工资项的平均值
                //由于无伤大雅，故没有删除
                double average = 0;
                average += vec_staff[i].salary6 / 5.0;
                Empoyee empoyee(vec_staff[i]);
                empoyee.averageSalary = average;
                //将数据插入搜索展示表格中
                searchTable->insertData(empoyee.formateInfoOfAverage());
                vec_modifyStaff.emplace_back(vec_staff[i]);
#if 0
                cout << "平均工资" << average << endl;
#endif
            }
        }
        //表格内有数据，设置为true
        searchTable->set_status(true);
    }
    //按空格则可将当前界面的所有信息进行初始化
    if (Window::hasMsg()) {
        m_msg = Window::getMsg();
        if (m_msg.message == WM_KEYDOWN)
            if (m_msg.vkcode == VK_SPACE) {
                searchTable->clear();
                searchTable->set_status(false);
                searchEdit->flag = false;
                vec_modifyStaff.clear();
                searchEdit->set_textContent("点击此输入职工id或者姓名进行搜索");
                Sleep(200);
            }
    }
}
//绘制背景
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
//监听事件同步
void Management::event_loop()
{
    //将当前窗口事件同步至所有需要监听事件的控件中
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
//读文件
void Management::readFile(const std::string& fileName)
{
    fstream fRead(fileName, ios::in);
    if (!fRead.is_open()) {
        return;
    }
    //读取表头
    char buf[1024] = { 0 };
    fRead.getline(buf, 1024);
    m_header = buf;
#if 0
    cout << buf << endl;
#endif
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
        //插入源数据表中
        vec_staff.push_back(tmp);
        
    }
    fRead.close();
}
//写文件（保存文件）
void Management::saveFile(const std::string& fileName)
{
    //为写文件而打开，如果文件已存在，则先删除再创建（以进行数据的同步）
    fstream fWrite(fileName, ios::out | ios::trunc);
    if (!fWrite.is_open()) {
        cerr << fileName << "file open failed" << endl;
        return;
    }
    //写表头
    //表头后自动跟换行，将数据格式统一
    if(m_header[m_header.size()-1] != '\n')//避免保存时添加多次换行符
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
