
/******************************************************************************
*
*   FILE
*   ----
*   testObject.c
*
*   History
*   -------
*   2016-10-27   File created
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
#include "libov/ov_path.h"
#include "libov/ov_string.h"

OV_DLLFNCEXPORT OV_RESULT opcua_testObject_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_opcua_testObject pinst = Ov_StaticPtrCast(opcua_testObject, pobj);
    OV_RESULT    result;

    /* do what the base class does first */
    result = ov_object_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */
    OV_INSTPTR_opcua_objectNode objectNode;
    OV_INSTPTR_opcua_objectNode objectNode2;
    OV_INSTPTR_opcua_reference reference1;
    OV_INSTPTR_opcua_reference reference2;
    OV_INSTPTR_opcua_variableNode variableNode;
    OV_INSTPTR_opcua_variableTypeNode variableTypeNode;
    OV_INSTPTR_ov_domain ptr = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, &(pdb->root), "TechUnits"));
    result = Ov_CreateObject(opcua_objectNode, objectNode, ptr, "objectNode");
    OV_STRING tmpString = "BNTest2";
    ov_string_setvalue(&objectNode->p_browseName.v_name, tmpString);
    tmpString = "desloc3";
    ov_string_setvalue(&objectNode->p_description.v_locale, tmpString);
    tmpString = "destext4";
    ov_string_setvalue(&objectNode->p_description.v_text, tmpString);
    tmpString = "disloc5";
    ov_string_setvalue(&objectNode->p_displayName.v_locale, tmpString);
    tmpString = "distext6";
    ov_string_setvalue(&objectNode->p_displayName.v_text, tmpString);

    objectNode->p_nodeId.v_namespaceIndex = 100;
    tmpString = "nodeId";
	ov_string_setvalue(&objectNode->p_nodeId.v_identifier, tmpString);
    objectNode->p_nodeId.v_identifierType = UA_NODEIDTYPE_NUMERIC;
    tmpString = "11";
	//ov_string_setvalue(&objectNode->p_nodeId.v_id.value.valueunion.val_string, tmpString);
    objectNode->p_nodeId.v_id.value.vartype = OV_VT_INT;
    objectNode->p_nodeId.v_id.value.valueunion.val_int = 99;
    objectNode->v_nodeClass = 8;
    objectNode->v_userWriteMask = 9;
    objectNode->v_writeMask = 10;

    result = Ov_CreateObject(opcua_objectNode, objectNode2, ptr, "objectNode2");
	tmpString = "BNTest20";
	ov_string_setvalue(&objectNode2->p_browseName.v_name, tmpString);
	tmpString = "desloc30";
	ov_string_setvalue(&objectNode2->p_description.v_locale, tmpString);
	tmpString = "destext40";
	ov_string_setvalue(&objectNode2->p_description.v_text, tmpString);
	tmpString = "disloc50";
	ov_string_setvalue(&objectNode2->p_displayName.v_locale, tmpString);
	tmpString = "distext60";
	ov_string_setvalue(&objectNode2->p_displayName.v_text, tmpString);


	objectNode2->p_nodeId.v_namespaceIndex = 200;
    tmpString = "nodeId2";
	ov_string_setvalue(&objectNode2->p_nodeId.v_identifier, tmpString);
	objectNode2->p_nodeId.v_identifierType = UA_NODEIDTYPE_STRING;
	tmpString = "22";
	ov_string_setvalue(&objectNode2->p_nodeId.v_id.value.valueunion.val_string, tmpString);
	objectNode2->v_nodeClass = 28;
	objectNode2->v_userWriteMask = 29;
	objectNode2->v_writeMask = 210;

	result = createOVReferenceNodeFromOPCUA(&objectNode->p_references, &reference1, "reference1");

	reference1->p_referenceTypeNodeId.v_namespaceIndex = objectNode->p_nodeId.v_namespaceIndex;
	reference1->p_referenceTypeNodeId.v_identifierType = objectNode->p_nodeId.v_identifierType;
	ov_string_setvalue(&reference1->p_referenceTypeNodeId.v_id.value.valueunion.val_string, objectNode->p_nodeId.v_id.value.valueunion.val_string);
	reference1->p_targetNodeId.p_nodeId.v_namespaceIndex = objectNode2->p_nodeId.v_namespaceIndex;
	reference1->p_targetNodeId.p_nodeId.v_identifierType = objectNode2->p_nodeId.v_identifierType;
	ov_string_setvalue(&reference1->p_targetNodeId.p_nodeId.v_id.value.valueunion.val_string, objectNode2->p_nodeId.v_id.value.valueunion.val_string);

	result = createOVReferenceNodeFromOPCUA(&objectNode->p_references, &reference2, "reference2");
	reference2->p_referenceTypeNodeId.v_namespaceIndex = objectNode2->p_nodeId.v_namespaceIndex;
	reference2->p_referenceTypeNodeId.v_identifierType = objectNode2->p_nodeId.v_identifierType;
	ov_string_setvalue(&reference2->p_referenceTypeNodeId.v_id.value.valueunion.val_string, objectNode2->p_nodeId.v_id.value.valueunion.val_string);
	reference2->p_targetNodeId.p_nodeId.v_namespaceIndex = objectNode->p_nodeId.v_namespaceIndex;
	reference2->p_targetNodeId.p_nodeId.v_identifierType = objectNode->p_nodeId.v_identifierType;
	ov_string_setvalue(&reference2->p_targetNodeId.p_nodeId.v_id.value.valueunion.val_string, objectNode->p_nodeId.v_id.value.valueunion.val_string);

    result = Ov_CreateObject(opcua_variableNode, variableNode, ptr, "variableNode");

    result = Ov_CreateObject(opcua_variableTypeNode, variableTypeNode, ptr,"variableTypeNode");



    return result;
}
OV_DLLFNCEXPORT void opcua_testObject_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
	OV_INSTPTR_opcua_testObject pinst = Ov_StaticPtrCast(opcua_testObject, pfb);
    /* do what */
    OV_INSTPTR_ov_domain ptr = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, &(pdb->root), "TechUnits"));
    if(!ptr)
    	return;
    ptr = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, ptr, "objectNode"));
