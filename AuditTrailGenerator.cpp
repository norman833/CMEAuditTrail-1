#include "AuditTrailGenerator.h"
#include "AuditTrailBase.h"

std::string AuditTrailGenerator::generatorAuditTrail(const Message &message) {
    AuditTrailBase auditTrailBase(message);
    return auditTrailBase.getCSV();
}