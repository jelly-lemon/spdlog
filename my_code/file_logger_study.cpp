#include <iostream>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"

void basic_logfile_example()
{
    try
    {
        //
        // 【注意】生成的日志文件位置是根据 exe 所在路径生成的，在 cmake-build-debug 目录下
        // logger->info 默认只向文件写入日志，不会打印到控制台
        //
        auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
        // 输出到控制台
        spdlog::info("hello world 你好世界");
        // 默认有换行
        logger->info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}

int main()
{
    basic_logfile_example();

    return 0;
}