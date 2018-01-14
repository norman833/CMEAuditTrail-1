#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc != 3) {
        std::cout << "Usage: " << argv[0] << " source_log_file_name target_audit_trail_file_name " << std::endl;
        return 1;
    }
    std::ifstream fixlog(argv[1]);
    std::string line;
    while (std::getline(fixlog, line))
    {
        std::cout << line << std::endl;
    }

    std::cout << "\nAudit Trail file " << argv[2] << " generated!" << std::endl;

    return 0;
}
