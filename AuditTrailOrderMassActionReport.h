#ifndef CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREPORT_H
#define CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREPORT_H

#include "AuditTrailBase.h"

class AuditTrailOrderMassActionReport : public AuditTrailBase {
public:
    AuditTrailOrderMassActionReport(const Message& message, const std::string& txnTime) : AuditTrailBase(message, txnTime){};

    std::string getCountryofOrigin();
    std::string getCMEGlobexOrderID(uint32_t i);
    std::string getCSV();
};


#endif //CMEAUDITTRAIL_AUDITTRAILORDERMASSACTIONREPORT_H
