#include <stdio.h>
#include <locale.h>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char operacao[10];
	double numero1, numero2, resultado;
	int choice;

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	printf("+-------------------------------+\n");
	printf("|                               |\n");
	printf("|Bem-vindo à Calculadora Simples|\n");
	printf("|                               |\n");
	printf("+-------------------------------+\n");
	printf("\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);


	while (1) {
        printf("escolha a operação que deseja fazer:\n");
        printf("1. Mais(+)                         \n");
        printf("2. Menos(-)                        \n");
        printf("3. Vezes(*)                        \n");
        printf("4. Dividir(/)                      \n");
        printf("5. Encerrar o programar\n");
        printf("-->  ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf ("\n");
            printf ("Programa encerrado\n");
            printf ("+---------------------------------------------+\n");
            printf ("|        Obrigado por testar o codigo!!       |\n");
            printf ("+---------------------------------------------+\n\n");
            break;
        }

        switch(choice) {
            case 1:
                strcpy(operacao, "+");
                break;
            case 2:
                strcpy(operacao, "-");
                break;
            case 3:
                strcpy(operacao, "*");
                break;
            case 4:
                strcpy(operacao, "/");
                break;
            default:
                printf("Erro: voce escolheu uma opção inválida.\n");
                return 1;
        }

	    // numero 1
	    printf("Digite o primeiro número: ");
	    scanf("%lf", &numero1);

	    // numero 2
	    printf("Digite o segundo número: ");
	    scanf("%lf", &numero2);

	    if (strcmp(operacao, "+") == 0){
		    resultado = numero1 + numero2;
	    }
	    else if (strcmp(operacao, "-") == 0){
		    resultado = numero1 - numero2;
	    }
	    else if (strcmp(operacao, "*") == 0){
		    resultado = numero1 * numero2;
	    }
	    else if (strcmp(operacao, "/") == 0){
		    if (numero2 != 0){
			    resultado = numero1 / numero2;
		    }
		    else{
			    printf("Erro: Divisão por zero não é permitida.\n");
			    return 1;
		    }
	    }
	    else{
		    printf("Erro: voce escreveu uma operação inválida.\n");
		    return 1;
	    }

	    printf("A operação de %.0lf %s %.0lf é igual a %.0lf\n", numero1, operacao, numero2, resultado);
        break;
    }

	return 0;
}
