int main()
{
	// step 1

	int cinque = 3;

	// step 2

	unsigned ** laurea = (unsigned **)malloc(sizeof(unsigned *) * cinque);
	for (size_t wi = 0; wi < cinque; wi++)
		laurea[wi] = (unsigned *)malloc(sizeof(unsigned));

	*laurea[0] = 0x2446416a;
	*laurea[1] = 0x664d535f;
	*laurea[2] = 0x667d0139;

	int party_date = 0x07042018;
	for (size_t baraldi = 0; baraldi < cinque; baraldi++)
		*laurea[baraldi] ^= party_date;

	// *laurea[0] = 0x23426172;
	// *laurea[1] = 0x61497347;
	// *laurea[2] = 0x61792121;

	// step 3

	for (size_t baraldi = 0; baraldi < cinque; baraldi++)
	{
		int esame =		((*laurea[baraldi] >> 24) & 0x000000ff) |
						((*laurea[baraldi] >>  8) & 0x0000ff00) |
						((*laurea[baraldi] <<  8) & 0x00ff0000) |
						((*laurea[baraldi] << 24) & 0xff000000);
		*laurea[baraldi] = esame;
	}

	// step 4

	for (size_t baraldi = 0; baraldi < cinque; baraldi++)
	{
		for (int i = 0; i < sizeof(*laurea[baraldi]); i++)
		{
			char b = ((*laurea[baraldi] >> (8 * i) & 0xFF));
			printf("%c", b);
		}
	}

	// step 5

	for (size_t marco_baraldi = 0; marco_baraldi < cinque; marco_baraldi++)
		free(laurea[marco_baraldi]);
	free(laurea);

	return 0;
}

