#include "commander.h"


namespace commander
{

Commander::Commander(std::size_t argc, char** argv) {
    
    if (argc < 2) {
        throw FewArgsException();
    }

    if (std::strcmp(argv[1], "-h") == 0) {
        get_help();
        std::exit(0);
    }
        
    files_.push_back("out.wav");
    for (std::size_t i = 1; i < argc - 1; ++i) {
        files_.push_back(argv[i]);
    }
        
    if (!txt_is_exist(argv[argc - 1])) {
        throw TXTExistException();
    }
    text_.open(argv[argc - 1]);
    if (!text_.is_open()) {
        throw OpeningFileException(argv[argc - 1]);
    }
}

    void Commander::gcommand(std::vector<std::string>& sparams, std::vector<double>& dparams) {

    std::vector<std::string> params;
    std::string line;
    std::string word;

    if (!getline(text_, line)) {
        sparams.push_back(NaC);
        return;
    }

    std::stringstream stream(line);
    while (getline(stream, word, ' ')) { 
        params.push_back(word);
    }

    sparams.push_back(params.at(0));
    std::size_t i = 1;
    for (; params.at(i)[0] == '$'; ++i) {
        std::string tmp = params.at(i).substr(1);
        std::size_t arg = std::stoul(tmp);
        sparams.push_back(files_[arg]);
    }

    for (; i < params.size(); ++i) {
        dparams.push_back(std::stod(params.at(i)));
    }
}

void Commander::run() {
    try {
        writer::Writer ofs(out_file);
        while (true) {
            std::vector<std::string> sparams;
            std::vector<double> dparams;
            gcommand(sparams, dparams);
            if (sparams.at(0) == NaC) {
                break;
            }
            std::vector<std::unique_ptr<reader::WavReader>> winstreams;
            get_instreams(winstreams, sparams);
            for (std::size_t i = 1; i < sparams.size(); ++i) {
                if (sparams.at(i).find(".wav") != std::string::npos) {
                    winstreams.push_back(std::make_unique<reader::WavReader>(reader::WavReader(sparams.at(i))));
                }
                else {
                    throw TypeFileException(sparams.at(i), "wav");
                }
            }
            processing_hdr(winstreams, ofs);
            wav_header_st hdr;
            for (std::size_t i = 0; i < winstreams.size(); ++i) {
                // reader::WavReader * ifs = (reader::WavReader *) instreams.at(i);
                winstreams.at(i)->read_header(hdr, WAV_HEADER_SIZE);
                if (i == 0) {
                    ofs.write_header(hdr, WAV_HEADER_SIZE);
                }
            }

            std::vector<std::unique_ptr<reader::Reader>> instreams;
            for (std::size_t i = 0; i < winstreams.size(); ++i) {
                instreams.push_back(std::make_unique<reader::Reader>(winstreams.at(i)));
            }

            std::unique_ptr<converter::Converter> conv = converter::createConverter(sparams[0]);
            conv->convert(instreams, ofs, dparams);
            ofs.seekp(0);
        }
    }
    catch(const BadCommandException& e) {
        std::cerr << e.what() << std::endl;
        exit(e.exit_code());
    }
    catch(const FewArgsException& e) {
        std::cerr << e.what() << std::endl;
        exit(e.exit_code());
    }
    catch(const TXTExistException& e) {
        std::cerr << e.what() << std::endl;
        exit(e.exit_code());
    }
    catch(const FileException& e) {
        std::cerr << e.what() << std::endl;
        exit(e.exit_code());
    }
    catch(const WavException& e) {
        std::cerr << e.what() << std::endl;
        exit(e.exit_code());
    }
    catch(const StreamException& e) {
        std::cerr << e.what() << std::endl;
        exit(e.exit_code());
    }
    catch(const SizeMismatchException& e) {
        std::cerr << e.what() << std::endl;
        exit(e.exit_code());
    }
}

void Commander::get_help() const noexcept {
    std::cout << "----------------HELP----------------" << std::endl;
    std::cout << "./wav [file1.wav [file2.wav...] commands.txt]" << std::endl;
    std::cout << "commands.txt : [converterName $N... other_args...]" << std::endl;
    std::cout << "\t$N arg : \"fileN.wav\"" << std::endl;
    std::cout << "\t$0 arg : \"out.wav\". Created and can be used" << std::endl;
    std::cout << "\tafter the first use of the converter" << std::endl;
}

bool Commander::txt_is_exist(const std::string filename) {
    return filename.find(".txt") != std::string::npos;
}

void Commander::get_instreams(std::vector<std::unique_ptr<reader::WavReader>>& instreams, std::vector<std::string>& sparams) {
    for (std::size_t i = 1; i < sparams.size(); ++i) {
        if (sparams.at(i).find(".wav") != std::string::npos) {
            instreams.push_back(std::make_unique<reader::WavReader>(reader::WavReader(sparams.at(i))));
        }
        else {
            throw TypeFileException(sparams.at(i), "wav");
        }
    }
}

void Commander::free_instreams(std::vector<reader::Reader *>& instreams) {
    for (auto s : instreams) {
        delete s;
    }
}

void Commander::processing_hdr(std::vector<std::unique_ptr<reader::WavReader>>& winstreams, writer::Writer& ofs) {
    wav_header_st hdr;
    for (std::size_t i = 0; i < winstreams.size(); ++i) {
        winstreams.at(i)->read_header(hdr, WAV_HEADER_SIZE);
        if (i == 0) {
            ofs.write_header(hdr, WAV_HEADER_SIZE);
        }
    }
}

}