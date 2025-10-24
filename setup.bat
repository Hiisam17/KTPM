@echo off
REM setup.bat - Script tự động setup môi trường cho Windows

echo 🚀 Đang setup môi trường kiểm thử Catch2...

REM Kiểm tra compiler
g++ --version >nul 2>&1
if %errorlevel% neq 0 (
    echo ❌ Không tìm thấy g++. Vui lòng cài đặt MinGW hoặc Visual Studio
    echo    Download tại: https://www.mingw-w64.org/
    pause
    exit /b 1
)

echo ✅ Compiler g++ đã sẵn sàng

REM Kiểm tra Catch2 header
if not exist "catch.hpp" (
    echo 📥 Đang tải Catch2 header...
    powershell -Command "try { Invoke-WebRequest -Uri 'https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp' -OutFile 'catch.hpp' } catch { Write-Host '❌ Không thể tải Catch2. Vui lòng tải thủ công'; exit 1 }"
    if %errorlevel% neq 0 (
        echo ❌ Tải thất bại. Vui lòng tải thủ công từ:
        echo    https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp
        pause
        exit /b 1
    )
)

echo ✅ Catch2 header đã sẵn sàng

REM Kiểm tra các file cần thiết
set missing=0
if not exist "ticket.h" (
    echo ❌ Thiếu file: ticket.h
    set missing=1
)
if not exist "ticket.cpp" (
    echo ❌ Thiếu file: ticket.cpp  
    set missing=1
)
if not exist "test_ticket.cpp" (
    echo ❌ Thiếu file: test_ticket.cpp
    set missing=1
)
if not exist "Makefile" (
    echo ❌ Thiếu file: Makefile
    set missing=1
)

if %missing%==1 (
    echo Vui lòng đảm bảo có đầy đủ file cần thiết
    pause
    exit /b 1
)

echo ✅ Tất cả file cần thiết đã có

REM Build test
echo 🔨 Đang build test...
g++ -std=c++11 -Wall -Wextra -o test_ticket.exe test_ticket.cpp ticket.cpp >nul 2>&1
if %errorlevel% neq 0 (
    echo ❌ Build thất bại. Chạy lại với:
    echo    g++ -std=c++11 -Wall -Wextra -o test_ticket.exe test_ticket.cpp ticket.cpp
    pause
    exit /b 1
)

echo ✅ Build thành công!
echo.
echo 🎉 Setup hoàn tất! Sử dụng các lệnh sau:
echo    .\test_ticket.exe  - Chạy test
echo    make test          - Build và chạy test
echo    make clean         - Dọn dẹp file build
echo.
echo 📚 Xem README.md để biết thêm chi tiết
pause