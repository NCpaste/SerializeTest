#pragma once
#define _AFXDLL

#include <afxwin.h>
#include <afx.h>

class Asd : public CObject
{
public:
	DECLARE_SERIAL(Asd);
	Asd();
	~Asd();

	virtual void Serialize(CArchive &ar);
	int GetE();
	int SetE(int t);
public:
	int a;
	double b;
	char c;

private:
	int e;
};



//#pragma once
///**
// * 定义数据对象
// */
//
//#define _AFXDLL //MFC程序的宏定义
//#include <afxwin.h> //MFC程序头文件
//#include <afx.h> //MFC程序头文件
//class Person : public CObject
//{
//    DECLARE_SERIAL(Person)    //第一个宏的位置，参数为当前类名
//public:
//    Person();
//    ~Person();
//public:
//    //重写了Serialize成员函数，实现对象序列化读写操作
//    virtual void Serialize(CArchive& ar);
//    //重写操作符友元函数
//    //friend CArchive& AFXAPI operator<<(CArchive& ar, Person& src);
//    //friend CArchive& AFXAPI operator>>(CArchive& ar, Person& src);
//    //定义对象数据
//public:
//    long m_id;
//    CString m_name;
//    int m_age;
//
//};