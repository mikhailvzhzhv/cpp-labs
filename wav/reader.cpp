#include "reader.h"

namespace reader
{

void Reader::open(const std::string& filename) {
    ifs_.open(filename, std::ios::binary);
    if (!ifs_.is_open()) {
        throw OpeningFileException(filename);
    }
    filename_ = filename;
}

void WavReader::read_header(wav_header_st& hdr, std::size_t size) {
    ifs_.read(reinterpret_cast<char*>(&hdr), size);
    if (!ifs_.gcount()) {
        throw EmptyFileException(filename_);
    }
    pos_ += ifs_.gcount();

    while (std::strncmp(reinterpret_cast<const char*>(hdr.subchunk2ID), "data", 4) && ifs_.gcount()) {
        ifs_.seekg(hdr.subchunk2size + pos_);
        pos_ += sizeof(uint8_t)*4 + sizeof(uint32_t) + hdr.subchunk2size;
        ifs_.read(reinterpret_cast<char*>(&hdr.subchunk2ID), sizeof(uint8_t)*4);
        if (ifs_.bad()) {
            throw StreamException(filename_);
        }
        ifs_.read(reinterpret_cast<char*>(&hdr.subchunk2size), sizeof(uint32_t));
        if (ifs_.bad()) {
            throw StreamException(filename_);
        }
    }

    if (std::strncmp(reinterpret_cast<const char*>(hdr.chunk_id), reinterpret_cast<const char*>(CHUNK_ID), 4) ||
        std::strncmp(reinterpret_cast<const char*>(hdr.wave), reinterpret_cast<const char*>(WAVE), 4) ||
        std::strncmp(reinterpret_cast<const char*>(hdr.fmt), reinterpret_cast<const char*>(FMT), 4) ||
        hdr.audio_format != AUDIO_FORMAT || hdr.bits_per_sample != BITS_PER_SAMPLE ||
        std::strncmp(reinterpret_cast<const char*>(hdr.subchunk2ID), reinterpret_cast<const char*>(SUBCHUNK2ID), 4)) {
            
        throw BadFormatException(filename_);
    }
}

void Reader::read_data(std::vector<int16_t>& data, std::size_t size) {
    if (data.size() * sizeof(data.data()) < size) {
        throw SizeMismatchException("Size mismatch in vector. Maybe bad alloc");
    }
    ifs_.read(reinterpret_cast<char*>(data.data()), size);
    if (ifs_.bad()) {
        throw StreamException(filename_);
    }
    ++sec_;
}

std::size_t Reader::gcount() const noexcept {
    return ifs_.gcount();
}

std::size_t Reader::seekg(std::size_t shift) {
    pos_ = shift;
    ifs_.seekg(pos_);
    return pos_;
}

std::size_t Reader::gpos() const noexcept {
    return pos_;
}

std::size_t Reader::gsec() const noexcept {
    return sec_;
}

}