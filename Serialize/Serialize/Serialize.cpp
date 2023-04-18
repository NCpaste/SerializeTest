#include <iostream>
#include "People.h"
using namespace std;

#define read 1
#define write 0

int main()
{
	bool flag = 0;
	Asd temp;
	CFile* fp = new CFile;

	fp->Open(_T("../CAsd.txt"), CFile::modeCreate);
	fp->Close();

	std::cout << "Begin with 0\n";
	while (cin >> flag)
	{
		if (flag == read)
		{
			cout << "Load" << endl;

			fp->Open(_T("../CAsd.txt"), CFile::modeRead);
			CArchive ar(fp, CArchive::load);
			
			temp.Serialize(ar);
			int a = temp.a;
			double b = temp.b;
			char c = temp.c;
			int e = temp.GetE();

			printf("Load : %d, %lf, %c, %d\n", a, b, c, e);
			std::cout << "Init : 1, 3.14, d, 999\n\n";

			ar.Close();
			fp->Close();
		}
		else if (flag == write)
		{
			cout << "Store" << endl;

			fp->Open(_T("../CAsd.txt"), CFile::modeWrite);
			CArchive ar(fp, CArchive::store);
			temp.a = 123;
			temp.b = 123.14;
			temp.c = 'D';
			temp.SetE(456);

			temp.Serialize(ar);

			ar.Close();
			fp->Close();
 		}
		else
		{
			break;
		}
	}


	std::cout << "End Proc" << endl;
	return 0;
}



//// TSTMFC序列化读写.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//#include "People.h"
//using namespace std;
////#define WRITE //读写控制宏 读：READ 写：WRITE
//#define READ
////测试入口函数
//int main()
//{
//#ifdef WRITE
//    cout << "执行写文件操作\n" << endl;
//    CFile file(_T("../person.txt"), CFile::modeCreate | CFile::modeWrite); //定义一个文件流对象
//    CArchive ar(&file, CArchive::store);  //定义一个序列化对象和文件流对象绑定并指定归档方式为储存，加载的方式为CArchive::load
//    Person person;
//    person.m_id = 12345;
//    person.m_name = "zhangsan";
//    person.m_age = 12;
//    person.Serialize(ar);
//    ar.Close();
//    file.Close();
//#endif
//#ifdef READ
//    cout << "执行读文件操作\n" << endl;
//    CFile file(_T("../person.txt"), CFile::modeRead); //定义一个文件流对象
//    CArchive ar(&file, CArchive::load);  //定义一个序列化对象和文件流对象绑定并指定归档方式为储存，加载的方式为CArchive::load
//    Person person;
//    person.Serialize(ar);
//    cout << person.m_id << "|" << person.m_name << "|" << person.m_age << endl;
//    ar.Close();
//    file.Close();
//    cin.get();
//#endif // DEBUG
//
//
//
//
//
//
//}
//
//// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
//// 调试程序: F5 或调试 >“开始调试”菜单
//
//// 入门使用技巧: 
////   1. 使用解决方案资源管理器窗口添加/管理文件
////   2. 使用团队资源管理器窗口连接到源代码管理
////   3. 使用输出窗口查看生成输出和其他消息
////   4. 使用错误列表窗口查看错误
////   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
////   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件