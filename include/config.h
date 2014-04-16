
/***************************************************/
/*** boot constants                              ***/
#define DEF_INITSEG     0x9000
#define DEF_SETUPSEG    0x9020
#define DEF_SYSSEG      0x1000
#define DEF_SYSSIZE     0x7F00

#define ASK_VGA         0xfffd

/***************************************************/
/*** system constants                            ***/
#define KERNEL_CS	0x10
#define KERNEL_DS	0x18
#define __KERNEL_CS	0x10
#define __KERNEL_DS	0x18

/***************************************************/
/*** others                                      ***/
#define SYMBOL_NAME(x) x
