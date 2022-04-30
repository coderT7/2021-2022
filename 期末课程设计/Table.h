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
    //行列数
    int m_rows;
    int m_cols;
    //表格的宽高
    int m_gridW;
    int m_gridH;
    //表格内文字的宽高
    int m_textW;
    int m_textH;
    //表头
    std::string m_header;
    std::vector<std::string> m_data;

protected:
    //分页操作（页数）
    int m_curPage;
    int m_maxPage;
    int m_extraData;//非整数页数时，最后一页剩余的数据

    PushButton* m_preBtn;
    PushButton* m_nextBtn;
    PushButton* m_firstBtn;
    PushButton* m_lastBtn;

protected:
    //表格是否有数据
    bool m_flag;

};

