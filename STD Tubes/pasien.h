#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED
#include <iostream>

#include <iostream>

using namespace std;

#define infoPasien(p) p -> infoPasien
#define nextRuangan(p) p -> nextRuangan
#define firstPasien(PS) ((PS).firstPasien)
#define infoRuangan(q) q -> infoRuangan
#define nextPasien(q) q -> nextPasien
#define Pas(q) q -> Pas
#define firstRuangan(Jur) ((Jur).firstRuangan)
#define nil NULL


struct Pasien {
    string namaPasien;
    string keluhanPasien;
    int idPasien;
};

struct Ruang {
    string namaRuangan;
    int noRuang;
};

typedef Pasien infotypePasien;
typedef struct elmPasien *adrPasien;
typedef Ruang infotypeRuang;
typedef struct elmRuang *adrRuang;

struct elmPasien {
    infotypePasien infoPasien;
    adrPasien nextPasien;
};

struct elmRuang{
    infotypeRuang infoRuangan;
    adrPasien Pas;
    adrRuang nextRuangan;
};

struct listPasien {
    adrPasien firstPasien;
};

struct listRuang {
    adrRuang firstRuangan;
};

void createlistRuang(listRuang &RG);
adrRuang createRuang(infotypeRuang infoRuangan);
void createlistPasien(listPasien &PS);
adrPasien createPasien(infotypePasien infoPasien);
void addRuang(listRuang &RG, adrRuang Ruang);
void showAllDataRuang(listRuang RG);
void DeleteRuangAndPasien(listRuang &RG, adrRuang &Ruang, string namaRuangan, int noRuang);
adrRuang findRuang(listRuang RG, string namaRuangan);
void addPasien(listRuang &RG, listPasien &PS, adrPasien Pas, string namaRuangan);
void showAllData(listRuang RG);
adrPasien findPasien(listPasien PS, string namaRuangan, string namaPasien, listRuang RG);
void deletePasien(listPasien &PS, string namaRuangan, int noRuang, listRuang &RG, adrPasien &Pas);
int countPasien(listRuang RG, string namaRuangan);

int Select_Menu();

#endif // PASIEN_H_INCLUDED
