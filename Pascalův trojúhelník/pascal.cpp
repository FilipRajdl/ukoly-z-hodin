// 1. "Importujeme" knihovny, které budeme potřebovat
#include <iostream>  // Pro vstup (cin) a výstup (cout)
#include <vector>    // Pro "chytrá pole", která mohou růst
#include <iomanip>   // Pro hezké formátování výstupu (setw)

// 2. Použijeme standardní jmenný prostor, abychom nemuseli psát std::cout
using namespace std;

int main() {
    // 3. Zeptáme se uživatele, kolik řádků chce
    int pocetRadku;
    cout << "Zadej pocet radku pro Pascaluv trojuhelnik: ";
    cin >> pocetRadku;

    // 4. Hlavní datová struktura: "Vektor vektorů"
    // Představ si to jako seznam řádků, kde každý řádek je seznam čísel.
    vector<vector<int>> trojuhelnik;

    // 5. Hlavní smyčka (cyklus), která generuje řádek po řádku
    // 'i' je číslo aktuálního řádku (začínáme od 0 do pocetRadku-1)
    for (int i = 0; i < pocetRadku; i++) {
        
        // 6. Vytvoříme nový prázdný řádek (jako dočasnou proměnnou)
        vector<int> aktualniRadek;

        // 7. Vnitřní smyčka, která plní aktuální řádek čísly
        // 'j' je číslo sloupce v aktuálním řádku
        // Každý řádek 'i' má 'i+1' prvků (řádek 0 má 1 prvek, řádek 1 má 2 prvky...)
        for (int j = 0; j <= i; j++) {
            
            // 8. Logika Pascalova trojúhelníku
            if (j == 0 || j == i) {
                // První (j==0) a poslední (j==i) prvek v řádku je VŽDY 1
                aktualniRadek.push_back(1);
            } else {
                // Jakékoliv jiné číslo je součtem dvou čísel nad ním
                // trojuhelnik[i-1] ... řádek nad námi
                // [j-1] a [j] ... dva prvky přímo nad námi
                int cislo = trojuhelnik[i-1][j-1] + trojuhelnik[i-1][j];
                aktualniRadek.push_back(cislo);
            }
        }
        
        // 9. Když je řádek hotový (vnitřní smyčka skončila),
        // přidáme ho do našeho hlavního trojúhelníku.
        trojuhelnik.push_back(aktualniRadek);
    }

    // 10. Tisk trojúhelníku
    cout << "\n--- Vas Pascaluv trojuhelnik ---\n" << endl;
    
    for (int i = 0; i < trojuhelnik.size(); i++) {
        // Přidáme odsazení zleva, aby to vypadalo jako trojúhelník
        // (počet mezer = celkový počet řádků - aktuální řádek)
        cout << string((pocetRadku - i - 1) * 3, ' '); // * 3 pro lepší rozestupy

        // Vytiskneme všechna čísla v řádku
        for (int j = 0; j < trojuhelnik[i].size(); j++) {
            // setw(6) "rezervuje" 6 míst pro číslo, aby se to hezky zarovnalo
            cout << setw(6) << trojuhelnik[i][j];
        }
        // Po každém řádku odřádkujeme
        cout << endl;
    }

    return 0; // Program úspěšně skončil
}