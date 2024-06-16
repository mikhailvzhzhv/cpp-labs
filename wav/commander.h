#pragma once

#include "converter.h"
#include "reader.h"
#include "writer.h"
#include "exceptions.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>

const std::string NaC {"NaC"}; // Not a Command

namespace commander
{
class Commander {
private:
    std::vector<std::string> files_;
    std::ifstream text_;

    bool txt_is_exist(const std::string filename);
    void get_instreams(std::vector<std::unique_ptr<reader::WavReader>>& instreams, std::vector<std::string>& sparams);
    void free_instreams(std::vector<reader::Reader *>& instreams);
    void processing_hdr(const std::vector<std::unique_ptr<reader::WavReader>>& instreams, writer::Writer& ofs);

public:
    Commander(std::size_t argc, char** argv);
    ~Commander() = default;
    void gcommand(std::vector<std::string>& sparams, std::vector<double>& dparams) ;
    void run();
    void get_help() const noexcept;
};

}