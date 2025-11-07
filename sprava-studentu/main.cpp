#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// -------------------- DATOVÉ STRUKTURY --------------------

struct Student {
    int id;
    string jmeno;
    double prumer;
};

struct Uzel {
    Student data;
    Uzel* dalsi;
};

// -------------------- FUNKCE --------------------

// Pomocná funkce pro výpis studenta
ostream& operator<<(ostream& os, const Student& s) {
    os << "ID: " << s.id << ", Jméno: " << s.jmeno << ", Průměr: " << s.prumer;
    return os;
}

// 1️⃣ Parsování řádku CSV formátu: "101, Jan Novak, 1.8"
Student parsujRadek(const string& radek) {
    Student s;
    stringstream ss(radek);
    string idStr, jmenoStr, prumerStr;

    if (!getline(ss, idStr, ',')) throw runtime_error("Chybi ID");
    if (!getline(ss, jmenoStr, ',')) throw runtime_error("Chybi jmeno");
    if (!getline(ss, prumerStr)) throw runtime_error("Chybi prumer");

    try {
        s.id = stoi(idStr);
        s.jmeno = jmenoStr;
        // Odstraní mezery na začátku
        if (!s.jmeno.empty() && s.jmeno[0] == ' ')
            s.jmeno.erase(0, 1);
        s.prumer = stod(prumerStr);
    } catch (...) {
        throw runtime_error("Chyba při převodu dat");
    }

    return s;
}

// 2️⃣ Přidání studenta na konec seznamu
void pridejStudentaNaKonec(Uzel** pHead, Student data) {
    Uzel* novy = new Uzel{data, nullptr};
    if (*pHead == nullptr) {
        *pHead = novy;
    } else {
        Uzel* temp = *pHead;
        while (temp->dalsi != nullptr)
            temp = temp->dalsi;
        temp->dalsi = novy;
    }
}

// 3️⃣ Načtení studentů ze souboru
void nactiStudentyZeSouboru(const string& studenti, Uzel** pHead) {
    ifstream soubor(studenti);
    if (!soubor.is_open()) {
        cerr << "Nelze otevřít soubor: " << studenti << endl;
        return;
    }

    string radek;
    while (getline(soubor, radek)) {
        if (radek.empty() || radek[0] == '#') continue;
        try {
            Student s = parsujRadek(radek);
            pridejStudentaNaKonec(pHead, s);
        } catch (exception& e) {
            cerr << "Chyba při zpracování řádku: " << radek << " (" << e.what() << ")" << endl;
        }
    }

    soubor.close();
}

// 4️⃣ Výpis seznamu
void vypisSeznam(Uzel* head) {
    cout << "----- SEZNAM STUDENTŮ -----" << endl;
    Uzel* temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->dalsi;
    }
    cout << "----------------------------" << endl;
}

// 5️⃣ Třídění podle průměru (Bubble sort)
void setridSeznamPodlePrumeru(Uzel* head) {
    if (head == nullptr) return;
    bool prohozeno;
    do {
        prohozeno = false;
        Uzel* temp = head;
        while (temp->dalsi != nullptr) {
            if (temp->data.prumer > temp->dalsi->data.prumer) {
                swap(temp->data, temp->dalsi->data);
                prohozeno = true;
            }
            temp = temp->dalsi;
        }
    } while (prohozeno);
}

// 6️⃣ Uložení seznamu do souboru
void ulozStudentyDoSouboru(const string& studenti, Uzel* head) {
    ofstream soubor(studenti);
    if (!soubor.is_open()) {
        cerr << "Nelze otevřít soubor pro zápis: " << studenti << endl;
        return;
    }

    Uzel* temp = head;
    while (temp != nullptr) {
        soubor << temp->data.id << ", " << temp->data.jmeno << ", " << temp->data.prumer << endl;
        temp = temp->dalsi;
    }

    soubor.close();
}

// 7️⃣ Uvolnění seznamu
void zrusSeznam(Uzel** pHead) {
    Uzel* temp;
    while (*pHead != nullptr) {
        temp = *pHead;
        *pHead = (*pHead)->dalsi;
        delete temp;
    }
    *pHead = nullptr;
}

// -------------------- MAIN --------------------

int main() {
    Uzel* head = nullptr;
    string vstup = "studenti.txt";
    string vystup = "studenti_serazeno.txt";

    // Načtení studentů
    nactiStudentyZeSouboru(vstup, &head);

    // Výpis nenačteného seznamu
    vypisSeznam(head);

    // Přidání nového studenta
    Student novy{999, "Filip Rajdl", 1.5};
    pridejStudentaNaKonec(&head, novy);

    cout << "\nPo přidání nového studenta:\n";
    vypisSeznam(head);

    // Seřazení podle průměru
    setridSeznamPodlePrumeru(head);

    cout << "\nPo seřazení podle průměru:\n";
    vypisSeznam(head);

    // Uložení do souboru
    ulozStudentyDoSouboru(vystup, head);

    // Uvolnění paměti
    zrusSeznam(&head);

    return 0;
}
