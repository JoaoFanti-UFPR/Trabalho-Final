//Trabalho Final em C - Conversor de Unidades
#include <stdio.h>
#include <math.h>

#define clrscr() printf("\e[1;1H\e[2J");

#include <stdio.h>

const double distanciaConst[26] = {
    1000.0,         //km -> m
    1,              //m  -> m
    0.1,            //dc -> m
    0.01,           //cm -> m
    0.001,          //mm -> m
    1e-6,           //μm -> m
    1e-9,           //nm -> m
    1e-12,          //pm -> m
    1609.344,       //milha -> m
    1852.0,         //milha nautica -> m 
    201.168,        //furlong  -> m   
    1.8288,         //fathom   -> m
    0.9144,         //jarda    -> m
    0.3048,         //pé       -> m
    0.0254,         //polegada -> m
    500.0,          //li    -> m
    3.333333,       //zhang -> m
    0.333333,       //chi   -> m
    0.033333,       //cun   -> m
    0.003333,       //fen   -> m
    0.000333,       //lii   -> m
    0.0000333,      //hao   -> m
    3.08567758149137e16,    //parsec  -> m
    384400000.0,    //distancia lunar -> m
    1.496e11,       //unidade astronomica -> m
    9.4607e15       //ano luz -> m
};

const double massaConst[21] = {
    1000.0,         //T  -> kg
    1,              //kg -> kg
    0.001,          //g  -> kg
    1e-6,           //mg -> kg
    1e-9,           //μg -> kg
    100.0,          //quintal -> kg
    0.453592,       //libra   -> kg
    0.0283495,      //onça    -> kg
    0.0002,         //quilate -> kg
    0.00006479891,  //grão    -> kg
    1016.0469088,   //tonelada britânica -> kg
    907.18474,      //tonelada norte-americana -> kg
    50.80234544,    //quintal britanico -> kg
    45.359237,      //quintal norte-americano -> kg
    6.35029,        //pedra -> kg
    0.0017718451953125,     //dram -> kg
    50.0,           //dan -> kg
    0.5,            //jin -> kg
    0.05,           //qian -> kg
    0.05,           //liang -> kg
    0.6,            //jin (taiwan) -> kg
};

const double areaConst[18] = {
    1e6,            //km² -> m²
    1,              //m²  -> m²
    0.01,           //dm² -> m²
    0.0001,         //cm² -> m²
    1e-6,           //mm² -> m²
    1e-12,          //μm² -> m²
    10000.0,        //hectare -> m²
    100.0,          //are -> m²
    4046.8564224,   //acre -> m²
    2.58998811e6,   //milha² -> m²
    0.83612736,     //jarda² -> m²
    0.09290304,     //pé²    -> m²
    0.00064516,     //polegada² -> m²
    25.2928,        //vara² -> m²
    66667.0,        //qing  -> m²
    666.67,         //mu    -> m²
    0.111111,       //chi²  -> m²
    0.0111111,      //cun²  -> m²
};

const double tempoConst[9] = {
    31536000.0,     //Ano -> s
    604800.0,       //Semana -> s
    86400.0,        //Dia -> s
    3600.0,         //Hora -> s
    60.0,           //Minuto -> s
    1,              //Segundo -> s
    0.001,          //Milissegundo -> s
    1e-6,           //Microsegundo -> s
    1e-12,          //Picosegundo  -> s
};

const double dadosConst[12] = {
    1,      //Byte -> B
    1024.0,     //Kilobyte -> B
    1048576.0,      //Megabyte -> B
    1073741824.0,       //Gigabyte -> B
    1.099511627776e12,      //Terabyte -> B
    1.125899906842624e15,       //Petabyte -> B
    0.125,      //Bit -> B
    128.0,      //Kilobit -> B
    131072.0,       //Megabit -> B
    1.34217728e8,       //Gigabit -> B
    1.37438953472e11,       //Terabit -> B
    1.40737488355328e14        //Petabit -> B
};

const double volumeConst[13] = {
    1000.0,         //m³  -> L
    1,              //dm³ -> L
    0.001,          //cm³ -> L
    1e-6,           //mm³ -> L
    1,              //L   -> L
    100.0,          //hectolitro -> L
    0.1,            //dl -> L
    0.01,           //cl -> L
    0.001,          //ml -> L
    28.316846592,   //pé³ -> L
    0.016387064,    //polegada³ -> L
    764.554857984,      //jarda³ -> L
    1233481.83754752,   //acre-pé -> L

};

