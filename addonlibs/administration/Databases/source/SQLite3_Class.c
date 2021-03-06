
/******************************************************************************
*
*   FILE
*   ----
*   SQLite3.c
*
*   History
*   -------
*   2018-04-25   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_Databases
#define OV_COMPILE_LIBRARY_Databases
#endif


#include "Databases.h"
#include "libov/ov_macros.h"
#include "sqlite3.h"
#include "libov/ov_logfile.h"
#include <stdio.h>



// global variables, access to object members and db handler
OV_INSTPTR_Databases_SQLite3 SQLITE3_pinst = NULL;
int rc;

// callback function
static int callback(void* data, int argc, char **argv, char **col_name) {

	Ov_SetDynamicVectorLength((OV_STRING_VEC*)data, ((OV_STRING_VEC*)data)->veclen + argc, STRING);

	for(int i = 0; i<argc; i++) {
		ov_string_setvalue(&(((OV_STRING_VEC*)data)->value[((OV_STRING_VEC*)data)->veclen - argc + i]), argv[i]);
		//ov_logfile_info("%-10s : %-s", col_name[i], argv[i] ? argv[i] : "NULL");
	}
	return 0;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_connect(void) {
	OV_STRING err_msg = NULL;

	// open database
	rc = sqlite3_open(SQLITE3_pinst->v_Endpoint , &SQLITE3_pinst->v_db);

	// check first if db handle allocated
	if(SQLITE3_pinst->v_db == NULL) {
		ov_string_setvalue(&SQLITE3_pinst->v_ErrorMessage, "Could not allocate memory for DB handle!");
		SQLITE3_pinst->v_ErrorFlag = TRUE;
		return OV_ERR_GENERIC;
	}
	// check then if error occured
	if( rc != SQLITE_OK) {
		// since v_db is not null we can retrieve sqlite3_errmsg()
		ov_string_setvalue(&err_msg,  (OV_STRING)sqlite3_errmsg(SQLITE3_pinst->v_db));
		ov_string_setvalue(&SQLITE3_pinst->v_ErrorMessage, err_msg);
		SQLITE3_pinst->v_ErrorFlag = TRUE;
		sqlite3_close(SQLITE3_pinst->v_db);
		return OV_ERR_GENERIC;
	}
	err_msg = NULL;

	// reset error message
	// TODO: what if db is already in bad state?
	if(!SQLITE3_pinst->v_ErrorFlag) {
		SQLITE3_pinst->v_ErrorFlag = FALSE;
		ov_string_setvalue(&SQLITE3_pinst->v_ErrorMessage, NULL);
	}

    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_disconnect(void) {
	sqlite3_close(SQLITE3_pinst->v_db);

    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_insertData(const OV_STRING table, const OV_STRING* fields, OV_UINT fieldsLen,
													   const OV_STRING* values, OV_UINT valuesLen) {
	if(fieldsLen != valuesLen) {
		return OV_ERR_BADPARAM;
	}
	// build up INSERT query
	OV_STRING query = NULL;
	ov_string_setvalue(&query, "INSERT INTO ");
	ov_string_print(&query, "%s%s ", query, table);
	ov_string_print(&query, "%s%s", query, "(");
	for(int i = 0; i < fieldsLen; i++) {
		if(i == fieldsLen-1) {
			ov_string_print(&query, "%s%s) ", query, fields[i]);
		} else {
			ov_string_print(&query, "%s%s, ", query, fields[i]);
		}
	}
	ov_string_print(&query, "%s%s", query, "VALUES (");
	for(int i = 0; i < fieldsLen; i++) {
		if(i == fieldsLen-1) {
			ov_string_print(&query, "%s%s); ", query, values[i]);
		} else {
			ov_string_print(&query, "%s%s, ", query, values[i]);
		}
	}
	//ov_logfile_info("%s", query);

	char* err_msg = NULL;
	rc = sqlite3_exec(SQLITE3_pinst->v_db, query, NULL, NULL, &err_msg);

	if(rc != SQLITE_OK) {
		ov_logfile_info("SQL Error: %s", err_msg);
		sqlite3_free(err_msg);
		ov_string_setvalue(&query, NULL);
		return OV_ERR_BADPARAM;
		ov_string_setvalue(&err_msg, "Could not connect to DB. Closing connection!");
	}

	ov_string_setvalue(&query, NULL);
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_selectData(const OV_STRING table, const OV_STRING* fields, OV_UINT fieldsLen, const OV_STRING* whereFields,
													   OV_UINT whereFieldsLen, OV_STRING* whereValues, OV_UINT whereValuesLen, OV_STRING_VEC* result) {
	if(whereFieldsLen != whereValuesLen) {
		return OV_ERR_BADPARAM;
	}
	// build up SELECT query
	OV_STRING query = NULL;
	ov_string_setvalue(&query, "SELECT DISTINCT");
	for(int i = 0; i < fieldsLen; i++) {
		if(i != fieldsLen-1) {
			ov_string_print(&query, "%s %s,", query, fields[i]);
		} else {
			ov_string_print(&query, "%s %s", query, fields[i]);
		}
	}
	if(!fieldsLen) ov_string_print(&query, "%s %s ", query, "*");
	ov_string_print(&query, "%s %s", query, "FROM");
	ov_string_print(&query, "%s %s", query, table);
	if (fieldsLen){
		ov_string_print(&query, "%s %s", query, "WHERE");
		for(int i = 0; i < fieldsLen; i++) {
			if(i != fieldsLen-1) {
				ov_string_print(&query, "%s %s IS NOT NULL AND", query, fields[i]);
				ov_string_print(&query, "%s %s != \"\" AND", query, fields[i]);
			} else {
				ov_string_print(&query, "%s %s IS NOT NULL AND", query, fields[i]);
				ov_string_print(&query, "%s %s != \"\" AND", query, fields[i]);
			}
		}
	}
	if(whereFieldsLen) {
		if (!fieldsLen)	ov_string_print(&query, "%s %s", query, "WHERE");
		for(int i = 0; i < whereFieldsLen; i++) {
			if(i != whereFieldsLen-1) {
				ov_string_print(&query, "%s %s = %s AND", query, whereFields[i], whereValues[i]);
			} else {
				ov_string_print(&query, "%s %s = %s", query, whereFields[i], whereValues[i]);
			}
		}
	}
	ov_string_print(&query, "%s%s", query, ";");

	//ov_logfile_info("%s", query);

	char* err_msg = NULL;
	rc = sqlite3_exec(SQLITE3_pinst->v_db, query, callback, result, &err_msg);

	if(rc != SQLITE_OK) {
		ov_logfile_info("SQL Error: %s", err_msg);
		sqlite3_free(err_msg);
		ov_string_setvalue(&query, NULL);
		return OV_ERR_BADPARAM;
	}

	ov_string_setvalue(&query, NULL);
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_deleteData(const OV_STRING table, const OV_STRING* fields, OV_UINT fieldsLen, const OV_STRING* values, OV_UINT valuesLen) {
	// build up DELETE query
	OV_STRING query = NULL;
	ov_string_setvalue(&query, "DELETE FROM ");
	ov_string_print(&query, "%s%s ", query, table);
	if(fieldsLen) {
		ov_string_print(&query, "%s%s ", query, "WHERE");
		for(int i = 0; i < fieldsLen; i++) {
			if(i != fieldsLen-1) {
				ov_string_print(&query, "%s%s = %s, ", query, fields[i], values[i]);
			} else {
				ov_string_print(&query, "%s%s = %s;", query, fields[i], values[i]);
			}
		}
	}

	//ov_logfile_info("%s", query);

	char* err_msg = NULL;
	rc = sqlite3_exec(SQLITE3_pinst->v_db, query, NULL, NULL, &err_msg);

	if(rc != SQLITE_OK) {
		ov_logfile_info("SQL Error: %s", err_msg);
		sqlite3_free(err_msg);
		ov_string_setvalue(&query, NULL);
		return OV_ERR_BADPARAM;
	}

	ov_string_setvalue(&query, NULL);
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_updateData(const OV_STRING table, const OV_STRING* fields, OV_UINT fieldsLen, const OV_STRING* fieldValues, OV_UINT fieldValuesLen, const OV_STRING* whereFields, OV_UINT whereFieldsLen, OV_STRING* whereValues, OV_UINT whereValuesLen) {
	// build up UPDATE query
	OV_STRING query = NULL;
	ov_string_setvalue(&query, "UPDATE");
	ov_string_print(&query, "%s %s", query, table);
	if(fieldsLen) {
		ov_string_print(&query, "%s %s", query, "SET");
		for(int i = 0; i < fieldsLen; i++) {
			if(i != fieldsLen-1) {
				ov_string_print(&query, "%s %s = %s,", query, fields[i], fieldValues[i]);
			} else {
				ov_string_print(&query, "%s %s = %s", query, fields[i], fieldValues[i]);
			}
		}
	}
	if(whereFieldsLen) {
		ov_string_print(&query, "%s %s", query, "WHERE");
		for(int i = 0; i < fieldsLen; i++) {
			if(i != fieldsLen-1) {
				ov_string_print(&query, "%s %s = %s,", query, whereFields[i], whereValues[i]);
			} else {
				ov_string_print(&query, "%s %s = %s", query, whereFields[i], whereValues[i]);
			}
		}
	}
	ov_string_print(&query, "%s%s", query, ";");

	//ov_logfile_info("%s", query);

	char* err_msg = NULL;
	rc = sqlite3_exec(SQLITE3_pinst->v_db, query, NULL, NULL, &err_msg);

	if(rc != SQLITE_OK) {
		ov_logfile_info("SQL Error: %s", err_msg);
		sqlite3_free(err_msg);
		ov_string_setvalue(&query,NULL);
		return OV_ERR_BADPARAM;
	}

	ov_string_setvalue(&query,NULL);
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_getComponentID(const OV_STRING table, const DB_QUERY* db_query, OV_UINT querySize, OV_STRING_VEC* result) {
	// TODO: Check Veclen => Errorhandling

	OV_STRING query = NULL;
    ov_string_setvalue(&query, "SELECT DISTINCT ComponentID0 FROM");

    for(OV_UINT i = 0; i < querySize; i++) {
    	ov_string_print(&query, "%s (SELECT DISTINCT ComponentID AS ComponentID%i FROM %s WHERE ", query, i, table);
    	for(OV_UINT j = 0; j < db_query[i].column.veclen; j++) {
    		if (j < db_query[i].column.veclen - 1)
    			ov_string_print(&query, "%s %s='%s' AND ", query, db_query[i].column.value[j], db_query[i].value.value[j]);
    		else
    			ov_string_print(&query, "%s %s='%s')", query, db_query[i].column.value[j], db_query[i].value.value[j]);
    	}
    	if (i < querySize - 1)
    		ov_string_append(&query, ",");
    }
    if (querySize > 1){
    	ov_string_append(&query, "WHERE ");
    	for(OV_UINT i = 0; i < querySize; i++) {
    		ov_string_print(&query, "%s ComponentID%i", query, i);
    		if(i < querySize-1)
    			ov_string_append(&query, "=");
    	}
    }
	ov_string_append(&query, ";");

	//ov_logfile_info("%s", query);

	char* err_msg = NULL;
	rc = sqlite3_exec(SQLITE3_pinst->v_db, query, callback, result, &err_msg);

	if(rc != SQLITE_OK) {
		ov_logfile_info("SQL Error: %s", err_msg);
		sqlite3_free(err_msg);
		ov_string_setvalue(&query, NULL);
		return OV_ERR_BADPARAM;
	}

	ov_string_setvalue(&query, NULL);
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_execQuery(const OV_STRING query) {

    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_query_set(
    OV_INSTPTR_Databases_SQLite3          pobj,
    const OV_STRING  value
) {
	if(!value) {
		const char* data = "Callback funtion called";
		char* err_msg = NULL;

		ov_string_setvalue(&pobj->v_query,value);
		//ov_logfile_info("%s", pobj->v_query);
		rc = sqlite3_exec(SQLITE3_pinst->v_db, pobj->v_query, callback, (void*)data, &err_msg);

		if( rc != SQLITE_DONE ) {
			ov_logfile_info("SQL error: %s", err_msg);
			return OV_ERR_GENERIC;
		}
	}

    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_io_set(
    OV_INSTPTR_Databases_SQLite3          pobj,
    const OV_BOOL  value
) {
	pobj->v_io = value;
/*
	if(pobj->v_io) {
		Databases_SQLite3_readData();
	}
	else {
		Databases_SQLite3_writeData();
	}*/

	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT Databases_SQLite3_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_Databases_SQLite3 pinst = Ov_StaticPtrCast(Databases_SQLite3, pobj);
    OV_RESULT    result;

    /* do what the base class does first */
    result = openAASDiscoveryServer_DBWrapper_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */
    SQLITE3_pinst = pinst;

    return OV_ERR_OK;
}

