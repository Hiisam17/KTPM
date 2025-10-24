# Dự án Kiểm thử hệ thống mua vé với Catch2

## 📋 Giới thiệu

Dự án này demo việc kiểm thử unit test cho hàm `buyTicket()` - một hệ thống mua vé đơn giản sử dụng framework Catch2.

## 🛠️ Yêu cầu hệ thống

- **Compiler**: GCC hoặc MinGW với hỗ trợ C++11
- **OS**: Windows, Linux, hoặc macOS
- **Git**: Để clone repository

## 📥 Cách cài đặt và chạy

### Bước 1: Clone repository
```bash
git clone <url-repository>
cd KTPM
```

### Bước 2: Kiểm tra các file cần thiết
Đảm bảo repository có các file sau:
```
├── ticket.h          # Header file chứa khai báo hàm
├── ticket.cpp        # Implementation của hàm buyTicket
├── test_ticket.cpp   # File test cases sử dụng Catch2
├── catch.hpp         # Header file Catch2 (đã có sẵn)
├── Makefile          # File build automation
└── README.md         # File hướng dẫn này
```

### Bước 3: Biên dịch và chạy test

#### Option 1: Sử dụng Makefile (Khuyến nghị)
```bash
# Chạy tất cả test
make test

# Dọn dẹp file executable
make clean
```

#### Option 2: Sử dụng g++ trực tiếp
```bash
# Biên dịch
g++ -std=c++11 -Wall -Wextra -o test_ticket.exe test_ticket.cpp ticket.cpp

# Chạy test
./test_ticket.exe        # Linux/macOS
# hoặc
.\test_ticket.exe        # Windows
```

#### Option 3: Sử dụng Visual Studio Code
1. Mở folder trong VS Code
2. Cài extension C/C++
3. Sử dụng Ctrl+Shift+P → "Tasks: Run Task" → chọn "build and test"

## 🧪 Hiểu về Test Cases

Dự án có các test cases kiểm tra:

### ✅ Test Cases hiện tại:
- **Invalid money - too low**: Tiền < 1000 VND
- **Invalid money - too high**: Tiền > 100000 VND  
- **Invalid tickets - too few**: Số vé < 1
- **Invalid tickets - too many**: Số vé > 5
- **Not enough money**: Tiền không đủ mua vé
- **Exact money**: Tiền vừa đủ (không có tiền thừa)
- **Enough money**: Tiền dư (có tiền thừa)

### 📊 Kết quả mong đợi:
Khi chạy thành công, bạn sẽ thấy:
```
===============================================================================
All tests passed (X assertions in 1 test case)
```

## 🔧 Tùy chỉnh Test Cases

### Thêm test case mới:
```cpp
SECTION("Tên test case của bạn") {
    REQUIRE(buyTicket(money, tickets) == "kết quả mong đợi");
}
```

### Các assertion có sẵn:
```cpp
REQUIRE(expression);           // Bắt buộc đúng, dừng nếu sai
CHECK(expression);             // Kiểm tra, tiếp tục nếu sai  
REQUIRE_FALSE(expression);     // Bắt buộc sai
```

## 🎯 Chạy test với options nâng cao

```bash
# Hiển thị chi tiết tất cả test
.\test_ticket.exe -s

# Chạy test với tag cụ thể
.\test_ticket.exe [buyTicket]

# Liệt kê tất cả test cases
.\test_ticket.exe --list-tests

# Chạy test và hiển thị thành công/thất bại
.\test_ticket.exe --reporter compact
```

## 🐛 Xử lý lỗi thường gặp

### Lỗi: "command not found"
```bash
# Cài đặt build tools
# Windows: Cài MinGW hoặc Visual Studio
# Ubuntu: sudo apt install build-essential
# macOS: xcode-select --install
```

### Lỗi: "No such file or directory" 
- Kiểm tra đã có file `catch.hpp` chưa
- Nếu chưa có, tải về: 
```bash
curl -o catch.hpp https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp
```

### Lỗi compilation
- Kiểm tra compiler hỗ trợ C++11: `g++ --version`
- Đảm bảo tất cả file .cpp và .h có cùng encoding

## 🤝 Đóng góp

1. Fork repository
2. Tạo feature branch: `git checkout -b feature/new-test`
3. Commit changes: `git commit -m "Add new test cases"`
4. Push branch: `git push origin feature/new-test`
5. Tạo Pull Request

## 📚 Tài liệu tham khảo

- [Catch2 Documentation](https://github.com/catchorg/Catch2)
- [C++ Unit Testing Best Practices](https://github.com/cpp-best-practices/cpp_starter_project)

## 📞 Hỗ trợ

Nếu gặp vấn đề, vui lòng:
1. Kiểm tra phần "Xử lý lỗi thường gặp" ở trên
2. Tạo issue trên GitHub với mô tả chi tiết lỗi
3. Đính kèm output của lệnh compilation