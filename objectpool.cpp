#include <iostream>
#include "ObjectPool.h"
#include "test.h"
int main()
{
	ObjectPool<test>* pool=new ObjectPool<test>();

	pool->SetPlus(200);
	test* p_test1 = pool->GetObject();
	test* p_test2 = pool->GetObject();


	p_test1->Draw();
	p_test2->Draw();

	pool->ReturnObject(&p_test1);
	pool->ReturnObject(&p_test2);

	delete pool;
	_CrtDumpMemoryLeaks();
//    std::cout << "Hello World!\n";
}