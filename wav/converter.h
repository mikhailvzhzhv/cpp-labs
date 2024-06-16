#pragma once

#include "reader.h"
#include "writer.h"
#include "exceptions.h"

namespace converter
{

class Converter {
public:
    virtual ~Converter() {};
    virtual void convert(std::vector<std::unique_ptr<reader::Reader>>& instreams, writer::Writer& ofs, std::vector<double>& dparams) = 0;
};

class Muter : public Converter {
public:
    ~Muter() {};
    virtual void convert(std::vector<std::unique_ptr<reader::Reader>>& instreams, writer::Writer& ofs, std::vector<double>& dparams) override;
    void mute_sec(  std::vector<int16_t>& data, 
                    std::size_t time1, std::size_t time2, 
                    std::size_t cur_time);
};

class Mixer : public Converter {
public:
    ~Mixer() {};
    virtual void convert(std::vector<std::unique_ptr<reader::Reader>>& instreams, writer::Writer& ofs, std::vector<double>& dparams) override;
    void mix_sec(   std::vector<int16_t>& s1, std::vector<int16_t>& s2,
                    std::size_t time, std::size_t cur_time , std::size_t r2data);
};

class Echo : public Converter {
public:
~Echo() {};
    virtual void convert(std::vector<std::unique_ptr<reader::Reader>>& instreams, writer::Writer& ofs, std::vector<double>& dparams) override;
    void echo_sec(  std::vector<int16_t>& s1, std::vector<int16_t>& s2, 
                    std::size_t time1, std::size_t time2, 
                    std::size_t cur_time, 
                    double delay, double decay);
};

std::unique_ptr<Converter> createConverter(const std::string& converter);

}
