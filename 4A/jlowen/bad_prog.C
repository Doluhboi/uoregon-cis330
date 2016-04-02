// This program is from: Jacob Lowen
// The author believes it has 1 memory errors
#include <stdio.h>
#include <stdlib.h>

class Miasma{

	public:
		int density;
		int getDensity()
		{
			return density;
		};
		Miasma()
		{
			density = 1;
			printf("A toxic cloud appears. \n");
		};
		~Miasma()
		{
			printf("The miasma has cleared! \n");
		};
		void intensify()
		{
			density++;
			printf("The cloud has thickened, concentration is now at %d! \n", density);
		}; 

};
int main()
{
	int stage;
	int hp = 100;
	printf("Hp is at %d.\n", hp);
	int waves = 10;
	Miasma FogOfDeath = *(new Miasma());
	for(stage =0; stage<waves;stage++)
	{
		FogOfDeath.intensify();
		if(FogOfDeath.getDensity() == 7)
		{
			printf("The fog's density has reached near catastrophic levels. \n"); 
		}
		if(FogOfDeath.getDensity() == 10)
		{
			printf("Warning! Fog density has reached catastrophic levels! \n ");
			printf("Vacate the area immediately. \n");
		}
		hp = hp - FogOfDeath.density;
		delete &FogOfDeath;
	}
	printf("Hp is at %d.\n", hp);
}
