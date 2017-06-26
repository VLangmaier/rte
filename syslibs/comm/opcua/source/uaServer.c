
/******************************************************************************
*
*   FILE
*   ----
*   ua.c
*
*   History
*   -------
*   2014-10-14   File created
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
#include "libov/ov_macros.h"
#include "libov/ov_vendortree.h"
#include "libov/ov_memstack.h"
#include "libov/ov_result.h"
#include "opcua_helpers.h"
#include "ks_logfile.h"
#include "open62541.h"
#include <errno.h>

#define ADDREFERENCE(NODEID, REFTYPE_NODEID, TARGET_EXPNODEID) do {     \
        UA_AddReferencesItem item;                                      \
        UA_AddReferencesItem_init(&item);                               \
        item.sourceNodeId = NODEID;                                     \
        item.referenceTypeId = REFTYPE_NODEID;                          \
        item.isForward = UA_TRUE;                                       \
        item.targetNodeId = TARGET_EXPNODEID;                           \
        UA_Server_addReference(server, &item);                          \
    } while(0)

//#include "/ua_nodestore_interface.h"

/*	function declaration needed as they are declared with __declspec(dllimport) in the header
 * which means they MUST come from a dll not an .a
*/
void UA_String_deleteMembers(UA_String *p);


OV_INSTPTR_opcua_uaServer opcua_pUaServer = NULL;
static UA_Boolean	UA_ServerRun = FALSE;




static UA_ByteString loadCertificate(void) {
    UA_ByteString certificate = UA_STRING_NULL;
	FILE *fp = NULL;
	OV_STRING tempstring = NULL;
	OV_STRING tempStackString = NULL;

	ov_memstack_lock();
	tempStackString = ov_vendortree_getcmdlineoption_value("UA_CertPath");
	if(tempStackString){
#if OV_SYSTEM_UNIX
		if(!(tempStackString[0]=='/'))
#else
		if(!(tempStackString[1]==':'|| tempStackString[0]=='\\'))
#endif
		{
			ov_string_print(&tempstring, "%s", tempStackString);
		} else {
			/*	relativePath --> prepend confdirpath	*/
#if OV_SYSTEM_UNIX
			ov_string_print(&tempstring, "%s/%s", ov_vendortree_getcmdlineoption_value("CONFDIR"), tempStackString);
#else
			ov_string_print(&tempstring, "%s\\%s", ov_vendortree_getcmdlineoption_value("CONFDIR"), tempStackString);
#endif
		}
	}
	ov_memstack_unlock();
	if(tempstring){
		fp=fopen(tempstring, "rb");
		ov_string_setvalue(&tempstring, NULL);
		if(!fp) {
			errno = 0; // we read errno also from the tcp layer...
			return certificate;
		}

		fseek(fp, 0, SEEK_END);
		certificate.length = ftell(fp);
		certificate.data = UA_malloc(certificate.length*sizeof(UA_Byte));
		if(!certificate.data){
			fclose(fp);
			return certificate;
		}
		fseek(fp, 0, SEEK_SET);
		if(fread(certificate.data, sizeof(UA_Byte), certificate.length, fp) < (size_t)certificate.length){
			UA_ByteString_deleteMembers(&certificate); // error reading the cert
		}
		fclose(fp);
	}
	//OV_PATH p;

    return certificate;
}


static void acpltDeleteNode(UA_Node* node)
{

}

