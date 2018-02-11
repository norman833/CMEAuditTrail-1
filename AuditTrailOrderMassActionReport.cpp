#include "AuditTrailOrderMassActionReport.h"
#include "quickfix/fix50sp2/OrderMassCancelReport.h"

std::string AuditTrailOrderMassActionReport::getCSV() {
    std::string res{};
    int32_t n{0};
    std::string noAffectedOrders = this->testAndGetField(FIX::FIELD::NoAffectedOrders);
    if(noAffectedOrders.size())
        n = std::stoi(noAffectedOrders);

    for(int i = 0; i < n; ++i){
        std::string delimitor = ",";
        res += getSendingTimestamps() + delimitor +
               getReceivingTimestamps() + delimitor +
               getMessageDirection() + delimitor +
               getOperatorID() + delimitor +
               getSelf_MatchPreventionID() + delimitor +
               getAccountNumber() + delimitor +
               getSessionID() + delimitor +
               getExecutingFirmID() + delimitor +
               getManualOrderIdentifier() + delimitor +
               getMessageType() + delimitor +
               getCustomerTypeIndicator() + delimitor +
               getOrigin() + delimitor +
               getCMEGlobexMessageID() + delimitor +
               getMessageLinkID() + delimitor +
               getOrderFlowID() + delimitor +
               getSpreadLegLinkID() + delimitor +
               getInstrumentDescription() + delimitor +
               getMarketSegmentID() + delimitor +
               getClientOrderID() + delimitor +
               getCMEGlobexOrderID(i) + delimitor +
               getBuySellIndicator() + delimitor +
               getQuantity() + delimitor +
               getLimitPrice() + delimitor +
               getStopPrice() + delimitor +
               getOrderType() + delimitor +
               getOrderQualifier() + delimitor +
               getIFMFlag() + delimitor +
               getDisplayQuantity() + delimitor +
               getMinimumQuantity() + delimitor +
               getCountryofOrigin() + delimitor +
               getFillPrice() + delimitor +
               getFillQuantity() + delimitor +
               getCumulativeQuantity() + delimitor +
               getRemainingQuantity() + delimitor +
               getAggressorFlag() + delimitor +
               getSourceofCancellation() + delimitor +
               getRejectReason() + delimitor +
               getProcessedQuotes() + delimitor +
               getCrossID() + delimitor +
               getQuoteRequestID() + delimitor +
               getMessageQuoteID() + delimitor +
               getQuoteEntryID() + delimitor +
               getBidPrice() + delimitor +
               getBidSize() + delimitor +
               getOfferPrice() + delimitor +
               getOfferSize();
        if(i < n -1)
            res += "\n";
    }
    return  res;
}

std::string AuditTrailOrderMassActionReport::getCountryofOrigin() {
    return this->message_.getHeader().getField(FIX::FIELD::TargetLocationID);
}

std::string AuditTrailOrderMassActionReport::getCMEGlobexOrderID(uint32_t i) {
    std::string msgString = this->message_.toString();
    size_t found = 0;

    for(auto j = 0; j <= i; ++j ){
        found = msgString.find("535=", found + 1);

        if(found == std::string::npos){
            break;
        }
        else if(j == i){

            auto tail = msgString.find("\1", found);

            return msgString.substr(found + 4, tail - found - 4);
        }
    }

    return "";
}