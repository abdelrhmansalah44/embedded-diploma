 
.section .vector

.word 0x20000000
.word _reset
.word vectorhandler  /* 2 NMI */
.word vectorhandler  /* 3 Hard fault */
.word vectorhandler  /* 4 MM fault */
.word vectorhandler  /* 5 bus fault */
.word vectorhandler  /* 6 usage fault */
.word vectorhandler  /* 7 reserved */
.word vectorhandler  /* 8 reserved */
.word vectorhandler  /* 9 reserved */
.word vectorhandler  /* 10 reserved */
.word vectorhandler  /* 11 sv call */
.word vectorhandler  /* 12 debug resurved */
.word vectorhandler  /* 13 reserved */
.word vectorhandler  /* 14 pendsv */
.word vectorhandler  /* 15 systick */
.word vectorhandler  /* 16 IRQ0 */ 
.word vectorhandler  /* 17 IRQ1 */
.word vectorhandler  /* 18 IRQ2 */
.word vectorhandler  /* 19 .... */

.section .text

_reset : 
bl main
b .

.thumb_func

vectorhandler:
b _reset