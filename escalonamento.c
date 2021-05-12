#include <stdio.h>
#include <locale.h>

int numeroLinhas = 0;
int numeroColunas = 0;

void imprimeMatriz(float a[][numeroColunas]){
	
	int i = 0;
	int j = 0;
	
	printf("\n");
	for(i = 0; i < numeroLinhas; i++){
		for(j = 0; j < numeroColunas; j++){
			printf("%f  ", a[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
	
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i = 0;
	int j = 0;
	
	printf("Informe o número de linhas: ");
	scanf(" %d", &numeroLinhas);
	
	printf("Informe o número de colunas: ");
	scanf(" %d", &numeroColunas);
	
	numeroColunas +=1;

	float matriz[numeroLinhas][numeroColunas];
	
	for(i = 0; i < numeroLinhas; i++){
		for(j = 0; j < numeroColunas; j++){
			if(j == (numeroColunas - 1)){
				printf("Informe o valor do termo independente da linha %d, coluna %d: ", i, j);
				scanf(" %f", &matriz[i][j]);
			}else{
				printf("Informe o valor do coeficiente da linha %d, coluna %d: ", i, j);
				scanf(" %f", &matriz[i][j]);
			}
		}
		printf("\n");
	} 
	
	imprimeMatriz(matriz);
	
	system("pause");
	
	float pivo2 = matriz[1][0]; 
	for(i = 1; i < numeroLinhas; i++){
		float pivo = matriz[0][0];
		float pivo2 = matriz[i][0];
		
		for(j = 0; j < numeroColunas; j++){
	
			matriz[i][j] = ((pivo * matriz[i][j]) - (pivo2 * matriz[0][j]));
	
		}
	
	}
	
	
	imprimeMatriz(matriz);
	
	printf("o linhas %d e colunas %d", numeroLinhas, numeroColunas);
	
	return 0;
}
