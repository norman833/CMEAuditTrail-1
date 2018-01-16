#ifndef CMEAUDITTRAIL_AUDITTRAILBASE_H
#define CMEAUDITTRAIL_AUDITTRAILBASE_H

#include <string>
#include "quickfix/Message.h"

using namespace FIX;
class AuditTrailBase {
public:
    explicit  AuditTrailBase(const Message& message, const std::string& txnTime);
    virtual std::string getCSV();
    virtual std::string getSendingTimestamps();
    virtual std::string getReceivingTimestamps();
    virtual std::string getMessageDirection();
    virtual std::string getOperatorID();
    virtual std::string getSelf_MatchPreventionID();
    virtual std::string getAccountNumber();
    virtual std::string getSessionID();
    virtual std::string getExecutingFirmID();
    virtual std::string getManualOrderIdentifier();
    virtual std::string getMessageType();
    virtual std::string getCustomerTypeIndicator();
    virtual std::string getOrigin();
    virtual std::string getCMEGlobexMessageID();
    virtual std::string getMessageLinkID();
    virtual std::string getOrderFlowID();
    virtual std::string getSpreadLegLinkID();
    virtual std::string getInstrumentDescription();
    virtual std::string getMarketSegmentID();
    virtual std::string getClientOrderID();
    virtual std::string getCMEGlobexOrderID();
    virtual std::string getBuySellIndicator();
    virtual std::string getQuantity();
    virtual std::string getLimitPrice();
    virtual std::string getStopPrice();
    virtual std::string getOrderType();
    virtual std::string getOrderQualifier();
    virtual std::string getIFMFlag();
    virtual std::string getDisplayQuantity();
    virtual std::string getMinimumQuantity();
    virtual std::string getCountryofOrigin();
    virtual std::string getFillPrice();
    virtual std::string getFillQuantity();
    virtual std::string getCumulativeQuantity();
    virtual std::string getRemainingQuantity();
    virtual std::string getAggressorFlag();
    virtual std::string getSourceofCancellation();
    virtual std::string getRejectReason();
    virtual std::string getProcessedQuotes();
    virtual std::string getCrossID();
    virtual std::string getQuoteRequestID();
    virtual std::string getMessageQuoteID();
    virtual std::string getQuoteEntryID();
    virtual std::string getBidPrice();
    virtual std::string getBidSize();
    virtual std::string getOfferPrice();
    virtual std::string getOfferSize();

    static const std::string FROM_CME;
    static const std::string TO_CME;
private:
    Message message_;
    std::string txnTime_;

    std::string testAndGetField(const int field);
};

#endif //CMEAUDITTRAIL_AUDITTRAILBASE_H