const double velocidadeConst[9] = {
    299792458.0,        //velocidade da luz -> m/s
    343.0,              //mach -> m/s
    1,                  //m/s  -> m/s
    1000.0,             //km/s -> m/s
    0.27777777778,      //km/h -> m/s
    0.514444,           //nó   -> m/s
    0.44704,            //mph  -> m/s
    0.0254,             //polegadas por segundo -> m/s
    0.3048,             //pés por ssegundo -> m/s
};

const char distancia[26][20] = {
    "Quilometro",               "Metro",
    "Decimetro",                "Centimetro",
    "Milimetro",                "Micrometro",
    "Nanometro",                "Picometro",
    "Milha",                    "Milha Nautica",
    "Furlong",                  "Fathom",
    "Jarda",                    "Pes",
    "Polegadas",                "Li",
    "Zhang",                    "Chi",
    "Cun",                      "Fen",
    "Lii",                      "Hao",
    "Parsec",                   "Distancia Lunar",
    "Unidade Astronomica",      "Ano Luz"
};

const char massa[21][25] = {
    "Tonelada",                 "Quilograma",               
    "Grama",                    "Miligrama",                
    "Micrograma",               "Quintal",                  
    "Libra",                    "Onca",                     
    "Quilate",                  "Grao",                     
    "Tonelada Britanica",       "Tonelada Norte-Americana",
    "Quintal Britanico",        "Quintal Norte-Americano",
    "Pedra",                    "Dram",
    "Dan",                      "Jin",
    "Qian",                     "Liang",
    "Jin (Taiwanes)"
};

const char area[18][20] = {
    "Quilometro Quadrado",      "Metro Quadrado",
    "Decimetro Quadrado",       "Centimetro Quadrado",
    "Milimetro Quadrado",       "Micrometro Quadrado",
    "Hectare",                  "Are",
    "Acre",                     "Milha Quadrada",
    "Jarda Quadrada",           "Pe Quadrado",
    "Polegada Quadrada",        "Vara Quadrada",
    "Qing",                     "Mu",
    "Chi Quadrado",             "Cun Quadrado"
};

const char tempo[9][13] = {
    "Anos",                      "Semanas",
    "Dias",                      "Horas",
    "Minutos",                   "Segundos",
    "Milissegundos",             "Microsegundos",
    "Picosegundos"
};

const char volume[13][20] = {
    "Metro Cubico",             "Decimetro Cubico",
    "Centimetro Cubico",        "Milimetro Cubico",
    "Litro",                    "Hectolitro",
    "Decilitro",                "Centilitro",
    "Mililitro",                "Pe Cubico",
    "Polegada Cubica",          "Jarda Cubica",
    "Acre-pe"
};

const char velocidade[9][24] = {
    "Velocidade da Luz",        "Mach",
    "Metros por Segundo",       "Quilometros por Segundo",
    "Quilometros por Hora",     "No",
    "Milhas por Hora",          "Polegadas por Segundo",
    "Pes por Segundo"
};

const char dados[12][9] = {
    "Byte",                     "Kilobyte",
    "Megabyte",                 "Gigabyte",
    "Terabyte",                 "Petabyte",
    "Bit",                      "Kilobit",
    "Megabit",                  "Gigabit",
    "Terabit",                  "Petabit"
};

const char temperatura[3][10] = {
    "Celsius",                  "Farenheit",
    "Kelvin"
};

const char sistemaNumerico[4][12] = {
    "Binario",                  "Octal",
    "Decimal",                  "Hexadecimal"
};

int uO, uD;                     //uO = unidadeOrigem / uD = unidadeDestino
float valorO, valorD, valorM;   //valorO = valorOrigem / valorD = valorDestino
                                //valorM = valorMedio
                                //ctrl+h para pesquisar e substituir se quiser
                                //para facilitar a leitura

void selecionar(){
    printf("\nDigite o numero correspondente a unidade de origem:");
    scanf("%d", &uO);
    printf("Digite o numero correspondente a unidade de destino:");
    scanf("%d", &uD);
    printf("Digite o valor a ser convertido:");
    scanf("%f", &valorO);
    uO--;
    uD--;
    printf("\n");
}

