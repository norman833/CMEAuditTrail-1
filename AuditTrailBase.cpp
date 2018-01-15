#include "AuditTrailBase.h"

const std::string AuditTrailBase::FROM_CME = "FROM CME";
const std::string AuditTrailBase::TO_CME = "TO CME";

AuditTrailBase::AuditTrailBase(const Message &message, const std::string& txnTime) : message_(message), txnTime_(txnTime)  {

};

std::string AuditTrailBase::getCSV() {
    std::string delimitor = ",";
    return getSendingTimestamps() + delimitor +
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
    getCMEGlobexOrderID() + delimitor +
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
};

std::string AuditTrailBase::getSendingTimestamps() {
    if(this->getMessageDirection() == AuditTrailBase::TO_CME ){
        return this->message_.getHeader().getField(FIX::FIELD::SendingTime);
    }
    else
        return "";
};

std::string AuditTrailBase::getReceivingTimestamps() {
    if(this->getMessageDirection() == AuditTrailBase::FROM_CME ){
        return this->txnTime_;
    }
    else
        return "";
}

std::string AuditTrailBase::getMessageDirection() {
    auto senderCompID = this->message_.getHeader().getField(FIX::FIELD::SenderCompID);
    if(senderCompID == "CME")
        return AuditTrailBase::FROM_CME;
    else
        return AuditTrailBase::TO_CME;
};

std::string AuditTrailBase::getOperatorID() {
    return "";
};

std::string AuditTrailBase::getSelf_MatchPreventionID(){
    return "";
};

std::string AuditTrailBase::getAccountNumber(){
    return "";
}

std::string AuditTrailBase::getSessionID() {
    if(this->getMessageDirection() == AuditTrailBase::FROM_CME ) {
        auto targetCompID = this->message_.getHeader().getField(FIX::FIELD::TargetCompID);
        return targetCompID.substr(0,3);
    }
    else{
        auto senderCompID = this->message_.getHeader().getField(FIX::FIELD::SenderCompID);
        return senderCompID.substr(0,3);
    }
};

std::string AuditTrailBase::getExecutingFirmID() {
    if(this->getMessageDirection() == AuditTrailBase::FROM_CME ) {
        auto targetCompID = this->message_.getHeader().getField(FIX::FIELD::TargetCompID);
        return targetCompID.substr(3,3);
    }
    else{
        auto senderCompID = this->message_.getHeader().getField(FIX::FIELD::SenderCompID);
        return senderCompID.substr(3,3);
    }
};

std::string AuditTrailBase::getManualOrderIdentifier() {
    return "";
};

std::string AuditTrailBase::getMessageType() {
    return "";
};

std::string AuditTrailBase::getCustomerTypeIndicator() {
    return "";
};

std::string AuditTrailBase::getOrigin() {
    return "";
};

std::string AuditTrailBase::getCMEGlobexMessageID() {
    return "";
};

std::string AuditTrailBase::getMessageLinkID() {
    return "";
};

std::string AuditTrailBase::getOrderFlowID() {
    return "";
};

std::string AuditTrailBase::getSpreadLegLinkID() {
    return "";
};

std::string AuditTrailBase::getInstrumentDescription(){
    return "";
};

std::string AuditTrailBase::getMarketSegmentID() {
    return "";
};

std::string AuditTrailBase::getClientOrderID() {
    return "";
};

std::string AuditTrailBase::getCMEGlobexOrderID() {
    return "";
};

std::string AuditTrailBase::getBuySellIndicator() {
    return "";
};

std::string AuditTrailBase::getQuantity() {
    return "";
};

std::string AuditTrailBase::getLimitPrice() {
    return "";
}

std::string AuditTrailBase::getStopPrice() {
    return "";
}

std::string AuditTrailBase::getOrderType() {
    return "";
}

std::string AuditTrailBase::getOrderQualifier() {
    return "";
}

std::string AuditTrailBase::getIFMFlag() {
    return "";
}

std::string AuditTrailBase::getDisplayQuantity(){
    return "";
};

std::string AuditTrailBase::getMinimumQuantity() {
    return "";
}

std::string AuditTrailBase::getCountryofOrigin() {
    return "";
}

std::string AuditTrailBase::getFillPrice() {
    return "";
}

std::string AuditTrailBase::getFillQuantity() {
    return "";
}

std::string AuditTrailBase::getCumulativeQuantity() {
    return "";
}

std::string AuditTrailBase::getRemainingQuantity() {
    return "";
}

std::string AuditTrailBase::getAggressorFlag() {
    return "";
}

std::string AuditTrailBase::getSourceofCancellation() {
    return "";
}

std::string AuditTrailBase::getRejectReason() {
    return "";
}

std::string AuditTrailBase::getProcessedQuotes() {
    return "";
}
std::string AuditTrailBase::getCrossID() {

    return "";
}

std::string AuditTrailBase::getQuoteRequestID() {
    return "";
}

std::string AuditTrailBase::getMessageQuoteID() {
    return "";
}

std::string AuditTrailBase::getQuoteEntryID() {
    return "";
}

std::string AuditTrailBase::getBidPrice() {
    return "";
}

std::string AuditTrailBase::getBidSize() {
    return "";
}

std::string AuditTrailBase::getOfferPrice() {
    return "";
}

std::string AuditTrailBase::getOfferSize() {
    return "";
}