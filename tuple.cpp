#include <iostream>


#include <tuple>
#include <vector>

#include <stdio.h>

using namespace std;

// Ԫ�����


void testTuple()
{
	//1.1)����һ��tupleʱ����Ҫָ��ÿ����Ա������,tuple�Ĺ��캯���� explicit �ģ���˱���ʹ�� ֱ�ӳ�ʼ����
	std::tuple<int, int, vector<int>> tupleTest(1, 4, { 5,6,7,8 });

	//1.2)make_tuple��������������tuple�����ó�ʼֵ�������ƶ�tuple����
	auto itme = make_tuple("string", 3, 20.01);
	//1.3)tie���  ����std::ignoreռλ������ʾ����ĳ��λ�õ�ֵ
	string x;
	tuple_element<2, decltype(itme)>::type  y;
	std::tie(x, std::ignore, y) = itme; //ֻ�������ֵ��
	
	//2)����tuple�ĳ�Ա
	auto first = get<0>(tupleTest);
	cout << "first value is : " << first << endl;

	auto second = get<1>(tupleTest);
	cout << "second value is : " << second << endl;

	auto third = get<2>(tupleTest);
	for (const auto& iter : third)
	{
		cout << "third value is : " << iter << endl;
	}

	//3)��ѯtuple��Ա������ʹ��tuple_size��Ҫ֪��tuple��������(�����Ƶ�ʹ�� decltyple)��tuple_size��һ��public static�����ݳ�Աvalue��
	int tupleTestSize = std::tuple_size<decltype(tupleTest)>::value;
	cout << "tuple size is : " << tupleTestSize << endl;

	//4).��ģ��tuple_element����ѯtuple��Ա�����͡�tuple_element����һ������(��0��ʼ)��һ��tuple�������͡�tuple_element��һ��public�ĳ�Աtype����ʾ����tuple������ָ����Ա������
	auto dditme = make_tuple("string", 3, 20.01);
	tuple_element<1, decltype(itme)>::type ctype;//ctype������Ϊint	

	
	// Ԫ��ϲ�
	auto newTuple = std::tuple_cat(itme, tupleTest);
	int newTupleSize = std::tuple_size<decltype(newTuple)>::value;
	cout << "after cat, new tuple size is : " << newTupleSize << endl;

	

}
//��ϵ����������
//������ֻ��2��tuple������ͬ�����ĳ�Ա���ſ��ԱȽϡ��Ƚ�ʱ��ÿ�Գ�Ա�����ǺϷ��ģ�����˵����2��tuple��Ա����Ӧ����ͬ��
//�߼��÷����Ӻ������ض��ֵ������tuple������ < �� == ���������˻����Խ�tuple���д��ݸ��㷨�����ҿ��������������н�tuple��Ϊ�ؼ�������