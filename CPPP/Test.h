#pragma once
#ifndef _TEST_H_
#define _TEST_H_
/****����Ϊ��˵�������Զ���һ��ָ��ָ��һ������ȫ���͵���(��������)*****/
/*����������Ķ�����ʹ��һ��һ������ȫ���͵��࣬Ҳ����˵Ҫ��ָ�룬������*/
class X;
class Y {
	X* ymem;
};
class X {
	Y xmem;
};

#endif