""""
def vypis_statistiku(seznam):
    if not seznam:
        print("Seznam je prázdný.")
        return

    soucet = sum(seznam)
    nejvetsi = max(seznam)
    nejmensi = min(seznam)
    sude =  sum(1 for num in seznam if num % 2 == 0)
    liche = sum(1 for num in seznam if num % 2 != 0)
    prumer = soucet / len(seznam)
 
    print("Statistika seznamu:")
    print(f"Součet: {soucet}")
    print(f"Největší číslo: {nejvetsi}")
    print(f"Nejmenší číslo: {nejmensi}")
    print(f"Počet sudých čísel: {sude}")
    print(f"Počet lichých čísel: {liche}")
    print(f"Průměr: {prumer:.2f}")
    print("-" * 17)

def main():
    cisla = []

    print("Zadejte čísla pro analýzu. Pro ukončení zadejte 'konec'.")

    while True:
        vstup = input("Zadejte číslo (nebo 'konec' pro ukončení): ")
        if vstup.lower() == 'konec':
            break
        try:
            cislo = float(vstup)
            cisla.append(cislo)
        except ValueError:
            print("Neplatný vstup, zkuste to znovu.")

    vypis_statistiku(cisla)

if __name__ == "__main__":
    main()
    

def spocitej_znaky(text):
    text = text.lower()
    frekvence = {}
    for znak in text:
        if znak == ' ':
            continue
        if znak in frekvence:
            frekvence[znak] += 1
        else:
            frekvence[znak] = 1
    return frekvence

def main():
    text = input("Zadejte text: ")
    vysledek = spocitej_znaky(text)
    print("\nFrekvence znaků:")
    print(vysledek)

    serazeno = sorted(vysledek.items(), key=lambda x: x[1], reverse=True)
    print("\nZnaky seřazené podle frekvence:")
    for znak, pocet in serazeno:
        print(f"'{znak}': {pocet}")

if __name__ == "__main__":
    main()
    """


studenti = []
def pridej_studenta(jmeno, znamky):
    studenti.append({'jmeno': jmeno, 'znamky': list(znamky)})

def prumer(znamky):
    return sum(znamky) / len(znamky) if znamky else float("inf")

def nejlepsi_student(seznam_studentu):
    if not seznam_studentu:
        print("Seznam studentů je prázdný.")
        return None
    best = min(seznam_studentu, key=lambda student: prumer(student['znamky']))
    avg = prumer(best['znamky'])
    print(f"Nejlepší student je {best['jmeno']} s průměrem {avg:.2f}")
    return best["jmeno"]

if __name__ == "__main__":
    pridej_studenta("Jan", [1, 2, 1, 3])
    pridej_studenta("Eva", [2, 2, 2])
    pridej_studenta("Petr", [1, 1, 1, 1])
    
    print("Seznam studentů:")
    for student in studenti:
        print(f"{student['jmeno']}: {student['znamky']} (průměr: {prumer(student['znamky']):.2f})")

    nejlepsi_student(studenti)