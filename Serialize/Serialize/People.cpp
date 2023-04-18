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
	// 内存为标准
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
////关键宏定义：第二个宏的位置，
////第一个参数为当前类名，
////第二个参数为父类类名，
////第三个参数为该类的特定整型标识,该标识将用来解序(重新实例化)，最小为0
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
//    //序列化读写基类对象数据
//    CObject::Serialize(ar);
//    //序列化读写当前对象数据
//    if (ar.IsStoring())//判断读写操作，写操作，将数据写入到文件，加载为ar.IsLoading()
//    {
//        ar << m_id << m_name << m_age; //功能类似cout、cin的IO数据流操作
//    }
//    else //读操作，将文件读入到内存
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