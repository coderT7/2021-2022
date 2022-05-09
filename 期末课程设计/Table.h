#pragma once
#include "BasicWidget.h"
#include"PushButton.h"
#include"config.h"
#include<vector>

class Table :
    public BasicWidget
{
    friend class Management;
public:
    Table(int row = 0, int col = 0);
    ~Table();
    //设置行列
    void setRowCount(int row);
    void setColCount(int col);
    //设置表头
    void setHeader(const std::string& header);
    //向表格中插入数据
    void insertData(const std::string& data);
    //显示表格
    virtual void show();
    //清空表格
    virtual void clear();
    //画出表格的格子（grid：格子）
    virtual void drawTableGrid();
    //画出表格中的按钮选项
    virtual void drawButton();
    //画出（显示）表格中的数据
    virtual void drawTableData();
    //画出（显示）表格的表头
    virtual void drawHeader();
    //以'\t'分割数据，逐个填入表格
    static std::vector<std::string> split(std::string str, char sperator = '\t');
    //获取表格的信息
    std::vector<std::string> get_data();
    //更新页面
    void updatePage();
    //获取监听消息
    virtual void event_loop(const ExMessage& msg);
    //获取以及设置表格状态（表格是否为空）
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
    //表格内的数据
    std::vector<std::string> m_data;

protected:
    //分页操作（页数）
    int m_curPage;
    int m_maxPage;
    int m_extraData;//非整数页数时，最后一页剩余的数据个数
    //页面切换按钮
    PushButton* m_preBtn;
    PushButton* m_nextBtn;
    PushButton* m_firstBtn;
    PushButton* m_lastBtn;

protected:
    //表格是否有数据
    bool m_flag;

};

