#include<stdio.h>
#include<string.h>
void encryptcaesercypher(char message[],int key)
{
	int i;
	for(i=0;message[i]!=0;i++)
	{
	 char character=message[i];
	 if(character>='a' && character<='z')
	 {
	 character='a'+(character -'a'+key)%26;	
	 }
	 else if(character>='A' && character<='Z'){
	 	character='A'+(character-'A' +key)%26;
	 }
	 message[i]=character;
    }
}
void decryptcaesercypher(char message[],int key)
{
	encryptcaesercypher(message,26-key);
}

int main(){
	char message[100];
	int key;
	printf("enter a message:");
	gets(message);
	printf("enter the key(shift):");
	scanf("%d",key);
	encryptcaesercypher(message,key);
	printf("Decrypted message: %s\n",message);
	return 0;
}

