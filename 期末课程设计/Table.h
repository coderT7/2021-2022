#pragma once
#include "BasicWidget.h"
#include"PushButton.h"
#include"config.h"
#include<vector>

class Table :
    public BasicWidget
{
    friend class Mangerment;
public:
    Table(int row = 0, int col = 0);
    ~Table();
    void setRowCount(int row);
    void setColCount(int col);
    void setHeader(const std::string& header);
    void insertData(const std::string& data);

    virtual void show();
    virtual void clear();
    virtual void drawTableGrid();
    virtual void drawButton();
    virtual void drawTableData();
    virtual void drawHeader();
    static std::vector<std::string> split(std::string str, char sperator = '\t');
    std::vector<std::string> get_data();

    void updatePage();

    virtual void event_loop(const ExMessage& msg);

    bool get_status();
    void set_status(bool flag);
protected:
    //������
    int m_rows;
    int m_cols;
    //���Ŀ��
    int m_gridW;
    int m_gridH;
    //��������ֵĿ��
    int m_textW;
    int m_textH;
    //��ͷ
    std::string m_header;
    std::vector<std::string> m_data;

protected:
    //��ҳ������ҳ����
    int m_curPage;
    int m_maxPage;
    int m_extraData;//������ҳ��ʱ�����һҳʣ�������

    PushButton* m_preBtn;
    PushButton* m_nextBtn;
    PushButton* m_firstBtn;
    PushButton* m_lastBtn;

protected:
    //����Ƿ�������
    bool m_flag;

};

