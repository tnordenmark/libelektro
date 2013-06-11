// Programmerare: Jakob Källner, jaka0039

float calc_resistans(int count, char conn, float *array)
{

float returnvalue;
int i;

//Om conn är s eller S
if (conn == 's' | conn == 'S')
	{
		//Nollställ returvärdes-variablen
		returnvalue = 0;

		//Lägg samman den totala resistansen i en seriekopplad krets (R1 + R2 = R-tot)
		for (i = 0; i < count; i++)
			{
				returnvalue = returnvalue + array[i];
			}
	}

//Om conn är p eller P
else if (conn == 'p' | conn == 'P')
	{
		//Nollställ returvärdes-variablen
		returnvalue = 0;

		//Beräkna för varje motstånd 1 dividerat på resistansen och lägg samman dem (1/R1 + 1/R2 = 1/R-tot).
		for (i = 0; i < count; i++)
			{
				returnvalue = returnvalue + (1 / array[i]);
			}
		
		//Beräkna den totala ersättnings-resistansen (1/R-tot)
		returnvalue = 1 / returnvalue;
	}

//Om conn inte är s, S, p eller P returnera -1 för att markera att något är fel 
else
	{
		return -1;
	}

return returnvalue;
}
