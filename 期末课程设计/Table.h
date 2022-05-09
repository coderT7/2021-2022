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
    //��������
    void setRowCount(int row);
    void setColCount(int col);
    //���ñ�ͷ
    void setHeader(const std::string& header);
    //�����в�������
    void insertData(const std::string& data);
    //��ʾ���
    virtual void show();
    //��ձ��
    virtual void clear();
    //�������ĸ��ӣ�grid�����ӣ�
    virtual void drawTableGrid();
    //��������еİ�ťѡ��
    virtual void drawButton();
    //��������ʾ������е�����
    virtual void drawTableData();
    //��������ʾ�����ı�ͷ
    virtual void drawHeader();
    //��'\t'�ָ����ݣ����������
    static std::vector<std::string> split(std::string str, char sperator = '\t');
    //��ȡ������Ϣ
    std::vector<std::string> get_data();
    //����ҳ��
    void updatePage();
    //��ȡ������Ϣ
    virtual void event_loop(const ExMessage& msg);
    //��ȡ�Լ����ñ��״̬������Ƿ�Ϊ�գ�
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
    //����ڵ�����
    std::vector<std::string> m_data;

protected:
    //��ҳ������ҳ����
    int m_curPage;
    int m_maxPage;
    int m_extraData;//������ҳ��ʱ�����һҳʣ������ݸ���
    //ҳ���л���ť
    PushButton* m_preBtn;
    PushButton* m_nextBtn;
    PushButton* m_firstBtn;
    PushButton* m_lastBtn;

protected:
    //����Ƿ�������
    bool m_flag;

};

