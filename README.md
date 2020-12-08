#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double sin(double Gleitkommazahl)
{
    double sign = 1;
    
    if (Gleitkommazahl<0)
    {
        sign = -1.0;
        Gleitkommazahl=-Gleitkommazahl;
    }

    if(Gleitkommazahl > 360) 
        Gleitkommazahl -= (Gleitkommazahl / 360) * 360;
        Gleitkommazahl *= M_PI / 180.0;
        double res = 0;
        double term = Gleitkommazahl;
        int k = 1;
        
        while(res + term != res)
        {
            res += term;
            k += 2;
            term *= -Gleitkommazahl*Gleitkommazahl/k/(k-1);
        }
        return sign*res;
}


int main(void)
{
    double Size, Ergebnis = 0;

    printf("Geben Sie eine ganze Zahl ein: ");

    if(scanf("%lf", &Size) == false)
    {
        printf("\nFalsche Eingabe.\nProgramm wird beendet.\n");
        return 1;
    }
    
    int Size1 = (int) Size;

    if(Size / Size1  != 1)
    {
        printf("Falsche Eingabe.\nProgramm wird beendet.\n");
        return 1;
    }
        
    for(double i = 1.0; i <= Size; i++)
    {
        double Gleitkommazahl;
        printf("\nGleitkommazahl %.0lf.  ", i);
        if(scanf("%lf", &Gleitkommazahl) == false)
        {
            printf("Falsche Eingabe.\nProgramm wird beendet.\n");
            return 1;
        }
        else
            Ergebnis += sin(2 * M_PI * Gleitkommazahl);
    }

    printf("\nlalala = %.7lf", Ergebnis);



    return 0;
}
