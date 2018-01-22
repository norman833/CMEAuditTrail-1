#ifndef CMEAUDITTRAIL_AUDITTRAILGENERATOR_H
#define CMEAUDITTRAIL_AUDITTRAILGENERATOR_H

#include "quickfix/Message.h"

using  namespace FIX;
class AuditTrailGenerator {
public:
    static std::string generateAuditTrail(const Message& message, const std::string& txnTime);
    static std::string generateHeader();
private:

};


#endif //CMEAUDITTRAIL_AUDITTRAILGENERATOR_H
