#include "isogram.h"

bool is_isogram(const char phrase[]) {
	int count[26] = { 0 };

	for(unsigned int s_idx=0; s_idx < strlen(phrase); s_idx++) {
		unsigned char s = phrase[ s_idx ];

		if( ! isalpha(s) )
			continue;

		s = tolower(s);

		int idx = s - 'a';

		count[ idx ] += 1;

		if( count[ idx ] > 1 )
			return false;
	}

	return true;
}