#include <stdio.h>
#include <locale.h>

int numeroLinhas = 0;
int numeroColunas = 0;

//Função que imprime a matriz
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

//Função principal
int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i = 0;
	int j = 0;
	int k = 0;
	float pivo = 0;
	float pivo2 = 0;
	
	printf("Informe o número de linhas: ");
	scanf(" %d", &numeroLinhas);
	
	printf("Informe o número de colunas: ");
	scanf(" %d", &numeroColunas);
	
	numeroColunas +=1;

	//Definindo a matriz
	float matriz[numeroLinhas][numeroColunas];
	
	//Laços para inserir valores na matriz
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
	
	//Funcao para imprimir a matriz
	imprimeMatriz(matriz);
	
	system("pause");
	
	//Lacos para zera os valores abaixo da diagonal principal
	//K serve para definir o pivo
	for(k = 0; k < numeroLinhas; k++){

		//i serve para percorrer as linhas 
		for(i = k+1; i < numeroLinhas; i++){
			pivo = matriz[k][k];
			pivo2 = matriz[i][k];
		
			//j serve para percorrer as colunas
			for(j = 0; j < numeroColunas; j++){
	
				matriz[i][j] = ((pivo * matriz[i][j]) - (pivo2 * matriz[k][j]));
	
			}	
		}
	}
	
	imprimeMatriz(matriz);	
	system("pause");
	
	//Laço para tornar os valores da diagonal principal um
	//i para percorrer as linhas
	for(i = 0; i < numeroLinhas; i++){
		pivo = matriz[i][i];
		
		//j para percorrer as colunas
		for(j = 0; j < numeroColunas; j++){
			matriz[i][j] = matriz[i][j]/pivo;
		}
	}
		
	imprimeMatriz(matriz);

	//Laco para zerar diagonal superior
	//K serve para definir o pivor	
	for(k = numeroColunas - 2; k > 0; k--){

		//i para percorrer as linhas
		for(i = k-1; i >= 0; i--){
			pivo = matriz[k][k];
			pivo2 = matriz[i][k];
		
			//j para percorrer as colunas 
			for(j = numeroColunas - 1; j >= 0; j--){
	
				matriz[i][j] = ((pivo * matriz[i][j]) - (pivo2 * matriz[k][j]));
	
			}	
		}
	}
	system("pause");
	imprimeMatriz(matriz);
	
	return 0;
}
