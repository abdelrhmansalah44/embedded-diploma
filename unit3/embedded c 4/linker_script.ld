

MEMORY{
	
	flash(RX) : ORIGIN = 0x00000000 , LENGTH = 512M
	SRAM(RWX) : ORIGIN = 0x20000000 , LENGTH = 512M
}


SECTIONS{
	
   .text : {

     *(.vector*)
     *(.text*)
     _E_TEXT = . ;

   } > flash

   .data : {

     _S_DATA = . ;
     *(.data)
     _E_DATA = . ;
    

   }> SRAM AT> flash

   .bss : {

      . = ALIGN(4) ;
     _S_BSS = . ;
    *(.bss)
    _E_BSS = . ;
     
   } > SRAM
 

}