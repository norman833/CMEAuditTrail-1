#include "AuditTrailGenerator.h"
#include "AuditTrailBase.h"

std::string AuditTrailGenerator::generatorAuditTrail(const Message &message, const std::string& txnTime) {
    AuditTrailBase auditTrailBase(message, txnTime );
    auto msgType = message.getHeader().getField(FIX::FIELD::MsgType);
    if(message.isApp() || (message.isAdmin() && (msgType == "3" || msgType == "j")) )
        return auditTrailBase.getCSV();
    else
        return "";
}