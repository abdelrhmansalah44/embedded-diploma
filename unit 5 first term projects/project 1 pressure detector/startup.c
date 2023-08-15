/* Eng Abdelrhman salah */
/* startup.c for cortexm3*/


void Reset_Hundler(void);

extern int main(void);

void Default_Hundler()
{
	Reset_Hundler();
}

void NMI_Handler(void)				__attribute__ ((weak, alias("Default_Hundler")));;
void H_Fault_Handler(void)			__attribute__ ((weak, alias("Default_Hundler")));;
void MM_Fault_Handler(void)			__attribute__ ((weak, alias("Default_Hundler")));;
void Bus_Fault(void)				__attribute__ ((weak, alias("Default_Hundler")));;
void Usage_Fault_Handler(void)		__attribute__ ((weak, alias("Default_Hundler")));;


extern unsigned int  _STACK_TOP;

unsigned int vectors[] __attribute__ ((section(".vectors"))) = 
{
	(unsigned int)	&_STACK_TOP,
	(unsigned int)	&Reset_Hundler,
	(unsigned int)	&NMI_Handler,
	(unsigned int)	&H_Fault_Handler,
	(unsigned int)	&MM_Fault_Handler,
	(unsigned int)	&Bus_Fault,
	(unsigned int)	&Usage_Fault_Handler
};

extern unsigned int _E_TEXT ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS ;
extern unsigned int _E_BSS ;


void Reset_Hundler (void)
{
	//copy data from ROM to RAM
	unsigned int DATA_Size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* P_src = (unsigned char*)&_E_TEXT ;
	unsigned char* P_dst = (unsigned char*)&_S_DATA ;
	int i;
	for ( i = 0; i < DATA_Size; ++i)
		{
			*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ; 
		}

	
	unsigned int BSS_Size = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS ;
	P_dst = (unsigned char*)&_S_BSS ;

	for ( i = 0; i < BSS_Size; ++i)
		{
			*((unsigned char*)P_dst++) = (unsigned char)0 ; 
		}

	main();
}