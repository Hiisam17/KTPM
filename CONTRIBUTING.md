# Hướng dẫn đóng góp cho dự án

## 🤝 Cách đóng góp

Chúng tôi rất hoan nghênh mọi đóng góp! Dưới đây là hướng dẫn chi tiết:

### 1. Setup môi trường phát triển

```bash
# Clone repository
git clone <url>
cd KTPM

# Chạy script setup (Windows)
setup.bat

# Hoặc (Linux/macOS)
./setup.sh
```

### 2. Quy trình đóng góp

1. **Fork** repository về GitHub của bạn
2. **Clone** fork về máy local:
   ```bash
   git clone https://github.com/<your-username>/KTPM.git
   ```
3. Tạo **branch mới** cho feature:
   ```bash
   git checkout -b feature/ten-feature-moi
   ```
4. Thực hiện **thay đổi** và **test**
5. **Commit** với message rõ ràng:
   ```bash
   git commit -m "Add: Thêm test case cho boundary values"
   ```
6. **Push** lên GitHub:
   ```bash
   git push origin feature/ten-feature-moi
   ```
7. Tạo **Pull Request**

### 3. Coding Standards

#### 📝 Code Style
- Sử dụng **4 spaces** cho indentation
- Đặt tên biến/hàm theo **camelCase**
- Comment bằng **tiếng Việt** có dấu
- Tối đa **80 ký tự** mỗi dòng

#### 🧪 Test Guidelines
```cpp
// ✅ Good
TEST_CASE("Test boundary conditions", "[boundary]") {
    SECTION("Test with minimum valid money") {
        REQUIRE(buyTicket(1000, 1) == "expected_result");
    }
}

// ❌ Bad  
TEST_CASE("test", "[test]") {
    REQUIRE(buyTicket(1000, 1) == "expected_result");
}
```

#### 📋 Commit Message Format
```
Type: Mô tả ngắn gọn

- Add: Thêm feature mới
- Fix: Sửa bug
- Update: Cập nhật code existing
- Test: Thêm hoặc sửa test
- Docs: Cập nhật documentation
- Refactor: Tái cấu trúc code

Ví dụ:
Add: Thêm test case cho invalid input
Fix: Sửa lỗi tính toán tiền thừa
```

### 4. Loại đóng góp được chào đón

#### 🧪 **Test Cases**
- Thêm test cases cho edge cases
- Thêm test cho error handling
- Performance tests
- Integration tests

#### 🐛 **Bug Fixes**
- Sửa logic errors
- Memory leaks
- Performance issues

#### 📚 **Documentation**
- Cải thiện README
- Thêm code comments
- API documentation
- Tutorial/examples

#### ✨ **Features**
- Thêm validation mới
- UI improvements
- New functionality

### 5. Quy trình Review

#### Trước khi submit PR:
- [ ] Code compile thành công
- [ ] Tất cả test cases pass
- [ ] Code tuân thủ style guide
- [ ] Documentation được cập nhật

#### Review checklist:
- [ ] Logic correctness
- [ ] Test coverage
- [ ] Performance impact
- [ ] Documentation quality

### 6. Báo cáo Bug

Khi báo cáo bug, vui lòng include:

```markdown
**Mô tả bug:**
Mô tả ngắn gọn về bug

**Các bước reproduce:**
1. Chạy lệnh...
2. Input...
3. Kết quả actual vs expected

**Environment:**
- OS: Windows 10/Linux/macOS
- Compiler: g++ version
- Catch2 version: 2.13.10

**Output/Screenshots:**
Paste output hoặc screenshot nếu có
```

### 7. Yêu cầu Feature mới

Template cho feature request:

```markdown
**Feature mong muốn:**
Mô tả feature bạn muốn thêm

**Tại sao cần feature này:**
Giải thích use case và lợi ích

**Proposed solution:**
Ý tưởng implement (optional)

**Alternative solutions:**
Các cách khác để giải quyết (optional)
```

### 8. Development Commands

```bash
# Build và test
make test

# Clean build files  
make clean

# Run với verbose output
./test_ticket.exe -s

# Check memory leaks (Linux)
valgrind --tool=memcheck ./test_ticket

# Format code (nếu có clang-format)
clang-format -i *.cpp *.h
```

### 9. Liên hệ

- 📧 Email: [maintainer-email]
- 💬 GitHub Issues: Cho bugs và feature requests
- 🤔 GitHub Discussions: Cho questions và ideas

---

**Cảm ơn bạn đã đóng góp! 🎉**