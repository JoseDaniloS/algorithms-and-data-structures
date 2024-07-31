#include <stdio.h>// printf, scanf
#include <math.h>// pow, sqrt


//FUNÇÃO QUE CALCULA A AREA E O PERIMETRO DE UM HEXAGONO
void calcula_hexagono(float l, float *area, float *perimetro){

    *area = (3*pow(l,2)*sqrt(3))/2;

    *perimetro = 6*l;

}

//FUNÇÃO PRINCIPAL
int main(void){

    float l, area, perimetro;

    printf("Digite o valor do lado do hexagono: ");
    scanf("%f", &l);

    //PASSANDO O VALOR DO LADO PARA A FUNÇÃO E O ENDEREÇO DAS VARIAVEIS "area","perimetro"
    calcula_hexagono(l, &area, &perimetro);

    //EXIBINDO OS VALORES QUE A FUNÇÃO RETORNOU, ATRAVÉS DOS PONTEIROS.
    printf("Area do Hexagono: %2.f\n", area);
    printf("Perimetro do Hexagono: %2.f\n", perimetro);

    return 0;
}