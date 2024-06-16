#include "converter.h"
#include "exceptions.h"

using namespace reader;
using namespace writer;

namespace converter
{   

void Muter::convert(std::vector<std::unique_ptr<reader::Reader>>& instreams, writer::Writer& ofs, std::vector<double>& dparams) {

    std::size_t time1 = dparams.at(0);
    std::size_t time2 = dparams.at(1);
    if (time1 > time2 || dparams.size() != 2 || instreams.size() != 1) {
        throw BadParamsException("muter");
    }
    do {
        std::vector<int16_t> data(COUNT_SAMPLES_PER_SEC);
        instreams.at(0)->read_data(data, BYTES_PER_SECOND);
        mute_sec(data, time1, time2, instreams.at(0)->gsec());
        ofs.write_data(data, instreams.at(0)->gcount());
    }
    while (instreams.at(0)->gcount() == BYTES_PER_SECOND);
}

void Muter::mute_sec(std::vector<int16_t>& data, std::size_t time1, std::size_t time2, std::size_t cur_time) {
    if (time1 < cur_time && cur_time <= time2) {
        data.assign(data.size(), static_cast<int16_t>(0));
    }
}

void Mixer::convert(std::vector<std::unique_ptr<reader::Reader>>& instreams, writer::Writer& ofs, std::vector<double>& dparams) {

    std::size_t time = dparams.at(0);
    if (dparams.size() != 1 || instreams.size() != 2) {
        throw BadParamsException("mixer");
    }
    do {
        std::vector<int16_t> mdata(COUNT_SAMPLES_PER_SEC);
        std::vector<int16_t> sdata(COUNT_SAMPLES_PER_SEC);
        instreams.at(0)->read_data(mdata, BYTES_PER_SECOND);
        instreams.at(1)->read_data(sdata, BYTES_PER_SECOND);
        mix_sec(mdata, sdata, time, instreams.at(0)->gsec(), instreams.at(1)->gcount());
        ofs.write_data(mdata, instreams.at(0)->gcount());
    }
    while (instreams.at(0)->gcount() == BYTES_PER_SECOND);
}

void Mixer::mix_sec(std::vector<int16_t>& s1, std::vector<int16_t>& s2,
                    std::size_t time, std::size_t cur_time , std::size_t r2data) {
    if (time < cur_time && r2data != 0) {
        for (std::size_t i = 0; i < COUNT_SAMPLES_PER_SEC; ++i) {
            int32_t mixed_smp = (static_cast<int32_t>(s1[i]) + static_cast<int32_t>(s2[i])) / 2;
            mixed_smp = std::max(static_cast<int32_t>(INT16_MIN), std::min(mixed_smp, static_cast<int32_t>(INT16_MAX)));
            s1[i] = static_cast<int16_t>(mixed_smp);
        }
    }
}

void Echo::convert(std::vector<std::unique_ptr<reader::Reader>>& instreams, writer::Writer& ofs, std::vector<double>& dparams) {
    std::size_t time1 = dparams.at(0);
    std::size_t time2 = dparams.at(1);
    double delay = dparams.at(2);
    double decay = dparams.at(3);
    if (time1 > time2 || dparams.size() != 4 || instreams.size() != 2) {
        throw BadParamsException("echo");
    }
    std::vector<int16_t> pdata(COUNT_SAMPLES_PER_SEC, 0);
    do {
        std::vector<int16_t> data(COUNT_SAMPLES_PER_SEC);
        instreams.at(0)->read_data(data, BYTES_PER_SECOND);
        echo_sec(data, pdata, time1, time2, instreams.at(0)->gsec(), delay, decay);
        ofs.write_data(data, instreams.at(0)->gcount());
    }
    while (instreams.at(0)->gcount() == BYTES_PER_SECOND);
}

void Echo::echo_sec(std::vector<int16_t>& s1, std::vector<int16_t>& s2, 
                    std::size_t time1, std::size_t time2, 
                    std::size_t cur_time, 
                    double delay, double decay) {
    if (time1 < cur_time && cur_time <= time2) {
        std::vector<int16_t> echoed_samples(COUNT_SAMPLES_PER_SEC);
        std::size_t echo_delay = static_cast<std::size_t>(delay * COUNT_SAMPLES_PER_SEC);
        for (std::size_t i = 0; i < COUNT_SAMPLES_PER_SEC; ++i) {
            int32_t echo;
            echoed_samples[i] = s1[i];
            int32_t echoed_smp = static_cast<int32_t>(echoed_samples[i]);
            if (i >= echo_delay) {
                echo = static_cast<int32_t>(echoed_samples[i - echo_delay]) * decay;
            } else {
                echo = static_cast<int32_t>(s2[COUNT_SAMPLES_PER_SEC - echo_delay + i]) * decay;
            }
            echoed_smp += echo;
            echoed_smp = std::max(static_cast<int32_t>(INT16_MIN), std::min(echoed_smp, static_cast<int32_t>(INT16_MAX)));
            echoed_samples[i] = static_cast<int16_t>(echoed_smp);
        }
        s1 = echoed_samples;
        s2 = s1;
    }
}

std::unique_ptr<Converter> createConverter(const std::string& converter) {
    if (converter == "mute") {
        return std::make_unique<Muter>();
    } else if (converter == "mix") {
        return std::make_unique<Mixer>();
    } else if (converter == "echo") {
        return std::make_unique<Echo>();
    }
    throw BadCommandException(converter);             
}

}
