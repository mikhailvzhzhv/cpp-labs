#pragma once

#include <exception>
#include <string>

class BaseException : public std::exception { // 1
protected:
    std::string text_;
    const std::string space_{" "};
public:
    virtual const char* what() const noexcept {
        return "Exception";
    }
    virtual int exit_code() const noexcept {
        return 1;
    }
    virtual ~BaseException() noexcept = default;
};


class FileException : public BaseException { // 2
public:
    virtual int exit_code() const noexcept {
        return 2;
    }
    virtual ~FileException() noexcept = default;
};

class TypeFileException : public FileException { 
public:
    TypeFileException(std::string filename, std::string text) {
        text_ = filename + space_ + "is not" + space_ + text;
    };
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual ~TypeFileException() noexcept = default;
};

class OpeningFileException final : public FileException { // 21
public:
    OpeningFileException(std::string text) {
        text_ = text + space_ + "cannot open";
    };
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual ~OpeningFileException() noexcept = default;
};

class EmptyFileException final : public FileException { // 22
public:
    EmptyFileException(std::string& text) {
        text_ = text + space_ + "is empty";
    };
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual ~EmptyFileException() noexcept = default;
};

class TXTExistException final : public FileException { // 23
public:
    TXTExistException() {
        text_ = "TXT file is nesseccery argumment\n-h for help";
    };
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual ~TXTExistException() noexcept = default;
};


class WavException : public BaseException { // 3
public:
    virtual int exit_code() const noexcept {
        return 2;
    }
    virtual ~WavException() noexcept = default;
};

class BadFormatException final : public WavException { // 31
public:
    BadFormatException(std::string& text) {
        text_ = text + space_ + "has bad format";
    };
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual ~BadFormatException() noexcept = default;
};


class ArgsException : public BaseException { // 4
public:
    virtual int exit_code() const noexcept {
        return 4;
    }
    virtual ~ArgsException() noexcept = default;
};

class FewArgsException final : public ArgsException { // 41
public:
    FewArgsException() {
        text_ = "Too few arguments\n-h for help";
    };
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual ~FewArgsException() noexcept = default;
};


class CommandException : public BaseException { // 5
public:
    virtual ~CommandException() noexcept = default;
};

class BadCommandException final : public CommandException { // 51
public:
    BadCommandException(std::string text) {
        text_ = "Cannot find" + space_ + "\"" + text + "\"" + space_ + "command";
    }
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual ~BadCommandException() noexcept = default;
};

class BadParamsException final : public CommandException { // 51
public:
    BadParamsException(std::string text) {
        text_ = "Bad params in" + space_ + text;
    }
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual ~BadParamsException() noexcept = default;
};

class StreamException final : public BaseException { // 6
public:
    StreamException(std::string text) {
        text_ = "Stream failure in" + space_ + "\"" + text + "\"";
    }
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual int exit_code() const noexcept {
        return 6;
    }
    virtual ~StreamException() noexcept = default;
};

class SizeMismatchException final : public BaseException {
public:
    SizeMismatchException(std::string text) {
        text_ = text;
    };
    virtual const char* what() const noexcept override {
        return text_.c_str();
    }
    virtual int exit_code() const noexcept {
        return 7;
    }
    virtual ~SizeMismatchException() noexcept = default;
};