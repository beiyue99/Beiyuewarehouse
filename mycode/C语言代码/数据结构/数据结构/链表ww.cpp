#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


////
////#define List_Init_Size 99
////const int MAXSIZE = 99;
////
///////定义线性表
////typedef struct {
////    int elem[List_Init_Size];
////    int length;
////}Sqlist;
////
///////线性表的初始化
////int InitList_Sq(Sqlist&L) {
////    if (!L.elem)
////        exit(OVERFLOW);
////    L.length = 0;
////   
////}
////
///////摧毁线性表
////void DestroyList(Sqlist& L) {
////    if (L.elem) 
////        delete L.elem;
////}
////
///////清除线性表L
////void ClearList(Sqlist& L) {
////    L.length = 0;
////}
////
///////求线性表L的长度
////int GetLength(Sqlist L) {
////    return L.length;
////}
////
///////判断线性表是否为空
////bool IsEmpty(Sqlist L) {
////    if (L.length == 0)
////        return true;
////    else return false;
////}
////
///////顺序表的取值
////int GetElem(Sqlist L, int i, int& e) 
////{
////    if (i<1 || i>L.length) return 0;
////    e = L.elem[i - 1];
////    return e;
////}
////
///////顺序表的查找
////int LocateElem(Sqlist L, int e) {
////    for (int i = 0; i <= L.length; i++)
////        if (L.elem[i] == e) 
////            return i+1;
////}
////
///////顺序表的插入
////int ListInsert_Sq(Sqlist& L, int i, int e) 
////{
////    if (i<1 || i>L.length + 1) return 0;
////    if (L.length == MAXSIZE) return 0;
////    for (int j = L.length; j >= i; j--)
////        L.elem[j] = L.elem[j - 1];
////    L.elem[i - 1] = e;
////    L.length++;
////}
////
///////顺序表的删除
////int ListDelete_Sq(Sqlist& L, int i) 
////{
////    if (i<1 || i>L.length) return 0;
////    for (int j = i; j <= L.length - 1; j++)
////        L.elem[j - 1] = L.elem[j];
////    L.length--;
////}
///////创建顺序表
////void CreateList(Sqlist& L, int a[], int n) {
////    for (int i = 0; i < n; i++) {
////        L.elem[i] = a[i];
////    }
////    L.length = n;
////}
////
///////输出顺序表
////void DispList(Sqlist&  L) {
////    for (int i = 0; i < L.length; i++) {
////        cout << L.elem[i] << " ";
////    }
////    cout << endl;
////}
////
////int main() {
////    Sqlist sq;
////    int x[9] = { 1,2,3,4,5,6,7,8,9 };
////    int a;
////    int t;
////    CreateList(sq, x, 9);
////    DispList(sq);
////    printf("表的长度为：%d\n", GetLength(sq));
////    printf("在第5个位置上插入数字10：\n", ListInsert_Sq(sq, 6, 10));
////    DispList(sq);
////    printf("删除第3个位置上的元素：\n", ListDelete_Sq(sq, 3));
////    DispList(sq);
////    printf("查找第7个元素：%d\n", LocateElem(sq, 7));
////}
////
