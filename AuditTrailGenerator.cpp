#include "AuditTrailGenerator.h"

std::string AuditTrailGenerator::generatorAuditTrail(const Message &message) {
    return message.toString();
}