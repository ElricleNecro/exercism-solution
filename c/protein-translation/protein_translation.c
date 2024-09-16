#include "protein_translation.h"

#include <stdio.h>
#include <string.h>

proteins_t proteins(const char *const rna) {
	proteins_t seq = {.valid=true, .count=0, .proteins={0}};

	for(size_t idx=0; idx < strlen(rna); idx += 3) {
		protein_t kind = Tryptophan;
		if( strncmp(&rna[idx], "AUG", 3) == 0 ) {
			kind = Methionine;
		} else if( strncmp(&rna[idx], "UUU", 3) == 0 || strncmp(&rna[idx], "UUC", 3) == 0 ) {
			kind = Phenylalanine;
		} else if( strncmp(&rna[idx], "UUA", 3) == 0 || strncmp(&rna[idx], "UUG", 3) == 0 ) {
			kind = Leucine;
		} else if( strncmp(&rna[idx], "UCU", 3) == 0 || strncmp(&rna[idx], "UCC", 3) == 0 || strncmp(&rna[idx], "UCA", 3) == 0   || strncmp(&rna[idx], "UCG", 3) == 0 ) {
			kind = Serine;
		} else if( strncmp(&rna[idx], "UAU", 3) == 0 || strncmp(&rna[idx], "UAC", 3) == 0 ) {
			kind = Tyrosine;
		} else if( strncmp(&rna[idx], "UGU", 3) == 0 || strncmp(&rna[idx], "UGC", 3) == 0 ) {
			kind = Cysteine;
		} else if( strncmp(&rna[idx], "UGG", 3) == 0 ) {
			kind = Tryptophan;
		} else if( strncmp(&rna[idx], "UAA", 3) == 0 || strncmp(&rna[idx], "UAG", 3) == 0 || strncmp(&rna[idx], "UGA", 3) == 0   || strncmp(&rna[idx], "UCG", 3) == 0 ) {
			break;
		} else {
			return (proteins_t){.valid=false, .count=0, .proteins={0}};
		}

		seq.proteins[seq.count++] = kind;
	}

	return seq;
}
