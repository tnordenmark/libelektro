#include <math.h> //log10
#include <stdio.h>
#include <stdlib.h>

float getE12Resistor(float resistance)
{
		int i;
	// Tabell för E12 serien
        float E12table[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2}; 
        int numzero = 0;
        float countdown = 0;

	// Få ut antal nollor som resistance innehåller.
        numzero = log10(resistance);

	// Räkna ner i tabellen tills countdown når 0.999 eller över.
        for(i = 11; countdown < 0.999; i--)
		{
				countdown = resistance / ((pow(10, numzero) * E12table[i]));
        }

	// Använd i+1 som vi fick ovan för att få ut rätt resistor
        return (E12table[(i+1)] * pow(10, numzero));
}

int e_resistance(float orig_resistance, float *res_array )
{
        int count = 0;
        float ResistanceLeft = 0;
        ResistanceLeft = orig_resistance;
		// Medans ersättningsresistancen är över 1 och count (komponenter) är under 3
        while(ResistanceLeft >= 1.0 && count < 3)
        {
				// Lägg till resultatet i arrayen res_array på positionen count
                *(res_array + count) = getE12Resistor(ResistanceLeft);
				// Subtrahera ResistanceLeft med resultatet
                ResistanceLeft -= *(res_array + count);
                count++;
        }

        return count;
}