//test copytoUANode
    if(!ptr)
    	return;

    UA_ObjectNode *uaObjectNode  	= ov_database_malloc(sizeof(UA_ObjectNode));
    UA_ObjectNode *uaObjectNode2  	= ov_database_malloc(sizeof(UA_ObjectNode));
    UA_VariableNode *uaVariableNode = ov_database_malloc(sizeof(UA_VariableNode));
    UA_VariableTypeNode *uaVariableTypeNode = ov_database_malloc(sizeof(UA_VariableTypeNode));

    if(!uaVariableNode)
    	return;


    if(!uaObjectNode)
     	return;

    if(opcua_nodeStoreFunctions_ovObjectNodeToOPCUA(NULL,Ov_StaticPtrCast(opcua_objectNode,ptr), uaObjectNode)!=OV_ERR_OK){
    	//copy object failed
    	return;
    }

    //OV_INSTPTR_opcua_objectNode tmpObjectNode = Ov_StaticPtrCast(opcua_objectNode,ptr);
    if(opcua_nodeStoreFunctions_opcuaObjectNodeToOv(NULL,uaObjectNode, Ov_StaticPtrCast(opcua_objectNode,ptr))!=OV_ERR_OK){
        //copy object failed
        	return;
        }

    /*if(opcua_nodeStoreFunctions_ovObjectNodeToOPCUA(NULL,Ov_StaticPtrCast(opcua_objectNode,ptr), uaObjectNode2)!=OV_ERR_OK){
        	//copy object failed
        	return;
        }

	//OV_INSTPTR_opcua_objectNode tmpObjectNode = Ov_StaticPtrCast(opcua_objectNode,ptr);
	if(opcua_nodeStoreFunctions_opcuaObjectNodeToOv(NULL,uaObjectNode2, Ov_StaticPtrCast(opcua_objectNode,ptr))!=OV_ERR_OK){
		//copy object failed
			return;
		}

*/
    pinst->v_var1 = uaObjectNode->browseName.name.length;
/*
    if(opcua_nodeStoreFunctions_ovVariableNodeToOPCUA(NULL,Ov_StaticPtrCast(opcua_variableNode,ptr), uaVariableNode)!=OV_ERR_OK){
        	//copy object failed
        	return;
        }

	if(opcua_nodeStoreFunctions_opcuaVariableNodeToOv(NULL,uaVariableNode, Ov_StaticPtrCast(opcua_variableNode,ptr))!=OV_ERR_OK){
		//copy object failed
			return;
		}
*/

    return;
}

OV_DLLFNCEXPORT void opcua_testObject_destructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_opcua_testObject pinst = Ov_StaticPtrCast(opcua_testObject, pobj);

    /* do what */

    /* destroy object */
    ov_object_destructor(pobj);

    return;
}


