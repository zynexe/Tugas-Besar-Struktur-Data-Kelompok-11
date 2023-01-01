#ifndef DATA_PASIEN_H_INCLUDED
#define DATA_PASIEN_H_INCLUDED
#include <iostream>

using namespace std;
#define infoPasien(P) P->infoPasien
#define nextPasien(P) P->nextPasien
#define first(L) ((L).first)
#define nil NULL
#define infoRumahSakit(P) P->infoRumahSakit
#define nextRumahSakit(P) P->nextRumahSakit

struct Pasien{
    string namaPasien;
    int idPasien;
    string keluhanPasien;
};

typedef struct elmPasien *adr_pasien;
typedef struct elmRuangan *adrRuangan;
typedef Pasien infotype_P;

struct elmPasien{
    infotype_P infoPasien;
    adr_pasien nextPasien;
    adrRuangan nextRumahSakit;
};

struct Ruangan{
    string kasurTersedia;
    int noRuang;
};

typedef Ruangan infotype_R;
struct elmRuangan{
    infotype_R infoRumahSakit;
    adrRuangan nextRumahSakit;
};

struct list_P{
    adr_pasien first;
};

struct list_R{
    adrRuangan first;
};

void createPasien(list_P &P);
adr_pasien createElementPasien(infotype_P x);
void insertLastPasien(list_P &P, adr_pasien y);
void showPasien(list_P P);
void deleteLastPasien(list_P &P, adr_pasien y);
adr_pasien searchPasien(list_P P, string namaPasien);


void createRuangan(list_R &R);
adrRuangan createElementRuangan(infotype_R a);
void insertRuangan(list_R &R, string namaPasien, adrRuangan b);
void showAll(list_P P, list_R R);
void deleteRuangan(list_R &R, adrRuangan &c);
bool findRuangan(list_R R, int id);



#endif // DATA_PASIEN_H_INCLUDED
