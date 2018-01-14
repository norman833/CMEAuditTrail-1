#include <iostream>
#include <fstream>
#include "quickfix/Message.h"
#include "AuditTrailGenerator.h"

int main(int argc, char *argv[]){
    using namespace FIX;

    if(argc != 3) {
        std::cout << "Usage: " << argv[0] << " <source_log_file_name> <target_audit_trail_file_name> " << std::endl;
        return 1;
    }
    std::ifstream fixlog(argv[1]);
    std::ofstream auditlog;
    auditlog.open(argv[2], std::ofstream::out|std::ofstream::app);

    std::string line;
    while (std::getline(fixlog, line))
    {
        auto pos = line.find(" : ");

        if(pos != std::string::npos) {
            auto timeStr = line.substr(0, pos);
            auto fixMessage = line.substr(pos + 3);

            Message message(fixMessage);

            auditlog << timeStr << "|" << AuditTrailGenerator::generatorAuditTrail(message) << std::endl;
        }
        else{
            throw("bad format in the input file");
        }
    }

    auditlog.close();
    std::cout << "Audit Trail file " << argv[2] << " generated!" << std::endl;

    return 0;
}
