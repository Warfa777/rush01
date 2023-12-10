#include <unistd.h>

int main(int ac, char *av[])
{
    if(ac != 2)
    {
        return 1;
    }
    
// column row variables
    
    char ColU1, ColU2, ColU3, ColU4;
    char ColD1, ColD2, ColD3, ColD4;
    char RowL1, RowL2, RowL3, RowL4;
    char RowR1, RowR2, RowR3, RowR4;

// values in the square

    int A1 = 1, A2 = 1, A3 = 1, A4 = 1;
    int B1 = 1, B2 = 1, B3 = 1, B4 = 1;
    int C1 = 1, C2 = 1, C3 = 1, C4 = 1;
    int D1 = 1, D2 = 1, D3 = 1, D4 = 1;
    

// square array
    
    char *square_index = av[1];
    
    ColU1 = square_index[0];
    ColU2 = square_index[2];
    ColU3 = square_index[4];
    ColU4 = square_index[6];
    ColD1 = square_index[8];
    ColD2 = square_index[10];
    ColD3 = square_index[12];
    ColD4 = square_index[14];
    RowL1 = square_index[16];
    RowL2 = square_index[18];
    RowL3 = square_index[20];
    RowL4 = square_index[22];
    RowR1 = square_index[24];
    RowR2 = square_index[26];
    RowR3 = square_index[28];
    RowR4 = square_index[30];
    
    //assegnazione valori
    A3 = A4 + 1;
    A2 = A3 + 1;
    A1 = A2 + 1;
    
    B3 = B4 + 1;
    B2 = B3 + 1;
    B1 = B2 + 1;
    
    C3 = C4 + 1;
    C2 = C3 + 1;
    C1 = C2 + 1;
    
    D3 = D4 + 1;
    D2 = D3 + 1;
    D1 = D2 + 1;

    // 4 and 1 rule condition
    
    //if      ((ColU1 == '4')||(RowL1 == '4')) A1 += 1;
    //else if ((ColU4 == '4')||(RowR1 == '4')) A4 += 1;
    //else if ((ColD1 == '4')||(RowL4 == '4')) D1 += 1;
    //else if ((ColD4 == '4')||(RowR4 == '4')) D4 += 1;
    
    //if      ((ColU1 == '1')||(RowL1 == '1')) A1 += 4;
    //else if ((ColU4 == '1')||(RowR1 == '1')) A4 += 4;
    //else if ((ColD1 == '1')||(RowL4 == '1')) D1 += 4;
    //else if ((ColD4 == '1')||(RowR4 == '1')) D4 += 4;
    
    
// FARE TUTTE FUNZIONI PRIMA DI MATRICE QUADRA
    int square_matrix[4][4] = {
         {A1, A2, A3, A4},
         {B1, B2, B3, B4},
         {C1, C2, C3, C4},
         {D1, D2, D3, D4}
     };
    
// ANCORA DA TESTTARE
    int c = 0;
    while (c < 4) {
        int r = 0;
        while (r < 3) {
            int current = square_matrix[c][r];
            int next = square_matrix[c][r + 1];

            if (current == next) {
                square_matrix[c][r] = next;
                square_matrix[c][r + 1] = current;
            }

            ++r;
        }

        ++c;
    }
    
// square array print
    int i = 0;
    int j = 0;
	int k = 0;
    
    while (i <= 3)
        {
            j = 0;
			k = 0;
            while(j <= 3)
            {
                char digit = square_matrix[i][j] + '0';
                write(1, &digit, 1);
                char sp;
				if (k < 3)
				{
					sp = ' ';
                	write(1, &sp, 1);
				}
				k++;
                j++;
            }
            i++;
            char c;
            c = '\n';
            write(1, &c, 1);
        }
    return 0;
}
