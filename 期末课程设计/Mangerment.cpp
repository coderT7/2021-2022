#include "Mangerment.h"

#include<iostream>
#include<conio.h>


using namespace std;

void Mangerment::run()
{
    int op = MENU;
    while (true) {
        if (Window::haveMsg()) {
            m_msg = Window::getMsg();
            switch (m_msg.message)
            {
            case WM_KEYDOWN:
                if (m_msg.vkcode == VK_ESCAPE) {
                    op = MENU;
                }
                break;
            
            default:
                cout << m_msg.vkcode << endl;
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
            break;
        } 
    }
}

int Mangerment::menu()
{
    int op = 0;
    cout << "MENU" << endl;
    cin >> op;
    return op;
}

void Mangerment::display()
{
    cout << "DISPLAY" << endl;
}

void Mangerment::add()
{
    cout << "ADD" << endl;
}

void Mangerment::erase()
{
    cout << "ERASE" << endl;
}

void Mangerment::modify()
{
    cout << "MODIFY" << endl;
}

void Mangerment::search()
{
    cout << "SEARCH" << endl;
}
