#pragma once

#include "wav_header.h"
#include "exceptions.h"

#include <cstdint>
#include <string>
#include <vector>
#include <cstring>
#include <memory>
#include <fstream>
#include <iostream>
#include <algorithm>

namespace writer
{

class Writer {
private:
    std::string filename_;
    std::fstream ofs_;
    std::size_t pos_;

public:
    Writer() : pos_(0) {};
    Writer(const std::string& filename) : filename_(filename), pos_(0) {
        ofs_.open(filename, std::ios::binary | std::ios::out);
        if (!ofs_.is_open()) {
            throw OpeningFileException(filename_);
        }
    }

    ~Writer() = default;
    void open(const std::string& filename);
    void write_header(wav_header_st& hdr, std::size_t size);
    void write_data(std::vector<int16_t>& v, std::size_t byte_count);
    void seekp(std::size_t t);
};

}