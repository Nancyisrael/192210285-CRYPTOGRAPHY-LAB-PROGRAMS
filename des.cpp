#include<stdio.h>
#include<stdint.h>
void initialpermutation(unit64_t *data){
	// implement initial permutation here
}
void finalpermutation(unit64 *data){
	// implement final permutation here
}
void generatesubkeys(unit64_t *key,unit64_t subkeys[16]){
	// implement key schedule here	
}
void feistelnetwork(unit32_t *left,unit32_t *right,unit64_t subkey){
	// implement feistalnetwork here
}
void desencryption(unit64_t plaintrxt,unit_64 key,unit_64 *ciphertext)
{
	unit_64 subkeys[16];
	generatesubkeys(&key,subkeys);
	initialpermutation(&plaintext);
	unit32_t left=(unit32_t)(plaintext>>32);
	unit32_t right=(unit32_t)(plaintext & 0xFFFFFFFF);
	for(int round=0;round<16;round++){
		feistalnetwork(&left,&right,subkeys[round]);
	}
}
*ciphertext=((unit64_t)right<<32)|(unit64_t)left;
finalpermutation(ciphertext);
}
int main(){
	unit64_t plaintext,key,ciphertext;
	printf("enter 64_bit plain text(in hexadecimal): ");
	scanf("llx",&plaintext);
	desencrypt(plaintext,key,&ciphertext);
	printf(plaintext,key,&ciphertext);
	printf("plaintext:0x01611X\n",plaintext);
	printf("ciphertext:0x01611X\n",ciphetext);
	return 0;
}
