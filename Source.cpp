#include <iostream>
#include <fstream>
#include <string>
#include "Forward_List.h"
#include "Double_List.h"
#include "Binary_Tree.h"
#include "Trie_Tree.h"
#include <list>
#include <algorithm>
#include <functional>

//void task2(DLIST& dlist) {
//	//	//3 вариант ƒан линейный двунаправленный список. ≈сли список содержит нечетное количество 
//	//	/* элементов,то продублировать центральный элемент, иначе оставить список без изменени€.
//	//	   —писок можно просматривать один раз
//	//	*/
//	NODEDL* p = dlist.get_begin();
//	NODEDL* q = dlist.get_begin();
//	NODEDL* g = dlist.get_end();
//
//	int     k = 0;
//
//	while (p->next && q->next->next && q->next->next != g) {
//		p = p->next;
//		q = q->next->next;
//		++k;
//	}
//
//	if (k % 2 != 0) {
//		dlist.add_after(p->next, p->next->info);
//	}
//	else {
//		dlist.print();
//	}
//}
// 
// 
//void task2(DLIST& dlist)
//{
//	/*  1 вариант          ƒан линейный двунаправленный список.≈сли список содержит нечетное количество
//				  элементов,то удалить центральный элемент, иначе оставить список без изменени€.
//				  —писок можно просматривать один раз*/
//
//	NODEDL* p = dlist.get_begin();
//	NODEDL* q = dlist.get_begin();
//	NODEDL* end = dlist.get_end();
//
//	int k = 0;
//	while (p->next && q->next->next && q->next->next != end)
//	{
//		p = p->next;
//		q = q->next->next;
//		k++;
//	}
//	if (k % 2 != 0) 
//	{
//		dlist.delete_after(p);
//	}
//	else 
//	{
//		dlist.print();
//	}
//
//}
//
// 
//void task2(DLIST& list) { 2 вариант
//	ptrNODEDL p = list.get_begin();
//	ptrNODEDL onex = p;
//	ptrNODEDL twox = nullptr;
//	double sum = 0;
//	int counter = 1;
//	while (p->next) {
//		sum += p->info;
//		counter++;
//		if (counter % 2 == 0) { onex = onex->next; }
//		p = p->next;
//	}
//	std::cout << std::endl << counter << " ";
//	if (counter % 2 == 0) { list.add_after(onex, sum); }
//
//}
//

void task1(FLIST& flist, std::function <bool(TInfo x)> lambda) // ¬ариант 3
{
    NODEL* p = flist.get_head()->next;
    NODEL* first = nullptr;
    NODEL* prelast = nullptr;
    NODEL* last = nullptr;

    while (p->next && !first)
    {
        if (lambda(p->info))
        {
            first = p;
        }
        p = p->next;
    }
    int sum = 0;
    while (p->next)
    {
        if (lambda(p->next->info))
        {
            prelast = last;
            last = p->next;
        }
        p = p->next;
    }
    p = first;
    while (first->next != prelast)
    {
        sum += first->next->info;
        flist.delete_by_pointer(first->next);
    }
    flist.adding_by_pointer(first->next, sum);

    std::cout << first->info << "  " << prelast->info << "  " << sum << std::endl;
}

//void task1(FLIST& list, std::function <bool(TInfo x)> lambda) { // 2 вариант
//	ptrNODEL p = list.get_head();
//	ptrNODEL first = nullptr;
//	ptrNODEL last = nullptr;
//	bool flag = true;
//	while (p->next && flag) {
//		if (lambda(p->next->info)) {
//			first = p;
//			flag = false;
//		}
//		p = p->next;
//	}
//	while (p->next) {
//
//		if (lambda(p->next->info)) {
//
//			last = p;
//
//		}
//		//if (!flag) { first = p; }
//		p = p->next;
//	}
//	if (last && first) {
//
//		while (first->next != last) { list.delete_by_pointer(first->next); }
//	}
//}


int main()
{
	std::ifstream file("data_list.txt");
	FLIST flist("data_list.txt");
	flist.print();
	task1(flist, [](TInfo x)
		{
			return x % 10 == 7;
		});

	flist.print();

	//task1(flist, [](TInfo x)
	//	{
	//		return x % 3 == 0;
	//	});

	//flist.print();


	//std::ifstream file1("data_list.txt");
	//DLIST dlist("data_list.txt");
	//dlist.print();
	//task2(dlist);
	//dlist.print();

	///*std::ifstream file2("data_tree.txt");
	//BTREE btree("data_tree.txt");
	//btree.print();*/

	//std::ifstream file3("words.txt");
	//TTREE ttree("words.txt");
	//ttree.print(false);

	std::cin.get();
	return 0;
}