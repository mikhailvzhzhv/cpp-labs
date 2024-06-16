#include "writer.h"

namespace writer
{

void Writer::open(const std::string& filename) {
    ofs_.open(filename, std::ios::binary | std::ios::out);
    if (!ofs_.is_open()) {
        throw OpeningFileException(filename_);
    }
}

void Writer::write_header(wav_header_st& hdr, std::size_t size) {
    ofs_.seekp(pos_, std::ios::beg);
    ofs_.write(reinterpret_cast<const char*>(&hdr), size);
    if (ofs_.bad()) {
        throw StreamException(filename_);
    }
    pos_ += size;
    ofs_.flush();
}

void Writer::write_data(std::vector<int16_t>& v, std::size_t size) {
    ofs_.seekp(pos_, std::ios::beg);
    ofs_.write(reinterpret_cast<const char*>(v.data()), size);
    if (ofs_.bad()) {
        throw StreamException(filename_);
    }
    pos_ += size;
    ofs_.flush();
}

void Writer::seekp(std::size_t t) {
    ofs_.seekp(t);
    pos_ = t;
}

}
