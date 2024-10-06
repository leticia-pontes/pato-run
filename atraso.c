
void atraso_ms(unsigned int valor)
{
unsigned int  i;
unsigned char j;

 for (i =0; i< (valor); i++)
 {
 
  for (j =0 ; j < 200; j++)
   {
     #asm
	NOP
	NOP
	NOP
	NOP
	NOP
    #endasm
   }
 }
}