void printBinary(int n){
    int startPrinting = 0; // Variável para identificar quando começar a imprimir
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--){
        if((n >> i) & 1) { 
            startPrinting = 1; // Começa a imprimir a partir do primeiro '1' encontrado
        }
        if(startPrinting) {
            printf("%d", (n >> i) & 1);
        }
    }
    if (!startPrinting){ 
        printf("0"); // Para o caso de "n == 0"
    }
    printf("\n");
}

int main() {
    int opcao, continuar, i, continuar2;

    FILE *fptr;
    fptr = fopen("log.txt", "w");


    do{
        do{
            continuar2 = 0;

            printf("Digite o numero correspondente a operacao desejada:\n\n");
            printf("1-Distancia         6-Volume\n");
            printf("2-Massa             7-Velocidade\n");
            printf("3-Area              8-Temperatura\n");
            printf("4-Tempo             9-Sistema Numerico\n");
            printf("5-Dados\n");
            printf("\nDigite sua opcao (0 para sair): ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:     //Distância
                    clrscr();
                    printf("Digite o numero correspondente a unidade de origem:\n\n");
                    for(i=0; i<26; i++){
                        printf("%d-%s\n", i+1, distancia[i]);
                    }
                    selecionar();
                    valorM = valorO * distanciaConst[uO];
                    valorD = valorM / distanciaConst[uD];
                    printf("%.16g %s correspondem a %.16g %s.", valorO, distancia[uO], valorD, distancia[uD]);
                    fprintf(fptr, "%.16g %s correspondem a %.16g %s.\n", valorO, distancia[uO], valorD, distancia[uD]);
                    break;
                case 2:     //Massa
                    clrscr();
                    printf("Digite o numero correspondente a unidade de origem:\n\n");
                    for(i=0; i<21; i++){
                        printf("%d-%s\n", i+1, massa[i]);
                    }
                    selecionar();
                    valorM = valorO * massaConst[uO];
                    valorD = valorM / massaConst[uD];

                    printf("%.16g %s correspondem a %.16g %s.", valorO, massa[uO], valorD, massa[uD]);
                    fprintf(fptr, "%.16g %s correspondem a %.16g %s.\n", valorO, massa[uO], valorD, massa[uD]);
                    break;
                case 3:     //Área
                    clrscr();
                    printf("Digite o numero correspondente a unidade de origem:\n\n");
                    for(i=0; i<18; i++){
                        printf("%d-%s\n", i+1, area[i]);
                    }
                    selecionar();
                    valorM = valorO * areaConst[uO];
                    valorD = valorM / areaConst[uD];
                    printf("%.16g %s correspondem a %.16g %s.", valorO, area[uO], valorD, area[uD]);
                    fprintf(fptr, "%.16g %s correspondem a %.16g %s.\n", valorO, area[uO], valorD, area[uD]);
                    break;
                case 4:     //Tempo
                    clrscr();
                    printf("Digite o numero correspondente a unidade de origem:\n\n");
                    for(i=0; i<9; i++){
                        printf("%d-%s\n", i+1, tempo[i]);
                    }
                    selecionar();
                    valorM = valorO * tempoConst[uO];
                    valorD = valorM / tempoConst[uD];
                    printf("%.16g %s correspondem a %.16g %s.", valorO, tempo[uO], valorD, tempo[uD]);
                    fprintf(fptr, "%.16g %s correspondem a %.16g %s.\n", valorO, tempo[uO], valorD, tempo[uD]);
                    break;
                case 5:     //Dados
                    clrscr();
                    printf("Digite o numero correspondente a unidade de origem:\n\n");
                    for(i=0; i<12; i++){
                        printf("%d-%s\n", i+1, dados[i]);
                    }
                    selecionar();
                    valorM = valorO * dadosConst[uO];
                    valorD = valorM / dadosConst[uD];
                    printf("%.16g %s correspondem a %.16g %s.", valorO, dados[uO], valorD, dados[uD]);
                    fprintf(fptr, "%.16g %s correspondem a %.16g %s.\n", valorO, dados[uO], valorD, dados[uD]);
                    break;
                case 6:     //Volume
                    clrscr();
                    printf("Digite o numero correspondente a unidade de origem:\n\n");
                    for(i=0; i<9; i++){
                        printf("%d-%s\n", i+1, volume[i]);
                    }
                    selecionar();
                    valorM = valorO * volumeConst[uO];
                    valorD = valorM / volumeConst[uD];
                    printf("%.16g %s correspondem a %.16g %s.", valorO, volume[uO], valorD, volume[uD]);
                    fprintf(fptr, "%.16g %s correspondem a %.16g %s.\n", valorO, volume[uO], valorD, volume[uD]);
                    break;
                case 7:     //Velocidade
                    clrscr();
                    printf("Digite o numero correspondente a unidade de origem:\n\n");
                    for(i=0; i<9; i++){
                        printf("%d-%s\n", i+1, velocidade[i]);
                    }
                    selecionar();
                    valorM = valorO * velocidadeConst[uO];
                    valorD = valorM / velocidadeConst[uD];
                    printf("%.16g %s correspondem a %.16g %s.", valorO, velocidade[uO], valorD, velocidade[uD]);
                    fprintf(fptr, "%.16g %s correspondem a %.16g %s.\n", valorO, velocidade[uO], valorD, velocidade[uD]);
                    break;
                case 8:     //Temperatura
                    clrscr();
                    printf("Digite o numero correspondente a unidade de origem:\n\n");
                    for(i=0; i<3; i++){
                        printf("%d-%s\n", i+1, temperatura[i]);
                    }
                    selecionar();
                    if (uO == 0){   //De Celsius
                        if (uD == 0) valorD = valorO;   //Para Celsius
                        if (uD == 1) valorD = (valorO * 1.8) + 32;  //Para Farenheit
                        if (uD == 2) valorD = valorO + 273.15;  //Para Kelvin
                    }else if (uO == 1){ //De Farenheit
                        if (uD == 0) valorD = (valorO - 32) / 1.8;  //Para Celsius
                        if (uD == 1) valorD = valorO;   //Para Farenheit
                        if (uD == 2) valorD = (valorO - 32) / 1.8 + 273.15; //Para Kelvin
                    }else if (uO == 2){ //De Kelvin
                        if (uD == 0) valorD = valorO - 273.15;  //Para Celsius
                        if (uD == 1) valorD = (valorO - 273.15) * 1.8 + 32; //Para Farenheit
                        if (uD == 2) valorD = valorO;   //Para Kelvin
                    }
                    printf("%.16g %s e igual a %.16g %s", valorO, temperatura[uO], valorD, temperatura[uD]);
                    fprintf(fptr, "%.16g %s e igual a %.16g %s.\n", valorO, temperatura[uO], valorD, temperatura[uD]);
                    break;
                case 9:     //Sistema Numérico
                    clrscr();
                    printf("Digite o numero correspondente a base para a qual quer converter:\n\n");
                    for (i = 0; i < 4; i++) {
                        printf("%d-%s\n", i + 1, sistemaNumerico[i]);
                    }
                    printf("\nEscolha a base:\n");
                    scanf("%d", &uO);
                    printf("\nDigite o numero, inteiro e em base decimal, a ser convertido: ");
                    scanf("%d", &uD);   //Usando uD porque é inteiro, com valorO não funciona.
                    switch (uO - 1) {
                        case 0: // Binário
                            printf("\n%d em base 2 e ", uD);
                            printBinary(uD);
                            break;
                        case 1: // Octal
                            printf("\n%d em base 8 e %o", uD, uD);
                            fprintf(fptr, "\n%d em base 8 e %o", uD, uD);
                            break;
                        case 2: // Decimal
                            printf("\n%d em base 10 e %d", uD, uD);
                            fprintf(fptr, "\n%d em base 10 e %d", uD, uD);
                            break;
                        case 3: // Hexadecimal
                            printf("\n%d em base 16 e %X", uD, uD);
                            fprintf(fptr, "\n%d em base 16 e %X", uD, uD);
                            break;
                        default:
                            printf("ERRO %d", uD);
                    }
                    printf("\n");
                    break;
                case 0:
                    return 0;
                    break;
                default:
                    clrscr();
                    printf("------------Entrada invalida------------\n");
                    continuar2 = 1;
                    break;
            }
        }while(continuar2 == 1);

        printf("\nDeseja fazer uma nova conversao? 1-sim     0-nao\n>");
        scanf("%d", &continuar);
        clrscr();
    }while(continuar);

    fclose(fptr);

    return 0;
}


