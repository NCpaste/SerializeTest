#include "People.h"

IMPLEMENT_SERIAL(Asd, CObject, 1);

Asd::Asd()
{
	a = 1;
	b = 3.14;
	c = 'd';
	this->e = 999;
}

Asd :: ~Asd()
{

}

int Asd::GetE()
{
	return this->e;
}
int Asd::SetE(int t)
{
	this->e = t;
	return 0;
}

void Asd::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	// �ڴ�Ϊ��׼
	if (ar.IsStoring())
	{
		// cout
		ar << a;
		//ar << a << b << c;
		//ar << a << b << c << e;
	}
	else
	{
		// cin
		ar >> a;
		//ar >> a >> b >> c;
		//ar >> a >> b >> c >> e;
	}
}



//#include "People.h"
//
////�ؼ��궨�壺�ڶ������λ�ã�
////��һ������Ϊ��ǰ������
////�ڶ�������Ϊ����������
////����������Ϊ������ض����ͱ�ʶ,�ñ�ʶ����������(����ʵ����)����СΪ0
//IMPLEMENT_SERIAL(Person, CObject, 1)
//Person::Person() :CObject()
//{
//    m_id = 0;
//    m_age = 0;
//
//}
//
//Person::~Person()
//{
//
//}
//
//void Person::Serialize(CArchive& ar)
//{
//    //���л���д�����������
//    CObject::Serialize(ar);
//    //���л���д��ǰ��������
//    if (ar.IsStoring())//�ж϶�д������д������������д�뵽�ļ�������Ϊar.IsLoading()
//    {
//        ar << m_id << m_name << m_age; //��������cout��cin��IO����������
//    }
//    else //�����������ļ����뵽�ڴ�
//    {
//        ar >> m_id >> m_name >> m_age;
//    }
//}
//
////CArchive& AFXAPI operator>>(CArchive& ar, Person& src)
////{
////    return ar >> src.m_id >> src.m_name >> src.m_age;
////}
////
////CArchive& AFXAPI operator<<(CArchive& ar, Person& src)
////{
////    return ar << src.m_id << src.m_name << src.m_age;
////}