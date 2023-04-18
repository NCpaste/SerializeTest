#include "People.h"

//�ؼ��궨�壺�ڶ������λ�ã�
//��һ������Ϊ��ǰ������
//�ڶ�������Ϊ����������
//����������Ϊ������ض����ͱ�ʶ,�ñ�ʶ����������(����ʵ����)����СΪ0
IMPLEMENT_SERIAL(Person, CObject, 1)
Person::Person() :CObject()
{
    m_id = 0;
    m_age = 0;

}

Person::~Person()
{

}

void Person::Serialize(CArchive& ar)
{
    //���л���д�����������
    CObject::Serialize(ar);
    //���л���д��ǰ��������
    if (ar.IsStoring())//�ж϶�д������д������������д�뵽�ļ�������Ϊar.IsLoading()
    {
        ar << m_id << m_name << m_age; //��������cout��cin��IO����������
    }
    else //�����������ļ����뵽�ڴ�
    {
        ar >> m_id >> m_name >> m_age;
    }
}

//CArchive& AFXAPI operator>>(CArchive& ar, Person& src)
//{
//    return ar >> src.m_id >> src.m_name >> src.m_age;
//}
//
//CArchive& AFXAPI operator<<(CArchive& ar, Person& src)
//{
//    return ar << src.m_id << src.m_name << src.m_age;
//}