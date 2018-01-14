#ifndef CMEAUDITTRAIL_AUDITTRAILCANCELAMENDREJECT_H
#define CMEAUDITTRAIL_AUDITTRAILCANCELAMENDREJECT_H

#include "AuditTrailBase.h"

class AuditTrailCancelAmendReject : public AuditTrailBase {
public:
    AuditTrailCancelAmendReject(const Message& message) : AuditTrailBase(message){};
};


#endif //CMEAUDITTRAIL_AUDITTRAILCANCELAMENDREJECT_H
