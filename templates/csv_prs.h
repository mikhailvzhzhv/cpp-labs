#pragma once
#include <iostream>
#include <sstream>
#include <tuple>
#include <string>
#include <algorithm>

template <typename... Args>
class CSVParser {
private:
    std::istream& stream_;
    int cskip_;

public:
    CSVParser(std::istream& stream, int cskip) : stream_(stream), cskip_(cskip) {};
    ~CSVParser() = default;

    class InputIterator {
    private:
        std::istream& stream_;
        int cskip_;
        std::tuple<Args...> curTuple_;
        bool isEnd;

        template <size_t idx>
        void readLine(std::istream& ss) {
            if constexpr (idx < sizeof... (Args)) {
                std::string l;
                std::getline(ss, l, ',');
                std::stringstream ls(l);
                ls >> std::get<idx>(curTuple_);
                readLine<idx + 1>(ss);
            }
        }

    public:
        InputIterator(std::istream& stream, int cskip) : stream_(stream), cskip_(cskip) {
            for (int i = 0; i < cskip_; ++i) {
                std::string line;
                std::getline(stream_, line);
            }
            isEnd = true;
            if (cskip_ != -1) {
                isEnd = false;
                ++(*this);
            }
        }

        bool operator!=(const InputIterator& otherIt) const {
            return !(otherIt.isEnd == isEnd);
        }

        std::tuple<Args...> operator*() const {
            return curTuple_;
        }

        InputIterator& operator++() {
            std::string line;
            if (std::getline(stream_, line)) {
                std::stringstream ss(line);
                readLine<0>(ss);
            }
            else {
                isEnd = true;
            }
            
            return *this;
        }
    };

    InputIterator begin() {
        return InputIterator(stream_, cskip_);
    }

    InputIterator end() {
        return InputIterator(stream_, -1);
    }
};
