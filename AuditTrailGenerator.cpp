#include "AuditTrailGenerator.h"
#include "AuditTrailBase.h"
#include "AuditTrailOrderMassActionReport.h"

std::string AuditTrailGenerator::generateAuditTrail(const Message &message, const std::string& txnTime) {
    auto msgType = message.getHeader().getField(FIX::FIELD::MsgType);

    if(msgType == "BZ"){
        AuditTrailOrderMassActionReport auditTrailOrderMassActionReport(message, txnTime);
        return auditTrailOrderMassActionReport.getCSV();
    }
    if(message.isApp() || (message.isAdmin() && (msgType == "3" || msgType == "j")) ){
        AuditTrailBase auditTrailBase(message, txnTime );
        return auditTrailBase.getCSV();
    }
    else{
        return "";
    }
}

std::string AuditTrailGenerator::generateHeader() {
    return std::string("Sending Timestamps,") +
           "Receiving Timestamps," +
           "Message Direction," +
           "Operator ID," +
           "Self-Match Prevention ID," +
           "Account Number," +
           "Session ID," +
           "Executing Firm ID," +
           "Manual Order Identifier," +
           "Message Type," +
           "Customer Type Indicator," +
           "Origin," +
           "CME Globex Message ID," +
           "Message Link ID," +
           "Order Flow ID," +
           "Spread/Leg Link ID," +
           "Instrument Description," +
           "Market Segment ID," +
           "Client Order ID," +
           "CME Globex Order ID," +
           "Buy/Sell Indicator," +
           "Quantity," +
           "Limit Price," +
           "Stop Price," +
           "Order Type," +
           "Order Qualifier," +
           "IFM Flag," +
           "Display Quantity," +
           "Minimum Quantity," +
           "Country of Origin," +
           "Fill Price," +
           "Fill Quantity," +
           "Cumulative Quantity," +
           "Remaining Quantity," +
           "Aggressor Flag," +
           "Source of Cancellation," +
           "Reject Reason," +
           "Processed Quotes," +
           "Cross ID," +
           "Quote Request ID," +
           "Message Quote ID," +
           "Quote Entry ID," +
           "Bid Price," +
           "Bid Size," +
           "Offer Price," +
           "Offer Size";
}