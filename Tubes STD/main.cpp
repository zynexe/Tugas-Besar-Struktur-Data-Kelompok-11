#include "data_pasien.h"
#include <iostream>

using namespace std;

int main(){
  // Create two lists, one for patients and one for rooms
  list_P pasienList;
  list_R ruanganList;

  // Initialize both lists
  createPasien(pasienList);
  createRuangan(ruanganList);

  // Create a new patient and add them to the patient list
  infotype_P p;
  p.namaPasien = "John Smith";
  p.idPasien = 1;
  p.keluhanPasien = "Flu symptoms";
  adr_pasien newPatient = createElementPasien(p);
  insertPasien(pasienList, newPatient);

  // Create a new room and add it to the room list
  infotype_R r;
  r.kasurTersedia = "Yes";
  r.noRuang = 101;
  adrRuangan newRoom = createElementRuangan(r);
  insertRuangan(ruanganList, p.namaPasien, newRoom);

  // Show all patients and their assigned rooms
  showAll(ruanganList);
  showPasien(pasienList);
  return 0;
}
