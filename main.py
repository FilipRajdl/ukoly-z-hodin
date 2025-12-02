import random
cislo = random.randrange(1, 10000)
pokusy = 0
while True:
    hadani = int(input("Hadej cislo od 1 do 10000: "))
    pokusy += 1
    if hadani < cislo:
        print("Cislo je vetsi.")
    elif hadani > cislo:
        print("Cislo je mensi.")
    else:
        print(f"Uhadl jsi cislo {cislo} za {pokusy} pokusu!")
        break   

# Tento program generuje náhodné číslo mezi 1 a 100 a uživatel má za úkol toto číslo uhodnout.