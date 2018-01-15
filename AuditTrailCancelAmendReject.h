#ifndef CMEAUDITTRAIL_AUDITTRAILCANCELAMENDREJECT_H
#define CMEAUDITTRAIL_AUDITTRAILCANCELAMENDREJECT_H

#include "AuditTrailBase.h"

class AuditTrailCancelAmendReject : public AuditTrailBase {
public:
    AuditTrailCancelAmendReject(const Message& message, const std::string& txnTime) : AuditTrailBase(message, txnTime){};
};


#endif //CMEAUDITTRAIL_AUDITTRAILCANCELAMENDREJECT_H
