#pragma once
/**
 * �������ݶ���
 */

#define _AFXDLL //MFC����ĺ궨��
#include <afxwin.h> //MFC����ͷ�ļ�
#include <afx.h> //MFC����ͷ�ļ�
class Person : public CObject
{
    DECLARE_SERIAL(Person)    //��һ�����λ�ã�����Ϊ��ǰ����
public:
    Person();
    ~Person();
public:
    //��д��Serialize��Ա������ʵ�ֶ������л���д����
    virtual void Serialize(CArchive& ar);
    //��д��������Ԫ����
    //friend CArchive& AFXAPI operator<<(CArchive& ar, Person& src);
    //friend CArchive& AFXAPI operator>>(CArchive& ar, Person& src);
    //�����������
public:
    long m_id;
    CString m_name;
    int m_age;

};