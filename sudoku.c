#include <stdio.h>

int verifica(int sudoku[][9], int l, int c, int n)
{
    int li = (l/3) * 3;
    int co = (c/3) * 3;
    int i, j;
    //verifica se valor da matriz corresponde ao numero que vai de um a nove
    for(i=0; i<9; ++i)
    {
        if (sudoku[l][i] == n)
            return 0;
        if (sudoku[i][c] == n)
            return 0;
        if (sudoku[li + (i%3)][co + (i/3)] == n)
            return 0;
    }
    return 1;
}

//Procurar resolucao para o sudoku apresentado
int resolve(int sudoku[][9], int l, int c)
{
    int i;
    if(l<9 && c<9)
    {
        //checa se posicao se encontra vazia
        if(sudoku[l][c] != 0)
        {
            if((c+1)<9)
                return resolve(sudoku, l, c+1);//retorno da funcao
            else
                if((l+1)<9)
                    return resolve(sudoku, l+1, 0);//retorno da funcao
            else
                return 1;
        }
        //Se posicao nao estiver vazio
        else
        {
            for(i=0; i<9; ++i)
            {
                //verifica com chamada da funcao o valor
                if(verifica(sudoku, l, c, i+1))
                {
                    sudoku[l][c] = i+1;
                    if((c+1)<9)
                    {
                        if(resolve(sudoku, l, c +1))
                            return 1;
                        else
                            sudoku[l][c] = 0;
                    }
                    else
                        if((l+1)<9)
                        {
                            if(resolve(sudoku, l+1, 0))
                                return 1;
                            else
                                sudoku[l][c] = 0;
                        }
                        else
                            return 1;
                }
            }
        }
        return 0;
    }
    else
        return 1;
}

int main()
{
    int i, j,sudoku[9][9];
    printf("\nForneca os valores em ordem linha . 0- Vazio\n\n");
    //Preenchimento do sudoku [ 0 para espaços vazios]
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d",&sudoku[i][j]);
        }
    }
    //Mostrar sudoku infomado
    printf("\n\nSudoku infomado:\n\n");
    for(i=0;i<9;i++){
            printf("| ");
        for(j=0;j<9;j++){
            printf(" %d ",sudoku[i][j]);
        }
        printf(" |");
        printf("\n");
    }
    //caso haja resolucao para o sudoku apresenta - o
    if(resolve(sudoku, 0, 0))
    {
        printf("\n-----------------------\n");
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j)
            {
                printf("|%d", sudoku[i-1][j-1]);
            }
            printf("|\n");
            if (i%3 == 0)
                printf("-----------------------\n");
        }
    }
    //Mensagem para caso em que nao haja resolucao
    else
        printf("\n\nO Sudoku parcialmente preenchido nao possui solucao!\n\n");

    return 0;
}
