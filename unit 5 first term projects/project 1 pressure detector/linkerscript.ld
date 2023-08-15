/* Eng:Abdelrhman salah */
/* linker script for cortexm3 */

MEMORY {
	flash(RX) : ORIGIN = 0x08000000 , LENGTH = 128k
	sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 20k

}

SECTIONS{
	 
    .text : {

     *(.vectors*)
     *(.text*)
     _E_TEXT = . ;

    }> flash


    .data : {

    _S_DATA = . ;
    *(.data*)
    . = ALIGN(4);
    _E_DATA = . ;
    
    }> sram AT > flash

    .bss : {
     
     _S_BSS = . ;
     *(.bss*)
     _E_BSS = . ;
     . = ALIGN(4);
     . = . + 0x01000;

     _STACK_TOP = . ;

    }> sram

}