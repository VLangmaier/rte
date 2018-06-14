
/******************************************************************************
*
*   FILE
*   ----
*   library_open.c
*
*   History
*   -------
*   2018-06-14   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/

#ifndef OV_COMPILE_LIBRARY_opcua
#define OV_COMPILE_LIBRARY_opcua
#endif

#include "opcua.h"
#ifdef ov_library_open_opcua
#undef ov_library_open_opcua
#endif

/*
* This function will be called, when the library is loaded.
* It could generate components and initializes the startup procedure
*/
OV_RESULT ov_library_setglobalvars_opcua_new(void) {
	OV_RESULT result;
	/*
	 *    set the global variables of the original version
	 *    and if successful, load other libraries
	 *    and create some objects
	 */
	result = ov_library_setglobalvars_opcua();
	return result;
}
/*
*       Replace the 'setglobalvars' function of a library with this
*       previous one, which additionally creates instances.
* 	This is called by the OV system upon library load.
*/
OV_DLLFNCEXPORT OV_LIBRARY_DEF *ov_library_open_opcua(void) {
	/* local variables */
	static OV_LIBRARY_DEF *OV_LIBRARY_DEF_opcua_new;
	/*
	*       replace the 'setglobalvars' function created by the code generator
	*       with a new one.
	*/
	OV_LIBRARY_DEF_opcua_new = ov_library_open_opcua_old();
	OV_LIBRARY_DEF_opcua_new->setglobalvarsfnc = ov_library_setglobalvars_opcua_new;
	return OV_LIBRARY_DEF_opcua_new;
}
