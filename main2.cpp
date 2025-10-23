#include <iostream>
void najdi_nejmensi_nejvetsi(int* pole, int velikost_pole, int** nejvetsi, int** nejmensi){
        int* stop = pole+velikost_pole;
        *nejvetsi = pole;
        *nejmensi = pole;
        while(!(pole==stop)){
            std::cout<< "adresa: "<<pole
            << ", hodnota: "<< *pole <<std::endl;
            if(**nejmensi>*pole){
                *nejmensi=pole;
            }
            if(**nejvetsi<*pole){
                *nejvetsi=pole;
            }
            pole++;
        }

}

int main(){
    int pole[10]={9,4,6,27,9,2,3,7,5,8};
    int* nejmensi;
    int* nejvetsi;
    najdi_nejmensi_nejvetsi(pole, 10, &nejvetsi, &nejmensi);

    std::cout<<*nejmensi << ", " << *nejvetsi <<std::endl;


    return 0;
}