static void opcua_uaServer_initServer(OV_INSTPTR_opcua_uaServer pinst){
	UA_Logger logger;
	//UA_String url;
	OV_STRING tempStackString = NULL;
	UA_Int32 port;
	UA_Int32 ksPort;
	OV_INSTPTR_ov_library	pLibrary	=	NULL;
	OV_INSTPTR_ov_class		pClass		=	NULL;
	OV_INSTPTR_ov_object	pListener	=	NULL;
	OV_INSTPTR_ov_association	pAssoc	=	NULL;
	OV_RESULT		result;
	OV_ELEMENT		parent;
	OV_ELEMENT		child;

	/*	determine port....	*/
	ov_memstack_lock();
	tempStackString = ov_vendortree_getcmdlineoption_value("UA_Port");
	ksPort = ov_vendortree_getport();
	if(!tempStackString){
		port = ksPort;
	} else {
		port = strtol(tempStackString, NULL, 10);
	}
	ov_memstack_unlock();
	if(port == -1){
		//	no port specified in either way --> use OPC-UA standard 16664
		port = 16664;
	}

	if(port != ksPort){
		Ov_ForEachChildEx(ov_instantiation, pclass_ov_library, pLibrary, ov_library){
			if(ov_string_compare(pLibrary->v_identifier, "TCPbind") == OV_STRCMP_EQUAL){
				break;
			}
		}
		if(!pLibrary){
			ov_logfile_error("%s: something went wrong while creating the specific Listener - could not find TCPbind library", pinst->v_identifier);
		}
		pClass = Ov_StaticPtrCast(ov_class, Ov_SearchChild(ov_containment, pLibrary, "TCPListener"));
		if(pClass){
			result = ov_class_createIDedObject(pClass, Ov_PtrUpCast(ov_domain, pinst), "TCPListener", OV_PMH_DEFAULT, NULL, NULL, NULL, &pListener);
			if(Ov_OK(result)){
				parent.elemtype = OV_ET_OBJECT;
				parent.pobj = pListener;
				child.elemtype = OV_ET_NONE;
				result = ov_element_searchpart(&parent, &child, OV_ET_VARIABLE, "port");
				if(Ov_OK(result)){
					*((OV_INT*)child.pvalue) = port;
				} else {
					ov_logfile_error("%s: something went wrong while creating the specific Listener - could not find port variable. reason: %s", pinst->v_identifier, ov_result_getresulttext(result));
				}
				parent.elemtype = OV_ET_OBJECT;
				parent.pobj = pListener;
				child.elemtype = OV_ET_NONE;
				result = ov_element_searchpart(&parent, &child, OV_ET_VARIABLE, "actimode");
				if(Ov_OK(result)){
					*((OV_INT*)child.pvalue) = 1;
				} else {
					ov_logfile_error("%s: something went wrong while creating the specific Listener - could not find actimode variable. reason: %s", pinst->v_identifier, ov_result_getresulttext(result));
				}
				pAssoc = Ov_StaticPtrCast(ov_association, Ov_SearchChild(ov_containment, pLibrary, "AssocSpecificClientHandler"));
				if(pAssoc){
					result = ov_association_link(pAssoc, pListener, Ov_GetFirstChild(ov_instantiation, pclass_opcua_uaIdentificator), OV_PMH_DEFAULT, NULL, OV_PMH_DEFAULT, NULL);
				} else {
					ov_logfile_error("%s: something went wrong while creating the specific Listener - could not find association class");
				}
			} else {
				ov_logfile_error("%s: something went wrong while creating the specific Listener - could not create object. reason: %s", pinst->v_identifier, ov_result_getresulttext(result));
			}
		} else {
			ov_logfile_error("%s: something went wrong while creating the specific Listener - could not find TCPListener class", pinst->v_identifier);
		}
	}

	logger = ov_UAlogger_new();
	pinst->v_serverConfig.logger = logger;
	pinst->v_serverConfig.serverCertificate = loadCertificate();
	pinst->v_networkLayerOv = ServerNetworkLayerOV_new(UA_ConnectionConfig_standard, port);
	pinst->v_serverConfig.networkLayers = &(pinst->v_networkLayerOv);
	pinst->v_serverConfig.networkLayersSize = 1;

	pinst->v_serverData = UA_Server_new(pinst->v_serverConfig);

	UA_String tmpNamespaceName = UA_String_fromChars(OV_UA_NAMESPACEURI);
	UA_Namespace_init(&pinst->v_namespace, &tmpNamespaceName);
	UA_String_deleteMembers(&tmpNamespaceName);

	pinst->v_namespace.nodestore = opcua_nodeStoreFunctions_ovNodeStoreInterface2New();

	if(UA_Server_addNamespace_full(pinst->v_serverData, &(pinst->v_namespace)) != UA_STATUSCODE_GOOD){
		ov_logfile_error("%s - init: could not add ov-namespace to ua server", pinst->v_identifier);
	}
	Ov_SetDynamicVectorLength(&opcua_pUaServer->v_namespaceNames, 1, STRING);
	ov_string_setvalue(&opcua_pUaServer->v_namespaceNames.value[0], OV_UA_NAMESPACEURI);


	/*	add reference to ov root	*/
	OV_STRING tmpString = pdb->root.v_identifier;
	if(UA_Server_addReference(pinst->v_serverData, UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
			UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES), UA_EXPANDEDNODEID_STRING(pinst->v_namespace.index, tmpString), true) != UA_STATUSCODE_GOOD){
		ov_logfile_error("%s - init: could not create reference to ov-namespace", pinst->v_identifier);
	}

	if(UA_Server_addReference(pinst->v_serverData, UA_NODEID_NUMERIC(0, UA_NS0ID_FOLDERTYPE),
				UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE), UA_EXPANDEDNODEID_STRING(pinst->v_namespace.index, "/acplt/ov/domain"), true) != UA_STATUSCODE_GOOD){
			ov_logfile_error("%s - init: could not create reference to ov-namespace library", pinst->v_identifier);
		}
	UA_Server_run_startup(opcua_pUaServer->v_serverData);
	return;
}

