#include <iostream>


#include <tuple>
#include <vector>

#include <stdio.h>

using namespace std;

// 元组访问


void testTuple()
{
	//1.1)定义一个tuple时，需要指出每个成员的类型,tuple的构造函数是 explicit 的，因此必须使用 直接初始化。
	std::tuple<int, int, vector<int>> tupleTest(1, 4, { 5,6,7,8 });

	//1.2)make_tuple函数：用来生成tuple对象，用初始值的类型推断tuple类型
	auto itme = make_tuple("string", 3, 20.01);
	//1.3)tie解包  以用std::ignore占位符来表示不解某个位置的值
	string x;
	tuple_element<2, decltype(itme)>::type  y;
	std::tie(x, std::ignore, y) = itme; //只解第三个值了
	
	//2)访问tuple的成员
	auto first = get<0>(tupleTest);
	cout << "first value is : " << first << endl;

	auto second = get<1>(tupleTest);
	cout << "second value is : " << second << endl;

	auto third = get<2>(tupleTest);
	for (const auto& iter : third)
	{
		cout << "third value is : " << iter << endl;
	}

	//3)查询tuple成员数量。使用tuple_size需要知道tuple对象类型(类型推导使用 decltyple)，tuple_size有一个public static的数据成员value，
	int tupleTestSize = std::tuple_size<decltype(tupleTest)>::value;
	cout << "tuple size is : " << tupleTestSize << endl;

	//4).类模板tuple_element：查询tuple成员的类型。tuple_element接受一个索引(从0开始)和一个tuple对象类型。tuple_element有一个public的成员type，表示给定tuple类型中指定成员的类型
	auto dditme = make_tuple("string", 3, 20.01);
	tuple_element<1, decltype(itme)>::type ctype;//ctype的类型为int	

	
	// 元组合并
	auto newTuple = std::tuple_cat(itme, tupleTest);
	int newTupleSize = std::tuple_size<decltype(newTuple)>::value;
	cout << "after cat, new tuple size is : " << newTupleSize << endl;

	

}
//关系和相等运算符
//条件：只有2个tuple具有相同数量的成员，才可以比较。比较时，每对成员必须是合法的，简单来说就是2个tuple成员类型应该相同。
//高级用法：从函数返回多个值。由于tuple定义了 < 和 == 运算符，因此还可以将tuple序列传递给算法，并且可以在无序容器中将tuple作为关键字类型