#!/bin/bash
# setup.sh - Script tự động setup môi trường cho dự án

echo "🚀 Đang setup môi trường kiểm thử Catch2..."

# Kiểm tra compiler
if ! command -v g++ &> /dev/null; then
    echo "❌ Không tìm thấy g++. Vui lòng cài đặt:"
    echo "   Windows: MinGW hoặc Visual Studio"
    echo "   Ubuntu: sudo apt install build-essential"
    echo "   macOS: xcode-select --install"
    exit 1
fi

echo "✅ Compiler g++ đã sẵn sàng: $(g++ --version | head -n1)"

# Kiểm tra Catch2 header
if [ ! -f "catch.hpp" ]; then
    echo "📥 Đang tải Catch2 header..."
    if command -v curl &> /dev/null; then
        curl -L -o catch.hpp https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp
    elif command -v wget &> /dev/null; then
        wget -O catch.hpp https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp
    else
        echo "❌ Cần curl hoặc wget để tải Catch2. Vui lòng tải thủ công:"
        echo "   https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp"
        exit 1
    fi
fi

echo "✅ Catch2 header đã sẵn sàng"

# Kiểm tra các file cần thiết
required_files=("ticket.h" "ticket.cpp" "test_ticket.cpp" "Makefile")
missing_files=()

for file in "${required_files[@]}"; do
    if [ ! -f "$file" ]; then
        missing_files+=("$file")
    fi
done

if [ ${#missing_files[@]} -ne 0 ]; then
    echo "❌ Thiếu các file sau:"
    printf '   %s\n' "${missing_files[@]}"
    exit 1
fi

echo "✅ Tất cả file cần thiết đã có"

# Build test
echo "🔨 Đang build test..."
if make test > /dev/null 2>&1; then
    echo "✅ Build thành công!"
    echo ""
    echo "🎉 Setup hoàn tất! Sử dụng các lệnh sau:"
    echo "   make test    - Chạy tất cả test"
    echo "   make clean   - Dọn dẹp file build"
    echo ""
    echo "📚 Xem README.md để biết thêm chi tiết"
else
    echo "❌ Build thất bại. Kiểm tra lỗi ở trên"
    exit 1
fi