#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


////
////#define List_Init_Size 99
////const int MAXSIZE = 99;
////
///////�������Ա�
////typedef struct {
////    int elem[List_Init_Size];
////    int length;
////}Sqlist;
////
///////���Ա�ĳ�ʼ��
////int InitList_Sq(Sqlist&L) {
////    if (!L.elem)
////        exit(OVERFLOW);
////    L.length = 0;
////   
////}
////
///////�ݻ����Ա�
////void DestroyList(Sqlist& L) {
////    if (L.elem) 
////        delete L.elem;
////}
////
///////������Ա�L
////void ClearList(Sqlist& L) {
////    L.length = 0;
////}
////
///////�����Ա�L�ĳ���
////int GetLength(Sqlist L) {
////    return L.length;
////}
////
///////�ж����Ա��Ƿ�Ϊ��
////bool IsEmpty(Sqlist L) {
////    if (L.length == 0)
////        return true;
////    else return false;
////}
////
///////˳����ȡֵ
////int GetElem(Sqlist L, int i, int& e) 
////{
////    if (i<1 || i>L.length) return 0;
////    e = L.elem[i - 1];
////    return e;
////}
////
///////˳���Ĳ���
////int LocateElem(Sqlist L, int e) {
////    for (int i = 0; i <= L.length; i++)
////        if (L.elem[i] == e) 
////            return i+1;
////}
////
///////˳���Ĳ���
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
///////˳����ɾ��
////int ListDelete_Sq(Sqlist& L, int i) 
////{
////    if (i<1 || i>L.length) return 0;
////    for (int j = i; j <= L.length - 1; j++)
////        L.elem[j - 1] = L.elem[j];
////    L.length--;
////}
///////����˳���
////void CreateList(Sqlist& L, int a[], int n) {
////    for (int i = 0; i < n; i++) {
////        L.elem[i] = a[i];
////    }
////    L.length = n;
////}
////
///////���˳���
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
////    printf("��ĳ���Ϊ��%d\n", GetLength(sq));
////    printf("�ڵ�5��λ���ϲ�������10��\n", ListInsert_Sq(sq, 6, 10));
////    DispList(sq);
////    printf("ɾ����3��λ���ϵ�Ԫ�أ�\n", ListDelete_Sq(sq, 3));
////    DispList(sq);
////    printf("���ҵ�7��Ԫ�أ�%d\n", LocateElem(sq, 7));
////}
////
