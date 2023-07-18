

MEMORY{
	
	flash(RX) : ORIGIN = 0x08000000 , LENGTH = 128k
	SRAM(RWX) : ORIGIN = 0x20000000 , LENGTH = 20k
}


SECTIONS{
	
   .text : {

     *(.vector*)
     *(.text*)
     _E_text = . ;

   } > flash

   .data : {

      _S_data = . ;
     *(.data)
     _E_data = . ;
    

   }> SRAM AT> flash

   .bss : {

      . = ALIGN(4) ;
     _S_bss = . ;
    *(.bss)
     _E_bss = . ;
      . = ALIGN(4) ;
      . = . + 0x1000 ;
      stacktop = . ;
   } > SRAM
 

}