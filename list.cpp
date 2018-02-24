#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L)=NULL;
    last(L)=NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = new elmlist;
    //-------------your code here-------------
    info(P)=x;

    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (first(L)==NULL) {
        first(L)=P;
        last(L)=P;
        next(P)=P;
        prev(P)=P;
    } else {
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=P;
        prev(first(L))=P;
        first(L)=P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (first(L)==NULL) {
        first(L)=P;
        last(L)=P;
        next(P)=P;
        prev(P)=P;
    } else {
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=P;
        prev(first(L))=P;
        last(L)=P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    P=first(L);
    P=first(L);
    do {
        if (info(P).ID==x.ID) {
            return P;
        }
        P=next(P);
    } while (P!=first(L));
    return NULL;
    //----------------------------------------

}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P=NULL;
    //-------------your code here-------------
    x.name=x.name+".wav";
    P=first(L);
    do {
        if (info(P).name==x.name) {
            return P;
        }
        P=next(P);
    } while (P!=first(L));
    return NULL;
    //----------------------------------------
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    P=first(L);
    if (next(P)==P) {
        first(L)=NULL;
        last(L)=NULL;
        next(P)=NULL;
        prev(P)=NULL;
    }
    else if (next(P)!=P) {
        first(L)=next(P);
        prev(first(L))=last(L);
        next(last(L))=first(L);
        prev(P)=NULL;
        next(P)=NULL;
    }
    else {

    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    P=last(L);
    if (prev(P)==P) {
        first(L)=NULL;
        last(L)=NULL;
        next(P)=NULL;
        prev(P)=NULL;
    }
    else if (prev(P)!=P) {
        last(L)=prev(P);
        prev(first(L))=last(L);
        next(last(L))=first(L);
        prev(P)=NULL;
        next(P)=NULL;
    }
    else {

    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if (Prec==first(L)) {
        insertFirst(L, P);
    }
    else if (Prec==last(L)) {
        insertLast(L, P);
    }
    else {
        next(P)=next(Prec);
        prev(P)=Prec;
        prev(next(Prec))=P;
        next(Prec)=P;
    }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    P=next(Prec);
    if (P==first(L)) {
        deleteFirst(L, P);
    }
    else if (P==last(L)) {
        deleteLast(L, P);
    }
    else {
        next(Prec)=next(P);
        prev(next(P))=Prec;
        next(P)=NULL;
        prev(P)=NULL;
    }
    //----------------------------------------
}

