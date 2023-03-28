#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* a;
	int size;
	int capcity;
}Hp;//定义一个堆

void HpInit(Hp* ps);//堆的初始化
void HpPush(Hp* ps,HpDataType x);//堆的插入
void HpPop(Hp* ps);//堆的删除
void HpDestroy(Hp* ps);//堆的销毁
void AdjustUp(HpDataType*a,int child);//向上调整
void Swap(HpDataType* a, HpDataType* b);//交换数据
void AdjustDown(HpDataType* a, int n, int parent);//向下调整
bool HpEmpty(Hp* ps);//判断是否为空
HpDataType HpTop(Hp* ps);//获取堆顶元素
int HpSize(Hp* ps);//获取堆有效数据大小

