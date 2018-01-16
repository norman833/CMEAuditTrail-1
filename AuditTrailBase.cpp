#include "AuditTrailBase.h"

const std::string AuditTrailBase::FROM_CME = "FROM CME";
const std::string AuditTrailBase::TO_CME = "TO CME";

AuditTrailBase::AuditTrailBase(const Message &message, const std::string& txnTime) : message_(message), txnTime_(txnTime)  {

};
std::string AuditTrailBase::testAndGetField(const int field) {
    if(this->message_.isSetField(field)){
        return this->message_.getField(field);
    }
    else{
        return "";
    }
}

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
    else{
        return "";
    }
};

std::string AuditTrailBase::getReceivingTimestamps() {
    if(this->getMessageDirection() == AuditTrailBase::FROM_CME ){
        return this->txnTime_;
    }
    else{
        return "";
    }
}

std::string AuditTrailBase::getMessageDirection() {
    auto senderCompID = this->message_.getHeader().getField(FIX::FIELD::SenderCompID);
    if(senderCompID == "CME") {
        return AuditTrailBase::FROM_CME;
    }
    else{
        return AuditTrailBase::TO_CME;
    }
};

std::string AuditTrailBase::getOperatorID() {
    if(this->getMessageDirection() == AuditTrailBase::TO_CME ) {
        return message_.getHeader().getField(FIX::FIELD::SenderSubID);
    }
    else{
        return message_.getHeader().getField(FIX::FIELD::TargetSubID);
    }
};

std::string AuditTrailBase::getSelf_MatchPreventionID(){
    return this->testAndGetField(7928);
};

std::string AuditTrailBase::getAccountNumber(){
    return this->testAndGetField(FIX::FIELD::Account);
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
    return this->testAndGetField(FIX::FIELD::ManualOrderIndicator);
};

std::string AuditTrailBase::getMessageType() {
    std::string msgType{""};

    msgType = this->message_.getHeader().getField(FIX::FIELD::MsgType);

    if(msgType == "8"){
        std::string ordStatus = this->message_.getField(FIX::FIELD::OrdStatus);
        msgType = msgType + "/" + ordStatus;
    }

    return msgType;
};

std::string AuditTrailBase::getCustomerTypeIndicator() {
    return this->testAndGetField(9702);
};

std::string AuditTrailBase::getOrigin() {
    return this->testAndGetField(FIX::FIELD::CustomerOrFirm);
};

std::string AuditTrailBase::getCMEGlobexMessageID() {
    return this->testAndGetField(FIX::FIELD::ExecID);
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
    return this->testAndGetField(FIX::FIELD::SecurityDesc);
};

std::string AuditTrailBase::getMarketSegmentID() {
    if(this->getMessageDirection() == AuditTrailBase::TO_CME){
        return this->message_.getHeader().getField(FIX::FIELD::TargetSubID);
    }
    else {
        return this->message_.getHeader().getField(FIX::FIELD::SenderSubID);
    }
};

std::string AuditTrailBase::getClientOrderID() {
    return this->testAndGetField(FIX::FIELD::ClOrdID);

};

std::string AuditTrailBase::getCMEGlobexOrderID() {
    return "";
};

std::string AuditTrailBase::getBuySellIndicator() {
    return this->testAndGetField(FIX::FIELD::Side);
};

std::string AuditTrailBase::getQuantity() {
    return this->testAndGetField(FIX::FIELD::Quantity);
};

std::string AuditTrailBase::getLimitPrice() {
    return this->testAndGetField(FIX::FIELD::Price);
}


std::string AuditTrailBase::getStopPrice() {
    return this->testAndGetField(FIX::FIELD::StopPx);
}

std::string AuditTrailBase::getOrderType() {
    return this->testAndGetField(FIX::FIELD::OrdType);
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