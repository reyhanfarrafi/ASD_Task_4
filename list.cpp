#include "list.h"

void createList(List &L)
{
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}
address allocate(infotype x)
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */
    address P = NULL;
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void deallocate(address &P)
{
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    delete P;
}
void insertFirst(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    if (first(L) != NULL)
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
    else
    {
        first(L) = P;
        next(P) = first(L);
        prev(P) = P;
    }
}
void insertLast(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    if (first(L)==NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
    }
}
address findElmByID(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */
    address P = NULL;
    P = first(L);
    do
    {
        P = next(P);
    }
    while( P != first(L)&& info(P).ID != x.ID);
    if (info(P).ID == x.ID)
    {
        return P;
    }
    return NULL;
}
address findElmByName(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */
    address P = NULL;
    P = first(L);
    do
    {
        P = next(P);
    }
    while( P != first(L) && info(P).name != x.name);
    if (info(P).name == x.name)
    {
        return P;
    }
    return NULL;
}
void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */

    if (first(L)==NULL)
    {
        cout<<"List Kosong"<<endl;
    }
    P = first(L);
    if (next(first(L))!= P)
    {
        first(L) = next(P);
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
    else
    {
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }
}
void deleteLast(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    P = prev(first(L));
    next(prev(P))= first(L);
    prev(first(L)) = prev(prev(P));
    next(P) = NULL;
    prev(P) = NULL;
}
void insertAfter(List &L, address &Prec, address P)
{
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    if (first(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}
void deleteAfter(List &L, address &Prec, address &P)
{
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    P = next(Prec);
    if (next(Prec) != first(L))
    {
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
    else
    {
        next(P) = NULL;
        prev(P) = NULL;
        P = NULL;
    }
}
