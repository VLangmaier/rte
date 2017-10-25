/* WARNING: This is a generated file.
 * Any manual changes will be overwritten.

 */
#ifndef NODESET_H_
#define NODESET_H_
#ifdef UA_NO_AMALGAMATION
#include "server/ua_server_internal.h"
  #include "ua_util.h"
  #include "ua_types.h"
  #include "ua_nodes.h"
  #include "ua_server.h"
  #include "ua_types_encoding_binary.h"
  #include "ua_types_generated_encoding_binary.h"
  #include "ua_transport_generated_encoding_binary.h"
#else
  #include "open62541.h"
#endif

/* Definition that (in userspace models) may be 
 * - not included in the amalgamated header or
 * - not part of public headers or
 * - not exported in the shared object in combination with any of the above
 * but are required for value encoding.
 * NOTE: Userspace UA_(decode|encode)Binary /wo amalgamations requires UA_EXPORT to be appended to the appropriate definitions. */
#ifndef UA_ENCODINGOFFSET_BINARY
#  define UA_ENCODINGOFFSET_BINARY 2
#endif
#ifndef NULL
  #define NULL ((void *)0)
#endif
#ifndef UA_malloc
  #define UA_malloc(_p_size) malloc(_p_size)
#endif
#ifndef UA_free
  #define UA_free(_p_ptr) free(_p_ptr)
#endif
#define UA_NS2ID_AASSTATUSCODE 3004
#define UA_NS2ID_AASFACTORYTYPE 1005
#define UA_NS2ID_CREATEAAS 7001
#define UA_NS2ID_CREATEAAS_INPUTARGUMENTS 1953
#define UA_NS2ID_CREATEAAS_OUTPUTARGUMENTS 1954
#define UA_NS2ID_CREATELCE 7002
#define UA_NS2ID_CREATELCE_INPUTARGUMENTS 1956
#define UA_NS2ID_CREATELCE_OUTPUTARGUMENTS 1957
#define UA_NS2ID_CREATEPVS 7013
#define UA_NS2ID_CREATEPVS_INPUTARGUMENTS 1959
#define UA_NS2ID_CREATEPVS_OUTPUTARGUMENTS 1960
#define UA_NS2ID_CREATEPVSL 7011
#define UA_NS2ID_CREATEPVSL_INPUTARGUMENTS 1962
#define UA_NS2ID_CREATEPVSL_OUTPUTARGUMENTS 1963
#define UA_NS2ID_CREATESUBMODEL 7009
#define UA_NS2ID_CREATESUBMODEL_INPUTARGUMENTS 1964
#define UA_NS2ID_CREATESUBMODEL_OUTPUTARGUMENTS 1965
#define UA_NS2ID_DELETEAAS 7003
#define UA_NS2ID_DELETEAAS_INPUTARGUMENTS 1967
#define UA_NS2ID_DELETEAAS_OUTPUTARGUMENTS 1968
#define UA_NS2ID_DELETELCE 7004
#define UA_NS2ID_DELETELCE_INPUTARGUMENTS 1970
#define UA_NS2ID_DELETELCE_OUTPUTARGUMENTS 1971
#define UA_NS2ID_DELETEPVS 7014
#define UA_NS2ID_DELETEPVS_INPUTARGUMENTS 1973
#define UA_NS2ID_DELETEPVS_OUTPUTARGUMENTS 1974
#define UA_NS2ID_DELETEPVSL 7012
#define UA_NS2ID_DELETEPVSL_INPUTARGUMENTS 1976
#define UA_NS2ID_DELETEPVSL_OUTPUTARGUMENTS 1977
#define UA_NS2ID_DELETESUBMODEL 7010
#define UA_NS2ID_DELETESUBMODEL_INPUTARGUMENTS 1979
#define UA_NS2ID_DELETESUBMODEL_OUTPUTARGUMENTS 1980
#define UA_NS2ID_GETAASNODEID 7005
#define UA_NS2ID_GETAASNODEID_INPUTARGUMENTS 1982
#define UA_NS2ID_GETAASNODEID_OUTPUTARGUMENTS 1983
#define UA_NS2ID_GETLASTLCES 7006
#define UA_NS2ID_GETLASTLCES_INPUTARGUMENTS 1985
#define UA_NS2ID_GETLASTLCES_OUTPUTARGUMENTS 1986
#define UA_NS2ID_GETLCE 7007
#define UA_NS2ID_GETLCE_INPUTARGUMENTS 1988
#define UA_NS2ID_GETLCE_OUTPUTARGUMENTS 1989
#define UA_NS2ID_GETLCESIMPLE 7018
#define UA_NS2ID_GETLCESIMPLE_INPUTARGUMENTS 1991
#define UA_NS2ID_GETLCESIMPLE_OUTPUTARGUMENTS 1992
#define UA_NS2ID_GETPVS 7016
#define UA_NS2ID_GETPVS_INPUTARGUMENTS 1994
#define UA_NS2ID_GETPVS_OUTPUTARGUMENTS 1995
#define UA_NS2ID_SETLCE 7008
#define UA_NS2ID_SETLCE_INPUTARGUMENTS 1997
#define UA_NS2ID_SETLCE_OUTPUTARGUMENTS 1998
#define UA_NS2ID_SETLCESIMPLE 7017
#define UA_NS2ID_SETLCESIMPLE_INPUTARGUMENTS 2000
#define UA_NS2ID_SETLCESIMPLE_OUTPUTARGUMENTS 2001
#define UA_NS2ID_SETPVS 7015
#define UA_NS2ID_SETPVS_INPUTARGUMENTS 2003
#define UA_NS2ID_SETPVS_OUTPUTARGUMENTS 2004
#define UA_NS2ID_ASSETADMINITRATIONSHELLTYPE 1002
#define UA_NS2ID_SUBMODELTYPE 1003

  extern UA_StatusCode nodeset(UA_Server *server);
  extern UA_StatusCode nodeset_returnNamespaces(UA_Server *server,
          UA_UInt16 *namespacesSize, UA_Namespace **namspaces);
#endif /* NODESET_H_ */