static void opcua_uaServer_stopServer(OV_INSTPTR_opcua_uaServer pinst){
	UA_Server_run_shutdown(opcua_pUaServer->v_serverData);
	UA_ByteString_deleteMembers(&pinst->v_serverConfig.serverCertificate);
	pinst->v_networkLayerOv.deleteMembers(&(pinst->v_networkLayerOv));
	UA_Server_delete(pinst->v_serverData);
	UA_Namespace_deleteMembers(&(pinst->v_namespace));
	return;
}

OV_DLLFNCEXPORT OV_BOOL opcua_uaServer_LoginEnableAnonymous_get(
    OV_INSTPTR_opcua_uaServer          pobj
) {
    return pobj->v_LoginEnableAnonymous;
}

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_LoginEnableAnonymous_set(
    OV_INSTPTR_opcua_uaServer          pobj,
    const OV_BOOL  value
) {
    if(value != pobj->v_serverConfig.accessControl.enableAnonymousLogin){
    	if(pobj->v_objectstate >= OV_OS_STARTED){
    		opcua_uaServer_stopServer(pobj);
    	}
    	pobj->v_LoginEnableAnonymous = value;
    	pobj->v_serverConfig.accessControl.enableAnonymousLogin = value;
    	if(pobj->v_objectstate >= OV_OS_STARTED){
    		opcua_uaServer_initServer(pobj);
    	}
    }
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_BOOL opcua_uaServer_LoginEnableUsernamePassword_get(
    OV_INSTPTR_opcua_uaServer          pobj
) {
    return pobj->v_LoginEnableUsernamePassword;
}

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_LoginEnableUsernamePassword_set(
    OV_INSTPTR_opcua_uaServer          pobj,
    const OV_BOOL  value
) {
	if(value != pobj->v_serverConfig.accessControl.enableUsernamePasswordLogin){
		if(pobj->v_objectstate >= OV_OS_STARTED){
			opcua_uaServer_stopServer(pobj);
		}
		pobj->v_LoginEnableUsernamePassword = value;
		pobj->v_serverConfig.accessControl.enableUsernamePasswordLogin = value;
		if(pobj->v_objectstate >= OV_OS_STARTED){
			opcua_uaServer_initServer(pobj);
		}
	}
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_STRING* opcua_uaServer_LoginUsernames_get(
    OV_INSTPTR_opcua_uaServer          pobj,
    OV_UINT *pveclen
) {
	*pveclen = pobj->v_LoginUsernames.veclen;
    return pobj->v_LoginUsernames.value;
}

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_LoginUsernames_set(
    OV_INSTPTR_opcua_uaServer          pobj,
    const OV_STRING*  value,
    const OV_UINT veclen
) {
	//OV_UINT iterator;
	OV_RESULT result;
	if(pobj->v_objectstate >= OV_OS_STARTED){
		opcua_uaServer_stopServer(pobj);
	}
	/*	set the vector in the database and adjust length of passwords vector at the same time	*/
	/* TODO: New AccessControl
	if(veclen != pobj->v_serverConfig.usernamePasswordLoginsSize){
		pobj->v_serverConfig.usernamePasswordLoginsSize = veclen;
		Ov_HeapFree(pobj->v_serverConfig.usernamePasswordLogins);
		pobj->v_serverConfig.usernamePasswordLogins = Ov_HeapMalloc(veclen * sizeof(UA_UsernamePasswordLogin));
		if(!pobj->v_serverConfig.usernamePasswordLogins){
			return OV_ERR_HEAPOUTOFMEMORY;
		}
		result = Ov_SetDynamicVectorLength(&(pobj->v_LoginPasswords), veclen, STRING);
		if(Ov_Fail(result)){
			return result;
		}
	}
	*/
	result = Ov_SetDynamicVectorValue(&(pobj->v_LoginUsernames), value, veclen, STRING);
	if(Ov_Fail(result)){
		return result;
	}


	/*	copy to server config struct	*/
	/* TODO: New AccessControl
	for(iterator = 0; iterator < veclen; iterator++){
		//	this works for different length ONLY because OV_SetDynamicVeclen sets unused memory to zero and ov_sting_getlength can catch this
		pobj->v_serverConfig.usernamePasswordLogins[iterator].username.data = (UA_Byte*)pobj->v_LoginUsernames.value[iterator];
		pobj->v_serverConfig.usernamePasswordLogins[iterator].username.length = ov_string_getlength(pobj->v_LoginUsernames.value[iterator]);
		pobj->v_serverConfig.usernamePasswordLogins[iterator].password.data = (UA_Byte*)pobj->v_LoginPasswords.value[iterator];
		pobj->v_serverConfig.usernamePasswordLogins[iterator].password.length = ov_string_getlength(pobj->v_LoginPasswords.value[iterator]);
	    }
	 */

	if(pobj->v_objectstate >= OV_OS_STARTED){
		opcua_uaServer_initServer(pobj);
	}
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_STRING* opcua_uaServer_LoginPasswords_get(
    OV_INSTPTR_opcua_uaServer          pobj,
    OV_UINT *pveclen
) {
	*pveclen = pobj->v_LoginPasswords.veclen;
	return pobj->v_LoginPasswords.value;
}

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_LoginPasswords_set(
    OV_INSTPTR_opcua_uaServer          pobj,
    const OV_STRING*  value,
    const OV_UINT veclen
) {
	//OV_UINT iterator;
	OV_RESULT result;
	/*	usernames have to be set before	*/
	/* TODO: New AccessControl
	if(veclen != pobj->v_serverConfig.usernamePasswordLoginsSize){
		return OV_ERR_BADVALUE;
	}
	*/

	if(pobj->v_objectstate >= OV_OS_STARTED){
		opcua_uaServer_stopServer(pobj);
	}
	result = Ov_SetDynamicVectorValue(&(pobj->v_LoginPasswords), value, veclen, STRING);
	if(Ov_Fail(result)){
		return result;
	}

	/*	copy to server config struct	*/
	/* TODO: New AccessControl
	for(iterator = 0; iterator < veclen; iterator++){
		pobj->v_serverConfig.usernamePasswordLogins[iterator].password.data = (UA_Byte*)pobj->v_LoginPasswords.value[iterator];
		pobj->v_serverConfig.usernamePasswordLogins[iterator].password.length = ov_string_getlength(pobj->v_LoginPasswords.value[iterator]);
	}
	*/

	if(pobj->v_objectstate >= OV_OS_STARTED){
		opcua_uaServer_initServer(pobj);
	}
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_UINT opcua_uaServer_LoginLoginsCount_get(
    OV_INSTPTR_opcua_uaServer          pobj
) {
	/* TODO: New AccessControl
    return pobj->v_serverConfig.usernamePasswordLoginsSize;
	*/
	return 0;
}

OV_DLLFNCEXPORT OV_STRING opcua_uaServer_ApplicationURI_get(
    OV_INSTPTR_opcua_uaServer          pobj
) {
    return pobj->v_ApplicationURI;
}

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_ApplicationURI_set(
    OV_INSTPTR_opcua_uaServer          pobj,
    const OV_STRING  value
) {
	OV_RESULT result = OV_ERR_OK;
	if(ov_string_compare(pobj->v_ApplicationURI, value) != OV_STRCMP_EQUAL){
		if(pobj->v_objectstate >= OV_OS_STARTED){
			opcua_uaServer_stopServer(pobj);
		}
		result = ov_string_setvalue(&(pobj->v_ApplicationURI), value);
		if(Ov_Fail(result)){
			return result;
		}
		pobj->v_serverConfig.applicationDescription.applicationUri.length = ov_string_getlength(pobj->v_ApplicationURI);
		pobj->v_serverConfig.applicationDescription.applicationUri.data = (UA_Byte*)pobj->v_ApplicationURI;
		if(pobj->v_objectstate >= OV_OS_STARTED){
			opcua_uaServer_initServer(pobj);
		}
	}
    return result;
}

OV_DLLFNCEXPORT OV_STRING opcua_uaServer_ApplicationName_get(
    OV_INSTPTR_opcua_uaServer          pobj
) {
	return pobj->v_ApplicationName;
}

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_ApplicationName_set(
    OV_INSTPTR_opcua_uaServer          pobj,
    const OV_STRING  value
) {
	OV_RESULT result = OV_ERR_OK;
	if(ov_string_compare(pobj->v_ApplicationName, value) != OV_STRCMP_EQUAL){
		if(pobj->v_objectstate >= OV_OS_STARTED){
			opcua_uaServer_stopServer(pobj);
		}
		result = ov_string_setvalue(&(pobj->v_ApplicationName), value);
		if(Ov_Fail(result)){
			return result;
		}
		pobj->v_serverConfig.applicationDescription.applicationName.text.length = ov_string_getlength(pobj->v_ApplicationName);
		pobj->v_serverConfig.applicationDescription.applicationName.text.data = (UA_Byte*)pobj->v_ApplicationName;
		if(pobj->v_objectstate >= OV_OS_STARTED){
			opcua_uaServer_initServer(pobj);
		}
	}
	return result;
}

OV_DLLFNCEXPORT OV_RESULT opcua_uaServer_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*
    *   local variables
    */
    OV_INSTPTR_opcua_uaServer pinst = Ov_StaticPtrCast(opcua_uaServer, pobj);
    OV_RESULT    result;
    OV_INSTPTR_ov_object pOtherObject = NULL;
    OV_STRING	uName1	= "operator";
    OV_STRING	uName2	= "programmer";
    OV_STRING	pw1		= "PWoperator";
    OV_STRING	pw2		= "PWprogrammer";
    OV_INSTPTR_opcua_uaIdentificator pIdentificator = NULL;
    OV_STRING_VEC usernames = {.veclen = 2, .value = (OV_STRING[]) {uName1, uName2}};
    OV_STRING_VEC pws = {.veclen = 2, .value = (OV_STRING[]) {pw1, pw2}};

    /* do what the base class does first */
    result = ksbase_ComTask_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */
    Ov_ForEachChild(ov_instantiation, pclass_opcua_uaServer, pOtherObject){
    	if(pOtherObject != pobj){
    		KS_logfile_error(("%s: cannot instantiate - ua instance already exists", pinst->v_identifier));
    		return OV_ERR_ALREADYEXISTS;
    	}
    }
    /*	initialize server configuration variables copy everything to the config-struct in startup	*/
    result = Ov_SetDynamicVectorValue(&(pinst->v_LoginUsernames), usernames.value, usernames.veclen, STRING);
    if(Ov_Fail(result)){
    	return result;
    }
    result = Ov_SetDynamicVectorValue(&(pinst->v_LoginPasswords), pws.value, pws.veclen, STRING);
    if(Ov_Fail(result)){
    	return result;
    }

    /*	create protocol identificator for OPCUA	*/
    pIdentificator = Ov_StaticPtrCast(opcua_uaIdentificator, Ov_SearchChild(ov_containment, Ov_StaticPtrCast(ov_domain, pobj), "Identificator"));
    if(pIdentificator)
    	Ov_DeleteObject(pIdentificator);
    pIdentificator = NULL;

    result = Ov_CreateObject(opcua_uaIdentificator, pIdentificator, Ov_StaticPtrCast(ov_domain, pobj), "Identificator");
    if(Ov_Fail(result)){
    	ov_logfile_error("Fatal: could not create Identificator object");
    	return result;
    }

    return OV_ERR_OK;
}

OV_DLLFNCEXPORT void opcua_uaServer_destructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*
    *   local variables
    */
	//OV_INSTPTR_opcua_uaServer pinst = Ov_StaticPtrCast(opcua_uaServer, pobj);
    /* do what */

    /* destroy object */
	ksbase_ComTask_destructor(pobj);

    return;
}


OV_DLLFNCEXPORT void opcua_uaServer_startup(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_opcua_uaServer pinst = Ov_StaticPtrCast(opcua_uaServer, pobj);
    //OV_UINT	iterator = 0;
    /* do what the base class does first */
    ov_object_startup(pobj);

    /* do what */
    opcua_pUaServer = pinst;

    /*	initialize config struct as standard and copy in variables from the server object	*/


    pinst->v_serverConfig = UA_ServerConfig_standard;
    /* TODO: New AccessControl
    pinst->v_serverConfig.enableAnonymousLogin = pinst->v_LoginEnableAnonymous;
    pinst->v_serverConfig.enableUsernamePasswordLogin = pinst->v_LoginEnableUsernamePassword;
    pinst->v_serverConfig.usernamePasswordLoginsSize = pinst->v_LoginUsernames.veclen;
    pinst->v_serverConfig.usernamePasswordLogins = Ov_HeapMalloc(pinst->v_serverConfig.usernamePasswordLoginsSize * sizeof(UA_UsernamePasswordLogin));
    if(!pinst->v_serverConfig.usernamePasswordLogins){
    	//	we're out of memory. a printf does not make sense so just dont start up...
    	return;
    }
    for(iterator = 0; iterator < pinst->v_serverConfig.usernamePasswordLoginsSize; iterator++){
    	pinst->v_serverConfig.usernamePasswordLogins[iterator].username.data = (UA_Byte*)pinst->v_LoginUsernames.value[iterator];
    	pinst->v_serverConfig.usernamePasswordLogins[iterator].username.length = ov_string_getlength(pinst->v_LoginUsernames.value[iterator]);
    	pinst->v_serverConfig.usernamePasswordLogins[iterator].password.data = (UA_Byte*)pinst->v_LoginPasswords.value[iterator];
    	pinst->v_serverConfig.usernamePasswordLogins[iterator].password.length = ov_string_getlength(pinst->v_LoginPasswords.value[iterator]);
    }
    */
    pinst->v_serverConfig.applicationDescription.applicationName.text.length = ov_string_getlength(pinst->v_ApplicationName);
    pinst->v_serverConfig.applicationDescription.applicationName.text.data = (UA_Byte*)pinst->v_ApplicationName;
    pinst->v_serverConfig.applicationDescription.applicationUri.length = ov_string_getlength(pinst->v_ApplicationURI);
    pinst->v_serverConfig.applicationDescription.applicationUri.data = (UA_Byte*)pinst->v_ApplicationURI;
    /*	initialize serverConfig	*/
    UA_ServerRun = TRUE;
    opcua_uaServer_initServer(pinst);
    return;
}

OV_DLLFNCEXPORT void opcua_uaServer_shutdown(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_opcua_uaServer pinst = Ov_StaticPtrCast(opcua_uaServer, pobj);

    /* do what */
    UA_ServerRun = FALSE;
    opcua_uaServer_stopServer(pinst);
    opcua_pUaServer = NULL;
    /* set the object's state to "shut down" */
    ov_object_shutdown(pobj);

    return;
}

OV_DLLFNCEXPORT OV_ACCESS opcua_uaServer_getaccess(
	OV_INSTPTR_ov_object	pobj,
	const OV_ELEMENT		*pelem,
	const OV_TICKET			*pticket
) {
	switch(pelem->elemtype) {
	case OV_ET_VARIABLE:
		if(pelem->elemunion.pvar->v_offset >= offsetof(OV_INST_ov_object,__classinfo)) {
			if(pelem->elemunion.pvar->v_vartype == OV_VT_CTYPE)
				return OV_AC_NONE;
			else{
				if((pelem->elemunion.pvar->v_varprops & OV_VP_DERIVED)){
					if((pelem->elemunion.pvar->v_varprops & OV_VP_SETACCESSOR)){
						return OV_AC_READWRITE;
					} else {
						return OV_AC_READ;
					}
				} else {
					return OV_AC_READWRITE;
				}
			}
		}
		break;
	default:
		break;
	}

	return ov_object_getaccess(pobj, pelem, pticket);
}

OV_DLLFNCEXPORT void opcua_uaServer_typemethod (
	OV_INSTPTR_ksbase_ComTask	this
) {
	OV_INSTPTR_opcua_uaServer thisServer = Ov_StaticPtrCast(opcua_uaServer, this);
	UA_Server_run_iterate(thisServer->v_serverData, false);
    return;
}

OV_DLLFNCEXPORT UA_StatusCode opcua_uaServer_addInformationModel(UA_Namespace **namespace, OV_UINT namespaceSize, OV_STRING *StartFolder, opcua_loadInformationModel *loadInfoModel) {
	UA_StatusCode result = UA_STATUSCODE_GOOD;
	OV_STRING tmpString = NULL;

	for (OV_UINT i = 0; i < namespaceSize; i++){
		result = UA_Server_addNamespace_full(opcua_pUaServer->v_serverData, namespace[i]);
		if (result != UA_STATUSCODE_GOOD){
			for (OV_UINT k = 0; k < i; k++){
				tmpString = NULL;
				copyOPCUAStringToOV(namespace[k]->uri, &tmpString);
				UA_Server_deleteNamespace(opcua_pUaServer->v_serverData, tmpString);
				ov_database_free(tmpString);
			}
			return result;
		}
	}

	UA_Namespace *tmpNamespace = NULL;
	UA_UInt16 tmpNamespacesSize = 0;
	if (loadInfoModel != NULL)
		result = loadInfoModel(opcua_pUaServer->v_serverData, &tmpNamespacesSize, &tmpNamespace);

	if (result != UA_STATUSCODE_GOOD){
		for (OV_UINT i = 0; i < namespaceSize; i++){
			tmpString = NULL;
			copyOPCUAStringToOV(namespace[i]->uri, &tmpString);
			UA_Server_deleteNamespace(opcua_pUaServer->v_serverData, tmpString);
			ov_database_free(tmpString);
		}
		return result;
	}

	for (OV_UINT i = 0; i < namespaceSize; i++){
		if (StartFolder[i] == NULL)
			continue;
		if(UA_Server_addReference(opcua_pUaServer->v_serverData, UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
				UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES), UA_EXPANDEDNODEID_STRING(namespace[i]->index, StartFolder[i]), true) != UA_STATUSCODE_GOOD){
			tmpString = NULL;
			copyOPCUAStringToOV(namespace[i]->uri, &tmpString);
			ov_logfile_error("%s - init: could not create reference to %s-namespace", opcua_pUaServer->v_identifier, tmpString);
			ov_database_free(tmpString);
		}
	}

	OV_UINT oldlength = opcua_pUaServer->v_namespaceNames.veclen;
	Ov_SetDynamicVectorLength(&opcua_pUaServer->v_namespaceNames, opcua_pUaServer->v_namespaceNames.veclen + namespaceSize, STRING);
	OV_UINT j = 0;
	for (OV_UINT i = oldlength; i < opcua_pUaServer->v_namespaceNames.veclen; i ++){
		OV_STRING tmpNamespaceUri = NULL;
		copyOPCUAStringToOV(namespace[j]->uri, &tmpNamespaceUri);
		ov_string_setvalue(&opcua_pUaServer->v_namespaceNames.value[i], tmpNamespaceUri);
		ov_string_setvalue(&tmpNamespaceUri, NULL);
		j++;
	}

	return result;
}

