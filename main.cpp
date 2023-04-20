#include <iostream>
#include "Connection.h"
#include "pch.h"
#include"CommonConnectionPool.h"
using namespace std;


int main()
{
	/*
	Connection conn;
	char sql[1024] = { 0 };
	sprintf(sql, "insert into user(name,age,sex) value('%s',%d,'%s')", "zhangsan", 20, "male");
	conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	conn.update(sql);
	*/

	clock_t begin = clock();
	ConnectionPool* cp = ConnectionPool::getConnectionPool();
	thread t1([&]() {
		for (int i = 0; i < 250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) value('%s',%d,'%s')", "zhangsan", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		}
		});
	thread t2([&]() {
		for (int i = 0; i < 250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) value('%s',%d,'%s')", "zhangsan", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		}
		});
	thread t3([&]() {
		for (int i = 0; i < 250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) value('%s',%d,'%s')", "zhangsan", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		}
		});
	thread t4([&]() {
		for (int i = 0; i < 250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) value('%s',%d,'%s')", "zhangsan", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		}
		});
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	clock_t end = clock();
	cout << (end - begin) << "ms" << endl;

	//#if 0
	//	for (int i = 0; i < 1000; ++i)
	//	{
	//		//不使用连接池
	//		/*Connection conn;
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name,age,sex) value('%s',%d,'%s')", "zhangsan", 20, "male");
	//		conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	//		conn.update(sql);*/
	//
	//		//使用连接池
	//		shared_ptr<Connection> sp = cp->getConnection();
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name,age,sex) value('%s',%d,'%s')", "zhangsan", 20, "male");
	//		sp->update(sql);
	//	}
	//#endif

	return 0;
}