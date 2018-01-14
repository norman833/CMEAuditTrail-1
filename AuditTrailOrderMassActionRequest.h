#ifndef CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREQUEST_H
#define CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREQUEST_H

#include "AuditTrailBase.h"

class AuditTrailOrderMassActionRequest : public AuditTrailBase {
public:
    AuditTrailOrderMassActionRequest(const Message& message) : AuditTrailBase(message){};
};


#endif //CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREQUEST_H
