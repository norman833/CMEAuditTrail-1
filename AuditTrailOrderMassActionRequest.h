#ifndef CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREQUEST_H
#define CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREQUEST_H

#include "AuditTrailBase.h"

class AuditTrailOrderMassActionRequest : public AuditTrailBase {
public:
    AuditTrailOrderMassActionRequest(const Message& message, const std::string& txnTime) : AuditTrailBase(message, txnTime){};
};


#endif //CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREQUEST_H
