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

namespace reader
{

class Reader {
protected:
    std::string filename_;
    std::ifstream ifs_;
    std::size_t pos_;
    std::size_t sec_;

public:
    Reader() : pos_(0), sec_(0) {};
    Reader(const std::string& filename) : filename_(filename), pos_(0), sec_(0) {
        ifs_.open(filename_, std::ios::binary);
        if (!ifs_.is_open()) {
            throw OpeningFileException(filename);
        }
    }

    virtual ~Reader() {};
    void open(const std::string& filename);
    void read_data(std::vector<int16_t>& data, std::size_t size);
    std::size_t gcount() const noexcept;
    std::size_t seekg(std::size_t shift);
    std::size_t gpos() const noexcept;
    std::size_t gsec() const noexcept;
};

class WavReader : public Reader {
public:
    WavReader(const std::string& filename) : Reader(filename) {
        ifs_.open(filename, std::ios::binary);
        if (!ifs_.is_open()) {
            throw OpeningFileException(filename);
        }
    }
    virtual ~WavReader() {};
    void read_header(wav_header_st& hdr, std::size_t size);
};

}