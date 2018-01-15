#ifndef CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREPORT_H
#define CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREPORT_H

#include "AuditTrailBase.h"

class AuditTrailOrderMassActionReport : public AuditTrailBase {
public:
    AuditTrailOrderMassActionReport(const Message& message, const std::string& txnTime) : AuditTrailBase(message, txnTime){};

};


#endif //CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREPORT_H
