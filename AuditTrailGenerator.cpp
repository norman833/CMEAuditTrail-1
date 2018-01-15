#include "AuditTrailGenerator.h"
#include "AuditTrailBase.h"

std::string AuditTrailGenerator::generatorAuditTrail(const Message &message, const std::string& txnTime) {
    AuditTrailBase auditTrailBase(message, txnTime );
    return auditTrailBase.getCSV();
}