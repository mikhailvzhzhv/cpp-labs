#pragma once

#include <cstdint>
#include <string>

const uint32_t    WAV_HEADER_SIZE {44};
const uint8_t     CHUNK_ID[4] {'R', 'I', 'F', 'F'};
const uint8_t     WAVE[4] {'W', 'A', 'V', 'E'};
const uint8_t     FMT[4] {'f', 'm', 't', ' '};
const uint32_t    SUBCHUNK_SIZE {16};
const uint16_t    AUDIO_FORMAT {1};
const uint16_t    NUM_OF_CHUNCK {1};
const uint32_t    SAMPLE_RATE {44100};
const uint32_t    BYTE_RATE {88200};
const uint16_t    BLOCK_ALIGN {2};
const uint16_t    BITS_PER_SAMPLE {16};
const uint8_t     SUBCHUNK2ID[4] {'d', 'a', 't', 'a'};

const std::size_t BYTES_PER_SECOND = SAMPLE_RATE * NUM_OF_CHUNCK * BLOCK_ALIGN;
const std::size_t COUNT_SAMPLES_PER_SEC = BYTES_PER_SECOND / BLOCK_ALIGN;
const std::string out_file{"out.wav"};

struct wav_header_st {
    uint8_t     chunk_id[4];
    uint32_t    chunk_size;
    uint8_t     wave[4];
    uint8_t     fmt[4];
    uint32_t    subchunk_size;
    uint16_t    audio_format;
    uint16_t    num_of_chan;
    uint32_t    sample_rate;
    uint32_t    byte_rate;
    uint16_t    block_align;
    uint16_t    bits_per_sample;
    uint8_t     subchunk2ID[4];
    uint32_t    subchunk2size;
};